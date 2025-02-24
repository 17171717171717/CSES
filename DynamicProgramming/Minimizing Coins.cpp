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
#define f first
#define s second
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

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n,k; 
    cin>>n>>k;
    vi v(n);
    vin(v);

    vi dp(k+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        // Iterate over all coins
        for (int j = 0; j < n; j++) {
            if(v[j] > i || dp[i-v[j]]==INF )continue;
            // if(v[j] > i  )continue; also work
            dp[i] = min(dp[i], dp[i - v[j]] + 1);
        }
    }
    // If it is possible to make sum = X, return dp[X]


    cout << (dp[k]==1000000000 ?  -1 : dp[k] );


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

