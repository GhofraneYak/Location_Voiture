#include "voiture.h"

using namespace std;

    class parking
    {
        int nbP;
        int id;
        int capacite;
        list<Voiture> liste_voiture;

    public:

        parking (int id, int c, list<Voiture> liste) ;// re-creation des parking à partir du fichier
        parking (int c);//creation de nouveau parking
        list<Voiture> get_voitures_de_parking();
        int get_capacite();
        void set_capacite(int c);
        int get_id();
        void affichage_info();

    };


