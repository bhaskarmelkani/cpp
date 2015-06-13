#include<dos.h>
#include<process.h>
#include<string.h>   // for various functions of strings like gets or puts
#include<fstream.h>   // for files
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
void starting();
void typing();
void openfile(char *);
void newfile(char *);
void print(char i[],int x,int y);

char ch ;
char s[20];
char xs[20];
char ys[20];

void main()
{
    clrscr();
    textmode(BW40);
    print(" MY NOTEPAD ",3,14);
    print(" Presented",6,14);
    print(" By ",7,17);
    print(" Zahid Ashfaq",8,13);


      textmode(BW80);

starting();


  typing();
   getch();
   }



 void starting()
 {   textcolor(1);
     textbackground(WHITE);


    clrscr();
    for(int i=0 ;i<45;i++)
    {if(i==0||i==44)
       cout<<"||";
       else if(i==4)
       cout<<" ctrl+O(Open file)";
       else if(i==24)
       cout<<" ctrl+n(New file)";
       else
       cout<<"=";}
        gotoxy(80,24);  cout<<endl;
     for( i=0 ;i<37;i++)
    {if(i==0||i==47)
       cout<<"||";
       else if(i==4)
       cout<<" ctrl+s(save file)";
       else if(i==16)
       cout<<" ctrl+k(Help)";
       else if(i==26)
       cout<<"ctrl+q(Quit)";
       else
       cout<<"=";}
}


void typing()
{  int i=0;
    char *p=new char[2000];
 step1 :  int row=2 ,col=1;
 while(ch!=19)
{
gotoxy(col,row);

  step2:  if(col==79)
     {col=1;row++;}
    else if (row==24)
      goto step1;
    int a;
    ch=getch();
    if(ch == 0)
    ch = getch();

      a=ch;  // To convert character to its ascii code

      switch(a)
{
case 13 : row=row++;col=1;      // case for press enter for next line
        gotoxy(col,row);
        ch='\n';
        break;

case 8 :
          if(col==1)           // case for backspace
         {row--;col=78;}
       else
        {col--;
        cout<<"  ";
         i--;
        }
        continue;

case 9 :    col=col+8;           // case for tab function
         if(col>79)
        {row++;col=col-79;
        }
         continue;

case 72 : row--;              //upper arrow key
       continue;

case 77 : col++; continue;     //right arrow key

case 75 : col--; continue;    //left arrow key

case 80 :                     //down arrow key
       row++;
       continue;

case 14 :   clrscr();       //to creat new file ctrl+n
        cout<<"Enter File`s Path ";
        gets(s);
        newfile(s);
        starting();
        break;

case 15 :     clrscr();   //to open existing file  ctrl+o
          cout<<"Enter file`s path to be open :" ;
          gets(xs);
          starting();
          openfile(xs);
          continue;




case 11 :     clrscr();
          gotoxy(20,3);
          cout<<"~`~`~`~`~  HELP PORTION  ~`~`~`~`~";
          gotoxy(20,4);
          cout<<"Following Are the Keys Used in My-Note PAD : ";
         int za=10;
          for(int i=0;i<46 ;i++ )
          {
           gotoxy(za,5);
        cout<<"=";za++;}
         za=6;
           for(i=0;i<15;i++)
           {gotoxy(10,za);
         cout<<"|"<<endl;

         za++;}
             za=10;
           for( i=0;i<46 ;i++ )
          {
           gotoxy(za,21);
        cout<<"=";
        za++;}
         za=6;
          for(i=0;i<15;i++)
           {gotoxy(56,za);
         cout<<"|"<<endl;

         za++;}

         gotoxy(13,6);
         cout<<" 1-To Open File Press  ( ctrl + o ) ";
         gotoxy(13,8);
         cout<<" 2-To create New File Press(ctrl+n) " ;
         gotoxy(13,10);
         cout<<" 3-MOve Arrow keys (up,down,right,left)" ;
         gotoxy(13,12);
         cout<<" 4-Back Space ";
         gotoxy(13,14);
         cout<<" 5-Save File(ctrl+s)";
         gotoxy(13,16);
         cout<<" 6-Enter For new line ";
         gotoxy(13,18);
         cout<<" 7-Enter ctrl+q(Quit)";

         gotoxy(13,20);
         cout<<"Press any key to Go back " ;

          getch();
          clrscr();
         starting();

         continue;


case 17 :  clrscr();
       gotoxy(24,6);
       cout<<"Thank You For using PIcs-soft Word ";
       cout<<endl;
       gotoxy(24,8);
       cout<<"Have A NIce Time ";
       getch();
       exit(0);






  }

    cout<<ch;
      p[i]=ch;
       col++; i++;

     p[i]='\0';
       }
       clrscr();
       cout<<"enter path where you want to save the file ";
       gets(ys);  int j=0;
       ofstream f1(ys,ios::out);
            while(p[j]!='\0')
       {f1.write((char*)&p[j],sizeof(p[j]));
        j++;}
       f1.close();
      delete [] p;
     exit(0);



}


void newfile(char *s)
{
   ofstream file(s,ios::out);
   file.close();
}

void openfile(char *xs)
{ char ch;  int col=3,row=2;
gotoxy(col,row);
  ifstream file(xs,ios::in);
  while( file.read((char*)&ch,sizeof(ch)))
                    cout<<ch;

           file.close();
}


void print(char i[],int x,int y)
    {
    char far* ptr=(char far*) 0xB8000000+(160*x)+(2*y) ;
    for(int a=0; i[a]!='\0'; a++)
        {
        *ptr=i[a];
        *(ptr+1)=16;
        ptr=ptr+2;
        delay(250);
        }
    ptr=ptr+2;
    }





