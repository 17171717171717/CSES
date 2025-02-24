#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
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
#define f first
#define s second
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

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n; 
    cin >> n;
    while(n--){
        str ss ;
        cin >> ss;
        // cout << "ss: " << ss << endl;


        if(ss.size() == 1){
            cout << 1 << endl;
            continue;;
        }
        if(ss.size() == 2){
            if(ss[0] == ss[1]){
                cout << 1 << endl;
            }else{
                cout << 2 << endl;
            }
            continue;
        }
        bool done = false;
        for(int i = 0; i<ss.size();i++){
            if(ss[i] == ss[i+1]){
                cout << 1 << endl;
                done = true;
                break;
            }
        }
        if(done)continue;
        else cout << ss.size() << endl;



    }
    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

