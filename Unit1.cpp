//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string.h>
#include <stdio.h>
#include "DateUtils.hpp"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int action = 0;
//  begindate = Form1->DateTimePicker1->DateTime;
struct book
{
     char exponame[16];
     char expoplace[16];
     char begindate[16];
     char enddate[16];
     char owner[16];
     char expotype[24];
     char expocount[8];
     char price[8];

        /*
1.	Название выставки
2.	Место проведения
3.	Сроки проведения
4.	Организатор
5.	Тип выставки: универсальная, специализированная, художественная
6.	Количество экспозиций
7.	Цена посещения
*/
} expo;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void inf2struct()  // Перезапись из полей ввода в структуру
{
    strcpy(expo.exponame,Form1->Edit1->Text.c_str());
    strcpy(expo.expoplace,Form1->Edit2->Text.c_str());
    strcpy(expo.owner,Form1->Edit3->Text.c_str());
    strcpy(expo.expocount,Form1->Edit4->Text.c_str());
    strcpy(expo.price,Form1->Edit5->Text.c_str());
    strcpy(expo.expotype,Form1->ComboBox1->Items->Strings[Form1->ComboBox1->ItemIndex].c_str());
    strcpy(expo.begindate,Form1->DateTimePicker1->Date.DateString().c_str());
    strcpy(expo.enddate,Form1->DateTimePicker2->Date.DateString().c_str());
}

