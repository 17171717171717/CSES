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

void dfs1(vi& maxd, vi& maxd2,vi& c,vvi& g, int cur, int pre){
    maxd[cur]=0;
    maxd2[cur]=0;
    for(auto child : g[cur]){
        if(child==pre)continue;
        dfs1(maxd,maxd2,c,g,child,cur);
        //take the 1st and 2nd dep in subtree
        if(maxd[child]+1 > maxd[cur]){
            maxd2[cur] = maxd[cur];
            maxd[cur] = maxd[child]+1;
            c[cur] = child;
        }
        else if(maxd[child]+1>maxd2[cur]){
            maxd2[cur]=maxd[child]+1;
        }
    }
}

void dfs2(vi& maxd, vi& maxd2,vi& c,vvi& g, int cur, int pre){
    for(auto child:g[cur]){
        if(child==pre)continue;
        // this child is the 1st deepest child
        if (c[cur] == child)
        {
            // cur max is go through max, but go 2nd farthest can +1 > go cur  => go 2nd 
            if (maxd[child] <= maxd2[cur] )
            {
                maxd2[child] = maxd[child];
                maxd[child] = maxd2[cur] + 1;
                c[child] = cur;
                    
            }
            // maxd2[cur] > maxd[child]
            // it's still the same, 2nd is still the 2nd => +1 for cur -> pre
            else
            {
                maxd2[child] = max(maxd2[child], maxd2[cur] + 1);
            }
        }
        else
        //cur doesn't go through this one -> have another deepest child -> 
        // best for the child is go back cur and go to where the deepest cur
        {
            maxd2[child] = maxd[child];
            maxd[child] = maxd[cur] + 1;
            c[child] = cur;
        
        }
        dfs2(maxd,maxd2,c,g,child,cur);
    }
}
signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)


    int n;
    cin >> n;
    vec<vec<int>>g(n);
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi maxd(n), maxd2(n), c(n);
    //maxd: max dep in subtree from x
    //maxd2: second dep in subtree from x
    //c: which child is the max dep go through 


    // ans: calculate the ans for node v (parent at node p)
    // case 1. ans in subtree => by calculate the depth for subtree rooted at v => A
    // case 2. ans need to go throuth parent 
    //         2-1: ans(p) is go through v => 1 + 2nd max in p => B
    //         2-2: ans(p) isn't go through v => 1 + ans in p => C

    // ans(v) = max(A,B,C)

    // top-down, root arbitrarily, then the root ans and 2nd max is ok
    // we need a ans_go_through for each node : c  , then we only need to de B or C


    dfs1(maxd,maxd2,c,g,0,-1);
    dfs2(maxd,maxd2,c,g,0,-1);

    debugv(maxd)
    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
