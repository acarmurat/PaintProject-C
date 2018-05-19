#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <winbgim.h>


int clr;
void renk(int,int);
void renkKutucuklari();
int secim(int,int);
void siyah();
int silgi();
int firca();
int cizgi();
int dik();
void butonlar();
int cember();
int ucgen();
int kaydet();
int temizle();
int Dos_ac();


int main()
{
initwindow(1750,1750);
butonlar();
renkKutucuklari();

setlinestyle(3,28,3);
clr = 11;
setcolor(clr);
int sec;
sec = temizle();
while(1)
{
 switch(sec){
  case 1: sec =silgi(); break;
  case 2: sec = firca();  break;
  case 3: sec =cember(); setlinestyle(3, 28, 3); break;
  case 4: sec=dik();break;
  case 5: sec=ucgen(); break;
  case 6: sec= cizgi();break;
  case 7: sec =temizle();break;
  case 8: sec= kaydet();break;
  case 9: sec= Dos_ac();break;
  default: break;
  }
}
    getch();
    closegraph();
    return 0;
}

void renk(int x,int y){
  int a=91;
    int i;
    for(clr=0;clr<=15;clr++)
    {
         if(x<a+45&&x>a)
       {
           setcolor(clr);
           break;
       }
        a+=45;
    }
}
void renkKutucuklari(){

int x=90,i;

    for(i=0;i<=15;i++)
    {
    setfillstyle(1,i);
    fillellipse(x+23,15,13,13);
    setcolor(i);
    circle(x+23,15,13);
    rectangle(x,0,x+45,30);
    x+=45;
    }
}
int secim(int x , int y){

    if(y<60)
    {
        printf("y<60  silgi\n");
            return 1;
    }
    else if(y>=60 && y<140 )
    {
        printf("y>=60 && y<140 kalem\n");
        return 2;
    }
    else if(y>140 && y<220)
    {
        printf("y>140 && y<220 cember\n");
        return 3;
    }
    else if(y>=220 && y<300 )
    {
        printf(" y>=220 && y?00 dikdortgen\n");
        return 4;
    }
    else if(y>=300&&y<380)
    {
        printf(" y>=300&&y<380 ucgen\n");
        return 5;
    }
     else if(y>=380&&y<450)
    {
        printf("y>=380&&y<450 cizgi\n");
        return 6;
    }
    else if(y>=450 && y<530)
    {
        return 7;
    }
    else if(y>=530 && y<640)
    {
        return 8;
    }
    else if(y>=640&&y<700)
    {
        return 9;
    }
}
void siyah(){
         int ust[]={813,30,813,0,1365,0,1365,30,813,30};
        setfillstyle(1,0);
        fillpoly(5,ust);
}
int silgi(){
    setcolor(15);
    siyah();
    outtextxy(850,10,"silgi");
    int quit=0;
    int x,y;
    setcolor(15);
    while(1)
    {
        setcolor(15);
        while(quit==0)
        {
            delay(2);
            if(ismouseclick(WM_LBUTTONDOWN))
            {   x = mousex();
                y = mousey();
                if(x<90)
                {
                    printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }

                printf("x:%d \n", x);
                printf("y:%d \n", y);
                quit=1;
            }
        }
        quit =0;
        if(x>98&&y>39)
        {
            if(ismouseclick(WM_RBUTTONDOWN))
            {
                clearmouseclick(WM_RBUTTONDOWN);
                clearmouseclick(WM_LBUTTONDOWN);
                return silgi();
            }
                //setcolor(WHITE);
                setfillstyle(1,15);
                fillellipse(x,y,9,9);

                circle(x,y,10);
        }
    }
 }
