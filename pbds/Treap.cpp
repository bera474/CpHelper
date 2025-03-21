#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/*** Needs C++11 or C++14 ***/

/// Treap supporting duplicating values in set
/// Maximum value of treap * ADD must fit in ll

struct Treap { /// hash = 96814
  int len;
  const int ADD = 1000010;
  const int MAXVAL = 1000000010;
  tr1::unordered_map<ll, int> mp; /// Change to int if only int in treap
  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
      T;

  Treap() {
    len = 0;
    T.clear(), mp.clear();
  }

  inline void clear() {
    len = 0;
    T.clear(), mp.clear();
  }

  inline void insert(ll x) {
    len++, x += MAXVAL;
    int c = mp[x]++;
    T.insert((x * ADD) + c);
  }

  inline void erase(ll x) {
    x += MAXVAL;
    int c = mp[x];
    if (c) {
      c--, mp[x]--, len--;
      T.erase((x * ADD) + c);
    }
  }

  /// 1-based index, returns the K'th element in the treap, -1 if none exists
  inline ll kth(int k) {
    if (k < 1 || k > len)
      return -1;
    auto it = T.find_by_order(--k);
    return ((*it) / ADD) - MAXVAL;
  }

  /// Count of value < x in treap
  inline int count(ll x) {
    x += MAXVAL;
    int c = mp[--x];
    return (T.order_of_key((x * ADD) + c));
  }

  /// Number of elements in treap
  inline int size() { return len; }
};