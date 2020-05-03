

#include "client.h"
using namespace std;

        client::client(string n, long idd, date d)
        {
            nom=n;
            id=idd;
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

        //ostream& operator<<(ostream& s,const voiture& V)

        ostream& operator<<(ostream& sortie, client& cl)
        {
            sortie<<cl.nom<<" "<<cl.id<<" "<<(cl.dernier_date_loc).getjour()<<" "<<(cl.dernier_date_loc).getmois()<<" "<<(cl.dernier_date_loc).getannee()<<endl;
            return sortie;
        }

