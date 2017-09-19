#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue
{
public:
    void enterQueue(T element) {
        Elements.push_back(element);
        qSize++;
    }

    void leaveQueue() {
        Elements.erase(Elements.begin());
        qSize--;
    }

    void setSize(int Size) {
        qSize = Size;
    }

    int getSize() {
        return qSize;
    }

    int getCustomerID(int i) {
        return Elements.at(i).getCustomerID();
    }

    int getOnQueueTime(int i) {
        return Elements.at(i).getOnQueueTime();
    }


private:
    vector<T> Elements;
    int qSize;
};

