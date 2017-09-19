#include <iostream>
#include <vector>
#include <iomanip>
#include "Customer.h"
#include "Queue.h"
#include "Teller.h"
using namespace std;


int main()
{
    int counterTime = 0;    // Keeps track of time, starts at minute 0
    int numTellers = 0;     // Number of tellers
    int waitTime = 0;       // Total wait time by all customers
    int customerId = 0;     // Customer ID used to identify customers
                            // Each customer will have its own unique ID
    int arrivalTime = 0;    // Input for arrival time
    int arrivalCust = 0;    // Input for amount of arriving customers
    int serviceTime = 0;    // Length of service time by Teller
    int maxCustomers = 0;   // Simulation ends once max customers are serviced
    int customerData = 0;   // Number of customers serviced

    Queue<Customer> Queue1;   // Creating Queue object called Queue1

    // User Inputs

    cout << "Enter number of Tellers: ";
    cin >> numTellers;
    while (numTellers <= 0) {
        cout << "Number of tellers cannot be negative or zero. Please re-enter valid number of tellers." << endl;
        cout << "Enter number of Tellers: ";
        cin >> numTellers;
    }
    cout << "X number of customers arrive every Y minutes." << endl;
    cout << "Enter X(amount of arriving customers): ";
    cin >> arrivalCust;
    while (arrivalCust <= 0) {
        cout << "Number of customers arriving cannot be negative or zero. Please re-enter valid number of arriving customers." << endl;
        cout << "Enter X(amount of arriving customers): ";
        cin >> arrivalCust;
    }
    cout << "Enter Y(in minutes): ";
    cin >> arrivalTime;
    while (arrivalTime <= 0) {
        cout << "Arrival time cannot be negative or zero. Please re-enter valid arrival time." << endl;
        cout << "Enter Y(in minutes): ";
        cin >> arrivalTime;
    }
    cout << "Enter service time(in minutes): ";
    cin >> serviceTime;
    while (serviceTime <= 0) {
        cout << "Service time cannot be negative or zero. Please re-enter valid service time." << endl;
        cout << "Enter service time(in minutes): ";
        cin >> serviceTime;
    }
    cout << "Enter max customers in simulation: ";
    cin >> maxCustomers;
    while (maxCustomers < 1) {
        cout << "Max number of customers cannot be less than one. Please re-enter valid amount of max customers." << endl;
        cout << "Enter max customers in simulation: ";
        cin >> maxCustomers;
    }

    // Setting up an array of Tellers

    Teller *arrTeller = new Teller[numTellers];
    for (int i = 0; i < numTellers; i++) {
        // Setting initial values for each teller

        arrTeller[i].setServiceTime(serviceTime);
        arrTeller[i].setBusy(false);
        arrTeller[i].setID(0);

    }

    int totalServiceTime = 0;           // Total service time overall
    int wait = 0;                       // Total waiting time overall
    Queue1.setSize(0);                  // Size of queue starts at 0
    int totalCustomers = 0;             // Total customers that have arrived
    int customerCounter = maxCustomers; // Counts down till 0, base case for while loop


    // Runs until max number of customers in simulation is reached
    while (customerCounter > 0) {
        cout << "\nTime: " << counterTime << endl;

        if ((counterTime % arrivalTime == 0 && totalCustomers < maxCustomers) ) {   // Check if customers arrive

            if (maxCustomers - totalCustomers < arrivalCust) {  // If (max customers in simulation) - (customers serviced) < (arriving number of customers)
                arrivalCust = maxCustomers - totalCustomers;    //      Arriving number of customers = (max customers in simulation) - (customers serviced)
            }                                                   // Total number of customers should not surpass max number of customers in simulation

            totalCustomers = totalCustomers + arrivalCust;      // Increase number of customers that will be serviced by the number
                                                                // of arriving customers

            cout << arrivalCust << " customer(s) enter the bank." << endl;

            // Add new customers onto queue
            for (int i=0; i < arrivalCust; i++) {

                Customer c1;                        // New customer
                customerId++;                       // Customer number n+1
                c1.setCustomerID(customerId);
                c1.setOnQueueTime(counterTime);     // Got on queue at current time

                Queue1.enterQueue(c1);    // Object of class Customer enters the Queue vector<Customer>
            }
        } // Ends if loop


        for (int i=0; i < numTellers; i++) {

            // Checking if there is a customer on queue and a free teller

            if (Queue1.getSize() != 0 && arrTeller[i].getBusy() == false ) {
                // There is a free teller and a customer waiting
                // Make customer leave queue and go to teller

                arrTeller[i].setBusy(true);                         // Teller is now busy with customer
                arrTeller[i].setID( Queue1.getCustomerID(0) );        // Customer at front of queue goes to teller
                arrTeller[i].setServiceTime(serviceTime);           // Customer at teller for length of service time

                totalServiceTime = totalServiceTime + serviceTime;  // Add service time to total service time

                wait = counterTime - Queue1.getOnQueueTime(0);        // wait = time elapsed - time customer got on queue

                cout << "Teller " << i << " is serving customer " << arrTeller[i].getID() << "." << endl;
                cout << "Customer " << arrTeller[i].getID() << " has waited in queue for " << wait << " minutes." << endl;
                cout << "Customer " << arrTeller[i].getID() << " will leave at minute " << counterTime + serviceTime << "." << endl;

                Queue1.leaveQueue();      // Customer leaves the queue
            }
        }

        for (int i=0; i < numTellers; i++) {

            if (arrTeller[i].getBusy() == true) {

                // Teller is still servicing customer
                // Decrement service time by one minute

                arrTeller[i].decrementServiceTime();
            }

            if (arrTeller[i].getServiceTime() == 0 && arrTeller[i].getBusy() == true) {

                // Teller is done servicing customer

                arrTeller[i].setBusy(false);    // Teller is now free for next customer
                customerCounter--;              // Subtract 1 from remaining customers needing service
                customerData++;                 // Counting total number of customers that have been serviced so far
            }
        }
        waitTime = waitTime + Queue1.getSize();     // Total wait time increased by size of queue
        counterTime++;                              // Increase the counter time by one
                                                    // Another minute has passed
        cout << Queue1.getSize() << " customer(s) are left in the queue." << endl;
    } // Ends while loop
    // End of simulation

    cout << "\nEnd of Simulation. Calculating output data..." << endl;

    cout << "\nNumber of Tellers: " << numTellers << endl;
    cout << "Total service time: " << totalServiceTime << " minutes" << endl;
    cout << "Total wait time: " << waitTime << " minutes" << endl;
    cout << "Total number of Customers: " << customerData << endl;

    float avgWaitTime = waitTime/(float)customerData;
    cout << "Average Wait Time: " << fixed << setprecision(2) << avgWaitTime << " minutes" << endl;


    delete arrTeller;
    return 0;
}



