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
// https://www.youtube.com/watch?v=jgEcICsn_6c
// Brute force 做pre降時間，找到pre[i-1]做set可以找出a<=len<=b的最大pre[i+len]-pre[i-1]
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n; 
    cin>>n;

    vi dp(n+6);

    dp[0] = 1;//for i = 1~6 self +1
    for(int i = 1; i<=n ; i++){
        for(int j =1; j <=6 ; j++){
            if(j > i)break;
            dp[i] += dp[i-j];
            dp[i] = dp[i] % (1000000007);
        }
    }

    cout << dp[n];


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

