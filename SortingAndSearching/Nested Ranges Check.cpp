#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define debugvec(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
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
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


struct range{
    int l, r, pos;

    bool operator < (const range& a)const{
        if(l==a.l)return r>a.r;
        return l < a.l;
    }
};
signed main()
{
    #ifdef local
    #endif

    fastios
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    int n,k;
    cin >> n ;

    vec<range>v(n);
    REP(i,n){
        int tmp;
        cin >> tmp;
        v[i].l = tmp;
        cin >> tmp;
        v[i].r = tmp;
        v[i].pos = i;
    }
    
    sort(v.begin(),v.end());

    // ***sort 後 保證 v[i].l <= v[i+1].l ***

    //contains
    vec<int>c1(n,0);
    int cur_r = 2e9;
    //只需要確認v[i].r有沒有包著(從後面，l最大的開始)人就好
    for(int i = n-1; i>=0 ; i--){
        if(v[i].r >= cur_r)c1[v[i].pos] = 1;
        if(v[i].r < cur_r)cur_r = v[i].r;
    }

    //contained by
    vec<int>c2(n,0);
    cur_r = 0;
    //只需要確認v[i].r有沒有被目前最右邊的包在裡面就好
    for(int i = 0; i < n ; i++){
        if(v[i].r <= cur_r)c2[v[i].pos] = 1;
        if(v[i].r > cur_r)cur_r = v[i].r;
    }
    debugvec(c1);
    debugvec(c2);
    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  