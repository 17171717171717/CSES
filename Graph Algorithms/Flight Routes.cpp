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

class edge{
    public:
        int src,to,w;
        edge(int a=0, int b=0,int c=0){
            src=a;to=b;w=c;
        }
};

signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> g(n);
    vector<vector<int>> dist(n,vector<int>(k,INF));//k dists for each node
    dist[0][0] = 0; // curnode: k_th weight
    
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].pb({b,c});
    }

    priority_queue<pii, vec<pii>, greater<pii>> min_pq; 

    min_pq.push({0,0}); // {cur shortest dist,node}

    while(!min_pq.empty()){
        auto cur = min_pq.top();
        min_pq.pop();
        int curnode = cur.second;
        int curweight = cur.first;

        // if(curweight >= dist[curnode][k-1])continue;
        if(curweight > dist[curnode][k-1])continue; // dist = [3 4 4], cur = 4 => may 3+1000 to final
                                                    // will longer than 4+100 to final

        for(auto e : g[curnode]){
            auto nxtnode = e.F;
            auto edgeweight = e.S;
            if(dist[nxtnode][k-1] > curweight + edgeweight){
                dist[nxtnode][k-1] = curweight + edgeweight;
                min_pq.push({dist[nxtnode][k-1],nxtnode});
                sort(al(dist[nxtnode]));
                
            }
        }
    }
    
    for(int i = 0; i< k; i++){
        cout << dist[n-1][i] << " ";
    }
    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
