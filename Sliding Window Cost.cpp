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

// Stick Lengths median in this chap
// https://www.youtube.com/watch?v=rMK_or9QNrg
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    int n,k ;
    cin >> n >> k;
    vi v(n);
    vecinint(v);
    
    ie(debugvec(v))

    if(k==1){
        REP(i,n)cout << 0 <<" " ;
        return 0;
    }
    if(k==2){
        REP1(i,n-1)cout << abs(v[i]-v[i-1]) <<" " ;
        return 0;
    }

    set<pii>ls;
    set<pii>rs;
    vpii vp;
    // for first window
    REP(i,k){
        vp.pb({v[i],i});
    }

    sort(al(vp));

    int lsum=0,rsum=0;
    for(int i = 0 ; i < (k/2+(k%2)); i++){
        ls.insert(vp[i]);
        lsum+=vp[i].f;
    }
    for(int i = (k/2+(k%2)); i < k ; i++){
        rs.insert(vp[i]);
        rsum+=vp[i].f;
    }

    int median = ls.rbegin()->first;
    cout << median * ls.size() - lsum + rsum - median * rs.size();

    for(int i = 1; i < (n-k+1) ; i++){
        if(ls.count({v[i-1],(i-1)})){
            lsum -= v[i-1];
            ls.erase({v[i-1],(i-1)});
        }
        else{
            rsum -= v[i-1];
            rs.erase({v[i-1],(i-1)});
        }

        if(*(ls.rbegin())<mp(v[k-1+i],(k-1+i))){
            rsum += v[k-1+i];
            rs.insert({v[k-1+i],(k-1+i)});
        }
        else{
            lsum += v[k-1+i];
            ls.insert({v[k-1+i],(k-1+i)});
        }

        while(ls.size()< (k/2+k%2)){
            pii z = *rs.begin();
            ls.insert(z);
            lsum+=z.f;
            rs.erase(z);
            rsum-=z.f;
        }
        while(ls.size() > (k/2+k%2)){
            pii z = *ls.rbegin();
            rs.insert(z);
            rsum+=z.f;
            ls.erase(z);
            lsum-=z.f;
        }

        median = (*ls.rbegin()).f;
        // median = ls.rbegin()->first;
        // ie(cout << v[i-1] << " v[i-1] " << endl;)
        // ie(cout << "median: " << median << endl;)
        cout <<  " "<<median * ls.size() - lsum + rsum - median * rs.size() ;

    }


 

    // cout << ans << endl;
}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

