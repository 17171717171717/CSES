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


// vector<ll> op(ll V, ll C, ll C_target, vector<ll>v){
//     // cout <<"CC: "<< C<<" VV: "<< V<<" C_target: "<< C_target <<" ans: "<< v[0]<< endl;
//     // cout << v[0] << endl;
//     // if(v[0]){
//     //     for(int i = 1; i <= v[0]; i++){
//     //         cout << v[i] << " ";
//     //     }
//     //     cout <<  endl;
//     // }
//     if(C == C_target){
//         cout << v[0] << endl;
//         if(v[0]){
//             for(int i = 1; i <= v[0]; i++){
//                 cout << v[i] << " ";
//             }
//         }
//         cout <<  endl;
//         return v;
//     }
//     if(v[0]==-1 || V == 0 || C == 0 || v[0]>120 ){
//         v[0] = -1;
//         return v;
//     }
//     vector<ll> ok1 = v;
//     vector<ll> res1 = v;
//     vector<ll> ok2 = v;
//     vector<ll> res2 = v;

//     if(!(V%2)){
//         ok1.push_back(2);
//         ok1[0] += 1;
//         res1 = op(V/2, C+(V/2),C_target, ok1);
//     }else{
//         res1[0] = -1;
//     }

//     if(!(C%2)){
//         ok2.push_back(1);
//         ok2[0] += 1;
//         res2 = op(V+C/2, C/2,C_target, ok2);
//     }else{
//         res2[0] = -1;
//     }


//     if(res1[0] != -1 && res2[0] != -1){
//         return res1[0] < res2[0] ? res1 : res2;
//     }else if(res1[0] != -1){
//         return res1;
//     }else if(ok2[0] != -1){
//         return res2;
//     }

//     v[0] = -1;
//     v.pop_back();
//     return v;
    
// }
signed main()
{
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int kase;
    cin >> kase;
    while(kase--){
        ll k, Chocola_target;
        cin >> k >> Chocola_target;
        ll total =1LL<<(k+1);
        ll Vanilla_target = total - Chocola_target;
        vector<int>ans;
        // (a, b) -> (2^k, 2^k)
        while(Vanilla_target != Chocola_target){
            if(Vanilla_target < Chocola_target){
                ans.pb(2);
                Chocola_target -= Vanilla_target;
                Vanilla_target *= 2;
            }
            else if(Vanilla_target > Chocola_target){
                ans.pb(1);
                Vanilla_target -= Chocola_target;
                Chocola_target *= 2;
            }
        } 
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << "\n";
    }
    
    return 0;
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


