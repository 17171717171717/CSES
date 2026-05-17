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


    int n, qq;
    cin >> n >> qq ;
    
    vector<int>nxt(n+1);
    for(int i = 1; i <= n; i++){
        cin >> nxt[i];
    }

    vector<vector<int>>steps(n+1,vector<int>(32));
    for(int i = 1; i <= n ; i++)steps[i][0] = nxt[i];
    
    for(int j = 1; j <= 31; j++){
        for(int i = 1; i <= n; i++){
            steps[i][j] = steps[steps[i][j-1]][j-1]; //step[i][k] i go 2^k steps
        }
    }

    auto lift = [&](int node, ll step){
        for(int i = 0; i <= 31; i++){
            if(step & (1LL << i))node = steps[node][i];
        }
        return node;
    };

    //find nodes which in cycle
    vector<vector<int>>rev(n+1);
    vector<int>indeg(n+1, 0);

    for(int i = 1; i <= n; i++){
        indeg[nxt[i]]++;
        rev[nxt[i]].push_back(i);
    }

    queue<int>q;
    for(int i = 1; i <= n; i++){
        if(indeg[i]==0)q.push(i);
    }

    vector<int>in_cycle(n+1, 1);
    while(!q.empty()){
        auto cur = q.front();q.pop();
        in_cycle[cur] = 0;
        auto node = nxt[cur];
        if(--indeg[node]==0)q.push(node);
    }

    // record cycle id/ node pos in cycle
    vector<int>cycle_id(n+1, -1);
    vector<int>cycle_pos(n+1, -1);
    vector<int>cycle_len;
    int cid = 0;

    vector<int>vis(n+1,0);
    for(int i = 1; i <= n; i++){
        if(in_cycle[i] && !vis[i]){
            int cur = i;
            vector<int>cur_cycle;
            do{
                vis[cur] = 1;
                cur_cycle.push_back(cur);
                cur = nxt[cur];
            }while(cur != i);
            int cur_cycle_len = cur_cycle.size();
            for(int j = 0; j < cur_cycle_len ; j++){
                int x = cur_cycle[j];
                cycle_id[x] = cid;
                cycle_pos[x] = j;
            }
            cycle_len.push_back(cur_cycle_len);
            cid++;
        }

    }

    // rev BFS => fill dist_to_cycle and cid for each node
    vector<int>cycle_dist(n+1, INT_MAX);
    queue<int>q2;
    for(int i = 1; i <= n; i++){
        if(in_cycle[i]){
            cycle_dist[i]=0;
            q2.push(i);
        }
    }

    while(!q2.empty()){
        auto cur = q2.front();
        q2.pop();
        for(int node : rev[cur]){
            if(!in_cycle[node] && cycle_dist[node]==INT_MAX){
                cycle_dist[node] = cycle_dist[cur]+1;
                cycle_id[node] = cycle_id[cur];
                q2.push(node);
            }
        }
    }

    auto steps_on_cycle = [&](int a, int b, int len)->int {
        int d = b - a;
        if(d < 0) d+=len;
        return d;
    };

    while(qq--){
        int st, ed;
        cin >> st >> ed;
        bool st_in_cycle = (cycle_dist[st]==0);
        bool ed_in_cycle = (cycle_dist[ed]==0);

        ll ans = -1;

        // 1. a b diff cycle => cant go

        
        // 2. a outside b outside => check if a/b can pass through b/a
        if(!ed_in_cycle){
            int st_dist = cycle_dist[st];
            int ed_dist = cycle_dist[ed];
            if(st_dist >= ed_dist){
                if(lift(st, st_dist - ed_dist) == ed){
                    ans = st_dist - ed_dist;
                }
            }
        }else{
        // 3. a inside b inside => check dist_cycle a b
            if(st_in_cycle){
                if(cycle_id[st] == cycle_id[ed]){
                    int len = cycle_len[cycle_id[st]];
                    ans = steps_on_cycle(cycle_pos[st], cycle_pos[ed], len);
                }
            }
        // 4. a outside b inside => a go to cycle then go to b
            else{
                int st_dist = cycle_dist[st];
                int node = lift(st,st_dist);
                if(cycle_id[node] == cycle_id[ed]){
                    int len = cycle_len[cycle_id[ed]];
                    ans = steps_on_cycle(cycle_pos[node], cycle_pos[ed], len) + st_dist;
                }
            }

        }

        cout << ans << endl;
    }


    
    return 0;
}
// g++ .\CSEStmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
