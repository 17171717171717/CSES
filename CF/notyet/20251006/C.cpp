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
        int n;
        cin >> n;
        str s;
        cin >> s;

        vector<int>as(n,0);
        vector<int>bs(n,0);
        vector<int>badiff(n,0);
        if(s[0]=='a'){
            as[0] = 1;
        }else{
            bs[0] = 1;
        }
        badiff[0] = bs[0] - as[0];

        for(int i = 1; i < n; i++){
            as[i] = as[i-1];
            bs[i] = bs[i-1]; 
            if(s[i] == 'a'){
                as[i]++;
            }else{
                bs[i]++;
            }
            badiff[i] = bs[i] - as[i]; // b cnt - a cnt
        }
        int target = badiff[n-1];
        if(target == 0){
            cout << 0 << endl;
            continue;
        }

        unordered_map<int, int>m; // diff / where
        int ans = n+1;
        m[0] = -1; 

        for(int i = 0; i < n; i++){
            int need_to_diff = badiff[i] - target;
            if(m.count(need_to_diff)){
                int pre = m[need_to_diff];
                ans = min(ans, i - pre);
            }

            // if(m.find(badiff[i])==m.end()){
            //     m[badiff[i]] = i;
            // }
            // if(m.find(badiff[i])==m.end()){
                m[badiff[i]] = i;
            // }
        }

        if(ans >= n){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }


    }
    
    return 0;
// g++ -std=c++17 .\CFtmp.cpp  -Dlocal -o tmp
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


