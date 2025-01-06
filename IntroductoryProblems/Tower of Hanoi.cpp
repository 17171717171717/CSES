#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
template <typename T>
using vec = vector<T>;
#define pb push_back
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long;
using str = string;
#define f first
#define s second
const double eps = 1e-9;

// g++ .\tmp.cpp -Dlocal -o tmp
vec<pii>v;
int ans=0;
void recur(int from, int to, int mid, int remain){
    // cout << from << " " << to << " " << mid << " " << remain << endl;
    if(remain==1){
        v.pb({from,to});
        ans++;
        return;
    }

    recur(from, mid, to, remain-1);
    recur(from, to, mid, 1);
    recur(mid,to ,from, remain-1);
}

int main()
{
    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif

    #ifndef local
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif


    int n;
    cin >> n;
    recur(1,3,2,n);
    cout<< ans << endl;

    for(auto &i : v ){
        cout<< i.f << " " << i.s << endl;
    }
    
    return 0;
}
