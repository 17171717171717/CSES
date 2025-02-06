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



int main()
{
    #ifdef local
    #endif

    #ifdef local
    freopen("test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif

    int n, m, k;
    cin >> n >> m >> k;
    vec<int>a(n);
    vec<int>b(m);
    int tmp;
    REP(i,n){
        cin >> a[i];
    }
    REP(i,m){
        cin >> b[i];
    }

    sort(al(a));
    sort(al(b));
    int ans = 0;
    int aIdx=0,bIdx=0;
    while(aIdx < n && bIdx < m){
        if(abs(a[aIdx]- b[bIdx]) <= k ){
            aIdx++;
            bIdx++;
            ans++;
        }
        else{
            if(a[aIdx] > b[bIdx]){
                bIdx++;
            }
            else{
                aIdx++;
            }
        }
    }
    cout << ans;
    return 0;
}