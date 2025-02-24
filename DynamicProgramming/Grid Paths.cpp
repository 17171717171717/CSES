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

int mod = 1e9+7;
// https://hackmd.io/@RaisoLiu/S1XI2aXmi
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int i= 0; i<n;i++){
        for(int j =0; j < n; j++){
            cin>>v[i][j];
            ie(cout << v[i][j]);
        }
        ie(cout << endl;)
    }
    if(v[0][0] == '*'){
        cout<<0;
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==0 && j==0)continue;
            if(v[i][j]=='*'){
                dp[i][j] = 0;
            }
            
            else if(i == 0 ){
                if( j>0 && dp[i][j-1] == 0)dp[i][j] = 0;
                else dp[i][j]=1;
                ie(cout<<dp[i][j];)
            }
            else if(j == 0 ){
                if( i>0 && dp[i-1][j] == 0)dp[i][j] = 0;
                else dp[i][j]=1;
                ie(cout<<" j==0 : "<<dp[i][j];)
            }
            else{
                dp[i][j] = dp[i-1][j];
                dp[i][j] %= mod;
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    ie(
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j]=='*' || dp[i][j]==INT_MAX)cout<<'*';
            else cout << dp[i][j];
        }
        cout << endl;
    }
    )
    cout<< dp[n-1][n-1];

    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

