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
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    #define int long long
    int N;
    cin >> N;
    while (N--)
    {
        int x, y;
        cin >> x >> y;
        int max_ = max(x,y);
        int cur = max_ * max_;
        int ans;
        if( max_ == 1){
            ans = 1;
        }
        else if(max_ %2 == 1){
            if(x<=y){
                ans = cur - (x - 1);
            }
            else{
                ans = cur - (x - 1) - (max_-y);
            }
        }
        else {
            if(x>=y){
                ans = cur - (y-1);
            }
            else{
                ans = cur - (y-1) - (max_-x);
            }
        }
        cout << ans<<endl;
        
    }
    return 0;
}
