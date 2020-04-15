#ifndef PERSONNE_H
#define PERSONNE_H
#include "include.h"


class Personne
{
 private:


 public:
    Personne();
    Personne(int idp,float prime,QString date_naissance,int numtel,QString adresse,QString nom,QString prenom,QString email,QString type,float salaire,int num_compteb,QString mot_de_passe);
    Personne(const Personne &p);
    ~Personne();




};
#endif // PERSONNE_H
