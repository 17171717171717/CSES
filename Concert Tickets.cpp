#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
template <typename T>
using vec = vector<T>;
#define pb push_back
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = unsigned long long ;
using str = string;
#define f first
#define s second
const double eps = 1e-9;
#define int long long


signed main()
{
    #ifdef local
    #endif

    #ifdef local
    freopen("test_input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif

    int n,m;
    cin >> n >> m;
    multiset<int>ms;
    
    vec<int>t(m);
    REP(i,n){
        int tmp;
        cin >> tmp;
        ms.insert(tmp);
    }
    REP(i,m){
        int avail_price;
        cin >> avail_price;
        auto it = ms.upper_bound(avail_price);
        
        // If it points to the begining that means no ticket is available for the customer
        // 第一個就比avail_price大 => 所有elements都比avail_price大
		if(it == ms.begin()){
            cout << -1 << endl;
        }
        else{
            cout << *prev(it) << endl;
            ms.erase(prev(it));
        }
    }


    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  