
#include <bits/stdc++.h>
#include "client.cpp"
using namespace std;

class agence
{
    private:
        date date_auj;
        list<voiture> liste_voiture;
        list<parking> liste_parking;
        list<client> liste_client;

    public:

        //Constructeur
        agence(date d_auj);
 //**********************Verifier l'agence contient des donnée dans les fichier***************//
    bool agence_vide_de_parking();//ces methodes sont utile pour le main 
    bool agence_vide_de_voiture();
//********************** Méthodes des clients **************************//
        //Lire les données concernant les clients
        void lire_fichier_cl();


        //Sauvegarder les données des clients dans le fichier
        void sauvegarder_client(list<client> l);


        bool client_existe(long id);

        void ajouter_client(string nom, long id);

        void creer_client();

        list<client> client_6_mois();


//********************** Méthodes des parkings **************************//
        //Lire les données concernant les parking
 
         list<parking> lire_fichier_park(); 
        void sauvegarder_parking(list<parking> l); 
         void nouveau_parking();
         int recherche_parking(voiture v);
         int parking_disponible(); 

        void grouper_dans_un_parking(parking p1, parking p2, parking p3); 
        void vider_selon_categories(parking p1, parking p2, parking p3);
        parking ce_parking(int);
    
 //********************** Création du contrat **************************//
    voiture wanted_car(date,date);    
    void creer_contrat();
        
/*************************Methodes liste de voitures *****************/
    void lire_fichier_voiture();//appeler cette methode dans le constructeur d'agence
    voiture nouvelle_voiture();
    voiture get_voiture(string immatricule); //pour avoir liste de voiture de chaque parking
    void location_voiture(voiture& v,long id_client,date date_de_prise,date date_de_remise);//appeler dans creation contrat
    void update_v_non_disponible(voiture& v);//elle change le boolean et supprime la voiture de parking on l'appel dans update methode
    void update_v_disponible(voiture& v);//elle appel parking disponible pour remettre voiture dans un parking. on l'appel dans update methode     
    voiture la_voiture_plus_ancienne();
    voiture la_voiture_plus_loue();
    list<voiture> voitures_2_3();//dont l'age entre 2 et 3ans
    list<voiture> voiture_actuellement_loue();//get liste voiture loue
    list<voiture> tri_voitures_age();
    list<string> get_liste_des_marques();//methode qui aide à trie les voitures selon leur marque
    list<voiture> tri_voiture_categorie();
    list<voiture> liste_voiture_available(date d1,date d2);// pour avoir les voitures disponible dans une periode precise
    bool marque_existe(string marq);//dans wanted car
    float prix_max(string marq);//dans wanted car
    float prix_min(string marq);//dans wanted car
    void sauvegarder_liste_voiture();
};

