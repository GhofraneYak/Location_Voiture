#include "voiture"

using namespace std;

    class parking
    {
        int nbP;
        int id;
        int capacite;
        int nbV;
        list<Voiture> liste_voiture;

    public:

        parking (int id, int c, int nb,  list<Voiture> liste) ;// re-creation des parking à partir du
        list<Voiture> get_voitures_de_parking();
        int get_capacite();
        void set_capacite(int c);
        int get_nbV();
        int get_id();
        void affichage_info();
        bool parking_disponible();
        bool voiture_est_dans_ce_parking(Voiture V);
        void ajout_voiture(Voiture v);
        float moy_prix();
        void delete_voiture(Voiture V)/
        void vider_le_parking();

    };


