#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "utileglobal.h"
#include "utileglobal.h"


void menu(int ch,char **champ,int nmbchamp)
{
    int i=0;

   // clrscr();

    while(i<nmbchamp)
    {
        gotoxy(xyglobale.x,xyglobale.y);
        (xyglobale.y)++;
        if(ch == i+1)
        {
            textbackground(3);

            cprintf("%s",champ[i]);
            textbackground(0);
        }
        else
        {

            printf("%s",champ[i]);
        }
        i++;
    }
    xyglobale.x=36;
    xyglobale.y=12;
}


int updownmenu(int y,char **tab,int nmb)
{
    char ch;
   // clrscr();
    menu(1,tab,nmb);
    while(1)
    {
        ch=getch();
        if(ch==13) break;
        switch(ch)
        {
        case 72:
            if(y!=1)
            {
                (y)--;
                menu(y,tab,nmb);
            }
            break;
        case 80:
            if(y!=nmb)
            {
                (y)++;
                menu(y,tab,nmb);
            }
            break;
        default :
            break;
        }
    }
    clrscr();
   return y;

}


void dat(char* date)
{
    time_t temp=time(NULL);
   struct tm *cur_time=localtime(&temp);//localtime(&temp);

   sprintf(date,"%02d/%02d/%d",cur_time->tm_mday,cur_time->tm_mon+1,cur_time->tm_year+1900);
}
void dateretoure(char* date,int i)
{
     time_t temp=time(NULL);
   struct tm *cur_time=localtime(&temp);
      cur_time->tm_mon=cur_time->tm_mon+1;
      cur_time->tm_year=cur_time->tm_year+1900;


   if(cur_time->tm_mday+i>31)
   {
        cur_time->tm_mday=cur_time->tm_mday+i-31;
         cur_time->tm_mon++;
         if(cur_time->tm_mon>12)
         {
             cur_time->tm_mon=cur_time->tm_mon-12;
         }

   }

  sprintf(date,"%02d/%02d/%d",cur_time->tm_mday,cur_time->tm_mon+1,cur_time->tm_year+1900);
}
