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

    int n , x;
    cin >> n >> x;
    vec<int>p(n);
    REP(i,n){
        cin >> p[i];
    }

    sort(al(p));

    int l = 0, r = p.size()-1;

    int ans = 0;
    while(l <= r){
        if((p[l]+p[r])<=x){
            l++;
            r--;
            ans++;
        }

        else {
            r--;
            ans++;
        }

        
    }
    cout << ans;
    return 0;
}