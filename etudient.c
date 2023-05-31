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
    int c=0;//nombre de fois que lutilisateur peut entrer un faut mot de passe
    char  cod[10],modpass[10];
   gotoxy(40,12); printf("entrere votre num apogg : ");
   gotoxy(40,13); printf("entrer votre mod passe : ");
     gotoxy(65,12);scanf("%[^\n]",cod);

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
            {   a: gotoxy(64,13);scanf("%[^\n]",modpass);
                if(et.modpas!=modpass)
                {   c++;
                     gotoxy(64,14);textcolor(RED);
                     printf("le mot de passe incorect");
                     getchar();
                     gotoxy(64,14);clreol();
                   if(c==1) exit(0);// il peut essayer 2 foit
                   goto a;
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


 etudientmenu(et.codeapogee);
}


void emprinterlivre(char cod[])
{  int j=0;//verifie ci le  livre existe
char q[4];//oui non
char date[9];
    FILE *f,*fliv,*tem;
    livre lv;
    char titre[60];
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
       gotoxy(64,14); printf("entrer le titre de livre :");
       gotoxy(93,14);scanf("%s",titre);



        while(!feof(fliv))
        {
             fscanf(fliv,lirliv,lv.titre,lv.genre,lv.autheur,&lv.nmbCopi,&lv.nmbCopiUtil);


           if(!strcmp(titre,lv.titre))
            {
               j=1;
               if(lv.nmbCopiUtil > 0)  //si il ya une copie pour emprinter
               {

                   lv.nmbCopiUtil--;
                   dat(date);
                fprintf(f,ecretudientdansliste,lv.titre,cod,date);
                 gotoxy(64,14);textcolor(GREEN);
                  printf("votre demonde est enregistrer");

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
            return;
        }

     fclose(f);
     fclose(fliv);
       fclose(tem);
      remove("livre.txt");
    rename("f.txt","livre.txt");


}
}

void livremprinter(char ph[])
  {
     FILE *file;
     int i=1;
     char titre[60],id[10],date[17];
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
      getchar();
  }
