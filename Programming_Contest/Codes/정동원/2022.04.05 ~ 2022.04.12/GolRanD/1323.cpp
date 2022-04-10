#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define int long long

int n, k;
int len;

int recur(int cur, int depth, int& k)
{
    // cout << cur << ' ';
    if(cur % k == 0) return depth;
    if(depth > k) return -1;

    return recur((cur % k) * (int)pow(10, len) + n, depth + 1, k);
}

void solve()
{
    cin >> n >> k;

    len = to_string(n).length();

    cout << recur(n, 1, k) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();

    return 0;
}