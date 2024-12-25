#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
template <typename T>
using vec = vector<T>;
#define al(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long;
using str = string;
const double eps = 1e-9;
 
int main()
{
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    int N;
    while (cin >> N)
    {
        if (N == 2 || N == 3) {
            cout << "NO SOLUTION\n";
            continue;;
        }
 
        // Output all even numbers first
        for (int i = 2; i <= N; i = i + 2) {
        
            // Print even numbers with a step of 2
            cout << i << " ";
        }
 
        // Output all odd numbers next
        for (int i = 1; i <= N; i = i + 2) {
        
            // Print odd numbers with a step of 2
            cout << i << " ";
        }
        
    }
    return 0;
}