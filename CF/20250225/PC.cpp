#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
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
#define F first
#define S second
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
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
    int kase;
    cin >> kase;
    // 2^0 ~ 2^29
    // vi dp(30);
    // dp[0] = 1;
    // for(int i = 1; i < 30; i++){
    //     dp[i] = dp[i-1]*2; // dp[i] = 2^i
    // }
    // // cout << dp[10] << endl;

    // vi pre(30);
    // pre[0] = 2; // 0, 1 for 1st_bit
    // pre[1] = 2; // 2, 3 for 2nd_bit
    // pre[2] = 4; // 4 5 6 7 for 3nd bit
    // pre[3] = 8; // 8~15 for 4nd bit
    // pre[5] = 16;// 16 ~ 31...
    // for (int i = 6; i < 30 ; i++){
    //     pre[i] = pre[i-1]*2; // pre[i] = dp[0] + dp[1] +.. +dp[i]
    // }
    while(kase--){
        int n, x;
        cin >> n >> x;
        vi ans(n,x);
        // ie(debugvec(ans))
        int or_val = 0;
        bool flag = true;
        // or_val: now val or sum, for check can we go through next iter
        // flag: we get the enough bits 1 for x , e.g. cur_iter_val

        for(int cur_iter_val = 0 ; cur_iter_val < n-1  ; cur_iter_val++){
            // 01011 | 00001/00010/00011 = 01101
            // check (or_val | cur_iter_val) and x have the same 1's == (or_val | cur_iter_val) 1's
            // if or_val = 00111, cur = 01000, or_val & cur_iter_val = 01111
            // x = 10111 => x & (or_val | cur_iter_val) = 00111 != 01111

            // and also, check cur iter >= x
            // if  7, 3 => 11 is the answer, MEX = 4, we only can have 0 1 2 3 in ans
            ie(cout << " cur_iter_val " << cur_iter_val << " or_val " << or_val << endl;
            cout << " or_val | cur_iter_val "<< (or_val | cur_iter_val) << endl;
            cout << "or_val | cur_iter_val) & x " << ((or_val | cur_iter_val) & x ) << endl;)
            if( ( (or_val | cur_iter_val) & x ) == (or_val | cur_iter_val)){
                or_val = (or_val | cur_iter_val);
                ans[cur_iter_val] = cur_iter_val;
            }
            // else => 01011 | 00100 != 01011 => first zero found
            // => meet first zero, break and flag = false
            // => fill x in ans
            else{
                flag = false;
                break;
            }
        }
        // flag => finished iter and we still can add MEX if (or_val | (n-1) ) == x
        // MEX++ still work => take n-1 in
        // else => still need to get x in 
        if(flag && (or_val | (n-1) )==x){
            ans[n-1] = n-1;
        }

        for(auto i : ans){
            cout << i << " ";
        }
        cout << endl;
    }

    // old bad sol
    //     int loc_max = findFirstOne(x);
    //     int r_ones = findFirstZero(x);
    //     int total_one = totalOne(x);
    //     cout <<"kase: "  << 9-kase << endl;
    //     cout << "Max 1 at position: " <<  loc_max << endl; 
    //     cout << "First 0 at position: " <<  r_ones << endl; 
    //     cout << "total_one: " <<  total_one << endl; 
    //     cout << dp[findFirstZero(x)] << endl;
    //     int l_ones = total_one-r_ones;
    //     cout << "l_ones:" << l_ones<<endl;
    //     cout << endl;

    //     n -= l_ones;
    //     if(n<0){
    //         n += l_ones;
    //         cout << x <<" ";
    //         for(int i = 1; i < n; i++){
    //             cout << 0 <<" " << endl;
    //         }
    //         cout << endl;
    //         continue;
    //     }
    //     int k_left = total_one - l_ones;
    //     for(int i = 0; i < r_ones; i++){
    //         if(r_ones-1 + pre[i] > n){
    //             for(int j = 0; j < n - (r_ones-1 + pre[i]) ; j++){
    //                 cout << dp[i] + j << " ";
    //             }
    //         }
    //         else{
    //             for(int j = 0; j < pre[i]-pre[i-1] ; j++){
    //                 cout << dp[i] + j << " ";
    //             }
    //         }

    //         if(r_ones - pre[i] > )
    //     }

        
    // }

    
    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

