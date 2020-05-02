#include<iostream>
#include"agence.cpp"

using namespace std;

int main(){
    
    time_t now = time(0);


    tm *ltm = localtime(&now);
    int a,m,j;
    a=1900 + ltm->tm_year;
    m=1 + ltm->tm_mon;
    j=ltm->tm_mday;
    date date_auj(j,m,a);
    
    agence ag(date_auj);

    int x,y;
    while(y==0)
    {
        // menu0
        cout<< "Bienvenu !"<< '\n'<< "Taper"<< '\n'<< "1: si vous etes un nouveau utilisateur"<< '\n'<< "2:Si vous avez deja utilisé cette app"<< endl;
        cin>>x;
        if (x==1)
        {
            while ((y!=0)
            cout<< "Tapez : "<< '\n'<< "1: Creer un Parking"<< '\n'<< "2: Ajouter une voiture"<<'\n'<< "0: Sortir" ;
            cin>>y;
            switch (y)
            {
            case 1:
                parking p=ag.nouveau_parking();
                break;
            case 2:
                if (ag.agence_vide_de_parking())
                    {cout<< "Vous devez creer d'abord un parking";
                     break;}
                else
                    {Voiture v=ag.nouvelle_voiture();
                     break;}
            }
        }
        if (x==2)
        {
            while (y!=0)
            {
                 cout << "Taper : "<< '\n' << "1: vehicule le plus ancien" << '\n' << "2:Le véhicule ayant le plus été loué"<< '\n'
                << "3:Les voitures ayant un âge entre 2 et 3 ans" << '\n' << "4: la liste des véhicules actuellement loués" << '\n'
                << "5:La liste des véhicules triés selon la catégorie"<< '\n'<< "6:La liste des véhicules triés selon l'âge"<<'\n'
                <<"7: la liste des clients n'ayant pas loué de véhicules depuis plus de 6 mois"<< '\n'
                << "15: Afficher info d'un parking"<< '\n'
                << "8: la moyenne de prix des véhicules d'un parking"<< '\n'<< "9:Grouper les véhicules de 2 parking dans un troisième parking"<<'\n'
                << "10:Vider un parking de ses véhicules en les distribuant à 2 autres parkings en fonction de leurs catégories"<<'\n'
                << "11: Creer un contrat" << '\n'<< "12: Ajouter une voiture"<<'\n'<< "13: Pour Ajouter un nouveau client" <<'\n'<< "14: Nouveau parking"<< '\n'
                <<"0: Retour menu" <<endl;
                cin>>y;
                switch(y)
                {
                    case 1:
                        voiture v=ag.la_voiture_plus_ancienne();
                        cout<< v;
                        break;
                    case 2:
                        voiture v=ag.la_voiture_plus_loue();
                        cout<< v;
                        break;
                    case 3:
                        list<voiture> L =ag.voitures_2_3();
                        cout<< L;
                        break;
                     case 4:
                        list<voiture> L=ag.voiture_actuellement_loue();
                        cout<< L;
                        break;
                    case 5:
                        list<client> L=ag.client_6_mois();
                        cout<< L;
                        break;
                    case 6:
                        list<voiture> L=ag.tri_voiture_categorie();
                        cout<<L;
                        break;
                    case 7:
                        list<voiture> L=ag.tri_voitures_age();
                        cout<<L;
                        break;
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
                        break;
                    case 9:
                        int a,b,c;
                        cout<< "Entrer l'id des 3 parkings"<< endl;
                        cin>>a>>b>>c;
                        ag.grouper_dans_un_parking(ag.ce_parking(a),ag.ce_parking(b) , ag.ce_parking(c));
                        break;
                    case 10:
                        int a,b,c;
                        cout<< "Entrer l'id des 3 parkings"<< endl;
                        cin>>a>>b>>c;
                        ag.vider_selon_categories(ag.ce_parking(a),ag.ce_parking(b),ag.ce_parking(c));
                        break;
                    case 11:
                        ag.creer_contrat();
                        break;
                    case 12:
                        Voiture v=ag.nouvelle_voiture();
                        break;
                    case 13:
                        string nom;
                        long id;
                        date date_auj;
                        cout<< "Entrer  nom id date_auj ";
                        cin>>nom>>id>>date_auj;
                        ag.ajouter_client();
                        break;
                    case 14:
                        int x;
                        cout<< "Entrer la capacitee du parking";
                        cin>>x;
                        parking p(x);
                        break;
                    case 15:
                        int x;
                        cout<< "Entrer l'id du parking pour voir tous ses infos";
                        cin>>x;
                        iterator it;
                        for(it=ag.liste_parking.begin();it!=ag.liste_parking.end();it++)
                        {
                            if ((*it).get_id()==x)
                                (*it).affichage_info();
                        }
                        break;

                }
            }

        }
    }

}
