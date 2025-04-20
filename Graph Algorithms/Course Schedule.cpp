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
// #define min_pq(type) priority_queue<type, vector<type>, greater<type>>
// big to small
// #define pq(type) priority_queue<type>
const double eps = 1e9+7;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef local
    #define ie(x) x
#else
    #define ie(x)
#endif
const int INF = 9e15;
const int mod = 1e9+7;

vvi dirs = {{-1,0},{1,0},{0,1},{0,-1}};
// vec<char>dirs_eng = {'L','R','U','D'}; 
vec<char>dirs_eng = {'U','D','R','L'};// -1,0 => Down 


signed main() {
    fastios;
    
    ie(freopen("test_input.txt", "r", stdin);)

    int n, m;
    cin >> n >> m ;
    vector<vector<int>>g(n);
    vector<int>indeg(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b); // a before b => a -> b;
        indeg[b]++;
    }
    queue<int>q;
    for(int i =0 ; i < n ; i++){
        if(indeg[i] ==0)q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.pb(cur+1);
        for(auto nxt : g[cur]){
            if(!(--indeg[nxt]))q.push(nxt);

            
        }
    }

    int total = ans.size();
    if(total == n){
        for (int a : ans) cout << a << " ";
    }else cout<<"IMPOSSIBLE";

    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
