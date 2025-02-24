#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debugvec(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
template <typename T>
using vec = vector<T>;
#define pb push_back
#define mp make_pair
#define al(x) x.begin(), x.end()
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vpii = vector<pair<int,int>>;
using ll = long long ;
using str = string;
using um = unordered_map<int,int>;
#define F first
#define S second
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
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
// https://www.youtube.com/watch?v=Zu_-Hmn_sxE

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n,x;
    cin >> n >> x;
    vi v(n);
    vin(v);
    sort(al(v));
    vi dp(x+1);
    dp[0] = 1;
    // 前i個coins可以組合出來的先記起來，並且dp[s]內前面都是由前i個組成
    // e.g 第一個coin = 2, dp[2]~dp[8]都是用2組成
    // 第二個 coin = 3 => dp[5]為dp[2]+一個3組成，dp[8]為dp[5]+1個3組成
    // 第三個 coin = 5 => dp[8]為dp[3]+一個5組成，d[13]為1 3 5組成且前面固定
    for(int i =0; i < n ; i++){
        for(int j = v[i]; j <= x; j++){
            dp[j] += dp[j-v[i]];
            dp[j] %= 1000000007;
        }
    }
    cout<< dp[x];

    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

