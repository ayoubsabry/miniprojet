#ifndef ESPACELIVRE_H_INCLUDED
#define ESPACELIVRE_H_INCLUDED

const char* ecrliv="%s,,%s,,%s,,%d,,%d\n"; //serialization   titre genre auteur nmbcopi nmbcoputil
const char* lirliv="%[^,,],,%[^,,],,%[^,,],,%d,,%d\n";

typedef struct livre
{
    int nmbCopi;
    int nmbCopiUtil;
    char titre[60];
    char autheur[20];
    char genre[60];

} livre;




//fichie livre.txt
void ajouterlivre(void);
void listerlivre(void);
void remplissagedetableau(livre*);
void chercherlivre(void);
void supprimerlivre(void);
void modifielivre(void);
void passagverespacelivre(void);


#endif // ESPACELIVRE_H_INCLUDED
