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

    
    int a,b;
    cin >> a >> b;
    int m = max(a,b);
    vector<vector<int>> dp(m+1, vector<int>(m + 1, INT_MAX));
    for(int i = 0; i<=m ; i++)dp[i][i] = 0;
    for(int i =1; i <= a ; i++){
        for(int j=1; j<=b; j++){
            for(int cut = 1 ; cut < i ; cut++){
                dp[i][j] = min(dp[i][j], dp[cut][j] + dp[i-cut][j]+1 );
            }
            for(int cut = 1 ; cut < j ; cut++){
                dp[i][j] = min(dp[i][j], dp[i][cut] + dp[i][j-cut]+1 );
            }
        }
    }
    cout<<dp[a][b];



    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

