#include "voiture.cpp"
#include <iostream>

using namespace std;

    class parking
    {
        int id;
        int capacite;
        int nbV;   // Nombre des voitures déja présente dans le parking
        list<voiture> liste_voiture;

    public:
        static int nbP;
        parking(int c,int idd);//lire un parking sans voitures du fichier
        parking (int id, int c, int nb,  list<voiture> liste) ;// re-creation des parking à partir du
        parking (int c);  // création d'un nouveau parking
        list<voiture>& get_voitures_de_parking();
        int get_capacite();
        void set_capacite(int c);
        int get_nbV();
        int get_id();
        void affichage_info();
        bool parking_disponible();
        bool voiture_est_dans_ce_parking(voiture); // Recherche d'une voiture dans ce parking
        void ajout_voiture(voiture);
        float moy_prix();
        void delete_voiture(voiture);
        void vider_le_parking();
        ~parking();
    };


