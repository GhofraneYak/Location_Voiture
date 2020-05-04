
#include "parking.cpp"//car on a besoin de classe date
#include <iostream>
using namespace std;


class client
{
    private:
        string nom;
        long id;
        date dernier_date_loc;
        int nbr_loc;

    public:
        client(string n, long idd, date d, int nbr);
        string getnom();
        long getid();
        date getdate();
        void setdate(date d);
        int get_nbr_loc();
        void set_nbr_loc();

        friend ostream& operator<<(ostream& sortie, client& cl);
};
