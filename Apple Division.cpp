#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
template <typename T>
using vec = vector<T>;
#define pb push_back
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long;
using str = string;
#define f first
#define s second
const double eps = 1e-9;

// g++ .\tmp.cpp -Dlocal -o tmp


int main()
{
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif

    #ifndef local
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif


    int n;
    cin >> n;
    ll sum=0,ans=LLONG_MAX;
    vec<int>v;
    REP(i,n){
        int tmp;
        cin >> tmp;
        v.pb(tmp);
        sum+=tmp;
    }

    REP(i, 1<<n){
        ll tmp = 0;
        REP(j,n){
            if(i & (1<<j)){
                tmp += v[j];
            }

        }
        ans = min( ans, abs( (sum - tmp) - tmp ) );
    }
    
    cout << ans << endl;

    
    return 0;
}
