

#include "client.h"
using namespace std;

        client::client(string n, long idd, date d, int nbr=0)
        {
            nom=n;
            id=idd;
            nbr_loc=nbr;
            dernier_date_loc=d;
            
        }


        //Retourne le nom du client
        string client::getnom()
        {
            return nom;
        }


        //Retourne l'id du client
        long client::getid()
        {
            return id;
        }

        //Retourne la dernière date de location du client
        date client::getdate()
        {
            return dernier_date_loc;
        }


        void client::setdate(date d)
        {
            dernier_date_loc=d;
        }

        int client::get_nbr_loc()
        {
            return nbr_loc;
        }

        void client::set_nbr_loc()
        {
            nbr_loc++;
        }
        //ostream& operator<<(ostream& s,const voiture& V)

        ostream& operator<<(ostream& sortie, client& cl)
        {
            sortie<<"Nom:                       "<<cl.nom<<endl;
            sortie<<"Id :                       "<<cl.id<<endl;
            sortie<<"Derniere date de location: "<<(cl.dernier_date_loc).getjour()<<" "<<(cl.dernier_date_loc).getmois()<<(cl.dernier_date_loc).getannee()<<endl;
            sortie<<"Nbre de locations :        "<<cl.nbr_loc<<endl<<endl<<endl;

            return sortie;
        }
