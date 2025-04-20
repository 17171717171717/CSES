#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].first >> v[i].second;
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define debug(x) cout << #x << " = " << x << "\n";
template <typename T>
using vec = vector<T>;
#define pb push_back
#define mp make_pair
#define al(x) (x).begin(), (x).end()
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<long long>>;
using vpii = vector<pair<long long,long long>>;
using ll = long long ;
using str = string;
using um = unordered_map<long,long>;
#define F first
#define S second
// small to big
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
// big to small
#define pq(type) priority_queue<type>
const double eps = 1e9+7;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef local
    #define ie(x) x
#else
    #define ie(x)
#endif
#define INF 1000000000

const int mod = 1e9+7;

vvi dirs = {{-1,0},{1,0},{0,1},{0,-1}};
// vec<char>dirs_eng = {'L','R','U','D'}; 
vec<char>dirs_eng = {'U','D','R','L'};// -1,0 => Down 


signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)


    int n,m;
    cin >> n >> m;
    
    vec<vec<pii>>g(n);
    REP(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        // c--;
        g[a].pb(mp(b,c));
    }

    vi ans(n,LLONG_MAX );
    min_pq(pii) edges; // {ans[i],i}
    edges.push({0,0});
    ans[0] = 0;
    
    while(!edges.empty()){
        auto cur = edges.top();
        edges.pop();
        int cur_dist = cur.F;
        int cur_node = cur.S;
        ie(debug(cur_dist)
        debug(cur_node))
        if(ans[cur_node] < cur_dist)continue;
        for(auto nxt : g[cur_node]){
            int nxt_node = nxt.F;
            int weight = nxt.S;
            ie(debug(nxt_node)
            debug(weight))
            if((cur_dist + weight) < ans[nxt_node]){
                ans[nxt_node] = (cur_dist+weight);
                edges.push({ans[nxt_node],nxt_node});
            }
        }
    }
    debugv(ans)
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
