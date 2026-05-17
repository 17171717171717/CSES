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
int f(int n){
  return n-n/2-n/3-n/5-n/7+n/6+n/10+n/14+n/15+n/21+n/35-n/30-n/42-n/70-n/105+n/210;
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
        vi v(n);
        vin(v);
        vector<int>premin(n);
        vector<int>sufmax(n);
        int pre_cur = INT_MAX;
        for(int i = 0; i < n; i++){
            pre_cur = min(pre_cur, v[i]);
            premin[i] = pre_cur;
        }
        int suf_cur = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            suf_cur = max(suf_cur, v[i]);
            sufmax[i] = suf_cur;
        }
        bool ok = false; 
        for(int i = 0; i <= n-1; i++){
            if(i==n-1){
                cout << "Yes" << endl;
                ok = true;
                break;
            }
            if(premin[i] > sufmax[i+1]){
                cout << "No" << endl;
                break;
            }
        }
        if(!ok)continue;
        

        vector<int>teams;
        int cur_min = INT_MAX;
        for(int i = 0; i < n; i++){
            if(v[i]<cur_min){
                cur_min = v[i];
                teams.pb(i);
            }
        }

        int team_id = 0;
        for(int i = 0; i < n; i++){
            if(team_id < teams.size()-1 && i==teams[team_id+1])team_id++;

            if(v[i] != v[teams[team_id]]){
                cout << v[teams[team_id]] << " " << v[i] << endl;
            }
        }

        int bridge_team_id = 0;
        for(int i = 0; i < teams.size()-1; i++){
            bridge_team_id = max(bridge_team_id, teams[i+1]+1);
            while (bridge_team_id < n) {
                    if (v[bridge_team_id] > v[teams[i]]) {
                        
                        cout << v[teams[i]] << " " << v[bridge_team_id] << endl;
                        
                        break; 
                    }
                    
                    bridge_team_id++;
                }
        }
        
    } 
    
    return 0;
// g++ -std=c++17 .\CFtmp.cpp  -Dlocal -o tmp
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


