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
#define f first
#define s second
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
#define pq(type) priority_queue<type>
const double eps = 1e-9;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



// 總時間越快，deadline越早的越要先完成
signed main()
{
    #ifdef local
    #endif

    fastios
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    int n , k;
    cin >> n >> k ;
    vec<int>v(n);
    vecinint(v);
    
    #ifdef local
    debugvec(v)
    #endif
    int tmp = 0, ans = 0;
    int i = 0, j = -1;
    while(j < n){
        #ifdef local
        cout << i << " j : "<< j << endl;
        #endif
        while(tmp < k ){
            j++;
            tmp += v[j];
            if(j>=n)break;
        }

        while(tmp>k){
            tmp -= v[i];
            i++;
            if(i>j)break;
        }

        if(tmp == k){
            ans++;
            tmp-=v[i];
            i++;
        }
    }
    cout << ans << endl;
}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

