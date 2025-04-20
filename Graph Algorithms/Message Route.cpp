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
vec<char>dirs_eng = {'U','D','R','L'};// col+1 是往右邊走 不


signed main()
{
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int n,m;
    // bfs sol
    cin >> n >> m;
    vvi g(n);
    vi g_record(n,-1);
    vi dist(n,-1);
    for(int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }
    
    ie(
        for(auto gg : g){
            debugv(gg)
        }
    )
    
    queue<int>q;
    q.push(0);
    dist[0] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nextOne : g[cur]){
            if(dist[nextOne] == -1){
                dist[nextOne] = dist[cur]+1;
                g_record[nextOne]=cur;
                q.push(nextOne);
            }
        }
    }
    int traverse = g_record[n-1];

    ie(debugv(g_record))
    ie(debugv(dist))
    stack<int> st;
    if(dist[n-1]==-1){
        cout <<  "IMPOSSIBLE" << endl;
    }
    else{
        cout << dist[n-1] << endl;
        cout << 1 << " ";
        for(int i = 1; i < dist[n-1]-1 ;i++){
            // cout << (traverse+1) << " ";
            st.push((traverse+1));
            traverse = g_record[traverse];
        }
        for(int i = 1; i < dist[n-1]-1 ;i++){
            cout <<  st.top() << " ";
            st.pop();
            // cout << (traverse+1) << " ";
            // st.push((traverse+1));
            // traverse = g_record[traverse];
        }
        cout << n ;
    }
    
    
    return 0;
    // g++ .\tmp.cpp -Dlocal -o tmp  
    // .\tmp.exe   
    


}
