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



signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    // 把每個cycle都拿出來 平攤成vector
    // 然後看會走到哪個cycle
    // 不在cycle內的 要走 cycle長度+走到cycle的距離
    // 在的直接走就好

    // 判斷在cycle內外: 在內的走k步可以回到自己
    // 可以用走到vis[i] == true, 然後那一個人開始走一圈 就可以裝這些人在cycle內
    // 所以一開始就可以precompute每個人在哪個cycle, 在不在cycle內
    // 每個人最終都會走進cycle內


    int n;
    cin >> n;
    vector<int>v(n);
    vector<bool>vis(n, false);
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        tmp--;
        v[i] = tmp;
    }

    vector<vector<int>>cycles;

    auto dfs = []()
    for(int i = 0; i < n; i++){
        if(vis[i])continue;
        vis[i] = true;
    }

   
    return 0;
}
// g++ .\CSEStmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
