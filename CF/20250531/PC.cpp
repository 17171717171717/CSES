#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debug(x) cout << #x << " = " << x << "\n";
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
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
#define INF 1e9+5

int mod = 998244353;
const int MAXA = 5000;
int gcd_table[MAXA + 1][MAXA + 1];


int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}


void preprocess_gcd() {
    for (int i = 1; i <= MAXA; i++) {
        gcd_table[i][i] = i;
        for (int j = i + 1; j <= MAXA; j++) {
            int g = gcd(i, j);
            gcd_table[i][j] = g;
            gcd_table[j][i] = g; // gcd 對稱性
        }
    }
}

signed main()
{
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int kase;
    preprocess_gcd();
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<int>v(n);
        REP(i,n){
            cin >> v[i]; 
        }

        int gcd_ = v[0];
        for(int i = 1; i < n; i++){
            gcd_ = gcd(v[i],gcd_);
        }

        bool has_g = false;
        int not_g = 0;
        for(int i = 0; i < n; i++){
            if(v[i]==gcd_){
                has_g = true;
            }else{
                not_g++;
            }
        }

        if(has_g){
            cout << not_g << endl;
            continue;
        }
        
        
        int max_val = 0;
        for(int i = 0; i < n; i++){
            v[i] /= gcd_;
            max_val = max(max_val, v[i]);
        }

        //dp[x] => min trans to x
        vector<int>dp(max_val+1,LLONG_MAX);

        for(int x : v){
            dp[x] = 0;
        }

        for(int i = max_val; i>=1 ; i--){
            if(dp[i]==LLONG_MAX)continue;

            for(int ai : v){
                int y = gcd_table[i][ai];
                dp[y] = min(dp[y],dp[i]+1);
            }
        }


        int ans = dp[1] + (n-1);
        cout << ans << endl;


    } 
    
    return 0;
// g++ -std=c++17 .\CFtmp.cpp  -Dlocal -o tmp
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


