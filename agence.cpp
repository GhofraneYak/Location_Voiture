
#include <iostream>
#include <list>
#include "agence.h"
using namespace std;




    agence::agence(date d_auj)
        {
            date_auj=d_auj;

            lire_fichier_cl();
            lire_fichier_voiture();
            lire_fichier_park();
            update_voiture();
        }

        list<voiture> agence::get_liste_voiture()
        {
            return liste_voiture;
        }

        list<client> agence::get_liste_client()
        {
            return liste_client;
        }
    //**********************Verifier l'agence contient des donnée dans les fichier***************//
    bool agence::agence_vide_de_parking()
    {
        return (liste_parking.size() == 0);
    }
    bool agence::agence_vide_de_voiture()
    {
        return (liste_voiture.size() == 0 );
    }
        //********************** Méthodes des clients **************************//
    void agence::lire_fichier_cl()
        {
            //création du fichier au cas où il n'existe pas
            ofstream f;
            f.open ("fichier_client.txt", fstream::app);
            f.close();
            //verifier si le fichier est vide et l'ouverture  en mode lecture
            fstream k;
            k.open ("fichier_client.txt", fstream::in);
            int nb;
            int line;
            if( !( k>> line ))
                nb=0;
            else
                nb=line;
            string nom;
            long ident;
            int j,m,a;
            int nbr_loc;
            for (int i=0;i<nb;i++)
            {
                k>>nom>>ident>>j>>m>>a>>nbr_loc;
                date da(j,m,a);
                client c(nom,ident,da,nbr_loc);
                liste_client.push_back(c);
            }
            k.close();
        }

        //Sauvegarder les données des clients dans le fichier
    void agence::sauvegarder_client()
        {
            freopen("fichier_client.txt", "w", stdout);
            cout<<liste_client.size()<<"\n";//1ere ligne contient combient de client on a
            list<client>::iterator it;
            for (it=liste_client.begin();it!=liste_client.end();++it)
            {
                cout<<(*it).getnom()<<" "<<(*it).getid()<<" "<<((*it).getdate()).getjour()<<" "<<((*it).getdate()).getmois()<<" "<<((*it).getdate()).getannee()<<" "<<(*it).get_nbr_loc()<<endl;
            }
            fclose;
        }


        void agence::afficher_client()
        {
            if (    liste_client.size()!=0     )
            {

                bool test=false;
                cout<<"Entrer l'id du client que vous voulez afficher"<<endl;
                do
                {
                    int x;
                    cin>>x;
                    cout<<endl;
                    if (client_existe(x))
                    {
                        test=true;
                        for (list<client>::iterator it=liste_client.begin();it!=liste_client.end();++it)
                        {
                            if (    (*it).getid()==x  )
                                cout<<(*it);
                        }
                    }
                    else
                        cout<<"Ce client n'existe pas, veuillez entrer un autre id"<<endl;


                }while (test==false);

            }
            else
                cout<<"Vous n'avez aucun client";

        }

        void agence::afficher_tous_les_client()
        {
            if (    liste_client.size()!=0     )
            {
                for (list<client>::iterator it=liste_client.begin();it!=liste_client.end();++it)
                {
                    cout<<(*it);
                }
            }
            else
                cout<<endl<<"Vous n'avez aucun client pour le moment"<<endl;
        }

    //Vérifier si un client existe ou pas
    bool agence::client_existe(long id)
        {
            list<client>::iterator it;
            for (it=liste_client.begin();it!=liste_client.end();++it)
            {
                if ((*it).getid()==id)
                    return true;
            }
            return false;
        }

    //Ajouter un client
    void agence::ajouter_client(string nom, long id)
        {
            client c(nom,id,date_auj);
            liste_client.push_back(c);
            cout<<"Client ajoute avec succes"<<endl;
        }

    //La liste des clients dont la date de leur dernière location dépasse 6mois
    void agence::client_6_mois()
        {
            list<client> l;
            //for (i in client)
            list<client>::iterator it;
            if (    liste_client.size() !=0     )
            {
                for (it=liste_client.begin();it!=liste_client.end();++it)
                {
                    if (      date_auj.dernier_loc_client((*it).getdate()    ) >=6   )
                        {
                            client c(   (*it).getnom(), (*it).getid(),(*it).getdate(), (*it).get_nbr_loc()  );
                            l.push_back(c);
                        }
                }

                //Affichage de la liste
                cout<<"Les clients qui ont depasse 6 mois depuis leur derniere location  : "<<endl;
                for (it=l.begin();it!=l.end();++it)
                {
                    cout<<(*it);
                }

            }
            else
                cout<<endl<<"Vous n'avez aucun client"<<endl;

        }


    void agence::meilleur_client()
        {
            int loc_max=0;
            list<client>::iterator it;
            long idd;
            string nom;
            date date_cre;
            if (liste_client.size()!=0)
            {
                for (it=liste_client.begin();it!=liste_client.end();++it)
                {
                    if (    (*it).get_nbr_loc() >= loc_max   )
                    {
                        loc_max=(*it).get_nbr_loc();
                        //affect(cl,(*it));
                        idd=(*it).getid();
                        nom=(*it).getnom();
                        date_cre=(*it).getdate();
                    }
                }


                cout<<"Le meilleur client est :  "<<endl;
                cout<<"Nom:  "<<nom<<endl;
                cout<<"D'id : "<<idd<<endl;
                cout<<"Nbre de locations est :  "<<loc_max<<endl;

            }
            else
                cout<<"Vous ne disposez d'aucun client pour le moment"<<endl;
        }


        void agence::effacer_client_date_superieure()
        {
            int azerty;
            cout<<"Entrer le nombre d'annee q'un client ne doit pas depasser"<<endl;
            cin>>azerty;
            list<client>::iterator it;
            list<client> prov;
            for(it=liste_client.begin();it!=liste_client.end();++it)
            {
                prov.push_back(*it);
            }

                liste_client.clear();

            for (it=prov.begin();it!=prov.end();++it)
            {
                if (    (date::age_voiture(date_auj, (*it).getdate())) < azerty    )
                        liste_client.push_back(*it);
            }
        }



        //********************** Création d'un contrat **************************//

        list<voiture>::iterator agence::wanted_car(date date_de_prise,date date_de_remise){

                string test;
                bool test2=false;
                list<voiture>::iterator i;
                list<voiture> L;
                L=liste_voiture_available(date_de_prise,date_de_remise);
                int n;
                do
                {
                    list<voiture> liste_rejete;
                    cout<<"Entrer la marque desiree parmie :";
                    //liste des marques dans l'agence
                    list<string> marque=get_liste_des_marques();
                    for(list<string>::iterator s=marque.begin();s!=marque.end();s++)
                        cout<<(*s)<<" ";
                    string marq;
                    cin>>marq;
                    while(marque_existe(marq)==false)//verifier marque existe
                    {
                        system("cls");
                        cout<<"la marque que vous avez donnee est introuvable priere de saisir de nouveau la marque parmi :";
                        for(list<string>::iterator s=marque.begin();s!=marque.end();s++)
                            cout<<(*s)<<" ";
                        cin>> marq;
                    }
                    cout<<"les prix de location pour "<<marq<<" est entre "<<prix_min(marq)<<" et "<<prix_max(marq);
                    cout<<"\nEntrer le prix qu'il ne faut pas depasser: ";
                    int pmax;
                    cin>>pmax;
                    cout<<"Entrer le prix minimal: ";
                    int pmin;
                    cin>>pmin;

                    for(i=L.begin();i!=L.end();i++)
                    {
                        if (    ((*i).get_marque()==marq )&& ((*i).get_prix()<=pmax) && ((*i).get_prix()>=pmin)  )
                            {
                                test2=true;
                                system("cls");
                                cout<<"voici une voiture qui possede ces caracteristique\n";
                                if (    (*i).get_age() > 15 )
                                {
                                    (*i).set_prix((*i).get_prix()*90/100);
                                }
                                cout<<(*i);
                                cout<<"\voulez vous confirmer votre choix ( ecrire Oui pour confirmer) :";
                                cin>>test;
                                if (test=="Oui")
                                    return(find(liste_voiture.begin(), liste_voiture.end(), (*i)));
                                else
                                    liste_rejete.push_back(*i);
                            }

                    }
                    if(test2==false)
                    {
                        cout<<"il n'y a pas une voiture avec ces caracteristique disponible entre les deux dates que vous donnez";
                        cout<<"\npriere choisir de nouveau les caracteristique \n";
                    }
                    else
                    {
                        cout<<"voulez vous choisir d'apres les voitures que nous avons proposer (ecrire Oui pour confirmer) :";
                        cin>>test;
                        if (test=="Oui")
                        {
                            for(list<voiture>::iterator v=liste_rejete.begin();v!=liste_rejete.end();v++)
                            {
                                cout<<(*v)<<"\n1: confirmer le choix\n2:la voiture suivante\n3changer les caracteristiques";
                                cin>>n;
                                do
                                {
                                    if(n==1)
                                        return(find(liste_voiture.begin(), liste_voiture.end(), (*v)));
                                    else if (n!=2)
                                        cout<<"ecrire 1 ou 2 ou 3";

                                }while((n<=0)&&(n>3));
                                if (n==3)
                                    break;
                            }
                        }
                    }
                }while (true);

          }


        void agence::creer_contrat(){
            //ID contrat
             cout<<"Donner un id pour le contrat: ";
             int id;
             cin>>id;
             // Client
            cout<<"Entrer le nom du client: ";
            string nom;
            cin>>nom;
            cout<<"Entrer la cin du client: ";
            long y;
            cin>>y;
            if (!(client_existe(y)))
                ajouter_client(nom,y);
            else
            {
                list<client>::iterator c;
                for(c=liste_client.begin();c!=liste_client.end();c++)
                {
                    if ((*c).getid()==y)
                    {
                        (*c).setdate(date_auj);
                        (*c).set_nbr_loc();
                    }
                }

            }
            //date
            cout<<"Entrer la date de prise de la voiture : jour mois annee ";//preciser le saisir
            int x,w,z;
            cin>>x>>w>>z;
            date date_de_prise(x,w,z);
            cout<<"Entrer la date de remise de la voiture : jour mois annee ";
            cin>>x>>w>>z;
            date date_de_remise(x,w,z);
            // voiture
           list<voiture>::iterator v = wanted_car(date_de_prise,date_de_remise);
           location_voiture((*v),y,date_de_prise,date_de_remise);
           cout<<"Contract creer avec succes "<<endl;
        }



 /**************************Liste voiture methodes*******************/

