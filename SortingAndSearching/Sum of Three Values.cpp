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
#define f first
#define s second
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
#define pq(type) priority_queue<type>
const double eps = 1e-9;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



// 總時間越快，deadline越早的越要先完成
signed main()
{
    #ifdef local
    #endif

    fastios
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    int n,k;
    cin >> n >> k ;
    // vec<int>v(n);
    // vecinint(v);
    // vec<pii>v(n);
    // vecinpii(v);
    vec<pii>v;
    REP(i,n){
        int tmp;
        cin >> tmp;
        v.pb({tmp,i+1});
    }
    sort(al(v));
    REP(i,n){
        int tmp_sum = k-v[i].f;
        int l,r;
        if(i == 0) l = 1;
        else l = 0;

        if(i == (n-1))r = n-2;
        else r = n-1;
        
        bool flag = false;
        while(l<r){
            if(l == i ){
                l++;
                continue;
            }
            else if(r == i){
                r--;
                continue;
            }
            int tmp_two_sum = v[l].f + v[r].f;
            if(tmp_two_sum == tmp_sum){
                flag = 1;
                cout << v[i].s << " " << v[l].s << " " << v[r].s << endl;
                break;
            }
            else if (tmp_two_sum < tmp_sum)l++;
            else r--;

            
            


        }
        if(flag)break;
        if(i==n-1){
            cout<<"IMPOSSIBLE";
            break;
        }
    }

    // cout << ans << endl;

    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   