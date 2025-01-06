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

// Function to calculate a^b using binary exponentiation
long long power(long long a, long long b)
{
    // If b = 0, whatever be the value of a,
    // our result will be 1.
    long long res = 1;
    while (b > 0) {
        // If b is an odd number, then
        // (a^b) = (a * (a^(b–1)/2)^2)
        if (b & 1) {
            res = (res * a);
        }

        // If b is an even number, then
        // (a^b) = ((a^2)^(b/2))
        a = (a * a);
        b >>= 1;
    }
    return res;
}

long long findDigit(long long int N)
{
    // No of digits
    long long digits = 1;
    // Total numbers in current digit interval
    long long base = 9;

    // Find the interval in which the Nth digit lies
    while (N - digits * base > 0) {
        N -= digits * base;
        base *= 10;
        digits++;
    }
    long long index = N % digits;

    // Calculate the number which contains the Nth digit
    // k = 582 =>num=101, idx = 1, ans = 1
    // N = 193 -189 = 4


    long long res
        = power(10, (digits - 1)) + (N - 1) / digits;
    #ifdef local
    cout << "N: "<< N << endl;
    cout << "digits: "<< digits << endl;
    cout << "res: "<< res << endl;
    cout << "idx " << index << endl;
    #endif
    // Find out which digit in the number is the result
    //res = 7485, k=28831
    // => 7485/(100 * 4 - 2)=74
    if (index != 0)
        res = res / power(10, digits - index);
    return res % 10;
}


int main()
{
    #ifdef local
    #endif

    #ifdef local
    freopen("test_input.txt", "r", stdin);
    #endif

    #ifndef local
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #endif
    // 1~9 : 9, 10~99 : 90, 100~999: 900 ....
    ll q, k;
    cin >> q;
    while(q--) {
        cin >> k;
        #ifdef local
        cout << "ori k " << k << endl;
        #endif
        cout << findDigit(k) << endl;

    }
    return 0;
}