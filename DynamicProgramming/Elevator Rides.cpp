#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].first >> v[i].second;
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define debug(x) cout << #x << " = " << x << "\n";
template <typename T>
using vec = vector<T>;
#define pb push_back
#define mp make_pair
#define al(x) (x).begin(), (x).end()
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<long long>>;
using vpii = vector<pair<long long,long long>>;
using ll = long long ;
using str = string;
using um = unordered_map<long,long>;
#define F first
#define S second
// small to big
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
// big to small
#define pq(type) priority_queue<type>
const double eps = 1e9+7;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef local
    #define ie(x) x
#else
    #define ie(x)
#endif
#define INF 1000000000

int mod = 1e9+7;


signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    
    int n, W;
    cin >> n >> W;
    vi v(n);
    vin(v);
    
    // 固定2個人的 會有最好情況下的ans以及目前占用的space
    // 則窮舉3個人的，固定其中一個，去找另外兩個人的ans及space
    // dp[01011]代表三個人 2,4,5在裡面，所以找2 4/ 4 5/ 2 4後結合則為這三個人最好的組合
    
    
    vpii dp(1<<n, {1e9, 1e9});// {ans, space_taken}
    

    // 1101 & 1<<3 = 1000 > 0 => 代表固定1，要找0101的答案
    // => 1101以及1000做XOR 則不一樣的會留下來 => 留下0101
    // => dp[0101]的解答可以最佳化dp[1101]

    dp[0] = {1,0};//ans = 1, space = 0

    for(int cur_subset = 1; cur_subset < (1<<n) ; cur_subset++){
        // check which k_th_person is in cur set
        for(int k_th_person = 0 ; k_th_person < n; k_th_person++){
            int pos = (1<<k_th_person);
            if(pos && cur_subset){// k_th person s in the cur_subset
                int spacetake = dp[cur_subset^(1<<k_th_person)].S;
                if(spacetake + v[k_th_person] <= W){ //放得下
                    dp[cur_subset] = min(dp[cur_subset],mp(dp[cur_subset ^ (1<<k_th_person)].F,
                                                        spacetake+v[k_th_person]));
                }
                else{ // 放不下
                    dp[cur_subset] = min(dp[cur_subset],mp(dp[cur_subset ^ (1<<k_th_person)].F+1,
                                                        v[k_th_person]));
                }
            }
        }  
    }
    cout << dp[(1<<n)-1].F;

    return 0;
    // g++ .\tmp.cpp -Dlocal -o tmp  
    // .\tmp.exe   
    


}
