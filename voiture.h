#include "date.cpp"
#include <bits/stdc++.h>
using namespace std;
class Voiture
{
private:
    string immatricule;
    string marque;
    float prix_par_jour;
    date date_de_creation;
    int age;
//concernant location
    bool est_loue;
    int nbr_de_fois_loue;
    date date_de_prise;
    date date_de_remise;
    int id_client
public:
    //constructeurs
    voiture(string immatricule,string marque,float prix_par_jour,date date_de_creation,int age,bool est_loue,int nbr_de_fois_loue,date date_de_prise ,date date_de_remise,int id_client);
    voiture(string immatricule,string marque,float prix_par_jour);//nouvelle voiture
    voiture(string marque,float prix_max);//constructeur de wanted car
    //age
    int get_age();
    void set_age(int);
    //getter et setter
    string get_immatricule();
    string get_marque();
    float get_prix();
    void set_prix(float);
                //'->lorsque voiture devenir plus agé l agence peut etre va changer le prix"
    //location
    bool voiture_loue();
    int get_nbr_de_fois_loue();
    int get_id_client();
    date get_date_de_prise();
    date get_date_de_remise();
    void location_voiture(int id_client,date date_de_prise,date date_de_remise);
    void remise_voiture();
    //surcharge des operateur
    friend ostream& operator<<(ostream& s,const voiture& V);
    bool operator==(const voiture& v);//comparaison avec wanted car
    ~voiture();
};
