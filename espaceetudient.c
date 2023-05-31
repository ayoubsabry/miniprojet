#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
#include "espaceetudient.h"
#include "utileglobal.h"

 coordonner cor1={1,12};

char *champetudient[]= {"lister les etudients","ajouter un etudient","chercher un etudient","modifie un etudient","suprimer un etudient","retour au menu admin","exit"};
void passagverespaceetudient(void)
{   int i;
   clrscr();
   do{ gotoxy(40,5);textcolor(GREEN);cprintf("ESPACE ETUDIENT");
    i=updownmenu(1,champetudient,7);
    switch(i)
    {
        case 1 : listeretudient();break;
        case 2 :  ajouteretudient();break;
        case 3 : chercheretudient();break;
        case 4 : modifieetudient();break;
        case 5 : suprimeretudient();break;
        case 6 : return; break;
        case 7 : exit(1);break;
    }

 }while(1);
}




void ajouteretudient(void)
{
    int test,i;
    char q[4];
     char *chec[]= {"ajout etudient ","retour a espace etudient"};
    etudient *et=NULL;
    FILE *fp;

  i=updownmenu(1,chec,2);
  if(i==2){clrscr();return;}
  clrscr();

    fp=fopen("etudient.txt","a");
    {
        if(fp==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }

tt:
        et=(etudient*)realloc(et,sizeof(etudient));

        if(et==NULL)
        {
            printf("taille insufisante");
            return;
        }
        clrscr();
        gotoxy(39,5);textcolor(BLUE);cprintf("entrer les info de l'etudient");
        fflush(stdin);
        gotoxy(32,12);
        printf("entrer le nom de letudient : ");
        gotoxy(32,13);
        printf("entrer le prenom de letudient : ");
        gotoxy(32,14);
        printf("entrer le code apoge de letudient : ");
        gotoxy(32,15);
        printf("entrer l'email de letudient : ");
        fflush(stdin);
        gotoxy(60,12);
        //fgets(et->nom,20,stdin);
        scanf("%[^\n]",et->nom);
        gotoxy(64,13);
        fflush(stdin);
        //fgets(et->prenom,20,stdin);
        scanf("%[^\n]",et->prenom);
        gotoxy(67,14);
       fflush(stdin);
        //fgets(et->codeapogee,10,stdin);
         scanf("%[^\n]",et->codeapogee);
        gotoxy(61,15);
       fflush(stdin);
        //fgets(et->email,30,stdin);
         scanf("%[^\n]",et->email);
        et->emprint=0;





        do
        {
            gotoxy(32,16);
            printf("vous voulez enregestrer l'etudient (oui/non) :  ");
           fflush(stdin);
            fgets(q,4,stdin);
            if(strcmp(q,"non") && strcmp(q,"oui"))
            {
                gotoxy(32,16);
                clreol();
                continue;
            }


            if(!strcmp(q,"non"))goto a;
            else break;
        }
        while(1);






        test= fprintf(fp,ecretudient,et->nom,et->prenom,et->codeapogee,et->email,et->codeapogee,et->emprint);///motpass est le cod apog par defaut

        if(test==EOF)
        {
            printf("problem denregi");
            return;
        }
        textcolor(GREEN);
        gotoxy(36,17);
        cprintf("l'etudient est enregistrer");

        do
        {
            gotoxy(32,18);
            printf("vous voulez demarrer une autre operation(oui/non) :  ");

            fgets(q,4,stdin);
            if(strcmp(q,"non") && strcmp(q,"oui"))
            {
                gotoxy(32,18);
                clreol();
                continue;
            }


            if(!strcmp(q,"non"))goto a;
            else break;
        }
        while(1);
        goto tt;


       a: fclose(fp);
    }

{clrscr(); return;}
}



void listeretudient(void)
{
    etudient lv;
    FILE *file;
    file=fopen("etudient.txt","r");
    {
        if(file==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }
        gotoxy(32,6);
        textcolor(9);
        cprintf("la liste des etudient est ");

       gotoxy(1,10);textcolor(BLUE+GREEN);
        cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄ¿");
          gotoxy(1,11);
       textcolor(GREEN);
        cprintf("³       nom         ³     prenom         ³nmbapog³         email               ³  emprent³");

        gotoxy(1,12);
        while(!feof(file))
        {    fscanf(file,liretudient,lv.nom,lv.prenom,lv.codeapogee,lv.email,lv.modpas,&lv.emprint);

            remplissagedetableau1(&lv);
        }
        fclose(file);
    }

    getch();
    clrscr();

    cor1.x=1;
    cor1.y=12;
    return;
}




void remplissagedetableau1(etudient *et)
{
    textcolor(3);


       //1 21 42 50 80 90 100

     gotoxy(cor1.x,cor1.y);
        cprintf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄ´");

    (cor1.y)++;
    gotoxy(cor1.x,cor1.y);
        cprintf("³                   ³                    ³       ³                             ³         ³");
    (cor1.y)++;
    gotoxy(cor1.x,cor1.y);
        cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÙ");



    gotoxy(2,cor1.y-1);
    printf("%s",et->nom);
    gotoxy(22,cor1.y-1);
    printf("%s",et->prenom);
    gotoxy(43,cor1.y-1);
    printf("%s",et->codeapogee);
    gotoxy(51,cor1.y-1);
    printf("%s",et->email);
    gotoxy(81,cor1.y-1);
    printf("%d",et->emprint);



}

