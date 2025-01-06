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

// 若 a+b = 3*i, i>=0, 則可輕易解答YES or NO
// 令 a+b = 3k, k >= 0
// 令 a = min(a,b), b-a = t , k>= t >= 0 
// 則 (b-2t) + (a-t) = a+b-3t = 3k - 3t = 3(k-t) 為 3*i 
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


    string s;
    cin >> s;
    int n = s.size();
    vec<int>cnts(26,0);
    REP(i,n){
        cnts[s[i]-'A']++;            
        #ifdef local
        cout<< "cnts " << s[i]-'A' << cnts[s[i]-'A'] << endl;
        #endif
    }
    
    int odd = 0, oddpos=30;
    
    REP(i,26){
        if((cnts[i]%2) == 1){
            odd++;
            oddpos = i;
            #ifdef local
            cout<<odd << "odd " << "oddpos" << oddpos << endl;
            #endif
            if(odd>=2){
                cout<<"NO SOLUTION"<<endl;
                return 0;
            }
        }
        cnts[i]/=2;
    }
    string ans = "";
    REP(i,26){
        if(i==oddpos)continue;
        ans += string(cnts[i], 'A'+i);
        #ifdef local
        cout<<ans << " first "<<endl;
        cout<<"cnts[i]: " << cnts[i] << endl;
        #endif
        
    }
    if(oddpos != 30)ans += string(1+2*cnts[oddpos], 'A'+oddpos);
    for(int i=25; i>=0;i--){
        if(i==oddpos)continue;
        ans += string(cnts[i], 'A'+i);
        #ifdef local
        cout<<"cnts[i]" << cnts[i] << endl;
        cout<<ans<<endl;
        #endif
        
    }
    cout << ans << endl;
    
    return 0;
}
