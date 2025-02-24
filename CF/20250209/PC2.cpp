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

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int kase; 
    cin >> kase;
    while(kase--){
        int n,m;
        cin >> n >> m;
        vi a(n),b(m);
        vin(a);
        vin(b);
        sort(al(b));
        bool ok =false;
        // tmp is the best choose for a[i], as min as possible
        int tmp = min(a[0], b[0]-a[0]);
        
        for(int i = 1; i < n ; i++){
            if( max( b[m-1] - a[i], a[i]) < tmp){
                cout<<"NO"<<endl;
                ok = true;
                break;
            }
            //  2 5 => if b[j] - 5 >= 2 => b[j] >= 7
            // => b[j] - a[i] >= tmp => b[j] >= tmp + a[i]
            int j = lower_bound(al(b),tmp+a[i]) - b.begin() ;
            ie(cout << j << endl;)
            // no b[j] ok => let a[i] be the same
            if(j > m-1)tmp = a[i];
            // a[i] >= a[i-1]==tmp => take the best sol for a[i]
            else if(a[i] >=tmp )tmp = min(a[i], b[j] - a[i]);
            // a[i] < a[i-1] => b[j] - a[i] >= tmp => b[j] - a[i] is the sol for a[i]
            else tmp = b[j] - a[i];
        }
        if(!ok){
            cout << "YES" << endl;
        }
        
    }
    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

