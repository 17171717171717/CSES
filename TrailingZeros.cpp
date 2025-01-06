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

// https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/


ll zeros(ll n){
    ll ans = 0;
    for(int i = 5; i <= n ; i*=5){
        ans += n/i;
    }
    return ans;
}
int main()
{
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif

    #ifndef local
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    
    ll n;
    cin >> n;
    
    
    cout << zeros(n) ;
    return 0;
}
