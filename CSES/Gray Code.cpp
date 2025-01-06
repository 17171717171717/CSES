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

// g++ .\tmp.cpp -Dlocal -o tmp
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

    vec<string>v;
    v.push_back("0");
    v.push_back("1");
    // cout << (1<<n) << endl;
    for(int i = 2; i <= n ; i++){
        int vs = v.size();
        for(int j = vs-1;j>=0;j--){
            v.push_back(v[j]);
        }
        for(int j = 0 ; j < vs ; j++){
            v[j] = "0" + v[j];
        }
        for(int j = vs ; j < 2*vs ; j++){
            v[j] = "1" + v[j];
        }
    }

    for(auto & i : v){
        cout << i << endl;
    }
    
    return 0;
}
