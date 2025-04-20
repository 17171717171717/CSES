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

    int n, m;
    cin >> n >> m;
    vector<edge>edges(m);
    for(int i = 0 ; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[i].src = (a-1);
        edges[i].to = (b-1);
        edges[i].w = (c);
    }

    vi dis(n,1e18);
    dis[0] = 0;

    for(int i = 0; i < n-1; i++){
        for(auto e: edges){
            if(dis[e.to] > dis[e.src] + e.w){
                dis[e.to] = dis[e.src] + e.w;
            }
        }
    }
    bool has_cycle = false;

    for(auto e: edges){
        if(dis[e.to] > dis[e.src] + e.w){
            dis[e.to] = dis[e.src] + e.w;
            has_cycle = true;
            break;
        }
    }


    if(!has_cycle){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        vec<int>par(n,-1);
        int st = -1;
        for(int i = 0; i < n*3; i++){
            for(auto e: edges){
                if(dis[e.to] > dis[e.src] + e.w){
                    ie(cout << "dis[e.to] " << dis[e.to] << " dis[e.src] " << dis[e.src]<< " e.w " << e.w<< endl ;)
                    ie(cout << "e.to " << e.to+1 << " e.src " << e.src+1<< endl ;)
                    dis[e.to] = dis[e.src] + e.w;
                    par[e.to] = e.src;
                    //pick any vertex in cycle
                    st = e.to; 
                    ie(cout << "st " << st+1 << endl ;)
                }
            }
        }

        // 2->4->1 is negative cycle, but 4->3 can be small by nega cycle => 3 isn't in cycle.
        for(int i = 0; i < n; i++){
            st=par[st];
            ie(cout << "st " << st+1 << " par[st] " << par[st]+1 << endl ;)
        }
        ie(cout <<  endl ;)

        int cur = st;

        stack<int>ans;
        //by line 102&114, nobody is reduced by node 3
        do{
            // ie(cout << cur << ' ' ;)
            ie(cout << "st " << st+1 << " par[st] " << par[st]+1 << endl ;)
            ans.push(cur+1);
            cur = par[cur];
            ie(cout << "st " << st+1 << " par[st] " << par[st]+1 << endl ;)
        }while(st != cur);

        ans.push(cur+1);
        while(ans.size()){
            cout<<ans.top()<<' ';
            ans.pop();
            
        }
    }
    
    
    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
