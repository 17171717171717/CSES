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

bool ok(int cur_mex, int k, const vi& v) {
    if (cur_mex == 0) return true;

    set <int> vis;
    int cur_k = 0, total_cur = 0;
    int n = v.size();
    for(int i = 0; i < n; i++){
        if(v[i] < cur_mex )vis.insert(v[i]);
        if(vis.size()==cur_mex){
            cur_k ++;
            vis.clear();
            if(cur_k >= k)return true;
        }
    }
    return false;
}

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    int kase;
    cin >> kase;
    while(kase--){
        int n,k;
        cin >> n >> k;
        vi v(n);
        vin(v);

        
        int l = 0;
        int r = n+1;
        while(l<r){//log k
            int mid = (l+r)/2;
            if(ok(mid,k,v)){ // On
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        cout << l-1 << endl;
        
    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

