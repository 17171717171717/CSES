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


signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    int kase;
    cin >> kase;

    // across all testcases => O(n^2)
    while(kase--){
        int n;
        cin >> n;
        vi v(n);
        vin(v);

        int max_inver = 0;
        int l=0 ,r=0;
        for(int i = 0; i < n ; i++){
            int cur_is_inv = 0;
            int cur_not_inv = 0;
            for(int j = i+1; j< n; j++){
                cur_is_inv += v[j] > v[i];
                cur_not_inv += v[j] < v[i];
          
                if (max_inver > cur_is_inv - cur_not_inv) {
                    max_inver = cur_is_inv - cur_not_inv;
                  l = i, r = j;
                }
            }
        }

        cout << l+1 << " " << r+1 << endl;
        


    }
    return 0;
    


}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

