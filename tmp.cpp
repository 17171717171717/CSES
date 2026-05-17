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


class node{
    int val;
    node *prev, *next;
};
class cache{
    // int key;
    // int val;
    int cap = n;
    unordered_map<int,node*>m // [key, val]
    node *head;
    node *tail;
    head->next = tail;
    head->prev = tail;
    tail->next = head;
    tail->prev = tail;
    int get(int key, int val){
        // 回傳 key -> val
        // 沒有的話 -> return -1

        if(m.find(key)!=m.end()){
            auto cur_node = m[key];
            return cur_node->val;
        }else{
            return -1;
        }
    }
    
    void insert(node *cur_node){
        cur_node->next = head->next;
        cur_node->next->prev = head->next;
        cur_node->prev = head;
        head->next = cur_node;
    }

    // void removeast(){
    //     if(){
    //         node *tail_pre_node = tail->prev;
    //         node *tail_pre_pre_node = tail->prev->prev;
    //         tail_pre_pre_node->next =tail;
    //         tail->prev = tail_pre_pre_node;
    //         del(tail_pre_node)
    //         m.erase(tail_pre_node);
    //     }
    // }
    void remove(node *cur_node){
        
        node *cur_next_node = cur_node->prev;
        node *cur_pre_node = cur_node->prev->prev;
        cur_pre_node->next = cur_next_node;
        cur_next_node->pre = cur_pre_node;
        del(cur_node)
        m.erase(cur_node);
    }
    void set(int key, int val){
        node *cur_node = new node(val);
        if(m.find(key)){
            node *exist_node = m[key];
            remove(exist_node);
            insert(cur_node);
            m[key] = cur_node;
            
            return ;
        }
        if(cap < n){
            insert(cur_node);
            m[key] = cur_node;
            cap++;
        }else{//cap==n
            remove(tail->prev);
            insert(cur_node);
        }
    }

    bool del(int key){
        if(m.find(key)!=m.end()){
            remove(m[key]);
            erase(m[key]);
            cap--;
            return true;
        }
        
        return false;
    }
};



signed main()
{
    fastios
    ie(freopen("test_input.txt", "r", stdin);)
    
    
    return 0;
// g++ -std=c++17 .\CFtmp.cpp  -Dlocal -o tmp
// g++ .\CFtmp.cpp -Dlocal -o tmp  
// .\tmp.exe   



}