void suprimeretudient(void)
{

    int j,i=0;
     char *chec[]= {"supprimer l'etudient","anuler  et retour a espace etudient"};
    coordonner xy= {22,10};
    char mot[10];
    etudient et;
    FILE *file,*tem;
    clrscr();
    gotoxy(40,5);textcolor(GREEN);cprintf("suprimer etudient");
    gotoxy(xy.x,xy.y);
    printf("entrer le code d'etudient :");
    gotoxy(xy.x+28,xy.y);
     fflush(stdin);
    scanf("%[^\n]",mot);

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


           if(!strcmp(mot,et.codeapogee)) {i=1;
           clrscr();
           j=updownmenu(1,chec,2);
           if(j==1) continue;}


             fprintf(tem,ecretudient,et.nom,et.prenom,et.codeapogee,et.email,et.modpas,et.emprint);

        }


        fclose(file);
        fclose(tem);
    }
    remove("etudient.txt");
    rename("f.txt","etudient.txt");
    if(i==0){textcolor(GREEN);
        gotoxy(36,14);
        cprintf("letudient n'existe pas");goto a;}
    textcolor(GREEN);
        gotoxy(36,14);
        cprintf("ll'etudient  est supprimer");

    a: gotoxy(xy.x,xy.y+8);textcolor(BLUE);cprintf("click pour retourner a espace etudient");
    getch();
    clrscr();
    return;

}


void chercheretudient(void)
{
    int i,j=0;
    coordonner xy= {22,10};
    char mot[8];
    etudient et;
    FILE *file;
    clrscr();
    gotoxy(40,5);textcolor(GREEN);cprintf("cherch etudient");
    gotoxy(xy.x+16,xy.y);
    printf("num apo : ");
    gotoxy(xy.x+28,xy.y);
     fflush(stdin);
    scanf("%[^\n]",mot);
  clrscr();
    file=fopen("etudient.txt","r");
    {
        if(file==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }


        while(!feof(file))
        {
            fscanf(file,liretudient,et.nom,et.prenom,et.codeapogee,et.email,et.modpas,&et.emprint);


           if(!strcmp(mot,et.codeapogee))
            {

                gotoxy(xy.x,xy.y++);
                printf("nom d'etudient : %s",et.nom);
                gotoxy(xy.x,xy.y++);
                printf("prenom d'etudient : %s",et.prenom);
                gotoxy(xy.x,xy.y++);
                printf("email d'etudient : %s",et.email);
                gotoxy(xy.x,xy.y++);
                if(et.emprint==1){textcolor(GREEN);printf("emprinter un livre");}
                else {textcolor(GREEN);cprintf("emprinte pas de livre");}
                gotoxy(xy.x,xy.y++);
               j=1;


            }
        }
       if(j==0)
        {     clrscr();
            textcolor(RED);
            gotoxy(29,11);
            cprintf("l'etudient n'existe pas ");
            getch();
            gotoxy(29,12);textcolor(BLUE);cprintf("click pour retourner aespace livre");
            return;
        }

        fclose(file);
    }
     gotoxy(xy.x,xy.y++);textcolor(BLUE);cprintf("click pour retourner aespace livre");
    getch();
    clrscr();
    return;

}



void modifieetudient(void)
{

  int i=0;
    coordonner xy= {22,10};
    char mot[60];
    etudient et;
    FILE *file,*tem;
    clrscr();
    gotoxy(40,5);textcolor(GREEN);cprintf("modifie etudient");
    gotoxy(xy.x,xy.y);
    printf("entrer num apoge detudient :");
    gotoxy(xy.x+28,xy.y);
     fflush(stdin);
    scanf("%[^\n]",mot);

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


           if(!strcmp(mot,et.codeapogee)) {i=1;
           clrscr();

        gotoxy(39,5);textcolor(BLUE);cprintf("entrer les nouve info d'etudient");
        fflush(stdin);
        gotoxy(32,12);
        printf("entrer le nom d'etudien : ");
        gotoxy(32,13);
        printf("entrer le prenom d'etudien : ");
        gotoxy(32,14);
        printf("entrer l'email d'etudien : ");
        fflush(stdin);
        gotoxy(59,12);
        scanf("%[^\n]",et.nom);
        fflush(stdin);
        gotoxy(61,13);
         scanf("%[^\n]",et.prenom);
         fflush(stdin);
        gotoxy(60,14);
         scanf("%[^\n]",et.email);

        }


            fprintf(tem,ecretudient,et.nom,et.prenom,et.codeapogee,et.email,et.modpas,et.emprint);

        }


        fclose(file);
        fclose(tem);
    }
    remove("etudient.txt");
    rename("f.txt","etudient.txt");
    if(i==0){textcolor(GREEN);
        gotoxy(36,16);
        cprintf("l'etudient n'existe pas");goto a;}
    textcolor(GREEN);
        gotoxy(36,16);
        cprintf("les info d'etudint est modifie");

    a: gotoxy(xy.x,xy.y+8);textcolor(BLUE);cprintf("click pour retourner aespace etudient");
    getch();
    clrscr();
    return;

}
