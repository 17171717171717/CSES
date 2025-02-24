#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    // ifstream cin("input.txt"); // 打开文件
    // if (!cin.is_open())
    // {
    //     cerr << "无法打开文件！" << endl;
    //     return 1;
    // }
 
    int kase = 0;
    cin >> kase; // 读取测试用例数
    // cout << "kase" << kase << endl;
    while (kase--)
    {
        int n = 0;
        cin >> n; // 读取当前数组大小
        // cout << "n:" << n << endl;
        int ans = 0;
        vector<int> arr(n);
        unordered_map<int, int> m;
 
        // 读取数组内容
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            // cout << "arr[i]: " << tmp << endl;
            m[tmp]++;
        }
 
        if (n <= 1)
        {
            cout << 0 << endl; // 如果只有一种数字
        }
        else
        {
            // 示例逻辑：计算每个元素的贡献
            for (auto i : m)
            {
                ans += (i.second / 2); // 使用计数值示例计算
            }
            cout << ans << endl;
        }
        // return ans;
    }
 
    return 0;
}