#ifndef UTILEGLOBAL_H_INCLUDED
#define UTILEGLOBAL_H_INCLUDED

typedef struct coordo
{
    int x;
    int y;
} coordonner;

typedef struct
{
    char numapogee[7];
    char modpass[13];
}loging;

coordonner xyglobale= {36,12};
void menu(int,char**,int);
int updownmenu(int,char**,int);
void dat(char*);
void dateretoure(char*,int);

#endif // UTILEGLOBAL_H_INCLUDED
