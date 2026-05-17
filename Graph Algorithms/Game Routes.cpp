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
    vvi g(n);
    vi indeg(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        g[a-1].pb(b-1);
        indeg[b-1]++;
    }

    queue<int>q;
    for(int i = 0; i < n; i++){
        // if(g[i].empty())q.push(i); // no outdegree
        
        if(indeg[i]==0)q.push(i); // no outdegree
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

    vi dp(n,0);
    dp[0] = 1;

    for(auto cur : topo){
        for(auto nxt : g[cur]){
            dp[nxt] = (dp[nxt] + dp[cur])%mod;
        }
    }
    cout << dp[n-1];

    
    
    
    
    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
