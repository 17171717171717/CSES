#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vecinint(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vecinpii(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
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
const double eps = 1e-9;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef local
    #define ie(x) x
#else
    #define ie(x)
#endif

bool ok(int mid,vi v,int n,int k){
    int tmp = 1, tmpsum = 0;

    REP(i,n){
        tmpsum += v[i];
        if(tmpsum > mid){
            tmpsum = v[i];
            tmp++;
        }
    }
    return tmp <= k;

}
// https://www.youtube.com/watch?v=8FdstVAkC5s
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n,k ;
    cin >> n >> k;
    vi v(n);
    vecinint(v);
    
    ie(debugvec(v))
    
    int h = accumulate(al(v),0LL);
    int l = *max_element(al(v));
    ie(cout << " l "<<l <<" h "<< h;)
    ll ans = 0;
    while(l <= h ){
        int mid = (l+h)/2;
        if(ok(mid,v,n,k)){
            ans = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }

    }

    cout << ans << endl;
}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

