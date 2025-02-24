#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define debug(x) cout << #x << " = " << x << "\n";
template <typename T>
using vec = vector<T>;
#define pb push_back
#define mp make_pair
#define al(x) x.begin(), x.end()
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int,int>>;
using ll = long long ;
using str = string;
using um = unordered_map<int,int>;
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
template <typename T, typename Y>
istream &operator>>(istream &is, pair<T, Y> &p)
{
    is >> p.first >> p.second;
    return is;
}
template <typename T, typename Y>
ostream &operator<<(ostream &os, pair<T, Y> p)
{
    os << p.first << ' ' << p.second << ' ';
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v)
{
    for (auto &i : v)
        os << i << ' ';
    return os;
}


int mod = 1e9+7;
// https://www.youtube.com/watch?v=CyEiW8FqmI4
// 找到分割點i，代表左邊只能取正的，右邊只能取負的，則往左邊第一個開始取正
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    int kase;
    cin >> kase;

    while(kase--){
        int n;
        cin >> n;
        // cout << "n" << n << endl;
        vi v(n);
        cin >> v;

        vi toleft(n),toright(n);

        if(v[0]>0)toleft[0] = v[0];
        if(v[n-1]<0)toright[n-1] = -v[n-1];
    
        for(int i = 1; i < n; i++){
            toleft[i] = toleft[i-1];
            if(v[i]>0){
                toleft[i] += v[i];
            }
        }
        for(int i = n-2; i >= 0; i--){
            toright[i] = toright[i+1];
            if(v[i]<0){
                toright[i] -= v[i];
            }
        }

        int ans = 0;
        // 必有解出現在某個i，且其他解都沒有他大
        // 假設 v[i]為分割點 v[i]>=0，往i_pre < i走的話取不到i 只能取右邊的toright[i]
        
        REP(i,n){
            ans = max(ans,toleft[i]+toright[i]);
        }
        cout<<ans<<endl;

    }
    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

