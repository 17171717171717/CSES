#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
template <typename T>
using vec = vector<T>;
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long;
using str = string;
const double eps = 1e-9;
 
int main()
{
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    #define int long long
    int N;
    cin >> N;
    REP1(i,N){
        cout << ((i * i) * (i * i - 1))/2 - 2 * (i-1) * (i-2) * 2 << endl;
    }
    // while (cin >> N)
    // {
    //     int ans = ((N^2) * (N^2 - 1))/2 - 2 * (K-1) * (K-2) * 2;
        
    //     cout << ans<<endl;
        
    // }
    return 0;
}
