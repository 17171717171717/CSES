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

vvi dirs = {{-1,0},{1,0},{0,1},{0,-1}};//l r u d


void dfs(int i, int j, vec<vec<char>>&g, int& n, int& m, vec<vec<bool>> &visited){
    visited[i][j] = true;
    for (auto dir : dirs){
        int new_i = i + dir[0];
        int new_j = j + dir[1];
        if(0 <= new_i && new_i < n && 0 <= new_j && new_j < m && !visited[new_i][new_j] && g[new_i][new_j] == '.'){
            dfs(new_i,new_j , g, n, m, visited);
        }
    }
    
    return ;
}

signed main()
{
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int n,m;
    cin >> n >> m;
    // vec<vec<char>>g(n,vec<char>(m));
    // // dfs sol
    // vec<vec<bool>>visited(n,vec<bool>(m,false));
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m ; j++){
    //         cin >> g[i][j];
    //         ie(cout<<g[i][j];)
    //     }
    //     ie(cout << endl;)
    // }

    // int ans = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         if(g[i][j] == '.' && !visited[i][j]){
    //             ans++;
    //             dfs(i,j,g, n,m,visited);
    //         }
    //         else{
    //             visited[i][j] = true;
    //             continue;
    //         }
    //     }
    // }


    // bfs sol
    str s;
    vec<vec<int>>g(n,vec<int>(m));
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < m; j++){
            if (s[j] == '.') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    queue<pii>q;
    int ans = 0;
    for(int i =0 ; i < n ; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 1){
                ans++;
                q.push(mp(i,j));
                while(!q.empty()){
                    pii cur = q.front();
                    q.pop();
                    // g[cur.F][cur.S] = 0;
                    // 不能放在這，會TLE，因為會左右互相放
                    for (auto dir : dirs){
                        int new_i = cur.F + dir[0];
                        int new_j = cur.S + dir[1];
                        if(0 <= new_i && new_i < n && 0 <= new_j && new_j < m && g[new_i][new_j]==1){
                            q.push(mp(new_i,new_j));
                            g[new_i][new_j] = 0;
                        }
                    }

                }
            }
        }
    }
    cout << ans;


    return 0;
    // g++ .\tmp.cpp -Dlocal -o tmp  
    // .\tmp.exe   
    


}
