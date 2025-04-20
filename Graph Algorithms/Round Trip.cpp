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

vvi g;
vi ans;
int n,m;
vector<bool> vis;
vi path;
bool ok;

// bool dfs(int cur, int pre, vi &ans){
//     ie(cout << "cur " << cur << endl;)
//     int ansSize = ans.size();
//     if(vis[cur] && ansSize>2) // two or more
//     {
//         int aans =0;
//         ok = true;
//         for(int i = ansSize-1; i >=0 ; i++){
//             aans++;
//             if(ans[i] == cur)break;
//         }
//         ie(debugv(ans))
//         ie(cout << "ans size: " ;)
//         cout << aans+1 << endl;
//         cout << cur+1 << " ";
//         // ie(debugv(ans))
//         for(int i = ansSize-1; i >=0 ; i--){
//             cout << ans[i]+1 << " ";
//             if(ans[i] == cur)break;
//         }
//         return true;
//     }

//     vis[cur] = true;
//     ans.pb(cur);
//     bool tmpRes;
//     for(auto nxt : g[cur]){
//         // if(vis[nxt]==true)continue;
//         if(pre==nxt)continue;
//         tmpRes = dfs(nxt,cur,ans);
//         if(ok)return true;
//         else{
//             ans.pop_back();
//         }
//     }

//     return false;
//     return tmpRes;

    

// }
  
// signed main()
// {
//     fastios
//     ie(freopen("test_input.txt", "r", stdin);)

//     // bfs sol
//     cin >> n >> m;
//     vvi tmp(n);
//     for(int i = 0; i < m;i++){
//         int a, b;
//         cin >> a >> b;
//         tmp[a-1].pb(b-1);
//         tmp[b-1].pb(a-1);
//     }
//     g = tmp;
//     vis = vec<bool>(n,false);
//     ie(
//         for(auto gg : g){
//             debugv(gg)
//         }
//     )
    

//     for(int i = 0; i < n; i++){
//         if(!vis[i] && g[i].size()>0){
//             vi tmppp;
//             ans = tmppp;
//             ie(cout << "start i "<<i<<endl;)
//             if(dfs(i,-1,ans))break;
//         }
//     }
//     if(!ok)cout <<  "IMPOSSIBLE";
//     return 0;
//     // g++ .\tmp.cpp -Dlocal -o tmp  
//     // .\tmp.exe   
    

// }

bool dfs(int cur, int pre) {
    vis[cur] = true;
    ans.pb(cur);

    for (auto nxt : g[cur]) {
        if (nxt == pre) continue; // 不走回头路
        if (vis[nxt]) { // 找到环
            int cycle_length = 1;
            vi tmp = ans;
            
            while (ans.back() != nxt) {
                cycle_length++;
                ans.pop_back();
            }
            ans = tmp;
            cout << cycle_length + 1 << endl;
            cout << nxt + 1 << " ";
            for (auto it = ans.rbegin(); *it != nxt; it++)
                cout << *it + 1 << " ";
            cout << nxt + 1 << " ";
            
            cout << endl;
            return true;
        }
        if (dfs(nxt, cur)) return true;
    }

    ans.pop_back(); // 回溯
    return false;
}

signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    cin >> n >> m;
    g.resize(n);
    vis.assign(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].pb(b - 1);
        g[b - 1].pb(a - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i] && !g[i].empty()) {
            ans.clear();
            if (dfs(i, -1)) return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
