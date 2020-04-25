
#include "date.h"
using namespace std;


class client
{
    private:
        string nom;
        long id;
        date dernier_date_loc;

    public:
        client(string n, long idd, int j,int m, int a);
        string getnom();
        long getid();
        date getdate();
        void setdate(date d);
};
