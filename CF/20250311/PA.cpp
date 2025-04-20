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
        int l,r,d,u;
        cin >> l >> r >>d >> u;
        // int ld,lu,rd,ru;
        // ld = (d-l)*(d-l);
        // lu = (u-l)*(u-l);
        // rd = (d-r)*(d-r);
        // ru = (d-u)*(d-u);
        if((l==r)&&(r==d)&&(d==u))cout<<"YES"<<endl;
        else cout <<"NO"<<endl;
        


    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

