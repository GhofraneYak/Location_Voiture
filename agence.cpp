
#include <iostream>
#include <list>
#include "agence.h"
using namespace std;




    agence::agence(date d_auj)
        {
            date_auj=d_auj;
            lire_fichier_park();
            lire_fichier_cl();
            lire_fichier_voiture();
        }

        //********************** Méthodes des clients **************************//
    void agence::lire_fichier_cl()
        {
            //création du fichier au cas où il n'existe pas
            freopen("fichier_client.txt","a+", stdout);
            fclose;
            //Ouverture du fichier en mode lecture
            freopen("fichier_client.txt", "r", stdin);
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
            fclose;
        }

        //Sauvegarder les données des clients dans le fichier
    void sauvegarder_client(list<client> l)
        {
            freopen("fichier_client.txt", "a"+, stdout);
            list<client>::iterator it;
            for (it=l.begin();it!=l.end();++it)
            {
                cout<<(*it).getnom<<(*it).getid<<((*it).getdate).getjour<<((*it).getdate).getmois<<((*it).getdate).getannee<<endl;
            }
            fclose;
        }

    //Vérifier si un client existe ou pas
    bool agence::client_existe(long id)
        {
            list<client>::iterator it;
            for (it=liste_client.begin();it!=liste_client.end();++it)
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
                if (    (   date_auj - ((*it).getdate())    ) >=6   )
                    l.emplace(liste_client.end(), (*it).getnom, (*it).getid,(*it).getdate );
            }

            return l;
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
                int x,y,z;
                cin>>x>>y>>z;
                date date_de_prise(x,y,z);
                cout<<"Entrer la date de remise de la voiture";
                cin>>x>>y>>z;
                date date_de_remise(x,y,z);
                list<voiture>::iterator i;
                L=liste_voiture_available(date_de_prise,date_de_remise);

                for(i=L.begin();i!=L.end();i++)
                {
                    if (((*i).get_marque()==marq)&&((*i).get_prix<pmax))
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
            if (!(client_existe(y)))
                ajouter_client(nom,y,date_auj);
            else
            {
                list<client>::iterator c;
                for(c=liste_client.begin();c!=liste_client.end();c++)
                {
                    if ((*c).getid()==y)
                        (*c).setdate(date_auj); //da : date d'aujourd'hui
                }
                
            }
            // voiture
           Voiture v = wanted_car();

        }



 /**************************Liste voiture methodes*******************/

void agence::lire_fichier_voiture()
{
    //Au cas où le fichier n'existe pas déjà
    FILE* fichier1 = fopen("liste_voitures.txt","a+");
    int fclose(FILE* fichier1);
    
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
        voiture v(immatricule, marque,prix_par_jour,date_de_creation,age, est_loue, nbr_de_fois_loue,date_de_prise ,date_de_remise,id_client);
        if (date_de_remise<date_auj)
            update_v_disponible(v);
        liste_voiture.push_back(v);
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
    (*p).ajout_voiture(v);

}

voiture agence::get_voiture(string immatricule)
{
     string voiture_immatricule;
     for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
     {
        voiture_immatricule=(*v).get_immatricule();
        if(voiture_immatricule==immatricule)
        {
            return (*v);
        }
     }
     cout<<"voiture non trouvable";
     voiture p("nontrouvable","nontrouvable",0);
     return p;
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
    (*p).delete_voiture(v);
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
    (*p).ajout_voiture(v);
}

voiture agence::la_voiture_plus_ancienne()
{
    int m;
    list<voiture>::iterator voiture_ancienne;
    for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
    {
        if((*v).get_age()>m)
        {
            m=(*v).get_age();
            voiture_ancienne=v;
        }
    }
    cout<<"la voiture la plus ancienne est :\n"<<*voiture_ancienne;
    return *voiture_ancienne;
}

voiture agence::la_voiture_plus_loue()
{
   int m;
   m=0;
   list<voiture>::iterator voiture_plus_loue;
   for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
   {
       if((*v).get_nbr_de_fois_loue()>m)
       {
           m=(*v).get_nbr_de_fois_loue();
           voiture_plus_loue=v;
       }
   }
   cout<<"la voiture la plus loue ("<<m<<" fois) est "<<*voiture_plus_loue;
   return *voiture_plus_loue;
}

list<voiture> agence::voitures_2_3()
{
    list<voiture> voitures_2_3;
    for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
    {
        if(((*v).get_age()==2)||((*v).get_age()==3))
            voitures_2_3.push_back(*v);
    }
    cout<<"les voitures dont leurs age entre 2 et 3 ans sont: "<<endl;
    for(list<voiture>::iterator v=voitures_2_3.begin();v!=voitures_2_3.end();v++)
    {
        cout<<*v<<endl;
    }
    return voitures_2_3;
}

