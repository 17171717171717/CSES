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
    
    vector<int>twos(1e5+1);
    twos[0] = 1;
    for(int i = 1; i < twos.size(); i++){
        twos[i] = twos[i-1]*2;
        twos[i] = twos[i] % 998244353;
    }
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        vector<int>q(n);
        REP(i,n){
            cin >> q[i];
        }
        vector<int>p(n);
        
        REP(i,n){
            cin >> p[i];
        }
        vector<int>ans;
        int q_idx = 0;
        int p_idx = 0;
        for(int i = 0 ; i < n; i++){
            if(q[q_idx] <= q[i]){
                q_idx = i;
            }
            if(p[p_idx] <= p[i]){
                p_idx = i;
            }

            if(q[q_idx] > p[p_idx]){
                ans.push_back((twos[q[q_idx]]+twos[p[i-q_idx]])%998244353);
            }else if(q[q_idx] < p[p_idx]){
                ans.push_back((twos[p[p_idx]]+twos[q[i-p_idx]])%998244353);
            }else{
                if(q[i-p_idx] >= p[i-q_idx]){                    
                    ans.push_back((twos[p[p_idx]]+twos[q[i-p_idx]])%998244353);
                }else{
                    ans.push_back((twos[p[i-q_idx]]+twos[q[q_idx]])%998244353);
                }
            }
            cout<< ans[i] << " ";
        }
        cout << endl;
    } 
    
    return 0;
// g++ -std=c++17 .\CFtmp.cpp  -Dlocal -o tmp
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


