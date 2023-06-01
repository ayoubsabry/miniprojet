#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "espaceetudient.h"
#include "utileglobal.h"
#include "espacelivre.h"
#include "espaceEmprinte.h"
#include "etudient.h"

void passagloging(void);
void verificationComptadmin(void);
void espaceAdmin(void);
int main()
{

passagloging();

    return 0;
}


void passagloging(void)
{   int i;
   char *log[]={"ADMIN","ETUDIENT","EXIT"};
   clrscr();
   do{
        gotoxy(40,9);textcolor(GREEN);
   cprintf("login tempt que : ");
    i=updownmenu(1,log,3);
    switch(i)
    {
        case 1 :verificationComptadmin();break;
        case 2 : verificationComptetudient();break;
        case 3 : exit(1);break;
    }

 }while(1);
}


void espaceAdmin(void)
{
    char *champ[]= {"gestion livre","gestion etudiant","Emprinter","exit"};
    int i;
    clrscr();
do{

gotoxy(40,5);textcolor(GREEN);cprintf("ADMIN MENU");
i=updownmenu(1,champ,4);
switch(i){
 case 1 :   passagverespacelivre();break;
 case 2 : passagverespaceetudient();break;
 case 3 : passagverEmprinte();break;
 case 4 : exit(1);

}
}while(1);
}



void verificationComptadmin(void)
{

    char  email[17],motpass[17];
   gotoxy(40,12); printf("entrer l'email : ");
   gotoxy(40,13); printf("entrer le mod passe : ");
     fflush(stdin);
     gotoxy(57,12);scanf("%s",email);
    fflush(stdin);
     gotoxy(62,13);scanf("%s",motpass);


            if(!(strcmp(email,"smis4@gmail.com")&& strcmp(motpass,"123")))
            {  clrscr();
               espaceAdmin();
            }


     else
     {clrscr();
     gotoxy(48,14);
     textcolor(RED);
     cprintf("les donner est incorecte");
     getch();
     clrscr();
         return;
     }
}
