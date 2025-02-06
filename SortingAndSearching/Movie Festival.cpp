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

    int n;
    cin >> n;
    vec<pii>v;
    REP(i,n){
        int tmp1, tmp2;
        cin >> tmp1>>tmp2;
        v.pb({tmp1,tmp2});
    }
    // pf: https://www.youtube.com/watch?v=m5hGKMi-NP8
    // G = [g1,g2...], intervals solution sort by ending time greedy algo
    // O = [o1,o2...], optimal solution
    // o1,g1可能starting time不一樣 但o2/g2都不會被o1/g1影響
    // => h1可以替換成最早結束的, 不影響o2的start的movie, 且必存在by g1_ending <= o1_ending
    // =>不影響o2開始,則o2也可以替換成h2....
    
    sort(al(v),[](pii &p1, pii &p2){
        return p1.s < p2.s;
    });

    int cur=0, ans=0;
    int cur_ending = 0;
    for(auto tmp : v){
        if(tmp.f >= cur_ending){
            ans++;
            cur_ending = tmp.s;
        }
        
    }

    cout << ans;
    
    


    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  