#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "espacelivre.h"
#include "espaceetudient.h"
#include "utileglobal.h"
#include "espaceEmprinte.h"

coordonner tab= {1,4};

void incrnmbredelivreutil(char *titre)
{



  int nmb;


    livre lv;
    FILE *file,*tem;
    clrscr();

    file=fopen("livre.txt","r");
    tem=fopen("f.txt","a");
    {
        if(file==NULL || tem==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }


        while(!feof(file))
        {
             fscanf(file,lirliv,lv.titre,lv.genre,lv.autheur,&lv.nmbCopi,&lv.nmbCopiUtil);


           if(!strcmp(titre,lv.titre))
            {

              lv.nmbCopiUtil++;
            }


             fprintf(tem,ecrliv,lv.titre,lv.genre,lv.autheur,lv.nmbCopi,lv.nmbCopiUtil);

        }


        fclose(file);
        fclose(tem);
    }
    remove("livre.txt");
    rename("f.txt","livre.txt");
     gotoxy(1,1);textcolor(BLUE);cprintf("click pour retourner ");
    getch();
    clrscr();
    return;

}

void etudientemprint0(char id[])
{

  int i=0;


    etudient et;
    FILE *file,*tem;
    clrscr();



    file=fopen("etudient.txt","r");
    tem=fopen("f.txt","a");
    {
        if(file==NULL || tem==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }


        while(!feof(file))
        {
             fscanf(file,liretudient,et.nom,et.prenom,et.codeapogee,et.email,et.modpas,&et.emprint);


           if(!strcmp(id,et.codeapogee)) {i=1;
           clrscr();
          et.emprint=0;

        }


            fprintf(tem,ecretudient,et.nom,et.prenom,et.codeapogee,et.email,et.modpas,et.emprint);

        }


        fclose(file);
        fclose(tem);
    }
    remove("etudient.txt");
    rename("f.txt","etudient.txt");


     gotoxy(1,1);textcolor(BLUE);cprintf("click pour retourner");
    getch();
    clrscr();
    return;

}
void emprinter(void)
 {
     int nmbday,i=0;
   char titre[60],id[10],cod[10],date[9],dateretour[9];
   FILE *file,*temp,*f;
  gotoxy(40,13);printf("entrer le cod apg de l'etudient : ");
   fflush(stdin);
   gotoxy(74,13); scanf("%[^\n]",cod);
   file=fopen("demonde.txt","r");
   temp=fopen("temp.txt","a");
   f=fopen("emprinter.txt","a");
   {
       if(file==NULL)
       {
           printf("probleme d'overture de fichier");
           return;
       }
       while(!feof(file))
       {
           fscanf(file,"%[^,,],,%[^,,],,%[^\n]\n",titre,id,date);
             if(!strcmp(id,cod))
             {   clrscr();textcolor(GREEN);
                 gotoxy(43,13);cprintf("l'etudient a demonder le livre %s ",titre);
                 gotoxy(43,14);printf("entrer le nombre de joure : ");
                 gotoxy(72,14);scanf("%d",&nmbday);
                     dateretoure(dateretour,nmbday);
                      fprintf(f,"%[^,,],,%[^,,],,%[^\n]\n",titre,id,dateretour);
                      i=1;
                 continue;
             }


           fprintf(temp,"%[^,,],,%[^,,],,%[^\n]\n",titre,id,date);
       }
      if(i==0)
      {  textcolor(RED);
      clrscr();
           gotoxy(43,14);cprintf("pas de demonde de livre avec cet id : ");
      }
       fclose(file);
       fclose(temp);
       fclose(f);
   }
   remove("demonde.txt");
   rename("temp.txt","demonde.txt");

}


void returner(void)
 {
     int i=0;
   char titre[60],id[10],cod[10],date[9],dateretour[9];
   etudient et;
   FILE *file,*temp,*f,*etu;
  gotoxy(43,13);printf("entrer le cod apg de l'etudient : ");
   fflush(stdin);
   gotoxy(79,13); scanf("%[^\n]",cod);
   file=fopen("emprinter.txt","r");
   temp=fopen("temp.txt","a");

       if(file==NULL)
       {
           printf("probleme d'overture de fichier");
           return;
       }
       while(!feof(file))
       {
           fscanf(file,"%[^,,],,%[^,,],,%[^\n]\n",titre,id,date);
             if(!strcmp(id,cod))
             {   clrscr();textcolor(GREEN);
                 gotoxy(43,13);cprintf("les info :titre: %s  id etudient: %s   date de retour : %s  ",titre,id,date);
                    //
                incrnmbredelivreutil(titre);
                etudientemprint0(id);

                      //
                      i=1;
                 continue;
             }


           fprintf(temp,"%s,,%s,,%s\n",titre,id,date);
       }
      if(i==0)
      {  textcolor(RED);
      clrscr();
           gotoxy(43,14);cprintf("l'etudient nas aucun livre : ");
      }
       fclose(file);
       fclose(temp);


   remove("emprinter.txt");
   rename("temp.txt","emprinter.txt");

 }


