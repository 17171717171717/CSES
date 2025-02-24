#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define debug(x) cout << #x << " = " << x << "\n";
template <typename T>
using vec = vector<T>;
#define pb push_back
#define mp make_pair
#define al(x) x.begin(), x.end()
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

int mod = 1e9+7;


signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    
    int n;
    cin >> n;
    vi v(n);
    vvi dp(n, vi(n));
    vi pre(n+1);
    vin(v);
    pre[1] = v[0];
    // pre[1] = v[1], pre[2] = v[1]+v[2]
    for(int i = 1; i <= n ; i++){
        pre[i] = v[i-1];
        pre[i] += pre[i-1];
    }
    // ie(debugv(pre));

    // for(int i = 0; i < n; i++){
    //     cin >> pre[i+1];
    //     pre[i+1] += pre[i]; 
    // }


    // dp[i][j] is the best for first one in [i,j]
    // pre[j] is 1 +~ j
    // pre[j]- pre[i] is sum [i+1 , j], index need move forward one step
    
    for(int i = 0; i < n; i++){
        dp[i][i] = v[i];
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = i+1 ; j < n; j++){
            dp[i][j] = max( pre[j+1]-pre[i] - dp[i+1][j],
                            pre[j+1]-pre[i] - dp[i][j-1]);
        }
    }
    cout << dp[0][n-1];
    // int total = 0;

    // for(int i = 0 ; i < n ; i++){
    //     cin >> v[i];
    //     dp[i][i] = v[i];
    //     total += v[i];
    // }

// score A+B = total
// => sA up , sB down
// => sA sB can swap, we can assume sA always > sB
// => want diff between sA and sB (aka sA - sB) as big as possible
// => sA + sB = total
// => sA - sB = dp[0][n-1]
// => A get v[l] => dpB(diff_B) get dp[l+1][r]
// => dp[i][j] = max v[i] - dp[i+1] or [j-1] also 
//                          1.equal to sB-sA 
//                          2.sB > sA
// => so dp[i][j]為 (sA - sB) 最好結果 為 dp[0][n-1] 最好結果
 
 
    // for(int l = n-1; l >= 0 ; l--){
    //     for(int r = l+1; r < n; r++){
    //         int pL = v[l] - dp[l+1][r];
    //         int pR = v[r] - dp[l][r-1];
    //         dp[l][r] = max(pL, pR);
    //     }
    // }

    // cout << (total + dp[0][n-1])/2;
    return 0;
    // g++ .\tmp.cpp -Dlocal -o tmp  
    // .\tmp.exe   
    


}


