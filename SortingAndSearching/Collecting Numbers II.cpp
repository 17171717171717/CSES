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

// https://www.youtube.com/watch?v=LEL3HW4dQew
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

    int n , q;
    cin >> n >> q;
    vec<int>v(n+1);
    vec<int>idx(n+1);
    for(int i = 1; i <= n ; i++){
        cin >> v[i];
        idx[v[i]] = i;
    }

    int ans = 1;
    for(int i = 1; i < n; i++){
        ans += (idx[i+1] < idx[i]);
    }

    set<pii>query;
    int l,r;
    while(q--){
        cin >> l >> r;
        if((v[l]+1) <= n)query.insert({v[l],v[l]+1});
        if((v[l]-1) >= 1)query.insert({v[l]-1,v[l]});
        if((v[r]+1) <= n)query.insert({v[r],v[r]+1});
        if((v[r]-1) >= 1)query.insert({v[r]-1,v[r]});

        for(auto qq : query){
            ans -= (idx[qq.f] > idx[qq.s]);
            // cout << ans <<" *** "<< endl;
        }

        swap(v[l],v[r]);
        // debugvec(v);
        idx[v[l]] = l;
        idx[v[r]] = r;

        for(auto qq:query){
            ans += (idx[qq.f]>idx[qq.s]);
        }
        cout << ans << endl;
        query.clear();
    }
    

    
    

    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  