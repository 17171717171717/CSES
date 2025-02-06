
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define debugvec(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
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
    multiset<int>ms;
    vec<int>v;
    REP(i,n){
        int tmp;
        cin >> tmp;
        v.pb(tmp);
    }
    int ans = 0;
    REP(i,n){
        // smallest cube in tower > i_th cube
        auto it = ms.upper_bound(v[i]);
        
        if(it == ms.end()){
            ans++;
            ms.insert(v[i]);
        }
        else{
            ms.erase(it);
            ms.insert(v[i]);
        }
    }

    
    cout << ans;
    

    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  