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

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}
bool isprime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0)return false;
    }
    return true;
}
vector<int> genprime(){
    int limit = 1e18;
    int cur = 2;
    vector<int>primes{2};
    for(int i = 3; ;i++){
        if(isprime(i)){
            primes.push_back(i);
            cur*=i;
            if(cur > limit)return primes;
        }
    }
}
signed main()
{
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int min_gcd = v[0];
        for(int i = 0; i < n-1; i++){
            min_gcd=gcd(min_gcd, v[i+1]);
        }
        vector<int>primes = genprime();

        for(auto p : primes){
            int x = gcd(min_gcd,p);
            if(x==1){
                cout << p << endl;
                break;
            }
        }
    } 
    
    return 0;
// g++ -std=c++17 .\CFtmp.cpp  -Dlocal -o tmp
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


