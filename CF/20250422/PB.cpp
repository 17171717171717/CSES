#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debug(x) cout << #x << " = " << x << "\n";
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

int mod = 998244353;

 
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int kase;
    cin >> kase;
    while(kase--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans;
        int cnt = 0;
        if(s[0]=='0')ans = 1;
        else{
            ans = 2;
            cnt = 1;
        }

        if(n==1){
            cout << ans << endl;
            continue;
        }

        for(int i = 1; i < n; i++){
            s[i] == s[i-1] ? ans+=1 : ans+=2;
            if(s[i] != s[i-1])cnt++;
        }
        // case 1 : 101 => 011, 6-2
        // case 2 : 00110 => 00011, 7-1
        // case 3 : 11100 => 00011, 7-1
        if(cnt >= 3){
            ans -= 2;
        }else if(cnt == 2){
            ans -= 1;
        }
        cout << ans << endl;

        
        
    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

