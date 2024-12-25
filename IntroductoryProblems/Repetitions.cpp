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
    // freopen("input.txt", "r", stdin);
    str s;
    while (cin >> s)
    {
        int max_len = 1;  
        int current_len = 1; 
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                current_len++;
            } else {
                max_len = max(max_len, current_len);
                current_len = 1;
            }
        }
 
        max_len = max(max_len, current_len);
 
        cout << max_len << endl;
 
    }
    return 0;
}