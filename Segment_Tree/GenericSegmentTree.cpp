#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MX = (1LL << 31) - 1;

struct Node {
    ll val;
    Node(): val(MX) {}
    Node(ll v): val(v) {}
    friend Node merge(Node l, Node r) { return Node(l.val + r.val); }
    void update(ll v) { val = v; }
};

struct SegTree {
    int n;
    vector<Node> seg;
    SegTree(int _n): n(_n), seg(2 * _n) {}
    template <typename Type>
    SegTree(vector<Type> a) {
        n = int(a.size());
        seg.resize(2 * n);
        for (int i = 0; i < n; i++) seg[i + n] = Node(a[i]);
        for (int i = n - 1; i > 0; i--) seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
    void update(int i, ll v) {
        for (seg[i += n].update(v); i >>= 1; ) seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
    Node query(int l, int r) {
        Node res_l, res_r;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res_l = merge(res_l, seg[l++]);
            if (r & 1) res_r = merge(seg[--r], res_r);
        }
        return merge(res_l, res_r);
    }
};

int main(){
    return 0;
}