void agence::lire_fichier_voiture()
{
    //création du fichier au cas où il n'existe pas
    ofstream f;
    f.open ("fichiervoitures.txt", fstream::app);
    f.close();
    fstream k;
    k.open ("fichiervoitures.txt", fstream::in);
    int nbr;
    int line;
    if( !( k>> line ))
        nbr=0;
    else
        nbr=line;
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
    for(int n=0;n<nbr;n++)
    {
        int a,b,c,d,e,f,g,h,i;
        k>>immatricule>>marque>>prix_par_jour>>a>>b>>c>>age>>est_loue>>nbr_de_fois_loue>>d>>e>>f>>g>>h>>i>>id_client;
        date date_de_creation(a,b,c);
        date date_de_prise(d,e,f);
        date date_de_remise(g,h,i);
        voiture v(immatricule, marque,prix_par_jour,date_de_creation,age, est_loue, nbr_de_fois_loue,date_de_prise ,date_de_remise,id_client);
        v.set_age(date::age_voiture(date_auj,date_de_creation));
        liste_voiture.push_front(v);

    }
    k.close();
}

void agence::update_voiture()
{
    for(list<voiture>::iterator it=liste_voiture.begin();it!=liste_voiture.end();it++)
    {

    if (    ((*it).get_date_de_remise()<date_auj) && ((*it).voiture_loue()==true) )
            update_v_disponible((*it));
        else
        {
            if (    ((*it).get_date_de_prise()<date_auj) && ((*it).get_date_de_remise()>date_auj) && ((*it).voiture_loue()==false)  )
                update_v_non_disponible((*it));
        }


     }
    }