list<voiture> agence::voiture_actuellement_loue()
{
    list<voiture> voitures_non_disponible;
    for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
    {
        if((*v).voiture_loue())
            voitures_non_disponible.push_back(*v);
    }
    cout<<"les voitures non disponibles à l'instant sont: "<<endl;
    for(list<voiture>::iterator v=voitures_non_disponible.begin();v!=voitures_non_disponible.end();v++)
    {
        cout<<*v<<endl;
    }
    return voitures_non_disponible;
}

list<voiture> agence::tri_voitures_age()
{
    list<voiture> voiture_tri_par_age;
    int age_max=la_voiture_plus_ancienne().get_age();
    for(int i=0;i<=age_max;i++)
    {
        for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
        {
            if((*v).get_age()==i)
                voiture_tri_par_age.push_back(*v);
        }
    }
    return voiture_tri_par_age;

}

list<string> agence::liste_des_marque()
{
    list<string> liste_marque;
    for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
    {

        if (find(liste_marque.begin(), liste_marque.end(), (*v).get_marque())== liste_marque.end())
            liste_marque.push_back((*v).get_marque());
    }
    return liste_marque;
}

list<voiture> agence::tri_voiture_categorie()
{
    list<voiture> voiture_par_categorie;
    list<string> liste_marque;
    liste_marque=liste_des_marque();
    for(list<string>::iterator m=liste_marque.begin();m!=liste_marque.end();m++)
    {
        for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
        {
            if(*m==(*v).get_marque())
                voiture_par_categorie.push_back(*v);
        }
    }
    return voiture_par_categorie;
}

list<voiture> agence::liste_voiture_available(date d1,date d2)
{
    long client_cin;
    list<voiture> voitures_disponibles;
    for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
    {
       client_cin=(*v).getid();
       if (client_cin==0)//voiture non reservé
           voitures_disponibles.push_back(*v);
       else
       {
           date date_p=(*v).get_date_de_prise();
           date date_r=*v.get_date_de_remise();
           if ((d2<date_p)||(date_r<d1))
               voitures_disponibles.push_back(*v);
       }
    }
    return voitures_disponibles;
}


        //********************** Méthodes des parkings **************************//
       

           list<parking> agence::lire_fichier_park()
    {
            //ouverture de fichier
            //création du fichier au cas où il n'existe pas
            freopen("fichier_parking.txt", "a+", stdout);
            fclose;
            //Ouverture du fichier en mode lecture
            freopen("fichier_parking.txt", "r", stdin);
            int nbP;
            cin>>nbP;
            bool test=false;
            int id,capacite,nbV;
            string immatricule;
            list<voiture> liste;

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
            fclose;

    }

    int agence::parking_disponible()
    {
        list<parking>::iterator it;
        for(it=liste_parking.begin();it!=liste_parking.end();it++)
        {
            if(it.parking_disponible())
            {
                return(it.get_id());
            }
        }
    }

    void agence::sauvegarder_parking(list l)
    {
        freopen("liste_parking", "a+", stdout);
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
        fclose;

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
                p3.ajout_voiture((*it));
                p1.delete_voiture((*it));
            }
            for(it=liste2.begin();it!=liste2.end();it++)
            {
                p3.ajout_voiture((*it));
                p2.delete_voiture((*it));
            }

        }

    }


      int agence::recherche_parking(Voiture v)
    {
        list<parking>::iterator it;
        list<voiture>::iterator l;
        for(it=liste_parking.begin();it!=liste_parking.end();it++)
        {
            list<voiture> liste=(*it).get_voiture_de_parking();
            for(l=liste.begin();l!=liste.end();l++)
            {
                if ((*l)==v)
                {
                    return((*it).get_id());
                }
            }
        }
        cout<<"Cette voiture n'est dans aucun parking"<<endl;
    }



     void agence::vider_selon_categories(parking p1, parking p2, parking p3)
    {


        int nb2=p2.get_nbV();
        int nb3=p3.get_nbV();
        int c2=p2.get_capacite();
        int c3=p3.get_capacite();
        list<string> listem=get_liste_des_marques();
        list<string>::iterator m;
        list<parking>::iterator p;
        for(m=listem.begin();m!=listem.end();m++)
        {
            int nb=0;
            for(p=liste1.begin();v!=liste1.end();p++)
            {
                if ((*v).get_marque()==m)
                {
                    nb++;
                }
            }
            if (nb=<(c2-nb2))
            {
                for(p=liste1.begin();v!=liste1.end();p++)
                {
                    if ((*v).get_marque()==m)
                    {
                        p2.ajout_voiture((*v));
                        p1.delete_voiture((*v));
                    }
                }

            }

            else if (nb=<(c3-nb3))
            {
                for(p=liste1.begin();v!=liste1.end();p++)
                {
                    if ((*v).get_marque()==m)
                    {
                        p3.ajout_voiture((*v));
                        p1.delete_voiture((*v));
                    }
                }
            }

            else
            {
                cout<<"Vous ne pouvez pas réaliser cette opération"<<endl;
            }

        }

    }
                    
                    
  

