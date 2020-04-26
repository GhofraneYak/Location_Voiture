
#include <iostream>
#include <list>
#include "agence.h"
using namespace std;




        agence::agence()
        {
            lire_fichier_park(liste_parking);
            lire_fichier_cl();
        }

        list<parking> lire_fichier_park()
        {
            //fichier_parking.txt
        }




        //********************** Méthodes des clients **************************//
        void agence::lire_fichier_cl()
        {
            //ouverture de fichier
            //création du fichier au cas où il n'existe pas
            freopen( string "fichier_client.txt", string a+, stdout);
            fclose();
            //Ouverture du fichier en mode lecture
            freopen( string "fichier_client.txt", string r, stdin);
            int nb;
            cin>>nb;

            string nom;
            long ident;
            int j,m,a;

            for (int i=0;i<nb;i++)
            {
                cin>>nom>>ident>>j>>m>>a;
                date da(j,m,a);

                liste_client.emplace(liste_client.end(),nom,ident,da);
            }
            fclose();

        }



        //Sauvegarder les données des clients dans le fichier
        void sauvegarder_client(string nom_fichier, list<client> l)
        {
            freopen( string nom_fichier, string a+, stdout);

            iterator it;
            for (it=l.beging();it!=l.end();++it)
            {
                cout<<(*it).getnom<<(*it).getid<<((*it).getdate).getjour<<((*it).getdate).getmois<<((*it).getdate).getannee<<endl;
            }


            fclose();
        }




        //Vérifier si un client existe ou pas
        bool agence::client_existe(long id)
        {
            list<client>::iterator it;
            for (it=liste_client.beging();it!=liste_client.end();++it)
            {
                if ((*it).getid==id)
                    return true;
            }

            return false;
        }



        //Ajouter un client
        void agence::ajouter_client(string nom, long id, date date_auj)
        {
            liste_client.emplace(liste_client.end(),nom,id,date_auj);
        }


        //Saisie des données du client
        void agence::creer_client()
        {
            cout<< "Entrer le nom du client";
            string nom;
            cin>>nom;
                cout<< "Entrer votre id";
                long id;
                cin>>idd;
            if (!(client_existe(id)))
                agence::ajouter_client(nom,id,date_auj);

        }




        //La liste des clients dont la date de leur dernière location dépasse 6mois
        list<client> agence::client_6_mois()
        {
            list<client> l;
            //for (i in client)
            list<client>::iterator it;
            for (it=liste_client.begin();it!=liste_client.end();++it)
            {
                if (    (   date_auj - (((*it).getdate()).dernier_date_loc)    ) >=6   )
                    l.emplace(liste_client.end(), (*it).getnom, (*it).getid,(*it).getdate );
            }

            return l;
        }


        //********************** Méthodes des voitures **************************//

        void update_age_voiture(voiture v)
        {
            date d=v.getdate();
            int age;
            age=d.age_voiture(date_auj,d);
            v.setage(age);
        }

        //********************** Création d'un contrat **************************//

            voiture agence::wanted_car(){
                    
                cout<<"Entrer la marque desirée";
                string marq;
                cin>>marq;
                cout<<"Entrer le prix qu'il ne faut pas depasser";
                int pmax;
                cin>>pmax;
                cout<<"Entrer la date de prise de la voiture";
                cin>>date_de_prise;
                cout<<"Entrer la date de remise de la voiture";
                cin>>date_de_remise;
                list<voiture>::iterator i;
                L=liste_voiture_available(date_de_prise,date_de_remise);

                for(i=L.begin();i!=L.end();i++)
                {
                    if ((*i.categorie==marq)&&((*i).get_prix_par_jour<pmax))
                        return *i ;

                }

        }

        void agence::creer_contrat(){
            //ID contrat
             cout<<"Donner un id pour ce contrat";
             int id;
             cin>>id;
             // Client
            cout<<"Entrer le nom du client";
            string nom;
            cin>>nom;
            cout<<"Entrer la cin du client";
            long y;
            cin>>y;
            if !(client_existe(x))
                ajouter_client(nom,y,date_auj);
            else
            {
                list<client>::iterator c;
                for(c=liste_client.begin();c!=liste_client.end();c++)
                {
                    if ((*c).id==x)
                        (*c).setdate(date_auj); //da : date d'aujourd'hui
                }
                
            }
            // voiture
           Voiture v = wanted_car();

        }






        //********************** Méthodes des parkings **************************//
       

            void agence::ajout_voiture(voiture V,int id)
            {
                bool test;

                list<parking>::iterator it;
                while (it!=liste_parking.end())
                {
                    if (((*it).get_id)!=id)
                    {
                        it++;
                    }
                    if  (it.le_parking_est_disponible())==false)
                    {
                        cout<<"Le parking est plein"<<endl;
                    }
                    else
                    {
                    (it.le_parking_est_disponible()).push_back(V);
                    }
                }


            }

            bool agence::le_parking_est_disponible(int id)
            {
                list<parking>::iterator it;
                while (it!=liste_parking.end())
                {
                    if (((*it).get_id)!=id)
                    {
                        it++;
                    }
                    iterator l;
                    int S=0;
                    for(l=parking::liste_voiture.begin();l!=parking::liste_voiture.end();l++)
                    {
                        S++;
                    }
                return(parking::capacite==S);
            }

            bool agence::voiture_est_dans_ce_parking(voiture V,int id)
            {
                 list<parking>::iterator it;
                while (it!=liste_parking.end())
                {
                    if (((*it).get_id)!=id)
                    {
                        it++;
                    }

                     list<voiture>::iterator l;
                    for(l=parking::liste_voiture.begin();l!=parking::liste_voiture.end();l++)
                    {
                        if((*l)==V)
                            return(true);
                    }
                    return(false);
            }


