#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> removable;

long long ln = 0, sn = 0, cnt = 0;

inline unsigned long long important(long long x){return (unsigned long long)sn * (unsigned long long)max(cnt, cnt * x - ln);}
inline unsigned long long virus(long long x, long long s, long long l){return (unsigned long long)s * (unsigned long long)max(1ll, x - l);}

void solve()
{
    long long n, g, k;
    cin >> n >> g >> k;

    for (int i = 0; i < n; i++)
    {
        unsigned long long s, l, o;
        cin >> s >> l >> o;

        if(o == 1)
        {
            removable.push_back({s, l});
        }
        else
        {
            cnt++;
            sn += s;
            ln += l;
        }
    }
    long long remove = removable.size();
    
    long long get = remove - k;
    
    // long long ans_can = 0;
    long long left = 0, right = 2e9, mid;
    while(left <= right)
    {
        // cout << left << ", " << right << "\n";
        mid = (left + right) / 2;
        unsigned long long sum = important(mid);
        
        vector<unsigned long long> virusvec;
        for (int i = 0; i < remove; i++)
        {
            // cout << removable[i].first << "," << removable[i].second << " ";
            virusvec.push_back(virus(mid, removable[i].first, removable[i].second));
        }
        // cout << "\n";
        
        sort(virusvec.begin(), virusvec.end());

        for (int i = 0; i < get; i++)
        {
            // cout << virusvec[i] << " ";
            sum += virusvec[i];
            if(sum > g)
            {
                right = mid - 1;
                continue;
            }
        }
        // cout << "\n";
        
        // cout << sum << "\n";
        if(sum > g)
        {
            right = mid - 1;
        }
        else
        {
            // ans_can = max(ans_can, mid);
            left = mid + 1;
        }
        // cout << "---------------\n";
    }
    
    cout << right << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();

    return 0;
}