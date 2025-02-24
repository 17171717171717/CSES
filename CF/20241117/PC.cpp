#include <bits/stdc++.h>
using namespace std;

// freopen("input.txt", "r", stdin);

int main()
{
    int t;
    cin >> t; // 測試案例數
    while (t--)
    {
        int n;
        // freopen("input.txt", "r", stdin);

        cin >> n;

        if (n == 2 || n == 3 || n == 4)
        {
            // n = 2 或 n = 3 無法滿足條件
            cout << -1 << endl;
            continue;
        }

        vector<int> even, odd;
        // 將奇數和偶數分開
        for (int i = 1; i <= n; i++)
        {
            if (i == 4 || i == 5)
                continue;

            if ((i % 2 == 0))
                even.push_back(i);
            else
            {
                odd.push_back(i);
            }
        }
        even.push_back(4);
        even.push_back(5);

        // 合併結果：偶數在前，奇數在後
        vector<int> result = even;
        result.insert(result.end(), odd.begin(), odd.end());

        // 輸出結果
        for (int x : result)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}