void agence::nouvelle_voiture()
{
    bool test;
    string immatricule;
    string marque;
    float prix_par_jour;
    int parking_id;
//creation de nouveau objet voiture
    cout<<"immatricule: ";
    do{
        cout<<"cette immatricule existe deja\nimmatricule: ";
        test=true;
        cin>>immatricule;
        for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)//verifier l'unicité d'immatricule
        {
            if ((*v).get_immatricule()==immatricule)
                test=false;
        }
      }while(test==false);
    cout<<"marque: ";
    cin>>marque;
    cout<<"Prix par jour de location: ";
    cin>>prix_par_jour;
    voiture v(immatricule,marque,prix_par_jour,date_auj);
    liste_voiture.push_back(v);
//ajout voiture dans le parking
  parking_id=parking_disponible();
    list<parking>::iterator p =liste_parking.begin();
    advance(p, parking_id);
    (*p).ajout_voiture(v);
    cout<<"Operation reussie"<<endl;

}

list<voiture>::iterator agence::get_voiture(string immatricule)
{
     string voiture_immatricule;
     for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
     {
        voiture_immatricule=(*v).get_immatricule();
        if(voiture_immatricule==immatricule)
        {
            return v;
        }
     }
     cout<<"Voiture n'exsite pas";

}


void agence::location_voiture(voiture& v,long id_client,date date_de_prise,date date_de_remise)//appeler dans creation contrat
{
    v.set_date_de_prise(date_de_prise);
    v.set_date_de_remise(date_de_remise);
    v.set_id_client(id_client);
    v.set_nbr_de_fois_loue();
    if(date_de_prise==date_auj)
        update_v_non_disponible(v);
}

