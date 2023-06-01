#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "espacelivre.h"
#include "espaceetudient.h"
#include "utileglobal.h"
#include "etudient.h"



void etudientmenu(char cod[])
{
    char *champ[]= {"chercher un livre","lister les livre","emprinter un livre ","livre emprinter","exit"};
    int i;
    clrscr();
do{

gotoxy(40,5);textcolor(GREEN);cprintf("ETUDIENT MENU");
i=updownmenu(1,champ,5);
switch(i){
 case 1 :   chercherlivre();break;
 case 2 :   listerlivre();break;
 case 3 : emprinterlivre(cod);break;
 case 4 : livremprinter(cod);break;
 case 5 : return ;

}
}while(1);
}


void verificationComptetudient(void)
{   FILE *P;
    etudient et;
    char  cod[10],modpass[10];

   gotoxy(40,12); printf("entrere votre num apogg : ");
   gotoxy(40,13); printf("entrer votre mod passe : ");
   fflush(stdin);
     gotoxy(65,12);scanf("%[^\n]",cod);
     fflush(stdin);
  gotoxy(64,13);scanf("%[^\n]",modpass);
    P= fopen("etudient.txt","r");
    {
        if(P==NULL)
        {    clrscr();
            textcolor(RED);
            gotoxy(45,13);
            cprintf("errure fichier");
            getch();
            return ;
        }

        while(feof(P))
        {
            fscanf(P,liretudient,et.nom,et.prenom,et.codeapogee,et.email,et.modpas,&et.emprint);
            if(et.codeapogee==cod)
            {
                if(et.modpas!=modpass)
                {
                     gotoxy(64,14);textcolor(RED);
                     printf("le mot de passe incorect");
                     getchar();
                     gotoxy(64,14);clreol();


                }
            }
        }
        if(feof(P))
        {   gotoxy(40,14);
            textcolor(RED);
            printf("le code que vous avez entrer n'exist pas :");
            return  ;
        }
        fclose(P);
    }


 etudientmenu(cod);
}


void emprinterlivre(char *cod)
{  int j=0,i;//verifie ci le  livre existe
char q[4];//oui non
char date[9];
    FILE *f,*fliv,*tem;
    livre lv;
    char titre[60];
///////////
    etudient et;
    FILE *file1;
    clrscr();

    file1=fopen("etudient.txt","r");
    {
        if(file1==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }


        while(!feof(file1))
        {
            fscanf(file1,liretudient,et.nom,et.prenom,et.codeapogee,et.email,et.modpas,&et.emprint);


           if(!strcmp(cod,et.codeapogee))
            {
              i=et.emprint;
            }
        }
        fclose(file1);
       if(i==1)
        {     clrscr();
            textcolor(RED);
            gotoxy(29,11);
            cprintf("tu ne peut pas emprinter plus q'un livre ");
            getch();
            gotoxy(29,12);textcolor(BLUE);cprintf("click pour retourner etudient menu");
            clrscr();
            return;
        }

    }






///////////

    f=fopen("demonde.txt","a");
    fliv=fopen("livre.txt","r");
     tem=fopen("f.txt","a");
    {
        if(f==NULL || fliv==NULL || tem==NULL)
        {
            printf("problemme d'overture de fichie");
            return;
        }
        clrscr();
       gotoxy(43,14); printf("entrer le titre de livre :");
       fflush(stdin);
       gotoxy(70,14);scanf("%[^\n]",titre);


        while(!feof(fliv))
        {
             fscanf(fliv,lirliv,lv.titre,lv.genre,lv.autheur,&lv.nmbCopi,&lv.nmbCopiUtil);


           if(!strcmp(titre,lv.titre))
            {
               j=1;
               if(lv.nmbCopiUtil > 0)  //si il ya une copie pour emprinter
               {

                   lv.nmbCopiUtil--;
                   etudientemprint1(cod);
                   dat(date);
                fprintf(f,ecretudientdansliste,titre,cod,date);
                 gotoxy(64,14);textcolor(GREEN);
                 clrscr();
                  cprintf("votre demonde est enregistrer");
              getch();
               }
               else
               {
                   clrscr();
                   gotoxy(64,14); printf("les copies sont tout emprinter");


               }


            }


        fprintf(tem,ecrliv,lv.titre,lv.genre,lv.autheur,lv.nmbCopi,lv.nmbCopiUtil);

        }
       if(j==0)
        {     clrscr();
            textcolor(RED);
            gotoxy(29,11);
            cprintf("le livre n'existe pas ");
            getch();
            gotoxy(29,12);textcolor(BLUE);cprintf("click pour retourner aespace livre");
        }

     fclose(f);
     fclose(fliv);
       fclose(tem);
      remove("livre.txt");
    rename("f.txt","livre.txt");
 clrscr();

}
}


void etudientemprint1(char id[])
{

  int i=0;


    etudient et;
    FILE *file,*tem;
    clrscr();



    file=fopen("etudient.txt","r");
    tem=fopen("t.txt","a");
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
          et.emprint=1;

        }


            fprintf(tem,ecretudient,et.nom,et.prenom,et.codeapogee,et.email,et.modpas,et.emprint);

        }


        fclose(file);
        fclose(tem);
    }
    remove("etudient.txt");
    rename("t.txt","etudient.txt");


     gotoxy(1,1);textcolor(BLUE);cprintf("click pour retourner");
    getch();
    clrscr();
    return;

}

void livremprinter(char ph[])
  {
     FILE *file;
     int i=1;
     char titre[60],id[10],date[17];
     clrscr();
     file=fopen("emprinter.txt","r");
     {
         if(file==NULL)
         {
             printf("erreur d'overture");
             return;
         }
         while(!feof(file))
         {
             fscanf(file,"%[^,,],,%[^,,],,%[^\n]\n",titre,id,date);
             if(!strcmp(id,ph))
             {  clrscr();
                 gotoxy(29,12);
                 printf("le titre est :%s",titre);
                 gotoxy(29,13);
                 printf("date de retour est :%s",date);
                 i=0;
                 break;

             }

         }
         if(i==1)
         {    clrscr();
                 gotoxy(29,12);
             printf("vous navez pas emprinter un livre ");
         }
         fclose(file);
     }
    getch();
    clrscr();

  }
