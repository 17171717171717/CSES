#include <bits/stdc++.h>
using namespace std;
 
// freopen("input.txt", "r", stdin);
// #define int long long
int main()
{
// freopen("input.txt", "r", stdin);
#define int long long
    int N;
    while (cin >> N)
    {
        cout << N;
        while (N != 1)
        {
            if (N % 2 == 0)
            {
                N /= 2;
                cout << " " << N;
                if (N == 1)
                {
                    cout << endl;
                    break;
                }
            }
            else
            {
                N *= 3;
                N += 1;
                cout << " " << N;
                if (N == 1)
                {
                    cout << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
