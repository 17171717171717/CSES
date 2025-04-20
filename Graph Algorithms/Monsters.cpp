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

    
    cin >> n >> m;
    vec<str> g(n);
    REP(i,n){
        cin >> g[i];
    }
    queue<pii>q,m_q;
    vec<vec<int>>m_step(n,vec<int>(m,INT_MAX));
    vvi step = m_step;
    vec<vec<pii>>come_way(n,vec<pii>(m,{2,2}));

    int sx,sy;
    REP(i,n){
        REP(j,m){
            if(g[i][j]=='M'){
                m_step[i][j] = 0;
                m_q.push(mp(i,j));
            }
            if(g[i][j]=='A'){
                step[i][j] = 0;
                q.push(mp(i,j));
                sx = i;
                sy = j;
            }
        }
    }

    // monster multi src BFS
    while(!m_q.empty()){
        auto cur = m_q.front();
        m_q.pop();
        int mx = cur.F;
        int my = cur.S;
        for(int i = 0 ; i < 4; i++){
            int nxtx = mx + dirs[i][0];
            int nxty = my + dirs[i][1];
            
            if(nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && g[nxtx][nxty] != '#' 
                && m_step[nxtx][nxty] == INT_MAX){//bfs, so small steps go first
                    
                        
                m_step[nxtx][nxty] = m_step[mx][my]+1;
                m_q.push(mp(nxtx,nxty));
            }
        }
    }
    ie(
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m ; j++){
                cout << m_step[i][j];
            }
            cout << endl;
        }
    )
    // return 0;
    int ans = 0;
    pii ans_loc = {-100,-100};
    bool ok = false;
    int ansx = -1;
    int ansy = -1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int curx = cur.F;
        int cury = cur.S;
        ie(debug(curx))
        ie(debug(cury))
        g[sx][sy] = '#';
        for(int i = 0 ; i < 4; i++){
            int nxtx = curx + dirs[i][0];
            int nxty = cury + dirs[i][1];
            
            if(nxtx >= n || nxtx < 0 || nxty >= m || nxty < 0 ){
                ans = step[curx][cury];
                ans_loc =  mp(dirs[i][0],dirs[i][1]);
                ansx = curx;
                ansy = cury;
                ie(debug(ansx))
                ie(debug(ansy))
                ie(debug(ans_loc.F))
                ie(debug(ans_loc.S))
                ok = true;
                break;
            }

            ie(debug(nxtx))
            ie(debug(nxty))
            ie(debug(step[curx][cury]))
            ie(debug(step[nxtx][nxty]))
            ie(debug(m_step[nxtx][nxty]))

            if(nxtx>=0 && nxtx < n && nxty>=0 && nxty<m && g[nxtx][nxty]!='#' 
                && step[nxtx][nxty] == INT_MAX
                && step[curx][cury]+1 < m_step[nxtx][nxty]){//monster nxt 5: A cur 3 => nxt 4 => ok
                
                
                step[nxtx][nxty] = step[curx][cury]+1;
                come_way[nxtx][nxty] = mp(dirs[i][0],dirs[i][1]);//-1,0 => Down 
                q.push(mp(nxtx,nxty));
                ie(debug(nxtx))
                ie(debug(nxty))
                ie(debug(step[curx][cury]))
                ie(debug(m_step[nxtx][nxty]))

            }
        }
        if(ok)break;
    }
    vec<char>ans_dir;
    if(ok){
        cout << "YES" << endl;
        cout << ans << endl;
        if(ans==0)return 0;

        ie(debug(ansx))
        ie(debug(ansy))
        ie(debug(ans_loc.F))
        ie(debug(ans_loc.S))
        ie(debug(dirs[0][0]))
        ie(debug(dirs[0][1]))
        for(int i = 0; i < 4 ; i++){
            ie(debug(ansx))
            ie(debug(ansy))
            if(ans_loc.F == dirs[i][0] && ans_loc.S == dirs[i][1]){
                ans_dir.pb(dirs_eng[i]);
                ansx -= dirs[i][0];
                ansy -= dirs[i][1];        
                ie(debug(ansx))
                ie(debug(ansy))
                break;
            }
        }
        ie(debug(ansx))
        ie(debug(sx))
        ie(debug(ansy))
        ie(debug(sy))
        while((ansx != sx) || (ansy != sy)){
            int cur_x = come_way[ansx][ansy].F;
            int cur_y = come_way[ansx][ansy].S;
            ie(debug(cur_x))
            ie(debug(cur_y))
            for(int i = 0; i < 4 ; i++){
                if(cur_x == dirs[i][0] && cur_y == dirs[i][1]){
                    ans_dir.pb(dirs_eng[i]);
                    ansx -= dirs[i][0];
                    ansy -= dirs[i][1];
                    break;
                }
            }
        }        
        for (auto it = ans_dir.rbegin(); it != ans_dir.rend(); it++) {
            cout << *it ;
        }
    }
    else{
        cout << "NO";
    }
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
