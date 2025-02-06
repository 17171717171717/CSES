#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
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
#define int long long int
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

template <typename T>
vector<T> in_vec(int n) {
    vector<T> v(n);  // 创建大小为 n 的 vector
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // 从输入读取值
    }
    return v;
}


signed main()
{
    #ifdef local
    #endif

    fastios
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    int n,t;
    cin >> n >> t ;
    vec<int>v = in_vec<int>(n);
    // sort(al(v));
    int ans = 1e18;
    int l=1,r=1e18;

    while(l <= r){
        int mid = (l+r)/2;
        int tmp_t = 0;
        bool flag = false;
        // cout << "tmp_t: " ;
        for(auto &tmp : v){
            tmp_t += (mid/tmp);
            // cout << tmp_t << " ";
            if(tmp_t>=t){
                flag = true;
                break;
            }
        }
        // cout << endl;
        if(flag){
            ans = min(mid, ans);
            r = mid-1;
        }else{
            l = mid+1;
        }

    }
    cout << ans << endl;

    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  