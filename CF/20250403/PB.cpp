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

int findFirstZero(int n) {
    return __builtin_ctz(~n); // 计算 ~n 的最低位 1 的索引
}

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    int kase;
    cin >> kase;

    while(kase--){
        int n,k,x;
        cin>>n>>k>>x;
        vi a(n);
        vin(a);

        vi suffix(n);
        suffix[n-1] = a[n-1];
        for(int i = n-2; i >=0; i--){
            suffix[i] = a[i] += suffix[i+1];
        }
        
        // debugvec(suffix);
        int asum = suffix[0];
        int ans = n*k;
        if(asum * ans < x){
            cout << 0 << endl;
            continue;
        }
        // 找出右往左最多幾個數字加起來比x小
        int l = 1;
        int k_groups = k;
        
        

        // 先找最多k_groups組 a加起來比x小
        while(l <= k_groups){
            int mid = (l+k_groups)/2;
            int tmp = mid * asum;
            
            if(tmp > x) k_groups=mid-1;
            else l = mid+1;

            // ie(
            // debug(mid);
            // debug(tmp);
            // debug(l);
            // debug(k_groups);
            // cout<<endl;
            // )
        }

        // ie(debug(k_groups);)

        ans -= k_groups * n;
        x -= k_groups * asum;

        if(x!=0){
            for(int i = n-1; i >= 0; i--){
                if(suffix[i] >= x){
                    // ie(debug(i);)
                    ans -= ((n-1)-(i));
                    break;
                }
            }
        }
        else{
            ans++;
        }
        cout << ans << endl;
        // ie(cout << endl;)

    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

