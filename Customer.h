#include <iostream>
#include <vector>
using namespace std;

class Customer
{
public:
    void setOnQueueTime(int time);
    void setCustomerID(int id);

    int getCustomerID();
    int getOnQueueTime();

private:
    int onQueueTime;
    int CustomerID;
};

