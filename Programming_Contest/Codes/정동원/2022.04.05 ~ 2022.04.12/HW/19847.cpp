#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v(1000001, 1);
int n, sx;

void solve()
{
    cin >> n;
    cin >> sx;

    int cmin = sx;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        if(x >= cmin) continue;

        int a = (cmin - x) / x, b = cmin % x;
        for (int j = 0; j < x; j++)
        {
            v[j] += v[j] * a;
        }
        for (int j = 1; j <= b; j++)
        {
            v[j]++;
        }

        cmin = x;
        // for (int i = 0; i < cmin; i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << "\n";
    }
    
    double ans = 0.0;
    for (int i = 0; i < cmin; i++)
    {
        // cout << v[i] << " ";
        ans += double(i) * (double(v[i]) / double(sx));
    }
    // cout << "\n";
    
    cout.precision(12);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();

    return 0;
}