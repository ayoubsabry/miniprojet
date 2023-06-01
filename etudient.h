#ifndef ETUDIENT_H_INCLUDED
#define ETUDIENT_H_INCLUDED

const char* ecretudientdansliste="%s,,%s,,%s\n"; //titrelivre  codapo   datedomm
  const char* liretudientdansliste="%[^,,],,%[^,,],,%[^\n]\n";
  void etudientmenu(char*);
void verificationComptetudient(void);
void emprinterlivre(char*);
void livremprinter(char*);
void etudientemprint1(char*);


#endif // ETUDIENT_H_INCLUDED
