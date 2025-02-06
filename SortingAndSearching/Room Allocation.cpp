#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define debugvec(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
template <typename T>
using vec = vector<T>;
#define pb push_back
#define al(x) x.begin(), x.end()
using pii = pair<long long, long long>;
using ll = long long ;
using str = string;
#define f first
#define s second
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
#define pq(type) priority_queue<type>
const double eps = 1e-9;
#define int long long
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


signed main()
{
    #ifdef local
    #endif

    fastios
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif
    int n,k;
    cin >> n ;

    vec<vec<ll>>v(n,vec<ll>(3));
    REP(i,n){
        cin >> v[i][0];
        cin >> v[i][1];
        v[i][2] = i;
    }

    sort(al(v));
    priority_queue<pii, vec<pii>, greater<pii> > cur_rooms;

    int ans = 0;
    vec<int>v_ans(n);

    REP(i,n){
        int come = v[i][0];
        int go = v[i][1];
        int room_idx = v[i][2];

        if(cur_rooms.empty() || cur_rooms.top().first >= come){
            ans ++;
            cur_rooms.push({go,ans});
            v_ans[room_idx] = ans;
        }

        else{
            int vacancy = cur_rooms.top().second;
            cur_rooms.pop();
            cur_rooms.push({go,vacancy});
            v_ans[room_idx] =  vacancy;
        }
    }

    cout << ans << endl;
    debugvec(v_ans);
    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  