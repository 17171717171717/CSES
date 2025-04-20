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
    str s;
    vec<str>g(n);
    pii st,ed;
    vec<vec<bool>> vis(n,vec<bool>(m,false));
    vec<vec<int>> steps_record(n,vec<int>(m,-1));
    for (int i = 0; i < n; i++){
        cin >> g[i];
        
        for (int j = 0; j < m; j++){
            if(g[i][j]=='A') st = mp(i,j);
            if(g[i][j]=='B') ed = mp(i,j);
            
        }
    }
    vis[st.F][st.S] = true;
    queue<pii>q;
    q.push(st);
    int ans = 0;
    bool ok = false;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();

        for (int k = 0 ; k < 4; k++){
            int new_i = cur.F + dirs[k][0];
            int new_j = cur.S + dirs[k][1];
            if(0 <= new_i && new_i < n && 0 <= new_j && new_j < m && !vis[new_i][new_j] && g[new_i][new_j]!='#'){
                q.push(mp(new_i,new_j));
                vis[new_i][new_j] = 1;
                steps_record[new_i][new_j] = k;
                if(mp(new_i,new_j)==ed)ok = true;
            } 
        }
        if(ok)break;
    }
    ie(debug(vis[ed.F][ed.S]))

    
    vec<char>steps;
    if(vis[ed.F][ed.S]){
        cout << "YES" << endl;
        while(ed != st){
            int k =(steps_record[ed.F][ed.S]);
            steps.pb(k);
            ed = mp(ed.F - dirs[k][0], ed.S - dirs[k][1]);
        }
        cout << steps.size() << endl;
        for(int i = steps.size()-1 ; i>=0 ; i--){
            cout << dirs_eng[steps[i]];
        }
    }else{
        cout << "NO" << endl;
    }


    return 0;
    // g++ .\tmp.cpp -Dlocal -o tmp  
    // .\tmp.exe   
    


}
