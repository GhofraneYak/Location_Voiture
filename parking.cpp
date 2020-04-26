
#include "parking.h";
using namespace std;

    parking::parking(int c)
    {
        id++;
        nbP++;
        capacite=c;
    }

    parking::parking(int id,int c, list<Voiture> liste)
    {
        capacite=c;
        this.id=id;
        list<Voiture>::iterator it;
        for(it=liste.begin();it!=liste.end();it++)
        {
            liste_voiture.insert(liste_voiture.size()+1,1,*it);
        }

    }

    list<Voiture> parking::get_voitures_de_parking()
    {
        list<Voiture>::iterator it;
        for(it=liste_voiture.begin();it!=liste_voiture.end();it++)
        {
            return((*it).get_matricule());
        }
    }



    void parking::affichage_info()

    {
        cout<<"Le parking numéro"<<id<<"a comme capacité:"<<capacite<<" et contient les immatricules des voitures suivantes :"<<endl;
        iterator it;
        int S=0;
        list<Voiture>::iterator it;
        for(it=liste_voiture.begin();it!=liste_voiture.end();it++)
        {
            cout<<it.get_matricule()<<endl;
            S++;
        }
        if (S==capacite)
        {
            cout<<"Ce parking est plein"<<endl;
        }
        else
        {
            cout<<"Vous pouvez toujours ajouter "<<(capacite-S)<<"voitures"<<endl;
        }
    }

    int parking::get_capacite()
    {
        return(capacite);
    }

    void parking::set_capacite(int c )
    {
        capacite=c;
    }

    int parking::get_id()
    {
        return(id);
    }
