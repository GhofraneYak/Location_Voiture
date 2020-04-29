#include <iostream>
#include"agence.h"
#include"client.h"
#include "voiture.h"
#include"parking.h"
#include"date.h"

using namespace std;


int main(){

    agence ag(date_auj); // date d'aujourdh'ui
    int x ;
    while (x!=0)
    {


        cout << "Entrez un numero : "<< '\n' << "1: vehicule le plus ancien" << '\n' << "2:Le v�hicule ayant le plus �t� lou�"<< '\n'
        << "3:Les voitures ayant un �ge entre 2 et 3 ans" << '\n' << "4: la liste des v�hicules actuellement lou�s" << '\n'
        << "5: la liste des clients n'ayant pas lou� de v�hicules depuis plus de 6 mois"<< '\n'<<"6:La liste des v�hicules tri�s selon la cat�gorie"<< '\n'
        << "7:La liste des v�hicules tri�s selon l'�ge"<<'\n'
        << "8: la moyenne de prix des v�hicules d'un parking"<< '\n'<< "9:Grouper les v�hicules de 2 parking dans un troisi�me parking"<<'\n'
        << "10:Vider un parking de ses v�hicules en les distribuant � 2 autres parkings en fonction de leurs cat�gories"<<'\n'
        << "11: Creer un contrat" << '\n'<< "12: Ajouter une voiture"<<'\n'<< "13: Pour Ajouter un nouveau client" <<'\n'<< "14: Nouveau parking"<< '\n'
        <<"Tapez 0 pour fermer l'app" <<endl;
        cin>> x;
        switch (x)
        {
        case 1:
            voiture v=ag.la_voiture_plus_ancienne();
            cout<< v;
        case 2:
            voiture v=ag.la_voiture_plus_loue();
            cout<< v;
        case 3:
            list<voiture> L =ag.voitures_2_3();
            cout<< L;
         case 4:
            list<voiture> L=ag.voiture_actuellement_loue();
            cout<< L;
        case 5:
            list<client> L=ag.client_6_mois();
            cout<< L;
        case 6:
            list<voiture> L=ag.tri_voiture_categorie();
            cout<<L;
        case 7:
            list<voiture> L=ag.tri_voitures_age();
            cout<<L;
        case 8:
            iterator i;
            int y;
            cout<< "Entrer l'id du parking"<< endl;
            cin>>y;
            for(i=liste_parking.begin();i!=liste_parking.end();i++)
            {
                if ((*i).get_id()==y)
                    cout<< (*i).moy_prix();
                else
                    cout<< "parking not found";
            }

        case 9:
            int a,b,c;
            cout<< "Entrer l'id du parking"<< endl;
            cin>>a;
            cout<< "Entrer l'id du parking"<< endl;
            cin>>b;
            cout<< "Entrer l'id du parking"<< endl;
            cin>>c;
            ag.grouper_dans_un_parking(ag.ce_parking(a),ag.ce_parking(b) , ag.ce_parking(c));
        case 10:
            int a,b,c;
            cout<< "Entrer l'id du parking"<< endl;
            cin>>a;
            cout<< "Entrer l'id du parking"<< endl;
            cin>>b;
            cout<< "Entrer l'id du parking"<< endl;
            cin>>c;
            ag.vider_selon_categories(ag.ce_parking(a),ag.ce_parking(b),ag.ce_parking(c));
        case 11:
            ag.creer_contrat();
        case 12:
            Voiture v=ag.nouvelle_voiture();
        case 13:
            string nom;
            long id;
            date date_auj;
            cout<< "Entrer  nom id date_auj ";
            cin>>nom>>id>>date_auj;
            ag.ajouter_client();
        case 14:
            int x;
            cout<< "Entrer la capacitee du parking";
            cin>>x;
            parking p(x);


        }
    }




}
