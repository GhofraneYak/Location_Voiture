
#include <iostream>
#include <list>
#include "agence.h"
using namespace std;




    agence::agence()
        {
            lire_fichier_park(liste_parking);
            lire_fichier_cl();
        }

        //********************** Méthodes des clients **************************//
    void agence::lire_fichier_cl()
        {
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
            lis<client>::iterator it;
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


        //********************** Méthodes update des voitures **************************//

    void update_age_voiture(voiture v)
        {
            date d=v.get_date();
            int age;
            age=d.age_voiture(date_auj,d);
            v.set_age(age);
        }

    bool date::voiture_available(voiture v,date date_prise)
        {
            if ((v.date_remise>date_prise))
                        return false;
            else return true;
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



 /**************************Liste voiture methodes*******************/

void agence::lire_fichier_voiture()
{
    FILE* fichier = fopen("liste_voitures.txt","r+");

    int nbr;
    string immatricule;
    string marque;
    float prix_par_jour;
    date date_de_creation;
    int age;
    bool est_loue;
    int nbr_de_fois_loue;
    date date_de_prise;
    date date_de_remise;
    long id_client;
    cin>>nbr;
    for(int i=0;i<nbr;i++)
    {
        cin>>immatricule>>marque>>prix_par_jour>>date_de_creation>>age>>est_loue>>nbr_de_fois_loue>>date_de_prise>>date_de_remise>>id_client;
        liste_voiture.push_back(voiture(immatricule, marque,prix_par_jour,date_de_creation,age, est_loue, nbr_de_fois_loue,date_de_prise ,date_de_remise,id_client));
    }
    int fclose(FILE* fichier);
}

voiture agence::nouvelle_voiture()
{
    string immatricule;
    string marque;
    float prix_par_jour;
    int parking_id;
//creation de nouveau objet voiture
    cout<<"immatricule: ";
    cin>>immatricule;
    cout<<"marque: ";
    cin>>marque;
    cout<<"prix par jour de location: ";
    cin>>prix_par_jour;
    voiture v(immatricule,marque,prix_par_jour);
    liste_voiture.push_back(v);
//ajout voiture dans le parking
    parking_id=parking_disponible();
    list<parking>::iterator p =liste_parking.begin();
    advance(p, parking_id);
    *p.ajout_voiture(v);

}

voiture agence::get_voiture(string immatricule)
{
     string voiture_immatricule;
     for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
     {
        voiture_immatricule=(*v).get_immatricule();
        if(voiture_immatricule==immatricule)
        {
            return *v;
        }
     }
     cout<<"voiture non trouvable";
     return voiture("nontrouvable","nontrouvable",0);
}

void agence::location_voiture(voiture& v,long id_client,date date_de_prise,date date_de_remise)//appeler dans creation contrat
{
    v.set_date_de_prise(date_de_prise);
    v.set_date_de_remise(date_de_remise);
    v.set_id_client(id_client);
    v.set_nbr_de_fois_loue();
}

void update_v_non_disponible(voiture& v)
{
    int parking_id;
    v.set_voiture_loue();
    parking_id=recherche_parking(const voiture& v);
    list<parking>::iterator p =liste_parking.begin();
    advance(p, parking_id);
    *p.delete_voiture(v);
}

void agence::update_v_disponible(voiture& v)
{
    int parking_id;
    date d(1,1,1);
    //voiture disponible
    v.set_id_client(0);
    v.set_date_de_prise(d);
    v.set_date_de_remise(d);
    v.set_voiture_loue();
    //ajout voiture dans un parking
    parking_id=parking_disponible();
    list<parking>::iterator p =liste_parking.begin();
    advance(p, parking_id);
    *p.ajout_voiture(v);
}



        //********************** Méthodes des parkings **************************//
       

           list<parking> agence::lire_fichier_park()
    {
            //ouverture de fichier
            //création du fichier au cas où il n'existe pas
            freopen( string "fichier_parking.txt, string a+, stdout);
            fclose();
            //Ouverture du fichier en mode lecture
            freopen( string "fichier_parking.txt", string r, stdin);
            cin>>nbP;
            bool test=false;
            int id,capacite,nbV;
            string immatricule;
            list<Voiture> liste;

            while (test==false)
            {
                cin>>id>>capacite>>nbV;
                for(int i=0;i<nbV;i++)
                {
                    cin>>immatricule;
                    liste.push_back(get_voiture(immatricule));
                }
                liste_parking.emplace(liste_parking.end(),id,capacite,nbV,liste);


                if (immatricule=="")   //fin du fichier
                {
                    test=true;
                }

            }
            fclose();

    }

    int agence::parking_disponible()
    {
        list<parking>::iterator it;
        for(it=liste_parking.begin();it!=liste_parking.end;it++)
        {
            if(it.parking_disponible())
            {
                return(it.get_id());
            }
        }
    }

    void agence::sauvegarder_parking(string nomF,list l)
    {
        freopen(string nom_fichier, string a+, stdout);
        cout<<parking::get_nbV();
        list<parking>::iterator it;
        for(it=l.begin();it!=l.end();it++)
        {
            cout<<(*it).get_id()<<endl;
            cout<<(*it).get_capacite()<<endl;
            cout<<(*it).get_nbV()<<endl;
            cout<<(*it).get_voitures_de_parking()<<endl;

        }
        cout<<""<<endl;
        fclose();

    }

    void agence::grouper_dans_un_parking(parking p1, parking p2, parking p3)
    {

        int nb1=p1.get_nbV();
        int nb2=p2.get_nbV();
        int nb3=p3.get_nbV();
        int c=p3.get_capacite();
        list<voiture> liste1=p1.get_voitures_de_parking();
        list<voiture> liste2=p2.get_voitures_de_parking();
        list<voiture> liste3=p3.get_voitures_de_parking();

            //véfification !
        if ((nb1+nb2)>(c-nb3))
        {
            cout<<"Vous ne pouvez pas faire cette opération"<<endl;
        }
        else
        {
            liste<voiture>::iterator it;
            for(it=liste1.begin();it!=liste1.end();it++)
            {
                liste3.push_back((*it));
                liste1.erase((*it));

            }
            for(it=liste2.begin();it!=liste2.end();it++)
            {
                liste3.push_back((*it));
                liste2.erase((*it));
            }

        }

    }

    void agence::vider_selon_categories(parking p1, parking p2, parking p3)
    {

    
         // parcours de liste des catégories

    }
                    
                    
  

