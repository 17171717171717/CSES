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
ll MOD = (1e9 + 7);

ll power(ll base, ll expo) {
    ll ans = 1;                // 初始化结果为 1
    while(expo) {              // 当指数不为 0 时，继续迭代
        if(expo & 1LL) {       // 检查指数的最低位是否为 1（奇数次幂）
            ans = (ans * base) % MOD;  // 如果为奇数，将当前 base 乘入结果并取模
        }
        base = (base * base) % MOD;  // base 自身平方并取模
        expo >>= 1LL;                // 指数右移一位，相当于整除 2
    }
    return ans;               // 返回结果
}

int main()
{
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    #define int long long
    ll n;
    cin >> n;
    
    
    cout << power(2LL,n) ;
    return 0;
}
