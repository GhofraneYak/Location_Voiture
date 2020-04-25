
#include <iostream>
#include <list>
#include "agence.h"
using namespace std;




        agence::agence()
        {
            liste_parking=lire_fichier_park();
            liste_client=lire_fichier_cl();
        }

        list<parking> lire_fichier_park()
        {
            //fichier_parking.txt
        }




        //********************** Méthodes des clients **************************//
        list<client> agence::lire_fichier_cl()
        {
            //ouverture de fichier
            //création du fichier au cas où il n'existe pas
            freopen( string "fichier_client.txt", string a+, stdout);
            fclose();
            //Ouverture du fichier en mode lecture
            freopen( string "fichier_client.txt", string r, stdin);
            int nb;
            cin>>nb;

            list<client> liste_cl;
            string nom;
            long ident;
            int j,m,a;

            for (int i=0;i<nb;i++)
            {
                cin>>nom>>ident>>j>>m>>a;
                date da(j,m,a);

                liste_cl.emplace(liste_cl.end(),nom,ident,da);
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
            iterator it;
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
            iterator it;
            for (it=liste_client.begin();it!=liste_client.end();++it)
            {
                if (    (((*it).getdate()).dernier_loc_client()) >=6   )
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




};
