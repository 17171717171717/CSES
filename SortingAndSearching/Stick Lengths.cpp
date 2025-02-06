#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define debugvec(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
template <typename T>
using vec = vector<T>;
#define pb push_back
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long ;
using str = string;
#define f first
#define s second
const double eps = 1e-9;
#define int long long


signed main()
{
    #ifdef local
    #endif

    #ifdef local
    freopen("test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif

    int n ;
    cin >> n ;
    vec<int>v;
    REP(i,n){
        int tmp;
        cin >> tmp;
        v.pb(tmp);
    }

    sort(al(v));
    // median : left side size a and right side size b are same size, a = b = n/2
    // go right one=> left side size sum+ (a+1), right side sum- (b-1) => a > b => bigger
    int m = v[n/2];
    ll ans = 0;
    
    REP(i,n){
        ans+=abs(v[i]-m);
    }
    
    cout << ans << endl;

    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  