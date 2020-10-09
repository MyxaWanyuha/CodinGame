#include <iostream>
#include <cmath>
using namespace std;

struct Temperature
{
    Temperature(int val)
    {
        temp = abs(val);
        isPositive = val > 0;
    }
    int temp;
    bool isPositive;
};

int main()
{
    int tempsCount;
    cin >> tempsCount; cin.ignore();
    const int impossibleTemp = 5527;
    Temperature closest(impossibleTemp);
    for (int i = 0; i < tempsCount; i++) {
        int t;
        cin >> t; cin.ignore();
        Temperature tt(t);

        if (tt.temp == closest.temp && tt.isPositive)
            closest.isPositive = true;
        else if (tt.temp < closest.temp)
            closest = tt;
    }
    int res = closest.isPositive ? closest.temp : -closest.temp;
    res = res == impossibleTemp ? 0 : res;
    cout << res << '\n';

    return 0;
}