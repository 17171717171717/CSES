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

 
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int kase;
    cin >> kase;
    while(kase--){
        int N, M; cin >> N >> M;
        vector<int> a(N), b(M);
        for(int i = 0; i < N; i++) cin >> a[i];
        for(int i = 0; i < M; i++) cin >> b[i];
        vector<int> backwards_match(M);
        int j = N - 1;
        for(int i = M - 1; i >= 0; i--){
            while(j >= 0 && a[j] < b[i]) j--;
            backwards_match[i] = j--;
        }
        vector<int> forwards_match(M);
        j = 0;
        for(int i = 0; i < M; i++){
            while(j < N && a[j] < b[i]) j++;
            forwards_match[i] = j++;
        }
        if(forwards_match.back() < N){
            cout << 0 << endl;
            continue;
        }
        int ans = INF;
        for(int i = 0; i < M; i++){
            int match_previous = i == 0 ? -1 : forwards_match[i - 1];
            int match_next = i + 1 == M ? N : backwards_match[i + 1];
            if(match_next > match_previous){
                ans = min(ans, b[i]);
            }
        }
        cout << (ans == INF ? -1 : ans) << "\n";
    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

