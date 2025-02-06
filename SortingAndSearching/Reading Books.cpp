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
#define al(x) x.begin(), x.end()
using pii = pair<long long, long long>;
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
    int n,t;
    cin >> n ;
    vec<int>v(n);
    vecinint(v);
    // vec<pii>v(n);
    // vecinpii(v);

    // 1 2 10 => 10*2 => wait to long
    // 1 3 3 7 => 1+3+3+7 => no wait to long
    // 1 3 4 7 => 1+3+4+7 => no wait to long

    sort(al(v));
    int longest = v[n-1];
    int total = -longest;
    for(auto aa : v){
        total += aa;
    }
    int ans = 0;
    if(longest>total)ans=2*longest;
    else ans=total+longest;

    cout << ans << endl;

    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  