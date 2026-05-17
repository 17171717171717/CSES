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

void solve(int col, int row, int n, int val, vector<vector<int>>&ans){
    if(row == n || col == n || row < 0 || col < 0 || ans[row][col] != -1) return;
    ans[row][col] = val;
    val--;
    // go right
    while(col <= n-2 && ans[row][col+1] == -1){
        col++;
        ans[row][col] = val;
        val--;
    }
    // go down
    while(row <= n-2 && ans[row+1][col] == -1){
        row++;
        ans[row][col] = val;
        val--;
    }
    // go left
    while(col >= 1 && ans[row][col-1] == -1){
        col--;
        ans[row][col] = val;
        val--;
    }
    // go up
    while(row >= 1 && ans[row-1][col] == -1){
        row--;
        ans[row][col] = val;
        val--;
    }

    solve(row, col+1, n, val, ans);
    return ;
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
        vector<vector<int>>ans(n,vector<int>(n,-1));
        solve(0, 0, n, n*n-1, ans);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
        
        // cout << endl;
        
    }
    
    return 0;
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


