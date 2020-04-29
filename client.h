
#include "parking.cpp"//car on est besoin de classe date
#include <iostream>
using namespace std;


class client
{
    private:
        string nom;
        long id;
        date dernier_date_loc;

    public:
        client(string n, long idd, date d);
        string getnom();
        long getid();
        date getdate();
        void setdate(date d);
};
