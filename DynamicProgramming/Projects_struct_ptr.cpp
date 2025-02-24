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

int mod = 1e9+7;

// proj這名字被汙染 不能加
// struct proj{
struct Project{
    int st;
    int ed;
    int p;
    // Project() : st(0), ed(0), p(0) {} 
    // vector<proj> projs(n); 报错的可能原因
    // vector<T> v(n); 需要 T 有默认构造函数，但你的 proj 结构体 没有默认构造函数。
    // note: 不是這個原因 但要養成習慣
    bool operator<(const Project &pp)const{
        return ed<pp.ed; // small is at previous
    }

};

signed main()
{


    fastios
    ie(freopen("test_input.txt", "r", stdin);)

    
    int n;
    cin >> n;
    int st, ed, p;

    // vec<T> 是你自己定义的 using vec = vector<T>;
    // 但 vec<proj> projs(n); 在编译器中找不到 vec 的定义
    // vec<proj>projs(n);
    // note: 不是上面的原因 是proj的原因
    vec<Project> projs(n);

    // for (auto k : projs) 
    // 1.正确的做法是使用引用 &k

    // for (const auto &k : projs){    
    // 2.const不能加

    for ( auto &k : projs){
        cin >> k.st >> k.ed >> k.p;
    }
    sort(al(projs));

    set<pii>eds;
    eds.insert({0,0});// end day : the day best sol
    int ans = 0;
    REP(i,n){
        // 不能直接-1
        // auto pre = eds.lower_bound(mp(projs[i].st, -1))-1 ;
        // pre--：自减操作会使迭代器 pre 指向 eds 中前一个元素。自减操作类似于 pre = pre - 1，
        // 但它修改的是迭代器本身的指向，而不是元素的值。
        // -- 是运算符，不是多载，它根据上下文来调整其行为。
        // 对于基本类型，它减小值；对于迭代器，它将迭代器指向前一个元素。
        auto pre = eds.lower_bound(mp(projs[i].st, -1));
        pre--;

        // lower_bound 是一个 重载函数，它有多个版本可以接受不同类型的参数，例如：
        // lower_bound(begin, end, value)
        // lower_bound(begin, end, value, comparator)
        // 当你将 lower_bound 这个函数定义为宏 #define lb lower_bound 后，
        // 编译器在遇到 lb 时会尝试将其替换为 lower_bound。然而，lower_bound 函数有多个版本，
        // 它的参数类型和使用场景比较复杂，编译器可能无法自动推导出应该使用哪个版本的 lower_bound。

        // pre->S 是直接通过迭代器 pre 访问其指向对象的成员 S，这是迭代器的标准用法。
        // *pre.S 是错误的，应该使用 (*pre).S，但这并不推荐，因为直接使用 pre->S 更简洁清晰。
        
        // -> 用于 指针，直接访问指针所指向对象的成员。
        // * 用于 解引用 指针，得到指针所指向的对象后，通过 . 来访问成员。
       
        // p->age = 25;
        // p->greet();
        
        // // 使用 * 和 . 访问成员
        // (*p).age = 30;
        // (*p).greet();
       
        ans = max(ans, projs[i].p + pre->S);


        eds.insert({projs[i].ed, ans});
    }

    cout << ans;

    return 0;
    // g++ .\tmp.cpp -Dlocal -o tmp  
    // .\tmp.exe   
    


}
