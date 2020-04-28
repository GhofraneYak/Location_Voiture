#include "date.cpp"
#include <bits/stdc++.h>
using namespace std;
class voiture
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
    long id_client;
public:
    //constructeurs
    voiture(string immatricule,string marque,float prix_par_jour,date date_de_creation,int age,bool est_loue,int nbr_de_fois_loue,date date_de_prise ,date date_de_remise,long id_client);
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
    void set_voiture_loue();//!voiture_loue
    int get_nbr_de_fois_loue();
    void set_nbr_de_fois_loue();//incrementer nbr de fois loué
    long get_id_client();
    void set_id_client(long);
    date get_date_de_prise();
    date get_date_de_remise();
    void set_date_de_prise(date);
    void set_date_de_remise(date);
    //surcharge des operateur
    friend ostream& operator<<(ostream& s,const voiture& V);
    bool operator==(const voiture& v);//comparaison avec wanted car
    void sauvegarder_une_voiture();//elle facilite le sauvegard de liste des voitures sans appelé get et set
    ~voiture();
};
