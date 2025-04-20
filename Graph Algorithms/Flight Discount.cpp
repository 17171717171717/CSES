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
using vvpii = vector<vector<pair<long long,long long>>>;
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

int max_s = 1e18;

vi dijk(int src, int dest, vvpii g){
    int n = g.size();
    
    vi dist(n,max_s);
    dist[src] = 0;
    min_pq(pii) q;
    q.push({0,src});
    while(!q.empty()){
        auto tmp = q.top();q.pop();
        int cur_dist = tmp.F;
        int cur_node = tmp.S;
        if(dist[cur_node] < cur_dist)continue;

        for(auto nxt : g[cur_node]){
            int nxt_node = nxt.F;
            int nxt_c = nxt.S;
            
            if(cur_dist + nxt_c < dist[nxt_node]){
                dist[nxt_node] = cur_dist + nxt_c;
                q.push({cur_dist + nxt_c, nxt_node});
            }
        }

    }
    return dist;
}


signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int n, m;
    cin >> n >> m;
    vvpii g(n);
    vvpii rev_g(n);
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].pb({b,c});
        rev_g[b].pb({a,c});

    }

    // for reverted graph, the n -> k shortest path is the original graph k -> n shortest path
    // !!!proof: https://stackoverflow.com/questions/16646326/all-shortest-paths-to-a-given-vertex
    vi min_src = dijk(0,n-1,g);
    vi min_rev = dijk(n-1,0,rev_g);


    int ans = max_s;

    REP(a,n){
        for(auto edge : g[a]){
            int b = edge.F;
            int c = edge.S;
            ans = min(min_src[a] + min_rev[b] + c/2, ans);
        }
    }
    cout << ans;

    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
