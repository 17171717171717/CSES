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
// https://hackmd.io/@RaisoLiu/S1XI2aXmi
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n,x;
    cin >> n ;
    // vi v(n);
    // vin(v);
    // sort(al(v));
    vi dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n ; i++){
        // bottom up, 一個一個試
        // dp[10] => dp[9]有了
        // dp[12] => dp[11] , dp[10]都有
        for(int j = i; j > 0 ; j/=10){
            if(j%10 > 0){
                dp[i] = min(dp[i],dp[i-(j%10)]+1);
            }
        }
    }
    cout<< dp[n];

    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

