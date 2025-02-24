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
// 做任何op分數都不會增加=> 
// 1. 刪除整個subarray未曾重複過 => len - dinstict # = 0
// 2. 任何一個in subarray曾重複過 => >0
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
        ie(debugv(v);)
        ie(cout<<"kase: " << kase << endl;)
        if(n==1){
            ie(cout<<"kase: " << kase << endl;)
            cout << "1 1" << endl;
            continue;
        }
        if(n==2){
            if(v[0]!=v[1]){
                ie(cout<<"kase: " << kase << endl;)
                cout<< "1 2"  << endl;
                continue;
            }
            else {
                cout << "0" << endl;
                continue;
            }
        }
        // 2 ptrs for max subarray
        map<int,int>freq;
        for(auto &i : v){
            freq[i]++;
        }

        int r = 0;
        int ansl = -1, ansr = -1;
        int len = 0;
        for(int i = 0; i < n; i++){
            // if r+1 freq > 1 => r stop => need i to save r
            r = max(r,i);
            

            // rolling r
            while (r < n && freq[v[r]] == 1)
            {
                r++;
            }

            // best
            if (r - i > len)
            {
                len = r - i;
                ansl = i;
                ansr = r - 1;
            }
        }
        ie(cout << endl << "ans "<<endl;)
        if (ansl == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ansl + 1 << " " << ansr + 1 << endl;
        }
    }
    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

