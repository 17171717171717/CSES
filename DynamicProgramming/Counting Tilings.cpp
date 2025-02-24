#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].first >> v[i].second;
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define debug(x) cout << #x << " = " << x << "\n";
template <typename T>
using vec = vector<T>;
#define pb push_back
#define mp make_pair
#define al(x) (x).begin(), (x).end()
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

const int mod = 1e9+7;

int dp[1001][(1<<10)] = {0};
int n, m;

void fill_col(int col, int cur_square, int cur_col_stat, int next_col_stat){
    if(cur_square == n){//finished this col
        dp[col+1][next_col_stat] = (dp[col+1][next_col_stat]+ 
                                  dp[col][cur_col_stat]) % mod;
        return;
    }

    if((cur_col_stat)&(1<<cur_square)){// the square is occupied
        fill_col(col, cur_square+1, cur_col_stat, next_col_stat);
    }
    else{
        // put a horizontal
        fill_col(col, cur_square+1, cur_col_stat, next_col_stat | (1<<cur_square));//occupy this one
        
        // put a vertical
        if((cur_square +1) < n && (!(cur_col_stat & (1<<(cur_square+1))))){
            fill_col(col, cur_square+2, cur_col_stat, next_col_stat);
        }
    }
     
}

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    
    cin >> n >> m;
    dp[0][0] = 1;
    for(int col = 0; col < m; col++){
        for(int stat = 0; stat < (1<<n); stat++){
            if(dp[col][stat] > 0){//there is at least a way to reach
                fill_col(col, 0, stat, 0);
            }

        }
    }
    cout << dp[m][0];//0~m-1 in m is empty
    

    return 0;
    // g++ .\tmp.cpp -Dlocal -o tmp  
    // .\tmp.exe   
    


}
