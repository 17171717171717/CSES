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

int findFirstZero(int n) {
    return __builtin_ctz(~n); // 计算 ~n 的最低位 1 的索引
}

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    int kase;
    cin >> kase;

    while(kase--){
        int x;
        cin>>x;
        // 0 ^ a1a2a3a4 = a1a2a3a4
        // a1a2a3 + b1b2b3 = A^B <=> A&B = 0
        // A=1111 B=1100 => A^B=0011 => A = B+A^B
        // => b1b2b3 is subset of a1a2a3 => A=B+A^B
        
        // at least a not addon 1 to x in y , make sure y+z > x
        // x = 1101110, y = 0000001 => z = 1101111
        // at least a addon 1 to x in y , make sure x+y > z
        // x = 1101110, y = 0000010 => z = 1101100
        
        // x = 1101110, y = 0000011 => z = 1101101
        // rightmost 0 in x => set 1 in y => y+z > x
        // rightmost 1 in x => set 1 in y => y+x > z

        // => if x is 11111 => no not addon 1
        // => if x is 10000 => no addon 1
        
        if (__builtin_popcountll(x) == 1) { // cnt for how many 1's
            cout << "-1\n";
            continue;
        }
        int y = 0;
        int f1 = 0, f0 = 0;
        for (int i = 0; i <= 30; i++) {
            if (x & (1 << i)) {
                if (f1 == 0) {
                    y |= 1 << i;
                    f1 = 1;
                }
            } else {
                if (f0 == 0) {
                    y |= 1 << i;
                    f0 = 1;
                }
            }
        }//log(x)
        if (y < x) {
            cout << y << '\n';
        } else
            cout << "-1\n";
    
        // one carry and fill 0 with 1
        //    1111101
        // =>  1
        // => 0011111
        // => 1100010
        // =>10000001 


    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

