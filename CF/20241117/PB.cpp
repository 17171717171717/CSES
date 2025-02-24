#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    int kase = 0;
    cin >> kase; // 读取测试用例数
    // cout << "kase" << kase << endl;
    while (kase--)
    {
        int k = 0;
        cin >> k;

        int size = k - 2;
        int n = 0, m = 0;
        unordered_map<int, int> tmp;

        // 读取数组内容
        bool flat = false;
        for (int i = 0; i < k; i++)
        {
            int t;
            cin >> t;
            // cout << "arr[i]: " << tmp << endl;
            tmp[t]++;
            if ((tmp[size / t] != 0) && (size % t == 0) && (flat == false))

            {
                if ((tmp[size / t] == 1) && (size / t == t))
                {
                    continue;
                }
                else
                {
                    cout << (size / t) << " " << t << endl;

                    flat = true;
                }
            }
        }
    }

    return 0;
}