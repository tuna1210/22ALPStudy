#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    string str;
    cin >> str;

    int red = 1, blue = 1;
    char prev = str[0];
    for(int i = 1; i <= n; i++)
    {
        if(i == n || prev != str[i])
        {
            if(prev == 'R') red++;
            else blue++;
        }
        prev = str[i];
    }
    cout << min(red, blue) << "\n";

    return 0;
}