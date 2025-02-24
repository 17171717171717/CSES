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
    
    int n,m;
    cin>>n>>m;
    int tmp;
    cin>>tmp;
    int dp[100010][110];
    if(tmp==0){
        for(int j=1;j<=m;j++){
            dp[1][j]=1;
        }
    }else{
        dp[1][tmp]=1;
    }
    for(int i=2;i<=n;i++){
        cin>>tmp;
        if(tmp==0){
            for(int j=1;j<=m;j++){
                dp[i][j]=((dp[i-1][j-1]+dp[i-1][j])%mod+dp[i-1][j+1])%mod;
            }
        }else{
            dp[i][tmp]=((dp[i-1][tmp-1]+dp[i-1][tmp])%mod+dp[i-1][tmp+1])%mod;
        }
    }
    if(tmp==0){
        int answer=0;
        for(int i=1;i<=m;i++){
            answer=(answer+dp[n][i])%mod;
        }
        cout<<answer;
    }else{
        cout<<dp[n][tmp];
    }

    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

