#include "WindGauge.h"
#include <iostream>
using namespace std;

int main()
{
    WindGauge w;
    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(12);
    w.currentWindSpeed(15);
    w.currentWindSpeed(15);
    w.dump();
    cout << endl;
    cout << "After addding new values" << endl;

    w.currentWindSpeed(16);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.dump();

    return 0;
}