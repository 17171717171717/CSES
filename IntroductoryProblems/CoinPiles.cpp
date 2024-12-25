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

// if a+b = 3*i, i>=0, then we can find YES
// let a+b = 3k, k >= 0
// let a = min(a,b), b-a = t , k>= t >= 0 
// => (b-2t) + (a-t) = a+b-3t = 3k - 3t = 3(k-t) is 3*i 
int main()
{
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif

    #ifndef local
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif
    
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        if((a + b) % 3 != 0 || (a / 2) > b || (b / 2) > a){
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    
    }
    
    return 0;
}
