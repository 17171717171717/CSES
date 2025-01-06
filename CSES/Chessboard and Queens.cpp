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

    // 1. not a row
    // 2. not a column
    // 3. not a diag (2 possible violations)
    // 4. not a *

    
    vector<vector<char>> v(8, vector<char>(8));

    REP(i,8){
        REP(j,8){
            cin>>v[i][j];
            #ifdef local
            cout<<v[i][j];
            #endif
        }
        #ifdef local
        cout << endl;
        #endif
    }    

    int ans = 0;
    vec<int>_permutaion = {0,1,2,3,4,5,6,7}; // fix rows, pick columns permutation


    do{
        bool ok = true;
        
        // i row, j col = * => this permutation fails
        REP(i,8){
            if(v[i][_permutaion[i]]!='.'){
                ok = false;
                break;
            }
        }

        vec<bool>cond(15,false);

        //upper right -> lower left
        REP(i,8){
            if(cond[i+_permutaion[i]]){
                ok = false;
            }
            cond[i+_permutaion[i]] = true;
        }
        
        //ok, empty
        REP(i,15){
            cond[i] = false;
        }

        //upper left -> lower right
        REP(i,8){
            if(cond[i+7-_permutaion[i]]){
                ok = false;
            }
            cond[i+7-_permutaion[i]] = true;
        }

        if (ok) {
            ans++;
        } else {
            continue;
        }
    }while(next_permutation(_permutaion.begin(),_permutaion.end()));

    cout << ans;
    return 0;
}
