
#include <iostream>
#include "contrat.h"
#include "voiture.h"
#include "parking.h"
#include "client.h"
#include "date.h"
using namespace std;

class agence
{
    private:

        list<parking> liste_parking;
        list<client> liste_client;

    public:

        //Constructeur
        agence();

        //Lire les données concernant les parking
        //list<parking> lire_fichier_park();

        //Lire les données concernant les clients
        void lire_fichier_cl();


        //Sauvegarder les données des clients dans le fichier
        void sauvegarder_client(string nom_fichier, list<client> l);


        bool client_existe(long id);

        void ajouter_client(string nom, long id, date date_auj);

        void creer_client();

        list<client> client_6_mois();



        void update_age_voiture(voiture v);





};

