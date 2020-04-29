#include "voiture.cpp"
#include <iostream>

using namespace std;

    class parking
    {
        int id;
        int capacite;
        int nbV;
        list<voiture> liste_voiture;

    public:
        static int nbP;
        parking (int id, int c, int nb,  list<voiture> liste) ;// re-creation des parking à partir du
        parking (int c);
        list<voiture> get_voitures_de_parking();
        int get_capacite();
        void set_capacite(int c);
        int get_nbV();
        int get_id();
        void affichage_info();
        bool parking_disponible();
        bool voiture_est_dans_ce_parking(voiture);
        void ajout_voiture(voiture);
        float moy_prix();
        void delete_voiture(voiture);
        void vider_le_parking();
        ~parking();
    };


