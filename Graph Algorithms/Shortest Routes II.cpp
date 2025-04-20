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


    int n,m,q;
    cin >> n >> m >> q;
    
    // vec<vec<pii>>g(n);
    vvi ans(n,vi(n,LLONG_MAX));

    REP(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        // g[a].pb(mp(b,c));
        // g[b].pb(mp(a,c));
        ans[a][b] = min(ans[a][b],c);
        ans[b][a] = min(ans[b][a],c);
        // test case have ?????
        // 2 2 1
        // 1 2 1
        // 1 2 2
        // 1 2
    }
    REP(i,n){
        ans[i][i] = 0;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(ans[i][k] == LLONG_MAX || ans[k][j] == LLONG_MAX)continue;
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
    // debug(ans[3][3])
    for(int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(ans[a][b]==LLONG_MAX)
            ans[a][b]=-1;
        cout << ans[a][b] << endl;
    }

    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
