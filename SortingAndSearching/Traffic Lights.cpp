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

    int n ,x;
    cin >> x >> n ;
    vec<int>v;
    REP(i,n){
        int tmp;
        cin >> tmp;
        v.pb(tmp);
    }
    #ifdef local
    debugvec(v);
    #endif

    set<pii>range;
    multiset<ll>lens;

    range.insert({0,x});
    lens.insert(x);

    int ans = 0;
    REP(i,n){
        auto it = range.upper_bound({v[i],0});
        it--;

        int st = (*it).f;
        // int ed = it->s;
        int ed = (*it).s;
        range.erase(it);
        lens.erase(lens.find(ed-st));


        // Insert the new ranges
        range.insert({ st, v[i] });
        range.insert({ v[i], ed });
        lens.insert(v[i] - st);
        lens.insert(ed - v[i]);



        cout << *lens.rbegin() << ' ';

    }

    

    
    

    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  