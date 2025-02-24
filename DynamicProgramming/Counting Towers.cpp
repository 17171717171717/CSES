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

ll dp[1000002][2];
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
	// dp[i][0] = number of ways to add rectangles to the 2*i squares such that the last 2 squares are united
	// dp[i][1] = number of ways to add rectangles to the 2*i squares such that the last 2 squares are not united
	dp[1][0] = 1, dp[1][1] = 1;
	for(int i = 1; i < 1000000; ++i)
	{
		dp[i][0] %= mod;
		dp[i][1] %= mod;
		dp[i+1][0] += 2*dp[i][0];
		dp[i+1][1] += dp[i][0];
		dp[i+1][0] += dp[i][1];
		dp[i+1][1] += 4*dp[i][1];
	}
	int t;
	cin >> t;
	for(; t; --t)
	{
		int n;
		cin >> n;
		ll ans = dp[n][0] + dp[n][1];
		ans %= mod;
		cout << ans << '\n';
	}


    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

