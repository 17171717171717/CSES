#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
template <typename T>
using vec = vector<T>;
#define pb push_back
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = unsigned long long ;
using str = string;
#define f first
#define s second
const double eps = 1e-9;
#define int long long


signed main()
{
    #ifdef local
    #endif

    #ifdef local
    freopen("test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif

    int n;
    cin >> n;
    vec<pii>v;
    REP(i,n){
        int tmp1, tmp2;
        cin >> tmp1>>tmp2;
        v.pb({tmp1,true});
        v.pb({tmp2,false});
    }

    sort(al(v));

    int cur=0, ans=0;
    for(auto tmp : v){
        // cout << tmp.f << endl;
        if(tmp.s == true)cur++;
        else cur--;
        ans = max(ans,cur);
    }

    cout << ans;
    
    


    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  