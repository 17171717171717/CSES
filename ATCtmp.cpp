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
#define INF 1e9+5

int mod = 998244353;
class segT {
private:
    int n;
    struct Node {
        ll sum;      // 區間總庫存
        ll min_val;  // 區間最小庫存
        ll lazy;     // 惰性減量
        Node() : sum(0), min_val(0), lazy(0) {}
    };
    vector<Node> tree;

    void push(int id, int l, int r) {
        if (tree[id].lazy == 0) return;
        tree[id].sum -= tree[id].lazy * (r - l + 1);
        tree[id].min_val -= tree[id].lazy;
        if (l != r) {
            tree[2 * id].lazy += tree[id].lazy;
            tree[2 * id + 1].lazy += tree[id].lazy;
        }
        tree[id].lazy = 0;
    }

    void build(vector<int>& v, int id, int l, int r) {
        if (l == r) {
            tree[id].sum = tree[id].min_val = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(v, 2 * id, l, mid);
        build(v, 2 * id + 1, mid + 1, r);
        tree[id].sum = tree[2 * id].sum + tree[2 * id + 1].sum;
        tree[id].min_val = min(tree[2 * id].min_val, tree[2 * id + 1].min_val);
    }

    ll query(int id, int l, int r, int ql, int qr, ll k) {
        push(id, l, r);
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) {
            if (tree[id].min_val >= k) return k * (r - l + 1);
            if (l == r) return tree[id].sum;
        }
        int mid = (l + r) / 2;
        return query(2 * id, l, mid, ql, qr, k) +
               query(2 * id + 1, mid + 1, r, ql, qr, k);
    }

    void update(int id, int l, int r, int ql, int qr, ll k) {
        push(id, l, r);
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr && tree[id].min_val >= k) {
            tree[id].lazy = k;
            push(id, l, r);
            return;
        }
        if (l == r) {
            tree[id].sum = max(0LL, tree[id].sum - k);
            tree[id].min_val = tree[id].sum;
            return;
        }
        int mid = (l + r) / 2;
        update(2 * id, l, mid, ql, qr, k);
        update(2 * id + 1, mid + 1, r, ql, qr, k);
        tree[id].sum = tree[2 * id].sum + tree[2 * id + 1].sum;
        tree[id].min_val = min(tree[2 * id].min_val, tree[2 * id + 1].min_val);
    }

public:
    segT(vector<int>& v) {
        n = v.size();
        tree.resize(4 * n);
        build(v, 1, 0, n - 1);
    }

    ll query(int l, int r, ll k) {
        return query(1, 0, n - 1, l, r, k);
    }

    void update(int l, int r, ll k) {
        update(1, 0, n - 1, l, r, k);
    }
};

signed main() {
    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    int n;
    cin >> n;
    vector<int> v(n);
    REP(i, n) {
        cin >> v[i];
    }
    int q;
    cin >> q;
    segT s(v);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--; // 轉為 0-based
        ll bought = s.query(l, r, k);
        cout << bought << "\n";
        s.update(l, r, k);
    }

    return 0;
}