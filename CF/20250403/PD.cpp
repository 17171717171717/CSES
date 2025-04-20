#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debug(x) cout << #x << " = " << x << "\n";
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

int mod = 998244353;

int fastpow(int x, int n) {
    x %= mod;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    int p = fastpow(x * x, n / 2);
    if (n % 2)
        return p * x % mod;
    else
        return p ;
}
// ans / x % MOD = (ans * x⁻¹) % MOD
// x⁻¹ ≡ x^(MOD - 2) (mod MOD)
int mod_div(int p, int q){
    return p % mod * fastpow(q, mod - 2) % mod; 
}
 
vector<int> fact, ifact;

void factCompute(int N = 1e6) {
    fact.assign(N + 1, 1);
    ifact.assign(N + 1, 1);
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i - 1] * i % mod;
    ifact[N] = mod_div(1, fact[N]);
    for (int i = N - 1; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
}

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    factCompute(1e6);

    int kase;
    cin >> kase;
    while(kase--){
        int n;
        // cin >> n;
        vector<int>c(27);
        // | i - j | % 2 = 0 => i % 2 - j % 2 = 0 => even+even or odd+odd
        // odd pos = ceil(n), even pos = floor(n)

        
        for(int i = 1; i <= 26; i++){
            cin >> c[i];
        }
        n = accumulate(c.begin(), c.end(), 0LL);



        // dp[x][i] = 取i個某些chars(必須全放)，有x格odd可以放的組合數(even自動分配給剩下的格子)
        // dp[x][i] = dp[x][i-1] + dp[x-c[i]][i-1]
        // dp[n/2][26]
        // char只能擺a的情況在1 2 3...n格有幾種擺法  
        // => 必須放在odd or even 所以只需要dp[1][n/2]
        // char可以擺a,b的情況在1 2 3...n格有幾種擺法  
        // => dp[2][1...n/2] = 
        // 1.不加入b dp[2-1][i]
        // 2.加入b dp[2-1][i-c[2]] (b出現的次數扣掉)在a能擺幾種

        vector<vector<int>> dp(27, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= 26; i++) {
            for (int j = 0; j <= n / 2; j++) {
                dp[i][j] = dp[i - 1][j];
                if (c[i] > 0 && j - c[i] >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - c[i]]) % mod;
            }
        } // 26*n
        int ans = dp[26][n / 2] * fact[n / 2] % mod * fact[(n + 1) / 2] % mod;
     

        // ans = n! / (a! * b! * c!)
        // =>
        // ans = fact(n);
        // ans = (ans * bpow(fact(a), MOD - 2)) % MOD;
        // ans = (ans * bpow(fact(b), MOD - 2)) % MOD;
        // ans = (ans * bpow(fact(c), MOD - 2)) % MOD;
        
        // ans / x % MOD = (ans * x⁻¹) % MOD
        // x⁻¹ ≡ x^(MOD - 2) (mod MOD)
        for (int i = 1; i <= 26; i++) {
            ans = mod_div(ans, fact[c[i]]);
        } // 26*log(ci)

        cout << ans << endl;
    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

