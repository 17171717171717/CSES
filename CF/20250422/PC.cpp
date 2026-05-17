#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debug(x) cout << #x << " = " << x << "\n";
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
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
using um = unordered_map<int,int>;
#define F first
#define S second
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
#define pq(type) priority_queue<type>
const double eps = 1e9+7;
#define int long long 
#define fastios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifdef local
    #define ie(x) x
#else
    #define ie(x)
#endif
#define INF 1000000000

int mod = 998244353;

 
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int kase;
    cin >> kase;
    while(kase--){
        int n, k;
        cin >> n >> k;
        vector<int>v(n+1,0);
        vector<int>precnt(n+1,0);
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        precnt[1] = v[1] <= k ? 1 : 0;

        for(int i = 2; i <= n; i++){
            if(v[i] <= k){
                precnt[i] = precnt[i-1]+1;
            }else{
                precnt[i] = precnt[i-1];
            }
        }

        ie(debugv(precnt))

        bool ok = false;
        int l = 0;
        bool lok =false;
        bool rok =false;
        bool midok =false; 
        for(int i = 1; i<= n-2; i++){
            // left block
            if(precnt[i] >= ((i/2)+(i%2))){//lok
                for(int j = i+1; j <= n-1; j++){//midok
                    if((precnt[j] - precnt[i])>= ((j-i)/2 + (j-i)%2)){
                        cout <<"YES" << endl;
                        ok = true;
                        break;
                    }else if((precnt[n] - precnt[j])>= ((n-j)/2 + (n-j)%2)){//rok
                        cout <<"YES" << endl;
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            
        }
        if(ok)continue;

        for(int i = n; i>= 3; i--){
            // right block
            if((precnt[n] - precnt[i-1])>= ((n - i + 1)/2 + (n - i + 1)%2)){ // rok
                for(int j = i-1; j >= 2; j--){
                    // 中段長度應該是 i-1 到 j，所以長度為 (i - j)
                    if((precnt[i-1] - precnt[j-1])>= ((i - j)/2 + (i - j)%2)){ // midok
                        cout << "YES" << endl;
                        ok = true;
                        break;
                    }else if((precnt[j-1])>= ((j - 1)/2 + (j - 1)%2)){ // lok
                        cout << "YES" << endl;
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
        }
        if(ok) continue;
        else{
            cout << "NO" << endl;
        }
        
    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

