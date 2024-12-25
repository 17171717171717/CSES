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


// let n belong to {4x, 4x+1, 4x+2, 4x+3}
// 4x, 4x+3 have sols in main()
// 4x+1 4x+2 can't have solutions by (1 + n )*n isn't divisible by 4
int main()
{
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    #define int long long
    int n;
    cin >> n;
    if(n < 3) cout << "NO";
    else if(n == 3) cout << "YES" << endl << 1 << endl << 3 << endl << 2 << endl << 1 << ' ' << 2;
    else if(n % 4 == 0) {
        cout << "YES";
        int k = 2;
        int i = 1;
        int j = n;
        while(k--) {
            cout << endl << n/2 << endl;
            for(int p = 0; p < n / 4; p++) {
                cout << i << ' ' << j << ' ';
                i++, j--;
            }
        }
    } 
    else if(n % 4 == 3) {
        cout << "YES" << endl;
        set<int>f;
        set<int>s;
        f.insert(1);
        f.insert(2);
        s.insert(3);
        for(int i = 4;i <= n; i++) {
            if(i % 4 == 0) f.insert(i);
            else if(i % 4 == 3) f.insert(i);
            else if(i % 4 == 1) s.insert(i);
            else s.insert(i);
        }
        cout << f.size() << endl;
        for(auto i = f.begin(); i != f.end(); i++) cout << *i << ' ';
        cout << endl << s.size() << endl;
        for(auto i = s.begin(); i != s.end(); i++) cout<<*i<<' ';
    }
    else cout<<"NO";
    // while (cin >> N)
    // {
    //     int ans = ((N^2) * (N^2 - 1))/2 - 2 * (K-1) * (K-2) * 2;
        
    //     cout << ans<<endl;
        
    // }
    return 0;
}
