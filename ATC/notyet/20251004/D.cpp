#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debug(x) cout << #x << " = " << x << "\n";
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
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
#define INF 1e9+5

int mod = 998244353;

int find(int x, vector<int>& parent) {
    if (x == 0) return 0; // 版本 0 表示「沒有更舊的版本」
    if (x != parent[x]) parent[x] = find(parent[x], parent);
    return parent[x];
}

signed main()
{
    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        str s;
        cin >> s;

        int max0_len = 0, max0_l = -1, max0_r = -1;
        int max1_len = 0, max1_l = -1, max1_r = -1;
        int cur_len = 1, cur_l = 0;

        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                cur_len++;
            } else {
                // 結束上一個區段，檢查長度
                if(s[i-1] == '0' && cur_len > max0_len) {
                    max0_len = cur_len;
                    max0_l = cur_l;
                    max0_r = i-1;
                } else if(s[i-1] == '1' && cur_len > max1_len) {
                    max1_len = cur_len;
                    max1_l = cur_l;
                    max1_r = i-1;
                }
                // 開始新區段
                cur_len = 1;
                cur_l = i;
            }
        }

        // 最後一個區段別忘了檢查
        if(s[n-1] == '0' && cur_len > max0_len) {
            max0_len = cur_len;
            max0_l = cur_l;
            max0_r = n-1;
        } else if(s[n-1] == '1' && cur_len > max1_len) {
            max1_len = cur_len;
            max1_l = cur_l;
            max1_r = n-1;
        }
        ie(
        cout << "0 length=" << max0_len << ", l=" << max0_l << ", r=" << max0_r << "\n";
        cout << "1 length=" << max1_len << ", l=" << max1_l << ", r=" << max1_r << "\n";
        )
        int ans_0 = 0;
        int idx = 0;
        while(idx<max0_l){
            if(s[idx]=='0'){
                ans_0+=2;
            }else{
                ans_0+=1;
            }
            idx++;
        }

        idx = n-1;
        while(idx>max0_r){
            if(s[idx]=='0'){
                ans_0+=2;
            }else{
                ans_0+=1;
            }
            idx--;
        }
        int ans_1 = 0;
        idx = 0;
        while(idx<max1_l){
            if(s[idx]=='1'){
                ans_1+=2;
            }else{
                ans_1+=1;
            }
            idx++;
        }

        idx = n-1;
        while(idx>max1_r){
            if(s[idx]=='1'){
                ans_1+=2;
            }else{
                ans_1+=1;
            }
            idx--;
        }
        if(ans_0 >= ans_1){
            cout << ans_1 << endl;
        }else{
            cout << ans_0 << endl;
        }


    }

    return 0;
// g++ .\ATCtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


