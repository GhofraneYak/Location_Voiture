#include "parking.h"
#include <bits/stdc++.h>
using namespace std;

    int parking::nbP=0;

    parking::parking(int c)
    {
        id=nbP;
        nbP++;
        capacite=c;
        nbV=0;
        //date d(1,1,1);
       // voiture v("introuvable","introuvable",0,d);
        //liste_voiture.push_back(v);
    }
    parking::parking(int c,int idd)
    {
        id=idd;
        capacite=c;
        nbV=0;
        nbP++;
    }
    parking::parking(int id,int c,int nb, list<voiture> liste)
    {
        nbP++;
        capacite=c;
        this->id=id;
        nbV=nb;
        list<voiture>::iterator it;
        for(it=liste.begin();it!=liste.end();it++)
        {
            liste_voiture.push_back(*it);
        }

    }

    list<voiture>& parking::get_voitures_de_parking()
    {
            return liste_voiture;
    }


    void parking::affichage_info()
    {
        cout<<"Le parking numero "<<id<<" a comme capacite :"<<capacite<<" et contient les immatricules des voitures suivantes :"<<endl;

        list<voiture>::iterator it;
        if(nbV!=0)
        {for(it=liste_voiture.begin();it!=liste_voiture.end();it++)
        {
            cout<<(*it).get_immatricule()<<endl;

        }}
        if (this->nbV==capacite)
        {
            cout<<"Ce parking est plein"<<endl;
        }
        else
        {
            cout<<"Vous pouvez toujours ajouter "<<(capacite-nbV)<<" voitures"<<endl;
        }

    }

    int parking::get_nbV()
    {
        return(nbV);
    }

    int parking::get_capacite()
    {
        return(capacite);
    }

    void parking::set_capacite(int c)
    {
        capacite=c;
    }

    int parking::get_id()
    {
        return(id);
    }

      void parking::ajout_voiture(voiture V)
    {

            if  (parking_disponible()==false)
            {
                cout<<"Le parking est plein"<<endl;
            }
            else
            {
                liste_voiture.push_back(V);
                nbV++;
            }


    }

    bool parking::parking_disponible()
    {

        return(capacite>nbV);
    }

    bool parking::voiture_est_dans_ce_parking(voiture V)
    {

            list<voiture>::iterator l;
            for(l=liste_voiture.begin();l!=liste_voiture.end();l++)
            {
                if((*l)==V)
                    return(true);
            }
            return(false);
    }

   float parking::moy_prix()
   {
       int S=0;
       list<voiture>::iterator it;
       for(it=liste_voiture.begin();it!=liste_voiture.end();it++)
       {
           S+=((*it).get_prix());
       }
       return(S/nbV);
   }

   void parking::delete_voiture(voiture v)
   {
       bool voiture_exist=false;
       list<voiture>::iterator it;
       for(it=liste_voiture.begin();it!=liste_voiture.end();it++)
       {
            if (    ((*it).get_immatricule())==(v.get_immatricule())  )
            {
                liste_voiture.erase(it);
                nbV--;
                voiture_exist=true;
            }
       }
       if (voiture_exist==false)
           cout<<"voiture n est pas deja dans le parking";
   }

   void parking::vider_le_parking()
   {    string test;

       cout<<"Merci de confirmer le vidage du parking\n-> ecrire Oui pour confirmer :";
       cin>>test;
       if (test=="Oui")
       {
            list<voiture>::iterator it;
            for(it=liste_voiture.begin();it!=liste_voiture.end();it++)
            {
                liste_voiture.erase(it);
            }
           nbV=0;
        }
        else
            cout<<"l action sera annulee";
   }
    parking ::~parking(){}
