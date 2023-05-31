#ifndef ESPACEETUDIENT_H_INCLUDED
#define ESPACEETUDIENT_H_INCLUDED


const char* ecretudient="%s,,%s,,%s,,%s,,%s,,%d\n"; //serialization   ** nom,,prenom,,codappog,,email,,motpass,,imprint
const char* liretudient="%[^,,],,%[^,,],,%[^,,],,%[^,,],,%[^,,],,%d\n";


typedef struct etu
{   int emprint;
     char codeapogee[10];
    char nom[20];
    char prenom[20];
    char email[30] ;
    char modpas[10];

} etudient;


void passagverespaceetudient(void);
void listeretudient(void);
void remplissagedetableau1(etudient*);
void ajouteretudient(void);
void suprimeretudient(void);
void modifieetudient(void);

void chercheretudient(void);


#endif // ESPACEETUDIENT_H_INCLUDED
