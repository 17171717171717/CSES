#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].first >> v[i].second;
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define debug(x) cout << #x << " = " << x << "\n";
const double eps = 1e9+7;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef local
    #define ie(x) x
#else
    #define ie(x)
#endif
#define INF 1000000000



signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    // 把每個cycle都拿出來 平攤成vector
    // 然後看會走到哪個cycle
    // 不在cycle內的 要走 cycle長度+走到cycle的距離
    // 在的直接走就好

    // 判斷在cycle內外: 在內的走k步可以回到自己
    // 可以用走到vis[i] == true, 然後那一個人開始走一圈 就可以裝這些人在cycle內
    // 所以一開始就可以precompute每個人在哪個cycle, 在不在cycle內
    // 每個人最終都會走進cycle內

    // 先預先計算cycle 只要DFS遇到vis[i]==true, 代表 i 就是cycle內的那個人 所以i 再去走一圈 裡面的就都是cycle的人，都可以標記起來，並且這些人的答案都是cycle長度

    // 然後一開始v[j]再走一次 看路過的每個人在不在cycle內 也順便紀錄步數 就可以知道這些人的答案

    // 但是會碰到 1 -> 2 -> 3 -> 2（2 和 3 形成一個環）。另外有一個獨立的枝條 4 -> 1。
    // 所以用三個state
    int n;
    cin >> n;
    vector<int>v(n);
    vector<bool>vis(n, false);
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        tmp--;
        v[i] = tmp;
    }

    vector<vector<int>>cycles;

    vector<int>state(n, 0); // 0:還沒 1:這一趟 2: ok了
    vector<int>ans(n, 0);

    for(int i = 0; i < n; i++){
        if(state[i] != 0) continue;
        int cur = i;

        while(state[cur] == 0){
            state[cur] = 1;
            cur = v[cur];
        }

        if(state[cur] == 1){
            int cycle_start = cur;
            int cycle_len = 0;
            do{
                cycle_len++;
                cur = v[cur];
            }while(cur != cycle_start);

            do{
                ans[cur] = cycle_len;
                cur = v[cur];
            }while(cur != cycle_start);
        }

        cur = i;
        while(state[cur] == 1){
            state[cur] = 2;
            cur = v[cur];
        }

    }
   
    for(int i = 0; i < n; i++){
        if(ans[i] != 0)continue;

        vector<int>path;
        int cur = i;
        while(ans[cur] == 0){
            path.push_back(cur);
            cur = v[cur];
        }

        int cur_ans = ans[cur];
        for(int j = path.size()-1; j >= 0; j--){
            cur_ans++;
            ans[path[j]] = cur_ans;
        }
    }

    for(int i = 0; i < n; i++)cout<<ans[i]<<" ";
    return 0;
}
// g++ .\CSEStmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
