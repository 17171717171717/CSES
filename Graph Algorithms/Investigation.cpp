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
    cin >> n >> m ;
    vector<vector<pair<int,int>>>g(n) ;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a-1].pb({b-1,c});
    }

    priority_queue<pii, vector<pii>, greater<pii> >pq;
    vi dist(n,LLONG_MAX);
    vi route(n,0);
    vi max_p(n,0);
    vi min_p(n,LLONG_MAX);
    vector<bool>vis(n,false);

    dist[0] = 0;
    route[0] = 1;
    min_p[0] = 0;
    max_p[0] = 0;

    pq.push({0,0});//dist, node
    while(!pq.empty()){
        auto cur = pq.top();pq.pop();
        int cur_dist = cur.first;
        int cur_node = cur.second;
        if(vis[cur_node])continue;
        vis[cur_node] = 1;
        for(auto nxt : g[cur_node] ){
            int nxt_cost = nxt.second;
            int nxt_node = nxt.first;
            int nxt_dist = nxt_cost + cur_dist;
            if(nxt_dist < dist[nxt_node]){
                dist[nxt_node] = nxt_dist;
                route[nxt_node] = route[cur_node];
                max_p[nxt_node] = max_p[cur_node]+1;
                min_p[nxt_node] = min_p[cur_node]+1;
                pq.push({dist[nxt_node],nxt_node});
            }else if(nxt_dist == dist[nxt_node]){
                max_p[nxt_node] = max(max_p[nxt_node], max_p[cur_node]+1);
                min_p[nxt_node] = min(min_p[nxt_node], min_p[cur_node]+1);
                route[nxt_node] = (route[nxt_node] + route[cur_node])%mod;
            }
        }
    }

    cout << dist[n-1] << " " << route[n-1] << " " << min_p[n-1] << " " << max_p[n-1];
    
    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
