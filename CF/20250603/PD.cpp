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
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>>floors(m);
        for(auto &f : floors){
            int tmp;
            cin >> tmp;
            f.first = tmp/100;
            f.second = tmp%100;
        }
        sort(floors.begin(),floors.end());
        
        vector<vector<int>>ans(n);
        
        int l = 0, r = m-1;
        for(int i = 0 ; i < n; i++){
            if(i%2 == 0){
                for(int j = 0 ; j < 3; j++){
                    // ans[i].push_back(floors[l].first*100+floors[l].second);
                    // ans[i].push_back(floors[m-1-l].first*100+floors[m-1-l].second);
                    cout << floors[l].first*100+floors[l].second << " " << floors[m-1-l].first*100+floors[m-1-l].second << " ";
                }
                cout << endl;
                continue;
            }else{
                for(int j = 0 ; j < 3; j++){
                    // ans[i].push_back(floors[l].first*100+floors[l].second);
                    // ans[i].push_back(floors[m-1-l].first*100+floors[m-1-l].second);
                    cout << floors[m-1-l].first*100+floors[m-1-l].second << " "<< floors[l].first*100+floors[l].second << " " ;
                }
            }
            l++;
            cout << endl;
        }

        

    } 
    
    return 0;
// g++ -std=c++17 .\CFtmp.cpp  -Dlocal -o tmp
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


