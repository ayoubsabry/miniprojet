#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utileglobal.h"
#include "espacelivre.h"

coordonner cor= {1,12};


char *champlivre[]= {"ajouter un livre","suprimer un livre","modifie un livre ","chercher un livre","lister les livre","retour au menu admin","exit du programme"};

void passagverespacelivre(void)
{   int a;
   clrscr();
   do{ gotoxy(40,5);textcolor(GREEN);cprintf("ESPACE LIVRE");
    a=updownmenu(1,champlivre,7);
    switch(a)
    {
        case 1 : ajouterlivre();break;
        case 2 : supprimerlivre();break;
          case 3 :  modifielivre();break;
        case 4 :  chercherlivre();break;
        case 5 : listerlivre();break;
         case 6 : return; break;
         case 7 : exit(1);break;
    }

 }while(1);//a!8


}

void ajouterlivre(void)
{
    int test,i;
    char q[4];
     char *chec[]= {"ajout un livre","retour a espace livre"};
    livre *lv=NULL;
    FILE *fp;

  i=updownmenu(1,chec,2);
  if(i==2){clrscr();return;}
  clrscr();

    fp=fopen("livre.txt","a");
    {
        if(fp==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }

tt:
        lv=(livre*)realloc(lv,sizeof(livre));

        if(lv==NULL)
        {
            printf("taille insufisante");
            return;
        }
        clrscr();
        gotoxy(39,5);textcolor(BLUE);cprintf("entrer les info de livre");
        fflush(stdin);
        gotoxy(32,12);
        printf("entrer le titre du livre : ");
        gotoxy(32,13);
        printf("entrer le nom de l'auteur : ");
        gotoxy(32,14);
        printf("entrer le genre de livre : ");
        gotoxy(32,15);
        printf("entrer le nombre de copie de livre : ");
        fflush(stdin);
        gotoxy(60,12);
        scanf("%[^\n]",lv->titre);
        gotoxy(61,13);
        fflush(stdin);
       scanf("%[^\n]",lv->autheur);
        gotoxy(59,14);
        fflush(stdin);
        scanf("%[^\n]",lv->genre);
        gotoxy(69,15);
        scanf("%d",&lv->nmbCopi);
        lv->nmbCopiUtil=lv->nmbCopi;



        do
        {
            gotoxy(32,16);
            printf("vous voulez enregestrer ce livre (oui/non) :  ");
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






        test= fprintf(fp,ecrliv,lv->titre,lv->genre,lv->autheur,lv->nmbCopi,lv->nmbCopiUtil);

        if(test==EOF)
        {
            printf("problem denregi");
            return;
        }
        textcolor(GREEN);
        gotoxy(36,17);
        cprintf("le livre est enregistrer");

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


void listerlivre(void)
{
    livre lv;
    FILE *file;
    file=fopen("livre.txt","r");
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
            gotoxy(10,11);
            cprintf("TITRE");
            gotoxy(37,11);
            cprintf("AUTEUR");
            gotoxy(63,11);
            cprintf("GENRE");
            gotoxy(77,11);
            cprintf("NMBTOTAL");
            gotoxy(88,11);
            cprintf("NMBREREST");
        }
        gotoxy(cor.x,cor.y);
        while(!feof(file))
        {
            fscanf(file,lirliv,lv.titre,lv.genre,lv.autheur,&lv.nmbCopi,&lv.nmbCopiUtil);
            remplissagedetableau(&lv);
        }
        fclose(file);
    }
    getch();
    clrscr();
     cor.x=1;
    cor.y=12;
    return;
}


void remplissagedetableau(livre* lv)
{
    textcolor(3);

    if(cor.y==12)
    {
        gotoxy(cor.x,cor.y);
        cprintf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");//29 55 77 88 98
    }
    else
    {
        gotoxy(cor.x,cor.y);
        cprintf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
    }
    (cor.y)++;
    gotoxy(cor.x,cor.y);
    cprintf("³                         ³                         ³                     ³          ³             ³");
    (cor.y)++;
    gotoxy(cor.x,cor.y);
    cprintf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");



    gotoxy(cor.x+1,cor.y-1);
    printf("%s",lv->titre);
    gotoxy(cor.x+30,cor.y-1);
    printf("%s",lv->autheur);
    gotoxy(cor.x+56,cor.y-1);
    printf("%s",lv->genre);
    gotoxy(cor.x+78,cor.y-1);
    printf("%d",lv->nmbCopi);
    gotoxy(cor.x+89,cor.y-1);
    printf("%d",lv->nmbCopiUtil);


}


void chercherlivre(void)
{    int i,j=0;
    coordonner xy= {22,10};
    char mot[60];
    livre lv;
    FILE *file;
    clrscr();
    gotoxy(40,5);textcolor(GREEN);cprintf("cherch livre");
    gotoxy(xy.x,xy.y);
    printf("entrer le titre du livre :");
    gotoxy(xy.x+28,xy.y);
     fflush(stdin);
    scanf("%[^\n]",mot);
  clrscr();
    file=fopen("livre.txt","r");
    {
        if(file==NULL)
        {
            printf("problemme d'overture du fechier");
            return;
        }


        while(!feof(file))
        {
             fscanf(file,lirliv,lv.titre,lv.genre,lv.autheur,&lv.nmbCopi,&lv.nmbCopiUtil);


           if(!strcmp(mot,lv.titre))
            {
                clrscr();
                gotoxy(xy.x,xy.y);
                printf("le titre du livre: %s",lv.titre);
                gotoxy(xy.x,xy.y+1);
                printf("l'auteur de livre : %s",lv.autheur);
                gotoxy(xy.x,xy.y+2);
                printf("le genre de livre : %s",lv.genre);
                gotoxy(xy.x,xy.y+3);
                printf("le nombre de cpie de livre : %d",lv.nmbCopi);
                gotoxy(xy.x,xy.y+4);
                printf("nmbre de copie utile  de livre : %d",lv.nmbCopiUtil);
                gotoxy(xy.x,xy.y+5);
               j=1;
                break;

            }
        }
       if(j==0)
        {     clrscr();
            textcolor(RED);
            gotoxy(29,11);
            cprintf("le livre n'existe pas ");
            getch();
            gotoxy(29,12);textcolor(BLUE);cprintf("click pour retourner aespace livre");
            clrscr();
            return;
        }

        fclose(file);
    }
     gotoxy(xy.x,xy.y+10);textcolor(BLUE);cprintf("click pour retourner aespace livre");
    getch();
    clrscr();
    return;

}

void supprimerlivre(void)
{

    int j,i=0;
     char *chec[]= {"supprimer le livre","anuler  et retour a espace livre"};
    coordonner xy= {22,10};
    char mot[60];
    livre lv;
    FILE *file,*tem;
    clrscr();
    gotoxy(40,5);textcolor(GREEN);cprintf("suprimer livre");
    gotoxy(xy.x,xy.y);
    printf("entrer le titre du livre :");
    gotoxy(xy.x+28,xy.y);
     fflush(stdin);
    scanf("%[^\n]",mot);

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


           if(!strcmp(mot,lv.titre)) {
                i=1;
               j=updownmenu(1,chec,2);
          if(j==1){clrscr();continue;}
           }

             fprintf(tem,ecrliv,lv.titre,lv.genre,lv.autheur,lv.nmbCopi,lv.nmbCopiUtil);

        }


        fclose(file);
        fclose(tem);
    }
    remove("livre.txt");
    rename("f.txt","livre.txt");
    if(i==0){textcolor(GREEN);
        gotoxy(36,14);
        cprintf("le livre n'existe pas");goto a;}
    textcolor(GREEN);
        gotoxy(36,14);
        cprintf("le livre est supprimer");

    a: gotoxy(xy.x,xy.y+8);textcolor(BLUE);cprintf("click pour retourner aespace livre");
    getch();
    clrscr();
    return;

}


