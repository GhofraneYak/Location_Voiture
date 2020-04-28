#pragma once
#ifndef DATE_H
#include <iostream>

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
            bool date_valide(int annee, int mois, int jour);

            //Affectation
            date& operator=(const date& d);


            //Retourne l'age d'une voiture en années
            static int age_voiture(date auj, date date_v);


            int dernier_loc_client(date date_cl);

            //Date résultante d'une différence entre 2 dates
            static date soustraction(const date& d1, const date& d2);

            //Comparaison date remise et date aujourd'hui
            bool operator<(date& d);
            bool operator>(date& d);
            //<=

            bool est_bissextile();

            //bool voiture_available(voiture v);

            bool operator==(const date& d);
};
#endif



