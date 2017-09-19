#include <iostream>
#include "Customer.h"
using namespace std;

void Customer::setOnQueueTime(int time)
{
    onQueueTime = time;
}

void Customer::setCustomerID(int id)
{
    CustomerID = id;
}

int Customer::getCustomerID()
{
    return CustomerID;
}

int Customer::getOnQueueTime()
{
    return onQueueTime;
}

