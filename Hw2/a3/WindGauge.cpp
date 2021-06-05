#include "WindGauge.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>

using namespace std;
WindGauge::WindGauge(int period)
{
    period = time;
}

void WindGauge::currentWindSpeed(int speed)
{
    wind.push_back(speed);
    
    if (wind.size() > time)
    {
        wind.pop_front();
    }
}
int WindGauge::highest() const
{
    return *max_element(wind.begin(), wind.end());
}

int WindGauge::lowest() const
{
    return *min_element(wind.begin(), wind.end());
}

int WindGauge::average() const
{
    float average = accumulate(wind.begin(), wind.end(), 0);
    return (average / wind.size());
}
void WindGauge::dump()
{
    cout << "Highest Wind speed" << highest() << endl;
    cout << "Lowest Wind Speed" << lowest() << endl;
    cout << "Average Wind Speed" << average() << endl;
}
//References
//https://www.cplusplus.com/reference/numeric/accumulate/
//https://www.cplusplus.com/reference/algorithm/max_element/
//https://www.cplusplus.com/reference/algorithm/min_element/