#include "voiture.h"
#include <bits/stdc++.h>
using namespace std;

/*******************Constructeurs***********************/
voiture::voiture(string immatricule,string marque,float prix_par_jour,date date_de_creation,int age,bool est_loue,int nbr_de_fois_loue,date date_de_prise ,date date_de_remise,int id_client);
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

void set_age(int a)
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

int voiture::get_nbr_de_fois_loue()
{
    return nbr_de_fois_loue;
}

int voiture::get_id_client()
{
    return id_client;
}

date voiture::get_date_de_prise()
{
    return date_de_prise;
}

date voiture::get_date_de_remise()
{
    return date_de_remise;
}

void location_voiture(int id_client,date date_de_prise,date date_de_remise)
{
    this->id_client=id_client;
    this->date_de_prise=date_de_prise;
    this->date_de_remise=date_de_remise;
    est_loue=true;
    nbr_de_fois_loue++;
}

void remise_voiture()
{
    id_client=0;
    date_de_prise=new date(0,0,0);
    date_de_remise=new date(0,0,0);
    est_loue=false;
}

/*******************Surcharge des operateurs*****************/

ostream& operator<<(ostream& s,const Voiture& V)
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
    return ((marque==v.marque)&&(prix_par_jour<=v.prix_par_jour))
}

/*******************Destructeur*************************/
voiture::~voiture()
{
};
























