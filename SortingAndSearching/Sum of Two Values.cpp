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

    int n,target;
    cin >> n >> target;
    vec<pii>v;
    REP(i,n){
        int tmp;
        cin >> tmp;
        v.pb({tmp,i+1});
    }

    sort(al(v));

    int left = 0, right = n-1;
    
	while (left < right) {
		// adjust left and right pointers
		if (v[left].f + v[right].f > target) {
			right--;
		} else if (v[left].f + v[right].f < target) {
			left++;
		} else if (v[left].f + v[right].f == target) {
			cout << v[left].s << " " << v[right].s << endl;
			return 0;
		}
	}

	cout << "IMPOSSIBLE" << endl;


    return 0;
}

// g++ .\tmp.cpp -Dlocal -o tmp  