#include <iostream>
using namespace std;

class Teller
{
public:
    void setBusy(bool Status);
    void setServiceTime(int time);
    void setID(int id);
    void decrementServiceTime();

    bool getBusy();
    int getID();
    int getServiceTime();


private:
    int serviceTime;
    bool isBusy;
    int ID;
};
