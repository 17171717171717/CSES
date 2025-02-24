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
    vin(v);
    int total = accumulate(al(v), 0LL);
    ie(cout<<"ttoal" << total << endl;)
    // first i coins, can have j value
    vector<vector<bool>>dp(n+1,vector<bool>(total+1,false));
    dp[0][0]=true;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= total; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= v[i-1] && dp[i-1][j-v[i-1]])dp[i][j] = true;
        }
    }
    int ans = 0;
    for(int i = 1; i <= total; i++){
        if(dp[n][i]){
            ans++;
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= total; i++){
        if(dp[n][i]){
            cout << i << " ";
        }
    }

    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

