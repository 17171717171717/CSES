#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define debugvec(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
template <typename T>
using vec = vector<T>;
#define pb push_back
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long ;
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

    int n ;
    cin >> n ;
    vec<int>v;
    REP(i,n){
        int tmp;
        cin >> tmp;
        v.pb(tmp);
    }

    sort(al(v));

    #ifdef local
    debugvec(v);
    #endif

    // 1 3 5 6, cur cant = 1->2 < 3 -> cant get 3
    // cur_cant = 9, v[i] = 4 => 1~12 all ok by 1~8 ok +4 => 1~12 ok => 13 cur cant
    // cur_cant = 7, v[i] = 8 => 1~3 all ok, cant get 4
    // cur_cant = 7, v[i] = 7 => 1~6 all ok => 7~13 all ok => 14 cur cant
    int cur_cant = 1;
    bool flag = false;
    REP(i,n){
        if(cur_cant < v[i]){
            cout << cur_cant;
            break;
        }
        else{
            cur_cant += v[i];
        }
        if (i == n-1)flag = true;
    }

    if(flag)cout << cur_cant << endl;

    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  