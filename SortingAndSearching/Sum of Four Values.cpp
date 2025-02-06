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



// signed main()
// {
//     #ifdef local
//     #endif

//     fastios
//     #ifdef local
//     freopen("test_input.txt", "r", stdin);
//     #endif
//     int n,k;
//     cin >> n >> k ;
//     // vec<int>v(n);
//     // vecinint(v);
//     // vec<pii>v(n);
//     // vecinpii(v);
//     vec<pii>v;
//     REP(i,n){
//         int tmp;
//         cin >> tmp;
//         v.pb({tmp,i+1});
//     }
//     sort(al(v));

//     return 0;
// }

// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

// function to find a quadruplet whose sum = X
void solve(vector<ll>& arr, ll X, ll N)
{
    // vector to store the values along with their indices
    vector<vector<ll>> vec(N, vector<ll>(2));

    for (int i = 0; i < N; i++) {
        vec[i][0] = arr[i];
        vec[i][1] = i + 1;
    }

    // Sort the vector in increasing order of the values
    sort(vec.begin(), vec.end());

    // Iterate for all possible values of first element
    for (ll ptr1 = 0; ptr1 < N - 3; ptr1++) {

        // Iterate for all possible values of second element
        for (ll ptr2 = ptr1 + 1; ptr2 < N - 2; ptr2++) {

            // Maintain two pointers for the third and
            // fourth element
            ll ptr3 = ptr2 + 1;
            ll ptr4 = N - 1;
            while (ptr3 < ptr4) {
                ll currentSum = vec[ptr1][0] + vec[ptr2][0]
                                + vec[ptr3][0]
                                + vec[ptr4][0];

                // If current sum is equal to X, then we
                // have found a quadruplet whose sum = X
                if (currentSum == X) {
                    cout << vec[ptr1][1] << " "
                         << vec[ptr2][1] << " "
                         << vec[ptr3][1] << " "
                         << vec[ptr4][1] << "\n";
                    return;
                }

                // Decrease the currentSum by moving ptr4 to
                // ptr4 - 1
                else if (currentSum > X) {
                    ptr4--;
                }

                // Increase the currentSum by moving ptr3 to
                // ptr3 + 1
                else if (currentSum < X) {
                    ptr3++;
                }
            }
        }
    }
    // If no quadruplet has sum = X, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE";
}

signed main()
{
    // Sample Input
    int n,k;
    cin >> n >> k ;
    vec<int>v(n);
    vecinint(v);

    solve(v, k, n);
    // your code goes here
    return 0;
}