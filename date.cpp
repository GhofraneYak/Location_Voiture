
#include <bits/stdc++.h>
#include "date.h"

using namespace std;

        date::date(int j, int m, int a)
        {
            annee=a;
            mois=m;
            jour=j;
        }


        int date::getjour()
        {
            return jour;
        }
        int date::getmois()
        {
            return mois;
        }
        int date::getannee()
        {
            return annee;
        }




        //Vérifier si la date entrée est valide
        bool date::date_valide(int annee, int mois, int jour)
        {
            if (annee <0)
                return false;

            if ((mois) >12 || (mois <1))
                return false;

            if ((jour >31) || (jour <1))
                return false;

            if ((jour ==31) && ((mois==4) || (mois==6) || (mois==9) || (mois==11)) )
                return false;

            if ((jour==29) && (mois==2) && (  ( (annee%4)!=0 ) || ( ((annee%100)==0) && ((annee%400!=0)) )  )   )
                return false;
            if ((jour>29) && (mois==2))
                return false;

            return true;
        }


        //Affectation
        date& date::operator=(const date& d)
        {
            annee = d.annee;
            mois = d.mois;
            jour = d.jour;
            return *this;
        }


        //Retourn l'age d'une voiture en année, APPELEE A PARTIR D'UN OBJET QUELCONQUE
        int date::age_voiture(date auj, date date_v)
        {
            return ((soustraction(auj,date_v)).annee);
        }


        int date::dernier_loc_client(date date_c)
        {
            return ((soustraction(*this,date_c)).mois + ((soustraction(*this,date_c)).annee)*12);
        }


        date date::soustraction(const date& d1, const date& d2)
        //OR date& soustraction(const date& d1, const date& d2)
        {
            date p(0,0,0);
            int x,y,z;
            x=d1.annee-d2.annee;
            y=d1.mois-d2.mois;
            z=d1.jour-d2.jour;

            if ((y>0) && (z<0))
            {
                if (    (d2.mois==4) || (d2.mois==6) || (d2.mois==9) || (d2.mois==11)   )
                    z=z+31;
                else
                    z=z+30;
                y=y-1;
            }
            else
            {
                if ((y<0) && (z>0))
                {
                    x=x-1;
                    y=y+12;
                }
                else
                {
                    if ((y<0) && (x<0))
                    {
                        if (    (d2.mois==4) || (d2.mois==6) || (d2.mois==9) || (d2.mois==11)   )
                            z=z+31;
                        else z=z+30;
                        y=y-1;
                        x=x-1;
                        y=y+12;
                    }
                }
            }


            p.annee=x;
            p.mois=y;
            p.jour=z;

            return p;
        }



        //Comparaison date remise et date aujourd'hui
        bool date::operator>(date& d)
        {


            if (annee>d.annee)
                return true;
            else
            {
                if ( (annee==d.annee) && (mois>d.mois) )
                    return true;
                else
                {
                    if ( (mois==d.mois) && (jour>d.jour) )
                        return true;

                }

            }
            return false;

        }

        bool date::operator<(date& d)
        {
            return !((*this)>d);
        }


             bool date::est_bissextile()
            {
                  if ( ( (annee%4)!=0 ) || ( ((annee%100)==0) && ((annee%400!=0)) ) )
                    return false;
                  else return true;
            }
            //Date de retour de la voiture
            date& date::date_remise(int nb_jr)
            {
                int j,m,a;
                j=this->jour+nb_jr;
                m=this->mois;
                a=this->annee;

                int x,y;
                bool ok=false;

                do
                {
                    if ( (j>30) && ( (m==4) || (m==6) || (m==9) || (m==11) ) )
                    {
                        j=j-30;
                        m=m+1;
                    }//ici
                    else
                    {
                        if ( (j>29) && ( m==2 ) && ((*this).est_bissextile()) )
                        {
                            j=j-29;
                            m=m+1;
                        }
                        else
                        {
                            if ( (j>28) && ( m==2 ) && ((!(*this).est_bissextile()) ) )
                            {
                                j=j-28;
                                m=m+1;
                            }
                            else
                            {
                                j=j-31;
                                m=m+1;
                            }
                        }
                    }
                    x=m/12;
                    y=m%12;

                    m=y;
                    a=a+x;
                    if ( (j>=30) && ( (m==4) || (m==6) || (m==9) || (m==11) ) )
                        ok=true;
                    if ( (j<=29) && ( m==2 ) && ((*this).est_bissextile()) )
                        ok=true;
                    if ( (j<=28) && ( m==2 ) && ((!(*this).est_bissextile()) ) )
                        ok=true;

                }
                while (ok=false);
                //test
            }


        bool date::operator==(const date& d)
        {
            return (    ((*this).annee==d.annee) && ((*this).mois==d.mois) && ((*this).jour==d.jour)    );
        }




