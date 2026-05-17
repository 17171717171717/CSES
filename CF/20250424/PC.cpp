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
#define INF 1000000000

int mod = 998244353;

 
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int kase;
    cin >> kase;
    while(kase--){
        // ie(cout << "kase " << kase << endl;)
        int n, k;
        cin >> n >> k;
        vector<int>a(n,0);
        vector<int>b(n,0);
        int amax = 0;
        for(int i = 0; i < n ; i++){
            cin >> a[i];
            if(a[i] > amax)amax=a[i];
        }
        for(int i = 0; i < n ; i++){
            cin >> b[i];
        }

        int sum = -100;
        bool bad = false;
        for(int i = 0; i < n; i++){
            if(b[i]!=(-1)){
                if(sum == -100){
                    
                    sum = a[i] + b[i];
                }else{
                    
                    if(a[i]+b[i] != sum){
                        bad = true;
                        break;
                    }
                }
            }
        }
        
        if(bad){
            cout << 0 <<endl;
            continue;;
        }

        for(int i = 0; i< n; i++){
            if(((a[i]+k)<sum) || (a[i]>sum && sum!= -100)){
                bad = true;
                break;
            }
        }
        if(bad){
            cout << 0 <<endl;
            continue;;
        }


        if(sum != -100){
            cout << 1 << endl;
            continue;
        }


        int minsum = 0;
        int maxsum = amax + k;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i]>minsum)minsum=a[i];
            if(a[i]+k < maxsum)maxsum = a[i]+k;
        }
        ans = maxsum - minsum + 1;
        cout << maxsum - minsum + 1 << endl;
        


        
        
    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

