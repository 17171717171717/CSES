#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].f >> v[i].s;
#define debug(x) cout << #x << " = " << x << "\n";
#define debugvec(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
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

int getNumber(int n , int x , int y){
    if(n == 1){ // 2*2
        if ( x == 1 && y == 1) return 1;
        if ( x == 1 && y == 2) return 4;
        if ( x == 2 && y == 1) return 3;
        if ( x == 2 && y == 2) return 2;
    }

    int size = 1LL << (n-1); // 4blocks , 2^(n-1)*2^(n-1)   
    int block = size * size; //  each 2^(2n-2)
    // total 2^(2n-2) * 4 = 2^2n 
    int half = size;

    int dx, dy;
    if (x <= half && y <= half) { //left top
        return getNumber(n - 1, x, y);
    } else if (x > half && y > half) { //bottom right
        dx = x - half, dy = y - half;
        return block + getNumber(n - 1, dx, dy);
    } else if (x > half && y <= half) { //right top
        dx = x - half, dy = y;
        return 2 * block + getNumber(n - 1, dx, dy);
    } else { //bottom left 
        dx = x, dy = y - half;
        return 3 * block + getNumber(n - 1, dx, dy); 
        //each block have (2^n) the number of block numbers
    }

    
}


pair<int, int> getPosition(int n, int d) {
    if (n == 1) {
        if (d == 1) return {1, 1};
        if (d == 2) return {2, 2};
        if (d == 3) return {2, 1};
        if (d == 4) return {1, 2};
    }
    
    int size = 1LL << (n - 1);
    int block = size * size;
    int px,py;
    if (d <= block) {
        pair<int, int> sub = getPosition(n - 1, d);
        return {sub.first, sub.second};
    } else if (d <= 2 * block) {
        pair<int, int> sub = getPosition(n - 1, d - block);
        return {sub.first + size, sub.second + size};
    } else if (d <= 3 * block) {
        pair<int, int> sub = getPosition(n - 1, d - 2 * block);
        return {sub.first + size, sub.second};
    } else {
        pair<int, int> sub = getPosition(n - 1, d - 3 * block);
        return {sub.first, sub.second + size};
    }
}
 
signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)


    int kase;
    cin >> kase;
    while(kase--){
        int n,q;
        cin >> n >> q;
        while(q--){
            string type ;
            cin >> type;
            int x,y;
            if (type == "->"){
                cin >> x >> y;
                cout << getNumber(n,x,y) << endl;
            }
            else{
                int d;
                cin >> d;
                pair<int, int> pos = getPosition(n, d);
                x = pos.first;
                y = pos.second;
                cout << x <<" " <<  y << endl;
            }
        }
    }
    return 0;
    


}

// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   

