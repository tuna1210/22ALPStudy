#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    long long temp = 1l * a.first * b.second + 1l * b.first * c.second + 1l * c.first * a.second;
    temp -= 1l * b.first * a.second + 1l * c.first * b.second + 1l * a.first * c.second;
    if (temp >= 0)
        return 1;
    else if (temp < 0)
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    double xa, ya;
    double xb, yb;
    double xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    cout << abs(xa * (yb-yc) + xb * (yc-ya) + xc * (ya-yb)) / 2 << "\n";

    int n;
    cin >> n;

    int cnt = 0;
    pair<double, double> a = {xa, ya}, b = {xb, yb}, c = {xc, yc};
    pair<double, double> p;
    for (int i = 0; i < n; i++)
    {
        cin >> p.first >> p.second;

        if(ccw(a, b, p) >= 0 && ccw(b, c, p) >= 0 && ccw(c, a, p) >= 0)
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
}