int firca(){
    setcolor(clr);
    siyah();
    outtextxy(850,10,"Firca");
    int quit=0;
    int x,y;

    int sayac=1;
    while(1)
    {
        while(quit==0)
        {
            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                x = mousex();
                y = mousey();
                if(sayac==1){moveto(x,y);}

                printf("x:%d \n", x);
                printf("y:%d \n", y);
                quit=1;
                if(x<90)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
                else if(y<30)
                {
                    printf("renk seciliyor");
                     clearmouseclick(WM_LBUTTONDOWN);
                     renk(x,y);
                     return firca();
                }
            }
        }
        quit =0;
  if(x>99&&y>39){
            if(ismouseclick(WM_RBUTTONDOWN))
            {
                clearmouseclick(WM_RBUTTONDOWN);
                clearmouseclick(WM_LBUTTONDOWN);
                return firca();
            }
    lineto(x,y);
    sayac++;
        }
    }
}
int cizgi(){
    setcolor(clr);
    siyah();
    outtextxy(850,10,"cizgi");
    int quit=0;
    int x,y;
    int x2,y2;
    printf("cizgi");
    while(1)
    {
        while(quit==0)
        {
            delay(25);

            if(ismouseclick(WM_LBUTTONDOWN))
            {
                x = mousex();
                y = mousey();
                printf("x:%d \n", x);
                printf("y:%d \n", y);
                quit=1;
                if(x<90)
                {
                   printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
                else if( y<30)
                {
                    printf("renk seciliyor");
                     clearmouseclick(WM_LBUTTONDOWN);
                     renk(x,y);
                     return cizgi();
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }

        quit =0;
        while(quit==0)
        {int sec;
            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                x2 = mousex();
                y2 = mousey();int sec;

                 printf("x2:%d \n", x2);
                printf("y2:%d \n", y2);
                quit=1;

                if(x2<90 )
                {
                    printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
                 else if( y2<30)
                {
                    printf("renk seciliyor");
                     clearmouseclick(WM_LBUTTONDOWN);
                     renk(x2,y2);
                     return cizgi();
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        quit=0;
        line(x,y,x2,y2);
    }
}
int dik(){
    setcolor(clr);
    siyah();
    outtextxy(850,10,"dikdortgen");
    int quit=0;
    int x,y;
    int x2,y2;
    while(1)
    {
        while(quit==0)
        {
            delay(25);

            if(ismouseclick(WM_LBUTTONDOWN))
            {

                x = mousex();
                y = mousey();
                if(x<90)
                {
                    printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
                    else if( y<30)
                {
                    printf("renk seciliyor");
                     clearmouseclick(WM_LBUTTONDOWN);
                     renk(x,y);
                     return dik();

                }
                printf("x:%d \n", x);
                printf("y:%d \n", y);
                quit=1;
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }
        quit =0;
        while(quit==0)
        {
            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {

                x2 = mousex();
                y2 = mousey();
                if(x2<90)
                {
                    printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
                else if(y2<30)
                {
                    printf("renk seciliiyor");
                    renk(x2,y2);
                    return dik();
                }
                printf("x2:%d \n", x2);
                printf("y2:%d \n", y2);
                quit=1;
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }
        quit=0;
        rectangle(x,y,x2,y2);
    }
}
void butonlar(){
    setcolor(15);
     line(90,30,1300,30);/// üstteki yatay çizgi
    line(90,0,90,1000);/// soldaki dikey cizgi
    setcolor(3);/// silginin rengi
    bar3d(20,35,40,20,25,1);/// 3 boyutlu silgi  int left, int top, int right, int bottom, int depth, int topflag
    outtextxy(15,40,"Silgi");
    setcolor(15);
    line(0,60,90,60);/// silginin altyndaki çizgi
    setcolor(12);
    rectangle(40,65,50,100);/// kalemin dikdörtgen  yeri int left, int top, int right, int bottom
    setcolor(15);
    line(40,100,45,120);/// kalemin uçlary
    line(50,100,45,120);///...
    setcolor(12);
    outtextxy(23,125,"Kalem");
    setcolor(15);
    line(0,140,90,140);/// kalemin altyndaki çizgi
    setcolor(BLUE);
    circle(45,170,20);/// çember
    outtextxy(20,200,"Cember");
    setcolor(WHITE);///cemberin altindaki cizginin rengi
    line(0,220,90,220);///cemberin altindaki cizgi
    setcolor(YELLOW);
    rectangle(15,235,75,275);/// dikdörtgen
    outtextxy(-3,285,"Dikdortgen");
   setcolor(WHITE);
    line(0,300,90,300);/// dikdörtgenin altindaki cizgi
    setcolor(10);/// ucgenin rengi
    /** ucgenin cizgileri*/
    line(45,310,80,360);
    line(45,310,10,360);
    line(10,360,80,360);
    /********/
    outtextxy(23,363,"Ucgen");
    setcolor(WHITE);
    line(0,380,90,380); /// ucgenin altyndaki cizgi
    setcolor(LIGHTRED);/// Egik CYZGYNYN RENGY
    line(30,390,70,430);/// Egik  cizgi
    outtextxy(25,435,"Cizgi");
   setcolor(WHITE);
    line(0,450,90,450);///Egik cizginin altindaki cizgi
    /** geri al butonu*/
     setcolor(LIGHTGRAY);
    line(35,500,45,520);/// ok üst
    line(25,530,45,520);/// ok alt
    arc(45,490,-30,270,30);///YAY (x,y,baslangyc acysy,bitis acysy,yarycap)
    outtextxy(15,540,"Temizle");
    /**********/
      setcolor(WHITE);
    line(0,560,90,560);///temizlenin  altindaki cizgi
    line(45,570,45,610);
    line(35,600,45,610);
    line(55,600,45,610);
    line(25,610,65,610);
    outtextxy(20,620,"Kaydet");
    line(0,640,90,640);/// kaydetin altındaki cizgi
    rectangle(30,645,60,680);
    line(35,655,55,655);
    line(35,665,55,665);
    line(35,675,55,675);
    outtextxy(10,670,"dosya ac");
    line(0,690,90,690);
    setcolor(clr);
}
int cember(){

setlinestyle(3, 28, 2);
    setcolor(clr);
    siyah();
    outtextxy(850,10,"cember");
    int quit=0;
    int x,y;
    int x2,y2;
    printf("cember");
    while(1)
    {
        while(quit==0)
        {
            delay(25);


            if(ismouseclick(WM_LBUTTONDOWN))
            {

                x = mousex();
                y = mousey();
                printf("x:%d \n", x);
                printf("y:%d \n", y);
                quit=1;
                if(x<90)
                {
                   printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
                else if( y<30)
                {
                    printf("renk seciliyor");
                     clearmouseclick(WM_LBUTTONDOWN);
                     renk(x,y);
                     return cember();
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        quit =0;
        while(quit==0)
        {

            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {

                x2 = mousex();
                y2 = mousey();
                int sec;

                 printf("x2:%d \n", x2);
                printf("y2:%d \n", y2);
                quit=1;

                if(x2<90 )
                {
                    printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
                 else if( y2<50)
                {
                    printf("renk seciliyor");
                     clearmouseclick(WM_LBUTTONDOWN);
                     renk(x2,y2);
                     return cember();
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        quit=0;
        circle((int)(x+x2)/2,(int)(y+y2)/2,sqrt((pow(x2-x,2)+pow(y2-y,2)))/2);

        int sol[]={0,768,0,0,90,0,90,768,0,768};
        setfillstyle(1,0);
        fillpoly(5,sol);
        int ust[]={90,30,90,0,1365,0,1365,30,90,30};
        setfillstyle(1,0);
        fillpoly(5,ust);
        renkKutucuklari();
        butonlar();
        outtextxy(850,10,"cember");
    }
renkKutucuklari();
}
int ucgen(){
   setcolor(clr);
   siyah();
   outtextxy(850,10,"ucgen");
    int quit=0;
    int x,y,x2,y2,x3,y3;

    while(1)
    {
        while(quit==0)
        {
            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                x = mousex();
                y = mousey();
                if(x<90)
                {
                    printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
                    else if( y<30)
                {
                    printf("renk seciliyor");
                    clearmouseclick(WM_LBUTTONDOWN);
                    renk(x,y);
                    return ucgen();
                }
                printf("x:%d \n", x);
                printf("y:%d \n", y);
                quit=1;
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }
        quit =0;
        while(quit==0)
        {
            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {   x2 = mousex();
                y2 = mousey();
                if(x2<90)
                {
                    printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x2,y2);
                }
                else if( y2<30)
                {
                    printf("renk seciliyor");
                    clearmouseclick(WM_LBUTTONDOWN);
                     renk(x2,y2);
                     return ucgen();
                }
                printf("x2:%d \n", x2);
                printf("y2:%d \n", y2);
                quit=1;
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }
        quit=0;
            while(quit==0)
        {
            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {   x3 = mousex();
                y3 = mousey();
                if(x3<90)
                {
                    printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x3,y3);
                }
                   else if( y3<30)
                {
                    printf("renk seciliyor");
                    clearmouseclick(WM_LBUTTONDOWN);
                     renk(x3,y3);
                     return ucgen();
                }
                printf("x3:%d \n", x3);
                printf("y3:%d \n", y3);
                quit=1;
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }
        quit=0;

        line(x,y,x2,y2);
        line(x2,y2,x3,y3);
        line(x3,y3,x,y);
    }
}
int kaydet(){
    int quit=0;
siyah();
outtextxy(850,10,"Kayit basladi");
delay(200);
siyah();
FILE*dosya=fopen("C:\\Users\\User\\Desktop\\uzanti.txt","w+");
 int x,y;
 for(x=0;x<1366;x++)
 {
     for(y=0;y<800;y++)
     {
         switch(getpixel(x,y)){
         case 0: fputc('0',dosya);break;
          case 1: fputc('1',dosya);break;
           case 2: fputc('2',dosya);break;
            case 3: fputc('3',dosya);break;
             case 4: fputc('4',dosya);break;
              case 5: fputc('5',dosya);break;
               case 6: fputc('6',dosya);break;
                case 7: fputc('7',dosya);break;
                 case 8: fputc('8',dosya);break;
                  case 9: fputc('9',dosya);break;
                   case 10: fputc('A',dosya);break;
                    case 11: fputc('B',dosya);break;
                     case 12: fputc('C',dosya);break;
                      case 13: fputc('D',dosya);break;
                       case 14: fputc('E',dosya);break;
                        default: fputc('F',dosya);break;}


     }
 }
 fclose(dosya);


siyah();
 outtextxy(850,10,"kaydetti");
    while(1)
    {
        while(quit==0)
        {
            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                x = mousex();
                y = mousey();
                quit=1;
                if(x<90)
                {
                   printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);//tyklady?yn tu?u unutturuyor bu fonksiyonda...
        }
        quit =0;
    }
}
int temizle(){
siyah();
outtextxy(850,10,"temizlendi");
    int quit=0;
    int x,y;
    delay(25);
    setbkcolor(15);
    setcolor(15);
    int dort[] = {90,1000,90,30,1382,30,1382,768,90,1000};
setfillstyle(1,15);
fillpoly(5,dort);/// beyaz alan
setbkcolor(0);
    while(quit==0)
        {
            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                x = mousex();
                y = mousey();
                printf("x:%d \n", x);
                printf("y:%d \n", y);
                quit=1;
                if(x<90)
                {
                   printf("temizleden cykty butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
                quit=0;
            }
        }
}
int Dos_ac(){
  siyah();
int quit=0;
    FILE*dosya=fopen("C:\\Users\\User\\Desktop\\uzanti.txt","r");
 int x,y;
 outtextxy(850,10,"dosya acilma basladi");
 for(x=0;x<1366;x++)
 {
     for(y=0;y<800;y++)
     {
         switch(fgetc(dosya)){
         case '0': putpixel(x,y,0);break;
          case '1': putpixel(x,y,1);break;
           case '2': putpixel(x,y,2);break;
            case '3': putpixel(x,y,3);break;
             case '4': putpixel(x,y,4);break;
              case '5': putpixel(x,y,5);break;
               case '6': putpixel(x,y,6);break;
                case '7': putpixel(x,y,7);break;
                 case '8': putpixel(x,y,8);break;
                  case '9': putpixel(x,y,9);break;
                   case 'A': putpixel(x,y,10);break;
                    case 'B': putpixel(x,y,11);break;
                     case 'C': putpixel(x,y,12);break;
                      case 'D': putpixel(x,y,13);break;
                       case 'E': putpixel(x,y,14);break;
                        default: putpixel(x,y,15);break;}
     }
 }
 fclose(dosya);
 siyah();
outtextxy(850,10,"dosya acildi");
    while(1)
    {
        while(quit==0)
        {
            delay(25);
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                x = mousex();
                y = mousey();
                printf("x:%d \n", x);
                printf("y:%d \n", y);
                quit=1;
                if(x<90)
                {
                    printf("butona basildi");
                    clearmouseclick(WM_LBUTTONDOWN);
                    return secim(x,y);
                }
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        quit =0;
    }
}
