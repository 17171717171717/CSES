#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define vin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i];
#define vpiiin(v) for( int i = 0 ; i < v.size() ; i++ ) cin >> v[i].first >> v[i].second;
#define debugv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define debug(x) cout << #x << " = " << x << "\n";
template <typename T>
using vec = vector<T>;
#define pb push_back
#define mp make_pair
#define al(x) (x).begin(), (x).end()
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<long long>>;
using vpii = vector<pair<long long,long long>>;
using vvpii = vector<vector<pair<long long,long long>>>;
using ll = long long ;
using str = string;
using um = unordered_map<long,long>;
#define F first
#define S second
// small to big
#define min_pq(type) priority_queue<type, vector<type>, greater<type>>
// big to small
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

const int mod = 1e9+7;

vvi dirs = {{-1,0},{1,0},{0,1},{0,-1}};
// vec<char>dirs_eng = {'L','R','U','D'}; 
vec<char>dirs_eng = {'U','D','R','L'};// -1,0 => Down 

int max_s = 1e18;
class bittree{
    private:   
        vi a;
        vi bit;
        int n;

        int lowbit(int x){
            return x & -x; // in 2's complement, -x = ~x+1, 則最右邊被反過來的1都會進位到第一個0為止
                            // 也就是原本最右邊的1
        }
    
    public:
        bittree(int n): n(n){ // == this->n = n;
            a.assign(n+1,0);
            bit.assign(n+1,0);
        }

        void init(vi &v){
            for(int i = 1; i <= n; i++){
                bit[i] = 0;
                a[i] = v[i];
            }
            for(int i = 1; i <= n; i++){
                bit[i]+=v[i];
                int y = i + lowbit(i); 
                // contribute to the where the range y belong to by 2^k
    
                // 1 for 1,2,4,8.. / 1  for 10, 100, 1000...
                // 2 for 2,4,8..   / 10 for 100, 1000...
                // 3 for 3,4,8... / 011 for 100, 1000...
                // 5 for 5,6,8... / 101 for 101, 110, 1000...
                // 6 for 6,8...   / 110 for 110, 1000, 10000
                // 9 = 1001 for 10,12,16 = 1010, 1100, 10000...
    
                if(y <= n)v[y] += v[i];
            }
        }
        // void init(vi v){
        //     for(int i = 1; i <= n; i++){
        //         bit[i] = 0;
        //         a[i] = v[i];
        //     }
        //     for(int i = 1; i <= n; i++){
        //         bit[i]+=a[i];
        //         int y = i + lowbit(i);
        //         if(y <= n)a[y] += a[i];
        //     }
        // }
        void init2(const vector<long long>& input) {
            for (int x = 1; x <= n; ++x) {
                a[x] = input[x];    // 複製輸入的陣列
                bit[x] = a[x];       // 初始化 bit[x] 為 arr[x]
    
                int y = x - lowbit(x);
                for (int i = x - 1; i > y; i -= lowbit(i)) {
                    bit[x] += bit[i];  // 將 [y+1, x-1] 區間的值累加到 bit[x]
                }
            }
        }

        void update(int idx, int x){
            int delta = x - a[idx];
            a[idx] = x;
            while (idx <= n) {
                bit[idx] += delta;
                idx += lowbit(idx);  // move to next range of 2^k
            }
        }

        int query(int idx){
            int sum = 0;
            // 1,7 => 7,7 + 1,6 => 7,7 + 5,6 + 1,4
            while (idx > 0) {
                sum += bit[idx];
                idx -= lowbit(idx);  // 移動到前一個有效節點
            }
            return sum;
        }

        int range_query(int l, int r){
            return(query(r) - query(l-1));
        }
};
signed main() {
    fastios;
    
    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    int n, q;
    cin >> n >> q;
    vi v(n+1);
    for(int i =1 ; i <= n; i++){
        cin >> v[i];
    }
    // debugv(v)
    bittree b(n);
    b.init(v);
    for(int i = 0; i < q; i++){
        int t,l,r;
        cin >> t >> l >> r;
        if(t == 1){
            b.update(l,r);
        }
        else if (t==2){
            cout<<b.range_query(l,r) << endl;
        }
        else break;

    }
    
    return 0;
}
// g++ .\tmp.cpp -Dlocal -o tmp  
// .\tmp.exe   
