#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vecinint(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vecinpii(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
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

void balance(multiset<int, greater<int> > &l, multiset<int, less<int> > &r){
    while(l.size() > r.size()){
        r.insert(*l.begin());
        l.erase(l.begin());
    }
    while(l.size() < r.size()){
        l.insert(*r.begin());
        r.erase(r.begin());
    }
}

// https://hackmd.io/@Maxlight/HJPDRG11A?utm_source=preview-mode&utm_medium=rec

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n,k ;
    cin >> n >> k;
    vi v(n);
    vecinint(v);
    
    ie(debugvec(v))

    multiset<int, greater<int> > l;
    multiset<int, less<int> > r;

    int ans = 0;

    REP(i,n){
        if( !l.size() || v[i]<= *l.begin()) l.insert(v[i]);
        else r.insert(v[i]);

        if(i>=k){
            if(l.size() && v[i-k] <= *l.begin())l.erase(l.find(v[i-k]));
            else r.erase(r.find(v[i-k]));
        }
        balance(l,r);
        if(i>=(k-1))cout<<*l.begin() << ' ' ;
        
    }

    // cout << ans << endl;
}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

