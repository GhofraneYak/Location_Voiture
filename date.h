
#include <iostream>
#include "voiture.h"

using namespace std;

// LA VARIABLE date_auj EST GLOBALE (Déclarée dans le main)
class date
{
    private:
        int annee;
        int mois;
        int jour;

    public:

            //Constructeur
            date(int j, int m, int a);

            int getjour();
            int getmois();
            int getannee();

            //Vérifier si la date entrée est valide
            bool date_valide(int a, int m, int j);

            //Affectation
            date& operator=(const date& d);


            //Retourne l'age d'une voiture en années
            int age_voiture(date auj, date date_v);


            int dernier_loc_client(date date_cl);

            //Date résultante d'une différence entre 2 dates
            date& soustraction(const date& d1, const date& d2);

            //Comparaison date remise et date aujourd'hui
            bool operator<(const date& d);
            bool operator>(const date& d);
            //<=

            bool est_bissextile();

            //Date de retour de la voiture
            date& date_remise(int nb_jr);

            bool voiture_available(voiture v);


};


