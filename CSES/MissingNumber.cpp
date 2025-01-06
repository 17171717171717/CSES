#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
template <typename T>
using vec = vector<T>;
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long;
 
const double eps = 1e-9;
 
int main()
{
    // freopen("input.txt", "r", stdin);
    #define int long long
    int n;
    while (cin >> n)
    {
        int total = (1 + n) * n / 2;
        int k = 0;
        // cout << total;
        for (int i = 0; i < n - 1; i++)
        {
            int tmp = 0;
            cin >> tmp;
            k += tmp;
            // cout << k << endl;
        }
        cout << (total - k) << endl;
    }
    return 0;
}