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
        // ie(cout << "1";)
        int n;
        cin >> n;
        vector<int>v(n);
        REP(i,n){
            cin >> v[i];
        }

        bool curr_neg = true;
        int i = 0;
        int j = n-1;
        while(i <= j){
            if(curr_neg){
                if(v[i] < v[j]){
                    cout << "L" ;
                    i++;
                    // ie(cout << "1";)
                }
                else{
                    cout << "R";
                    j--;
                    // ie(cout << "2";)
                }
            }else{
                if(v[i] > v[j]){
                    cout << "L" ;
                    i++;
                    // ie(cout << "3";)
                }
                else{
                    cout << "R";
                    j--;
                    // ie(cout << "4";)
                }
            }
            curr_neg = !curr_neg;
        }
        cout << endl;
    }
    
    return 0;
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


