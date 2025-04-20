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

void dfs(int cur, vec<bool>& reachable, vvi& neighbors){
    if(reachable[cur])return;
    reachable[cur] = 1;
    for(auto n: neighbors[cur]){
        dfs(n,reachable,neighbors);
    }
}

signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int n, m;
    cin >> n >> m;
    int max_s = n*1e9;
    vec<tuple<int,int,int>>edges;
    vi ans(n,max_s);
    vvi forward_(n);
    vvi backward_(n);
    ans[0] = 0;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        edges.pb(make_tuple(a,b,-c));
        forward_[a].pb(b);
        backward_[b].pb(a);
        ie(debug(b) debugv(backward_[b]))
    }
    // ie(for(int i= 0 ; i < n; i++){
    //     debugv(backward_[i])
    // })

    // if the neg cycle from 1 cant go back to n, then we dont care the cycle
    // !! draw the pic
    // if from 1 can go to the cycle, and cant go back => it means the backward from n-1 cant go to the cycle
    vec<bool>go_st(n,false);
    vec<bool>go_ed(n,false);
    dfs(0,go_st,forward_);
    dfs(n-1,go_ed,backward_);
    

    ie(debugv(go_st)
    debugv(go_ed)
    debugv(ans)
    cout <<"ok"<<endl;)
    for(int i = 0; i < n; i++){
        for(auto e:edges){
            int cur = get<0>(e);
            int nxt = get<1>(e);
            int w = get<2>(e);
            ie(debug(cur)
            debug(nxt)
            debug(w))

            // as small as possible
            if(ans[cur]+w < ans[nxt]){
                ans[nxt] = ans[cur]+w;
                ie(debug(ans[nxt]))
                if(i==n-1 && go_st[nxt] && go_ed[nxt]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    ie(debugv(go_st)
    debugv(go_ed)
    debugv(ans)
    cout <<"ok"<<endl;)
    
    cout << -1*ans[n-1];


    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
