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
// #define min_pq(type) priority_queue<type, vector<type>, greater<type>>
// big to small
// #define pq(type) priority_queue<type>
const double eps = 1e9+7;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef local
    #define ie(x) x
#else
    #define ie(x)
#endif
const int INF = 9e15;
const int mod = 1e9+7;

vvi dirs = {{-1,0},{1,0},{0,1},{0,-1}};
// vec<char>dirs_eng = {'L','R','U','D'}; 
vec<char>dirs_eng = {'U','D','R','L'};// -1,0 => Down 



signed main() {
    fastios;
    
    ie(freopen("test_input.txt", "r", stdin);)

    
    int n,m;
    cin >> n >> m;
    vvi g(n+1);
    vi indeg(n+1,0);
    REP(i,m){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        indeg[b]++;
    }

    queue<int>q;
    for(int i = 1; i <=n ; i++){
        if(indeg[i]==0)q.push(i);
    }

    vi topo;
    while(!q.empty()){
        int cur=q.front();q.pop();
        topo.push_back(cur);
        for(auto nxt : g[cur]){
            indeg[nxt]--;
            if(indeg[nxt]==0)q.push(nxt);
        }
    }

    vector<int>dp(n+1, -1e9), routes(n+1,-1);
    dp[1] = 1;

    for (int u : topo) {
        if (dp[u] == -1e9) continue;
        for (int v : g[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                routes[v] = u;
            }
        }
    }

    if (dp[n] == -1e9) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct path
    vector<int> path;
    for (int cur = n; cur != -1; cur = routes[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int x : path) cout << x << " ";
    cout << "\n";
    return 0;
} 
// g++ -std=c++17 CSEStmp.cpp -Dlocal -o tmp
// .\tmp.exe   
