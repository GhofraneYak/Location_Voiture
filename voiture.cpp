#include "voiture.h"
#include <bits/stdc++.h>
using namespace std;

/*******************Constructeurs***********************/
voiture::voiture(string immatricule,string marque,float prix_par_jour,date date_de_creation,int age,bool est_loue,int nbr_de_fois_loue,date date_de_prise ,date date_de_remise,long id_client);
{
    this->immatricule=immatricule;
    this->marque=marque;
    this->prix_par_jour=prix_par_jour;
    this->date_de_creation=date_de_creation;
    this->age=age;
    this->est_loue=est_loue;
    this->nbr_de_fois_loue=nbr_de_fois_loue;
    this->date_de_prise=date_de_prise;
    this->date_de_remise=date_de_remise;
    this->id_client=id_client;
}

voiture::voiture(string immatricule,string marque,float prix_par_jour)
{
    this->immatricule=immatricule;
    this->marque=marque;
    this->prix_par_jour=prix_par_jour;
    //date_de_creation=date::date_aujourdhui();
    age=0;
    est_loue=false;
    nbr_de_fois_loue=0;
    date_de_prise=new date(1,1,1);
    date_de_remise=new date(1,1,1);
}

voiture::voiture(string marque,float prix_max)
{
    this->marque=marque;
    prix_par_jour=prix_max;
}

/*******************age***********************/

int voiture::get_age()
{
    return age;
}

void voiture::set_age(int a)
{
    age=a;
}

/*******************getter/setter*****************/

string voiture::get_immatricule()
{
    return immatricule;
}

string voiture::get_marque()
{
    return marque;
}

float voiture::get_prix()
{
    return prix_par_jour;
}

void voiture::set_prix(float p)
{
    prix_par_jour=p;
}

/*******************location*********************/
bool voiture::voiture_loue()
{
    return est_loue;
}

void voiture::set_voiture_loue()
{
    est_loue=!est_loue;
}

int voiture::get_nbr_de_fois_loue()
{
    return nbr_de_fois_loue;
}

void voiture::set_nbr_de_fois_loue()
{
    nbr_de_fois_loue++;
}

long voiture::get_id_client()
{
    return id_client;
}

void voiture::set_id_client(long id)
{
    id_client=id;
}

date voiture::get_date_de_prise()
{
    return date_de_prise;
}

date voiture::get_date_de_remise()
{
    return date_de_remise;
}

void voiture::set_date_de_prise(date d)
{
    date_de_prise=d;
}

void voiture::set_date_de_remise(date d)
{
    date_de_remise=d;
}

/*******************Surcharge des operateurs*****************/

ostream& operator<<(ostream& s,const voiture& V)
{
    s<<"Voiture "<<V.immatricule<<":/n/tMarque: "<<V.marque<<"/n";
    s<<"/tAge: "<<V.age<<"/n/tPrix par jour: "<<V.prix_par_jour<<endl;
    s<<"/tNombre de fois loue"<<V.nbr_de_fois_loue<<endl;
    if (V.est_loue==true)
        s<<"la voiture est loue à l'instant"<<endl;
    else
        s<<"/tla voiture est disponible à l'instant "<<endl;
    return s;
}

bool voiture::operator==(const voiture& v)
{
    return ((marque==v.marque)&&(prix_par_jour<=v.prix_par_jour));
}

/*******************Sauvegarde*************************/
void voiture::sauvegarder_une_voiture()
{
    cout<<immatricule<<" ";
    cout<<marque<<" ";
    cout<<prix_par_jour<<" ";
    cout<<date_de_creation.getjour()<<date_de_creation.getmois()<<date_de_creation.getannee()<<" ";
    cout<<age<<" ";
    cout<<est_loue<<" ";
    cout<<nbr_de_fois_loue<<" ";
    cout<<date_de_prise.getjour()<<date_de_prise.getmois()<<date_de_prise.getannee()<<" ";
    cout<<date_de_remise.getjour()<<date_de_remise.getmois()<<date_de_remise.getannee()<<" ";
    cout<<id_client<<endl;
}

voiture::~voiture()
{
}
