void blank2struct()
{
    strcpy(expo.exponame,"");
    strcpy(expo.expoplace,"");
    strcpy(expo.owner,"");
    strcpy(expo.expocount,"");
    strcpy(expo.price,"");
    strcpy(expo.expotype,"");
    strcpy(expo.begindate,"");
    strcpy(expo.enddate,"");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{         //Создание нового файла выбрано
action =1;

FILE *p;
p=fopen("book","rb");
if (p)
{
MessageDlg("Файл уже существует! Сначала удалите старый!",mtWarning,TMsgDlgButtons()<<mbOK,0);
fclose(p);
return;
}
Form1->GroupBox1->Caption="Введите первую запись нового файла";
Form1->GroupBox1->Visible=true;
}
//---------------------------------------------------------------------------
       // Добавление записи в конец файла выбрано
void __fastcall TForm1::N4Click(TObject *Sender)
{
action =2;

//  проверка на существование файла, если нету - вывести сообщение.
FILE *p;
p=fopen("book","rb");
if (!p)
{
MessageDlg("Файл не существует",mtWarning,TMsgDlgButtons()<<mbOK,0);
fclose(p);
return;
}

Form1->GroupBox1->Caption="Введите данные для добавления записи в конец файла";
Form1->GroupBox1->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
switch (action){
case 0: {
ShowMessage("WHAT DA F*CK? HOW?!");
break;
}
case 1:         // Создание файла + первая запись
{
     FILE *p;
     p=fopen("book","wb");
     inf2struct();
     fwrite(&expo,sizeof(expo),1,p);
     fclose(p);
     ShowMessage("Готово!");
     Form1->GroupBox1->Visible=false;
     break;
}

case 2:
{             // ДОбавление записи в конец
        FILE *p;
        p=fopen("book","ab");
        inf2struct();
        fwrite(&expo,sizeof(expo),1,p);
        fclose(p);
        ShowMessage("Готово!");
        Form1->GroupBox1->Visible=false;
        break;

}

case 3:        // Вставка записи по номеру
{
     int RecNo = Form1->Edit6->Text.ToInt(); // Нужный номер записи
     FILE *p;
     FILE *tmp;
     p=fopen("book","rb");
     tmp=fopen("book.tmp","ab");
     for(int i = 1; i < RecNo; i++)
     {         // Переписываем записи до нужной в темп
       if (fread(&expo,sizeof(expo),1,p)!=0)
       {     // Если не достигли конца файла, просто переписываем то, что есть в исходном
        fwrite(&expo,sizeof(expo),1,tmp);
       }
       else
       {   // Если достигли - вписываем пустые значения
        blank2struct();
        fwrite(&expo,sizeof(expo),1,tmp);
       }
    }
    inf2struct();   // пишем поля в структуру
    fwrite(&expo,sizeof(expo),1,tmp); // пишем структуру в файл
          // Запись вставлена
    while(fread(&expo,sizeof(expo),1,p)!=0)   // Дописываем оставшееся, если есть
      fwrite(&expo,sizeof(expo),1,tmp);
    fcloseall();
    remove("book");
    rename("book.tmp","book");
    ShowMessage("Готово!");
    Form1->Edit6->Visible=false;
    Form1->Label2->Visible=false;
    Form1->GroupBox1->Visible=false;
    break;
}

case 4:
{
     int RecNo = Form1->Edit6->Text.ToInt(); // Нужный номер записи
     FILE *p;
     FILE *tmp;
     p=fopen("book","rb");
     tmp=fopen("book.tmp","ab");
        for(int i = 1; i < RecNo; i++)
         {         // Переписываем записи до нужной в темп
           if (fread(&expo,sizeof(expo),1,p)!=0)
                {     // Если не достигли конца файла, просто переписываем то, что есть в исходном
                  fwrite(&expo,sizeof(expo),1,tmp);
                }
           else
                {   // Если достигли - Выдаём сообщение и выходим
                 ShowMessage("Такой записи нет!");
                 return;
                }
        }
    fseek( p , 120 , 1 );
    while(fread(&expo,sizeof(expo),1,p)!=0)   // Дописываем оставшееся, если есть
        fwrite(&expo,sizeof(expo),1,tmp);
    fcloseall();
    remove("book");
    rename("book.tmp","book");
    ShowMessage("Готово!");
    break;
 }

case 5:
 {
     FILE *p;
     FILE *tmp;
     p=fopen("book","rb");
     tmp=fopen("book.tmp","ab");
     char *current;
        switch (Form1->ComboBox1->ItemIndex)
        {
         case 0: {current = "Универсальная";
         break;}
         case 1: {current = "Специализированная";
         break;}
         case 2: {current = "Художественная";
         break;}
        }
     while(fread(&expo,sizeof(expo),1,p)!=0)
     {   // Читаем файл в структуру
        if (strcmp(expo.expotype,current) != 0 )
                {  // Переписываем только неподходящие строки
                 fwrite(&expo,sizeof(expo),1,tmp);
                }
     }

    fcloseall();
    remove("book");
    rename("book.tmp","book");
    ShowMessage("Готово!");
  break;
 }

case 6:
    {
     int RecNo = Form1->Edit6->Text.ToInt(); // Нужный номер записи
     FILE *p;
     FILE *tmp;
     p=fopen("book","rb");
     tmp=fopen("book.tmp","ab");
     for(int i = 1; i < RecNo; i++)
     {         // Переписываем записи до нужной в темп
      if (fread(&expo,sizeof(expo),1,p)!=0)
       {     // Если не достигли конца файла, просто переписываем то, что есть в исходном
       fwrite(&expo,sizeof(expo),1,tmp);
       }
      else
       {   // Если достигли - Выдаём сообщение и выходим
        ShowMessage("Такой записи нет!");
        return;
       }
    }
    fread(&expo,sizeof(expo),1,p);  // Читаем нужную запись в структуру
    strcpy(expo.begindate,Form1->DateTimePicker1->Date.DateString().c_str());
    strcpy(expo.enddate,Form1->DateTimePicker2->Date.DateString().c_str());
    fwrite(&expo,sizeof(expo),1,tmp); // Пишем с структуру с новой датой в файл

    while(fread(&expo,sizeof(expo),1,p)!=0)   // Дописываем оставшееся, если есть
        fwrite(&expo,sizeof(expo),1,tmp);

    fcloseall();
    remove("book");
    rename("book.tmp","book");
    ShowMessage("Готово!");
    Form1->GroupBox1->Visible=false;
     break;
    }

case 7:
  {
// ---------------------------------------------------------------
FILE *p;

 p=fopen("book","rb");
    int i,j;
    for (i=0; i<Form1->SG->ColCount; i++)
      for (j=0; j<Form1->SG->RowCount; j++)
        Form1->SG->Cells[i][j]="";

    Form1->SG->Cells[0][0]="Название";
    Form1->SG->Cells[1][0]="Место";
    Form1->SG->Cells[2][0]="Организатор";
    Form1->SG->Cells[3][0]="Тип выставки";
    Form1->SG->Cells[4][0]="Экспозиций";
    Form1->SG->Cells[5][0]="Цена";
    Form1->SG->Cells[6][0]="Дата начала";
    Form1->SG->Cells[7][0]="Дата окончания";
    Form1->SG->Visible=true;
    i=0;                      // добавить условия, чтобы выводились только подходящие

    while (fread(&expo,sizeof(expo),1,p)!=0)
      { if (strcmp(expo.expotype,Form1->ComboBox1->Items->Strings[Form1->ComboBox1->ItemIndex].c_str())==0 && strcmp(expo.expocount,Form1->Edit4->Text.c_str()) > 0 )
        {                     // TO BE CONTINUED FROM HERE
                i++;            // JUST A LITTLE BIT LEFT!!
                Form1->SG->Cells[0][i]=expo.exponame;
                Form1->SG->Cells[1][i]=expo.expoplace;
                Form1->SG->Cells[2][i]=expo.owner;
                Form1->SG->Cells[3][i]=expo.expotype;
                Form1->SG->Cells[4][i]=expo.expocount;
                Form1->SG->Cells[5][i]=expo.price;
                Form1->SG->Cells[6][i]=expo.begindate;
                Form1->SG->Cells[7][i]=expo.enddate;
                Form1->SG->RowCount=i+1;
          }
      }
    fclose(p);
    Form1->GroupBox1->Visible=false;
    break;
  }
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
       Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
    int pr;
    pr=MessageDlg("Подтвердите удаление файла",mtWarning,TMsgDlgButtons()<<mbYes<<mbNo,0);
    if (pr==mrYes)
      {
        remove("book");
        MessageDlg("Файл удален",mtWarning,TMsgDlgButtons()<<mbOK,0);
      }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::N6Click(TObject *Sender)
{



FILE *p;   // проверка существования файла
p=fopen("book","rb");
if (!p)
{
MessageDlg("Файл не существует",mtWarning,TMsgDlgButtons()<<mbOK,0);
fclose(p);
return;
}

//просмотр всех записей
    int i,j;
    for (i=0; i<Form1->SG->ColCount; i++)
      for (j=0; j<Form1->SG->RowCount; j++)
        Form1->SG->Cells[i][j]="";

    p=fopen("book","rb");
    i=0;
    Form1->SG->Cells[0][0]="Название";
    Form1->SG->Cells[1][0]="Место";
    Form1->SG->Cells[2][0]="Организатор";
    Form1->SG->Cells[3][0]="Тип выставки";
    Form1->SG->Cells[4][0]="Экспозиций";
    Form1->SG->Cells[5][0]="Цена";
    Form1->SG->Cells[6][0]="Дата начала";
    Form1->SG->Cells[7][0]="Дата окончания";
 Form1->SG->Visible=true;
    while (fread(&expo,sizeof(expo),1,p)!=0)
      {
        i++;
        Form1->SG->Cells[0][i]=expo.exponame;
        Form1->SG->Cells[1][i]=expo.expoplace;
        Form1->SG->Cells[2][i]=expo.owner;
        Form1->SG->Cells[3][i]=expo.expotype;
        Form1->SG->Cells[4][i]=expo.expocount;
        Form1->SG->Cells[5][i]=expo.price;
        Form1->SG->Cells[6][i]=expo.begindate;
        Form1->SG->Cells[7][i]=expo.enddate;
        Form1->SG->RowCount=i+1;
      }
    fclose(p);
}
      /*
1.	Название выставки
2.	Место проведения
3.	Сроки проведения
4.	Организатор
5.	Тип выставки: универсальная, специализированная, художественная
6.	Количество экспозиций
7.	Цена посещения
*/
//---------------------------------------------------------------------------


void __fastcall TForm1::N1Click(TObject *Sender)
{
    Form1->GroupBox1->Visible=false;
    Form1->SG->Visible=false;
    Form1->Edit6->Visible = false;
    Form1->Label2->Visible=false;

    Form1->Edit1->Enabled=true;
    Form1->Edit2->Enabled=true;
    Form1->Edit3->Enabled=true;
    Form1->Edit4->Enabled=true;
    Form1->Edit5->Enabled=true;
    Form1->ComboBox1->Enabled=true;
    Form1->DateTimePicker1->Enabled=true;
    Form1->DateTimePicker2->Enabled=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{   action = 3;         // Вставка по номеру записи

    Form1->Edit6->Visible = true;
    Form1->Label2->Visible=true;
    Form1->GroupBox1->Caption="Добавить запись в заданную позицию";
    Form1->GroupBox1->Visible=true;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::N12Click(TObject *Sender)
{
//копирование в резервный файл
    FILE *p1,*p2;
    p1=fopen("book","rb");
    p2=fopen("book.bak","wb");
    while(fread(&expo,sizeof(expo),1,p1)!=0)
      fwrite(&expo,sizeof(expo),1,p2);
    fcloseall();
    MessageDlg("Резервный файл создан",mtWarning,TMsgDlgButtons()<<mbOK,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N13Click(TObject *Sender)
{                // Восстановление из бэкапа файла
FILE *p1,*p2;
    p1=fopen("book","wb");
    p2=fopen("book.bak","rb");
    while(fread(&expo,sizeof(expo),1,p2)!=0)
      fwrite(&expo,sizeof(expo),1,p1);
    fcloseall();
    MessageDlg("Файл восстановлен",mtWarning,TMsgDlgButtons()<<mbOK,0);

}
//---------------------------------------------------------------------------


void __fastcall TForm1::N7Click(TObject *Sender)
{
        action = 4;

    Form1->Edit1->Enabled=false;
    Form1->Edit2->Enabled=false;
    Form1->Edit3->Enabled=false;
    Form1->Edit4->Enabled=false;
    Form1->Edit5->Enabled=false;
    Form1->ComboBox1->Enabled=false;
    Form1->DateTimePicker1->Enabled=false;
    Form1->DateTimePicker2->Enabled=false;

    Form1->Edit6->Visible = true;
    Form1->Label2->Visible=true;
    Form1->GroupBox1->Caption="Введите номер записи для удаления";
    Form1->GroupBox1->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
        action = 5;
    Form1->Edit1->Enabled=false;
    Form1->Edit2->Enabled=false;
    Form1->Edit3->Enabled=false;
    Form1->Edit4->Enabled=false;
    Form1->Edit5->Enabled=false;
    Form1->DateTimePicker1->Enabled=false;
    Form1->DateTimePicker2->Enabled=false;

    Form1->GroupBox1->Caption="Выберите тип выставки для удаления";
    Form1->GroupBox1->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{     action = 6;
    Form1->Edit1->Enabled=false;
    Form1->Edit2->Enabled=false;
    Form1->Edit3->Enabled=false;
    Form1->Edit4->Enabled=false;
    Form1->Edit5->Enabled=false;
    Form1->ComboBox1->Enabled=false;
    Form1->Label2->Visible=true;
    Form1->Edit6->Visible=true;

   Form1->GroupBox1->Caption="Введите номер записи и новые даты проведения выставки";
   Form1->GroupBox1->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
        action = 7;
    Form1->Edit1->Enabled=false;
    Form1->Edit2->Enabled=false;
    Form1->Edit3->Enabled=false;
    Form1->Edit5->Enabled=false;
    Form1->DateTimePicker1->Enabled=false;
    Form1->DateTimePicker2->Enabled=false;

  Form1->GroupBox1->Caption="Выберите тип и минимальное количество экспозиций";
  Form1->GroupBox1->Visible=true;
}
//---------------------------------------------------------------------------


