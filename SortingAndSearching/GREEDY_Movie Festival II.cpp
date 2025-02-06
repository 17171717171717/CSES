#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vecinint(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vecinpii(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debugvec(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
template <typename T>
using vec = vector<T>;
#define pb push_back
#define mp make_pair
#define al(x) x.begin(), x.end()
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vpii = vector<pair<int,int>>;
using ll = long long ;
using str = string;
using um = unordered_map<int,int>;
#define f first
#define s second
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
#define pq(type) priority_queue<type>
const double eps = 1e-9;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef local
    #define ie(x) x
#else
    #define ie(x)
#endif
#define st_it set<int>::iterator
int j = 0;
bool cmp(pii a, pii b){
    ie(cout << "j: " << j++ << endl;)
        
    if(a.s != b.s)return a.s<b.s;
    return a.f <= b.f;
}
// proof :
// 假设贪心算法得到的解 G 不是最优解，存在更优解O满足∣O∣>∣G∣。 
// 按结束时间排序后，设第一个分叉点为电影 m，O 未选 m 但 G 选了 m。
// 由于 m 是当前结束时间最早的可选电影，O中未选m必然选择了另一个电影 m ′ 且 e m ′ ≥ e m​ 。
// 替换操作：将 O O 中的 m ′ 替换为 m，得到新解O′ 。
// 由于 e m ≤ e m ′ ，替换后的O ′ 仍为合法解，且 ∣ O ′ ∣ = ∣ O ∣。 
// 重复此替换，最终 O 可转化为 G ，矛盾。

// start不影響證明：
// G_st為start, G_ed 為end， G_ed <= O_ed
// G_st >= G_ed => 可替換
// G_st < G_ed => 若影響則代表G_st ~ O_st中間有k個, 本來greedy就會選G不選O


// https://blog.csdn.net/qq_45931691/article/details/134819133
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n,k; 
    cin>>n>>k;
    vpii v(n);
    REP(i,n){
        cin >> v[i].f >> v[i].s;
        ie(cout << "j: " << j++ << endl;)
        
    }
    j = 0;
    sort(al(v),cmp);

    multiset<int>ms;
    REP(i,k){
        ms.insert(0);
    }

    int ans = 0;
    j = 0;
    for(auto t:v){
        // upperbound為 ed >= G.start 的 下一個，則前一個正為ms最大且滿足條件的ed
        // 全部都> => 去begin() => 沒有比目前start小的ed
        // 全部都< => 去end() => 全部的ed都比目前start小
        ie(cout << "j: " << j++ << endl;)
        auto it = ms.upper_bound(t.f);
        if(it == ms.begin())continue;
        ms.erase(--it);
        ans++;
        ms.insert(t.s);
    }
    cout << ans << endl;
}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