void modifielivre(void)
{

  int i=0,nmb;
    coordonner xy= {22,10};
    char mot[60];
    livre lv;
    FILE *file,*tem;
    clrscr();
    gotoxy(40,5);textcolor(GREEN);cprintf("modifie livre");
    gotoxy(xy.x,xy.y);
    printf("entrer le titre du livre :");
    gotoxy(xy.x+28,xy.y);
     fflush(stdin);
    scanf("%[^\n]",mot);

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


           if(!strcmp(mot,lv.titre)) {i=1;
           clrscr();
           nmb=lv.nmbCopi;
        gotoxy(39,5);textcolor(BLUE);cprintf("entrer les nouve info de livre");
        fflush(stdin);
        gotoxy(32,12);
        printf("entrer le titre du livre num : ");
        gotoxy(32,13);
        printf("entrer le nom de l'auteur : ");
        gotoxy(32,14);
        printf("entrer le genre de livre du livre : ");
        gotoxy(32,15);
        printf("entrer le nombre de copie de livre du livre : ");
        fflush(stdin);
        gotoxy(64,12);
        gets(lv.titre);
        gotoxy(61,13);
        gets(lv.autheur);
        gotoxy(69,14);
        gets(lv.genre);
        gotoxy(78,15);
        scanf("%d",&lv.nmbCopi);

           if(nmb>lv.nmbCopi)
           {
               nmb=nmb-lv.nmbCopi;
           }

          else{nmb=lv.nmbCopi-nmb;}

         lv.nmbCopiUtil=lv.nmbCopiUtil+nmb;
        }


             fprintf(tem,ecrliv,lv.titre,lv.genre,lv.autheur,lv.nmbCopi,lv.nmbCopiUtil);

        }


        fclose(file);
        fclose(tem);
    }
    remove("livre.txt");
    rename("f.txt","livre.txt");
    if(i==0){textcolor(GREEN);
        gotoxy(36,16);
        cprintf("le livre n'existe pas");goto a;}
    textcolor(GREEN);
        gotoxy(36,16);
        cprintf("le livre est modifie");

    a: gotoxy(xy.x,xy.y+8);textcolor(BLUE);cprintf("click pour retourner aespace livre");
    getch();
    clrscr();
    return;

}