void listertableau(char *titre,char *id,char *date)
{
    textcolor(3);


    if(tab.y==4)
    {
        gotoxy(tab.x,tab.y);
        cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");//29 55 77 88 98
    }
    else
    {
        gotoxy(tab.x,tab.y);
        cprintf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
    }
    (tab.y)++;
    gotoxy(tab.x,tab.y);
        cprintf("³                         ³                         ³                     ³");
    (tab.y)++;
    gotoxy(tab.x,tab.y);
    cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");



    gotoxy(tab.x+1,tab.y-1);
    printf("%s",titre);
    gotoxy(tab.x+30,tab.y-1);
    printf("%s",id);
    gotoxy(tab.x+56,tab.y-1);
    printf("%s",date);


}

void listerdemonds(void)
{
    char titre[60],id[10],date[12];

    FILE *file;
    file=fopen("demonde.txt","r");
    {
        if(file==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }
        gotoxy(32,6);
        textcolor(9);
        cprintf("la liste des livre est ");
        {
            textcolor(GREEN);
            gotoxy(10,3);
            cprintf("TITRE");
            gotoxy(37,3);
            cprintf("id");
            gotoxy(63,3);
            cprintf("date domande");

        }
        gotoxy(tab.x,tab.y);
        while(!feof(file))
        {
            fscanf(file,"%[^,,],,%[^,,],,%[^\n]\n",titre,id,date);

            listertableau(titre,id,date);
        }
        fclose(file);
    }
      gotoxy(1,1);textcolor(BLUE);cprintf("click pour retourner aespace livre");
    getch();
    clrscr();
     tab.x=1;
    tab.y=4;
    return;
}
void listerEmprinter(void)
{
    char titre[60],id[10],date[12];

    FILE *file;
    file=fopen("emprinter.txt","r");
    {
        if(file==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }
        gotoxy(32,6);
        textcolor(9);
        cprintf("la liste des livre est ");
        {
            textcolor(GREEN);
            gotoxy(10,3);
            cprintf("TITRE");
            gotoxy(37,3);
            cprintf("id");
            gotoxy(63,3);
            cprintf("date de retour");

        }
        gotoxy(tab.x,tab.y);
        while(!feof(file))
        {
            fscanf(file,"%[^,,],,%[^,,],,%[^\n]\n",titre,id,date);

            listertableau(titre,id,date);
        }
        fclose(file);
    }
      gotoxy(1,1);textcolor(BLUE);cprintf("click pour retourner aespace livre");
    getch();
    clrscr();
     tab.x=1;
    tab.y=4;
    return;
}

void suprimerdelalistedemonde(void)
{    char titre[60],cod[10],date[12];
     char id[9];
     int i=0;
      FILE *file,*temp;
   gotoxy(40,12); printf("entrer id de l'etudient : ");
   gotoxy(66,12); scanf("%[^\n]",id);

    file=fopen("demonde.txt","r");
    temp=fopen("temp.txt","a");
    {
        if(file==NULL || temp==NULL)
        {
            printf("erreur doverture");
            return;
        }
        while(!feof(file))
        {
            fscanf(file,"%[^,,],,%[^,,],,%[^\n]\n",titre,cod,date);
            if(!strcmp(cod,id))
            {  i=1;
                etudientemprint0(id);
                continue;
            }
             fprintf(temp,"%s,,%s,,%s\n",titre,cod,date);
        }

    if(i==0)
    { clrscr();
    gotoxy(46,12);
    textcolor(RED);
        cprintf("id nexiste pas");
    }
    if(i==1)
    { clrscr();
    gotoxy(46,12);
    textcolor(GREEN);
        cprintf("l'etudient est suprimer de la liste de demande");
    }

        fclose(file);
        fclose(temp);
    }
    remove("demonde.txt");
    rename("temp.txt","demonde.txt");
}

char *champeEmprint[]= {"emprinter un livre a un etudient","lister les demonde","lister EMprinter","suprimer un etudient de la liste de demonde","retour au menu admin","exit"};

void passagverEmprinte(void)
{   int i;
   clrscr();
   do{ gotoxy(40,5);textcolor(GREEN);cprintf("ESPACE ETUDIENT");
    i=updownmenu(1,champeEmprint,6);
    switch(i)
    {
        case 1 : emprinter();break;
        case 2 : listerdemonds();break;
        case 3 : listerEmprinter();break;
        case 4 : suprimerdelalistedemonde();break;
        case 5 : return; break;
        case 6 : exit(1);break;
    }

 }while(1);
}
