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
#define f first
#define s second
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
#define pq(type) priority_queue<type>
const double eps = 1e-9;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef local
    #define ie(x) x
#else
    #define ie(x)
#endif
// https://www.youtube.com/watch?v=jgEcICsn_6c
// Brute force 做pre降時間，找到pre[i-1]做set可以找出a<=len<=b的最大pre[i+len]-pre[i-1]
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n,a,b; 
    cin>>n>>a>>b;
    vi v(n+1);
    for(int i = 1; i <= n ; i++){
        cin >> v[i];
    }
    v[0] = 0;
    for(int i = 1; i <= n ; i++){
        v[i] += v[i-1];
    }

    multiset<int>ms;
    for(int i = a ; i <= b ; i++){
        ms.insert(v[i]);
    }
    ie(debugvec(v))
    int ans = LLONG_MIN;

    for(int i = 1; i <= (n-a+1); i++){
        ie(cout << " i " <<  i << endl;)
        ie(cout << "ans "<< ans << endl << " ms rbegin" <<  *(ms.rbegin()) << endl;)
        if(!ms.empty()) {
            ie(cout << " v[i-1] " <<  v[i-1] << endl;)
            ans = max(ans,  *(ms.rbegin()) - v[i-1] ) ;
        }
        ie(cout << " v[i+a-1] " <<  v[i+a-1] << endl;)
        
        ms.erase(ms.find(v[i+a-1]));

        if((i+b)<=n){
            ie(cout << " v[i+b] " <<  v[i+b] << endl;)
            ms.insert(v[i+b]);
        }
    }

    cout << ans;



}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

