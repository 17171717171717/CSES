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


signed main()
{
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int kase;
    cin >> kase;
    while(kase--){
        int n ;
        cin >> n;
        vector<int>v(n);
        vin(v);
        REP(i,n){
            v[i] = v[i] % 3;
        }

        vi pre(n);
        pre[0] = v[0];
        for(int i = 1; i < n; i++){
            pre[i] = (v[i] + pre[i-1]);
            
        }
        int ans1 = 0, ans2 = 0;
        ie(debugv(pre););
        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++ ){
                int s1 = pre[i]%3;
                int s2 = (pre[j] - pre[i])%3;
                int s3 = (pre[n-1] - pre[j])%3;
                if(s1 == s2 && s2 == s3){
                    ans1 = i+1;
                    ans2 = j+1;
                }else if(s1 != s2 && s1 != s3 && s2 != s3){
                    ans1 = i+1;
                    ans2 = j+1;
                }
            }
        }
        cout << ans1 <<" " << ans2 << endl;
    }
    
    return 0;
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


