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
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


signed main()
{
    #ifdef local
    #endif

    fastios
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
// https://www.youtube.com/watch?v=8QfWrRRK2PA
    int n;
    cin >> n;
    vec<int>v;
    REP(i,n){
        v.pb(i+1);
    }

    while(v.size()>1){
        vec<int>left;
        int k = v.size();
        REP(i,k){
            if(i%2)cout<<v[i]<<" ";
            else left.pb(v[i]);
        }

        if(k%2){
            int st = left.back();
            left.pop_back();
            v.clear();
            v.pb(st);
            for(auto a : left)v.pb(a);
        }
        else v = left;
    }
    cout << v[0];
    

    
    

    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  