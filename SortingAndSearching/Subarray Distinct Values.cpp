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


// https://www.youtube.com/watch?v=8FdstVAkC5s
signed main()
{
    #ifdef local
    #endif

    fastios
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    int n,k ;
    cin >> n >> k;
    vi v(n);
    vecinint(v);
    
    #ifdef local
    debugvec(v)
    #endif
    int ans = 0;
    um m;
    int tmp = 0;
    int i=0, j=0;

    while(j < n){
        if( (m.find(v[j]) == m.end()) || m[v[j]]==0)tmp++;
        m[v[j]]++;
        while(tmp>k){
            m[v[i]]--;
            if(m[v[i]]==0)tmp--;
            i++;
        }
        //  3 1 1 1 => 3 + 31 + 311 + 3111 => 31=1+31 , 311 = 1+ 11 + 311, 3111 = 1 + 11 + 111 + 3111 
        ans += (j-i+1);
        j++;
    }

    cout << ans << endl;
}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

