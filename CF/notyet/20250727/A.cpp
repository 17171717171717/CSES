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

int sol(int r) {
   
    int a = 2, b = 3, c = 5, d = 7;
    int ab = a * b;
    int ac = a * c;
    int ad = a * d;
    int bc = b * c;
    int bd = b * d;
    int cd = c * d;
    int abc = a * b * c;
    int abd = a * b * d;
    int bcd = b * c * d;
    int abcd = a * bcd;


    int ans = 0;
    int ans_a = r / a;
    int ans_b = r / b;
    int ans_c = r / c;
    int ans_d = r / d;
    int ans_ab = r / ab;
    int ans_ac = r / ac;
    int ans_ad = r / ad;
    int ans_bc = r / bc;
    int ans_bd = r / bd;
    int ans_cd = r / cd;
    int ans_abc = r / abc;
    int ans_abd = r / abd;
    int ans_bcd = r / bcd;
    int ans_abcd = r / abcd;

    ans = ans_a + ans_b + ans_c + ans_d - (ans_ab + ans_ac + ans_ad + ans_bc + ans_bd + ans_cd) + (ans_abc + ans_abd + ans_bcd) - (ans_abcd);
    return ans;
}

signed main()
{
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int kase;
    cin >> kase;
    while(kase--){
        int n, c;
        cin >> n >> c;
        vector<int>v(n);
        REP(i,n){
            cin >> v[i];
        }
        int ans = n;
        sort(al(v));
        // cout << v[0] << endl;
        for(int i = 0 ; i < n; i++){
            for(int j = n-1 ; j>=0; j--){
                if(v[j]<=c){
                    ans--;
                    v[j] = c+1;
                    while(j--){
                        v[j]*=2;
                    }
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


