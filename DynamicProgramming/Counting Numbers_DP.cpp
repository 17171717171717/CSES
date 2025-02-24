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

const int mod = 1e9+7;

// sol by https://www.youtube.com/watch?v=TN0qGN0YqDQ
int solve(int n, vi dp){
    if (n<1)return n==0? 1 : 0;
    
    str nums = to_string(n);
    int ans = 0;

    for(int i = 0; i < nums.size();i++){
        ans += dp[i];
    }

    int prev_digit_pos = 0;
    for (int i = 0; i < nums.size(); i++) {
        int cur_pos = nums[i] - '0';
        int k_th_bit = nums.size() - i - 1;
        int below = prev_digit_pos < cur_pos ? cur_pos - 1 : cur_pos;
        ans += (cur_pos == 0) ? 0 : below * dp[k_th_bit];
        if (cur_pos == prev_digit_pos)
            return ans;
        prev_digit_pos = cur_pos;
    }
    return ans + 1; 
}

// signed main()
// {


//     fastios
//     ie(freopen("test_input.txt", "r", stdin);)

//     int a,b;
//     cin >> a >> b;
    

//     // build the dp table for all m digit numbers
//     vector<ll> dp(19);
//     dp[0] = 1;
//     for (int i = 1; i < 19; i++) {
        
//         dp[i] = dp[i-1] * 9;
//     }

//     cout << solve(b,dp) - solve(a-1,dp);
//     return 0;
//     // g++ .\tmp.cpp -Dlocal -o tmp  
//     // .\tmp.exe   
    


// }


int dp[20][10][2][2]; 


// dp[ith digit from left][previous digit][limit][leading_zero]
// limit: 34567 => digit_1 = 3 => when do 0,1,2 in digit 2 : 0000~9999, 3: 0000~4567

// init : dp[0][0][true][true], go to dp[]
int memorize_dp(const str &s, int cur_pos, int pre_digit, bool limit, bool leading_zero){

    // this space is done => it's like recursion, so we backtrack and memorize the dp from end to fron
    if(dp[cur_pos][pre_digit][limit][leading_zero] != (-1)){
        return dp[cur_pos][pre_digit][limit][leading_zero];
    }

    // initial cond.
    if (cur_pos == s.size()){
        return dp[cur_pos][pre_digit][limit][leading_zero] = 1;
    }


    int ans = 0;
    int max_iteration;

    if(limit){
        max_iteration = s[cur_pos] - '0';
    }
    else{
        max_iteration = 9;
    }

    for(int iterate_digit = 0; iterate_digit <= max_iteration ; iterate_digit++){
        if(iterate_digit == pre_digit){
            if(pre_digit != 0) continue; // cant have 2 same
            if(leading_zero == false) continue; // if it isn't 000xxx
            //else: 000XXX => OK
        }
        // 56789 => 789 is limited by 56 => 6 is limited by 5  ==> 56 turn go to 789 =>when iterate 7 => 8 is limit
        bool next_digit_limit = limit & (iterate_digit == (s[cur_pos]-'0'));
        bool still_leading_zero = leading_zero & (iterate_digit==0);

        ans += memorize_dp(s, cur_pos+1, iterate_digit, next_digit_limit, still_leading_zero);
    }
    dp[cur_pos][pre_digit][limit][leading_zero] = ans;
    return ans;
}

int solve2(int n){
    memset(dp, -1, sizeof(dp));
    str s = to_string(n);  
    return memorize_dp(s, 0, 0, true, true);
}

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int a,b;
    cin >> a >> b;

    cout << solve2(b) - solve2(a-1);
    return 0;
    // g++ .\tmp.cpp -Dlocal -o tmp  
    // .\tmp.exe   
    


}
