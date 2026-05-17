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

vvi dirs = {{-1,0},{1,0},{0,1},{0,-1}};
// vec<char>dirs_eng = {'L','R','U','D'}; 
vec<char>dirs_eng = {'U','D','R','L'};// -1,0 => Down 


signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)


    int n, q;
    cin >> n >> q ;
    
    vector<vector<int>>jump_parent(n,vector<int>(30,-1));
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        jump_parent[i][0] = a-1 ; // [i][j] : i node go back 2^j steps
        // 9 = 8+1, 13 = 8+4+1
    }

    // 1->2->3->4 => a[4][1] = a[a[4][0]][0] = a[3][0] = 3
    for(int i = 1; i < 30; i++){
        for(int j = 0; j < n; j++){
            jump_parent[j][i] = jump_parent[jump_parent[j][i-1]][i-1];
        }
    }

    while(q--){
        int l,r;
        cin >> l >> r;
        l--;
        for(int i = 0 ; i < 30; i++){
            if(r & (1LL<<i))l=jump_parent[l][i];
        }

        cout << l+1 << "\n";
    }

    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
