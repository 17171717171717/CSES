#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debug(x) cout << #x << " = " << x << "\n";
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

int mod = 1e9+7;

bool isp(int n) {
    if (n == 1 || n == 2) return false;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2){
        // ie(cout<<"i"<<i<<endl;)
        if (n % i == 0)
            return false;
    }
    return true;
}

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    int kase;
    cin >> kase;
    while(kase--){
        int x, k;
        cin >> x >> k;

        if(k==1){
            if(isp(x))cout<<"YES"<<endl;
            else cout <<"NO"<<endl;
        }
        else{//3737 = 37*100 + 37*1 = 37*101
            if(x!=1)cout<<"NO"<<endl;
            else{
                int xk = 1;
                for(int i = 1; i < k; i++){
                    xk = xk*10+1;
                }
                // ie(cout<<xk<< endl;);            
                if(isp(xk))cout<<"YES"<<endl;
                else cout <<"NO"<<endl;

                
            }
        }
        
    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

