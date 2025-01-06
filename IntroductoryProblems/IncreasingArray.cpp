#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
template <typename T>
using vec = vector<T>;
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long;
using str = string;
const double eps = 1e-9;
 
int main()
{
    #define int long long
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    while (cin >> n)
    {
        int pre,cur, ans=0;
        cin >> pre;
        
        for(int i = 1; i < n;i++){
            cin >> cur;
            while(cur < pre){
                cur++;
                ans++;
            }
            pre = cur;
        }
        cout << ans;
        
    }
    return 0;
}