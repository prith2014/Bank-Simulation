#include <iostream>
#include "Teller.h"

void Teller::setBusy(bool Status)
{
    isBusy = Status;
}

void Teller::setServiceTime(int time)
{
    serviceTime = time;
}

bool Teller::getBusy()
{
    return isBusy;
}

void Teller::setID(int id)
{
    ID = id;
}

int Teller::getID()
{
    return ID;
}

void Teller::decrementServiceTime()
{
    serviceTime--;
}

int Teller::getServiceTime()
{
    return serviceTime;
}

