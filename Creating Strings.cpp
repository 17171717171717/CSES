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

set<string>ans;
    
void permuteRec(string& str, int CurChangeStart)
{
    // Base case
    if (CurChangeStart == str.size() - 1) {
        cout<<"str " << str<<endl;
        ans.insert(str);
        return;
    }

    for (int i = CurChangeStart; i < str.size(); i++) {
      
        // Swapping 
        swap(str[CurChangeStart], str[i]);

        // First CurChangeStart+1 characters fixed
        permuteRec(str, CurChangeStart + 1);

        // Backtrack
        swap(str[CurChangeStart], str[i]);
    }
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


    string str;
    cin >> str;

    permuteRec(str,0);
    
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout << i << endl;
    }
    
    return 0;
}