void agence::update_v_non_disponible(voiture& v)
{
    int parking_id;
    v.set_voiture_loue();
    parking_id=recherche_parking(v.get_immatricule());
    list<parking>::iterator p;
    p=liste_parking.begin();
    advance(p, parking_id);
    (*p).delete_voiture(v);
}

void agence::update_v_disponible(voiture& v)
{
    int parking_id;
    date d(1,1,1);
    //voiture disponible
    v.set_id_client(-1);
    v.set_date_de_prise(d);
    v.set_date_de_remise(d);
    v.set_voiture_loue();
    //ajout voiture dans un parking
  parking_id=parking_disponible();
    list<parking>::iterator p;
    p=liste_parking.begin();
    advance(p, parking_id);
    (*p).ajout_voiture(v);
}

voiture agence::la_voiture_plus_ancienne()
{
    int m=(*liste_voiture.begin()).get_age();
    list<voiture>::iterator voiture_ancienne;
    for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
    {
        if((*v).get_age()>=m)
        {
            m=(*v).get_age();
            voiture_ancienne=v;
        }
    }

    return *voiture_ancienne;
}

voiture agence::la_voiture_plus_loue()
{
   int m;
   m=0;
   list<voiture>::iterator voiture_plus_loue;
   for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
   {
       if((*v).get_nbr_de_fois_loue()>=m)
       {
           m=(*v).get_nbr_de_fois_loue();
           voiture_plus_loue=v;
       }
   }
   cout<<"La voiture la plus louee  ("<<m<<"  fois) est "<<*voiture_plus_loue;
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
    if(voitures_2_3.size()!=0)
    {
        cout<<"Les voitures d'age entre 2 et 3 ans sont : "<<endl;
        for(list<voiture>::iterator v=voitures_2_3.begin();v!=voitures_2_3.end();v++)
        {
            cout<<*v<<endl;
        }
    }
    else
    {
        cout<<"Il n'y a pas des voitures dont leurs ages est entre 2 et 3ans";
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
    if(voitures_non_disponible.size()==0)
        cout<<"Toutes les voitures sont disponibles";
    else
    {
        cout<<"Les voitures non disponibles pour le moment sont : "<<endl;
        for(list<voiture>::iterator v=voitures_non_disponible.begin();v!=voitures_non_disponible.end();v++)
        {
            cout<<*v<<endl;
        }
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
    cout<<"La liste des voitures triee selon leur age: "<<endl;
    for(list<voiture>::iterator v=voiture_tri_par_age.begin();v!=voiture_tri_par_age.end();v++)
    {
        cout<<*v<<endl;
    }

    return voiture_tri_par_age;

}

list<string> agence::get_liste_des_marques()
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
    liste_marque=get_liste_des_marques();
    for(list<string>::iterator m=liste_marque.begin();m!=liste_marque.end();m++)
    {
        for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
        {
            if(*m==(*v).get_marque())
                voiture_par_categorie.push_back(*v);
        }
    }
    cout<<"La liste des voitures triee selon leur marque: "<<endl;
    for(list<voiture>::iterator v=voiture_par_categorie.begin();v!=voiture_par_categorie.end();v++)
    {
        cout<<*v<<endl;
    }
    return voiture_par_categorie;
}

list<voiture> agence::liste_voiture_available(date d1,date d2)
{
    long client_cin;
    list<voiture> voitures_disponibles;
    for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
    {
       client_cin=(*v).get_id_client();
       if (client_cin==-1)//voiture non reservé
           voitures_disponibles.push_back(*v);
       else
       {
           date date_p=(*v).get_date_de_prise();
           date date_r=(*v).get_date_de_remise();
           if ((d2<date_p)||(date_r<d1))
              voitures_disponibles.push_back(*v);
       }
    }
    return voitures_disponibles;
}

bool agence::marque_existe(string marq)
{
    list<string> liste_marque=get_liste_des_marques();
    for(list<string>::iterator i=liste_marque.begin();i!=liste_marque.end();i++)
    {
        if (marq==(*i))
            return true;
    }
    return false;
}

float agence::prix_max(string marq)
{
    int M=0;
    for(list<voiture>::iterator i=liste_voiture.begin();i!=liste_voiture.end();i++)
    {
        if (marq==(*i).get_marque())
           {
              if(M<(*i).get_prix())
                M=(*i).get_prix();
           }
    }
    return M;
}

float agence::prix_min(string marq)
{
    int m=(*liste_voiture.begin()).get_prix();
    for(list<voiture>::iterator i=liste_voiture.begin();i!=liste_voiture.end();i++)
    {
        if (marq==(*i).get_marque())
           {
              if(m>(*i).get_prix())
                m=(*i).get_prix();
           }
    }
    return m;
}

void agence::set_prix()
{
    bool test=true;
    string immatricule;
    float prix;
    for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
        if ((*v).get_age()>=2)
    {
        if(test==true)
            {
                cout<<"On vous recommande ces voitures puisque leur age depasse 2ans:\n";
                test=false;
            }
        cout<<(*v);
    }
    do{
        test=true;
        cout<<"Entrer l'immatricule de voiture pour change sa prix de location par jour";
        cin>>immatricule;
        for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
        {
            if ((*v).get_immatricule()==immatricule)
                test=false;
        }
      }while(test==true);
    cout<<"Donner le nouveau prix";
    cin>>prix;
    (*get_voiture(immatricule)).set_prix(prix);
}

void agence::supprimer_voiture()
{
    bool test=true;
    string immatricule;
    for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
    if (((*v).get_age()>=5)&&((*v).voiture_loue()==false))
    {
        if(test==true)
            {
                cout<<"On vous recommande ces voitures puisque leur age depasse 5ans:\n";
                test=false;
            }
        cout<<(*v);
    }
    bool test1;
    do{
        cout<<"Entrer l'immatricule de voiture pour supprimer: ";
        test1=true;
        cin>>immatricule;
        for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
        {
            if ((*v).get_immatricule()==immatricule)
                test1=false;
        }
      }while(test1==true);
    //supprimer de parking
    int parking_id=recherche_parking(immatricule);
    list<parking>::iterator p;
    p=liste_parking.begin();
    advance(p, parking_id);
    (*p).delete_voiture((*get_voiture(immatricule)));
     liste_voiture.erase(get_voiture(immatricule));
}

void agence::voiture_info()
{
    string immatricule;
    bool test;
    do{
        test=true;
        cout<<"Entrer l'immatricule de voiture :";
        cin>>immatricule;
        for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
        {
            if ((*v).get_immatricule()==immatricule)
                test=false;
        }
      }while(test==true);
    cout<<((*get_voiture(immatricule)));
    
}

void agence::sauvegarder_liste_voiture()
{
    if (liste_voiture.size()!=0)
    {
        freopen("fichiervoitures.txt", "w", stdout);
        cout<<liste_voiture.size()<<"\n";
        for(list<voiture>::iterator v=liste_voiture.begin();v!=liste_voiture.end();v++)
        {
            (*v).sauvegarder_une_voiture();
        }
        fclose(stdout);
    }

}

        //********************** Méthodes des parkings **************************//


           void agence::lire_fichier_park()
    {
            //ouverture de fichier
            //création du fichier au cas où il n'existe pas
            ofstream f;
            f.open ("fichier_parking.txt", fstream::app);
            f.close();
            fstream k;
            k.open ("fichier_parking.txt", fstream::in);
            int nbP;
            int line;
            if( !( k>> line ))
                nbP=0;
            else
                nbP=line;
            int capacite,nbV;
            string immatricule;
            list<voiture> liste;
            for(int j=0;j<nbP;j++)//j id de parking
            {
                k>>capacite>>nbV;
                for(int i=0;i<nbV;i++)
                {
                    k>>immatricule;
                    liste.push_back((*get_voiture(immatricule)));
                }
                if(nbV!=0)
                {parking p(j,capacite,nbV,liste);
                liste_parking.push_back(p);
                while (liste.empty()==false)//assurer que la liste revient  vide lorsque on a un autre parking
                {
                        liste.pop_front();
                }}
                else
                {
                    parking p(capacite,j);
                    liste_parking.push_back(p);
                }
            }
            k.close();

    }

        list<parking> agence::get_liste_parking()
        {
            return liste_parking;
        }

        void agence::nouveau_parking()
    {
            int c;
            cout<<"Donner la capacite du parking :"<<endl;
            cin>>c;
            parking p(c);
            liste_parking.push_back(p);
            cout<<"Parking ajoute avec succes"<<endl;
    }

    int agence::parking_disponible()
    {
        list<parking>::iterator it;
        for(it=liste_parking.begin();it!=liste_parking.end();it++)
        {
            if((*it).parking_disponible())
            {
                return((*it).get_id());
            }
        }
        cout<<"Tous les parking sont occupes, voulez vous creer un nouveau parking";
        nouveau_parking();
    }

    parking& agence::get_parking(int id)
    {
        list<parking>::iterator p;
        p=liste_parking.begin();
        advance(p, id);
        return (*p);
    }


   void agence::sauvegarder_parking()
    {
        freopen("fichier_parking.txt", "w", stdout);
        cout<<parking::nbP<<"\n";
        if (parking::nbP!=0)
      {
        list<parking>::iterator it;
        for(it=liste_parking.begin();it!=liste_parking.end();it++)
        {
            cout<<(*it).get_capacite()<<" ";
            cout<<(*it).get_nbV()<<" ";
            if((*it).get_nbV()!=0)
            {for(list<voiture>::iterator j=(*it).get_voitures_de_parking().begin();j!=(*it).get_voitures_de_parking().end();j++)
                 cout<<(*j).get_immatricule()<<" ";}
                 cout<<"\n";
        }


      }
        fclose;

    }

    void agence::grouper_dans_un_parking(parking& p1, parking& p2, parking& p3)
    {

        int nb1=p1.get_nbV();
        int nb2=p2.get_nbV();
        int nb3=p3.get_nbV();
        int c=p3.get_capacite();
        list<voiture>& liste1=p1.get_voitures_de_parking();
        list<voiture>& liste2=p2.get_voitures_de_parking();
        list<voiture>& liste3=p3.get_voitures_de_parking();


        if ((nb1+nb2)>(c-nb3))
        {
            cout<<"Vous ne pouvez pas faire cette operation"<<endl;
        }
        else
        {
            list<voiture>::iterator it;
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
        cout<<"Operation reussie"<<endl;

        }

    }


     int agence::recherche_parking(string immatricule)
    {
        list<parking>::iterator it;
        list<voiture>::iterator l;
        for(it=liste_parking.begin();it!=liste_parking.end();it++)
        {
            list<voiture>& liste=(*it).get_voitures_de_parking();
            for(l=liste.begin();l!=liste.end();l++)
            {
                if ((*l).get_immatricule()==immatricule)
                {
                    return((*it).get_id());
                }
            }
        }
        cout<<"Cette voiture n'est dans aucun parking"<<endl;
    }



         void agence::vider_selon_categories(parking& p1, parking& p2, parking& p3)
    {


        int nb2=p2.get_nbV();
        int nb3=p3.get_nbV();
        int c2=p2.get_capacite();
        int c3=p3.get_capacite();
        list<voiture> liste1=p1.get_voitures_de_parking();
        list<string> listem=get_liste_des_marques();
        list<string>::iterator m;
        list<voiture>::iterator v;
        for(m=listem.begin();m!=listem.end();m++)
        {
            int nb=0;
            for(v=liste1.begin();v!=liste1.end();v++)
            {
                if ((*v).get_marque()==(*m))
                {
                    nb++;
                }
            }
            if (nb<=(c2-nb2))
            {
                for(v=liste1.begin();v!=liste1.end();v++)
                {
                    if ((*v).get_marque()==(*m))
                    {
                        p2.ajout_voiture((*v));
                        p1.delete_voiture((*v));
                    }
                }
            }

            else if (nb<=(c3-nb3))
            {
                for(v=liste1.begin();v!=liste1.end();v++)
                {
                    if ((*v).get_marque()==(*m))
                    {
                        p3.ajout_voiture((*v));
                        p1.delete_voiture((*v));
                    }
                }
                cout<<"Operation reussie"<<endl;
            }

            else
            {
                cout<<"Vous ne pouvez pas realiser cette operation"<<endl;
            }
            nb2=p2.get_nbV();//mettre ajour nbr de voitures pour savoir la capacité
            nb3=p3.get_nbV();
        }

    }

 void    agence::changer_parking(string immatricule, parking& p1, parking& p2)
    {

        list<voiture>::iterator it;
        list<voiture> listee=p1.get_voitures_de_parking();


        if(listee.size()!=0)
        {
            if ( recherche_parking(immatricule)==p1.get_id() )

            {
                for(it=listee.begin();it!=listee.end();it++)
                {
                    if ( ((*it).get_immatricule())==immatricule )
                    {
                        p2.ajout_voiture((*it));
                        p1.delete_voiture((*it));
                        cout<<"Operation reussie"<<endl;
                    }
                }
            }
            else
                cout<<"Voiture n'est pas dans ce parking";
        }

    }

    agence::~agence()
    {
        sauvegarder_client();
        sauvegarder_liste_voiture();
        sauvegarder_parking();
    }
