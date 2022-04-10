#include<iostream>
#include <cmath>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int ab, bc, ca;
    cin >> ab >> bc >> ca;

    int mab = min(a, b);

    int ans = 0;
    for (int i = 0; i <= mab; i++)
    {
        int mbc = min(b - i, c);
        for (int j = 0; j <= mbc; j++)
        {
            int k = min(a - i, c - j);

            ans = max(ans, ab * i + bc * j + ca * k);
        }
    }
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}