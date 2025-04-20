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

int mod = 1e9+7;


signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    int kase;
    cin >> kase;
    while(kase--){
        str s;
        cin >> s;
        int n = s.size();
        // cout << "n" << n;
        if(n==1){
            cout << 0 <<endl;
            continue;
        }

        int tmp = n;
        tmp--;
        int ans = 0;
        while(tmp >= 1 && s[tmp] == '0'){
            tmp--;
            ans++;
        }
        int i = 0;
        for(i ; i < tmp; i++){
            // cout << s[i];
            if(s[i]!='0')ans++;
        }
        cout<< ans << endl;
    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

