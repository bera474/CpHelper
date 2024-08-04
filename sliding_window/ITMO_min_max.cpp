#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 2e18;

struct stk {
  vector<ll> s, smin = {inf}, smax = {-inf};
  void push(ll x) {
    s.push_back(x);
    smin.push_back(::min(smin.back(), x));
    smax.push_back(::max(smax.back(), x));
  }
  ll pop() {
    ll res = s.back();
    s.pop_back();
    smin.pop_back();
    smax.pop_back();
    return res;
  }
  bool empty() { return s.empty(); }
  ll max() { return smax.back(); }
  ll min() { return smin.back(); }
};

struct mnx_stk {
  stk s1, s2;
  void push(ll x) { s2.push(x); }
  void pop() {
    if (s1.empty()) {
      while (!s2.empty())
        s1.push(s2.pop());
    }
    s1.pop();
  }
  ll max() { return ::max(s1.max(), s2.max()); }
  ll min() { return ::min(s1.min(), s2.min()); }
};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (ll &x : v)
    cin >> x;

  mnx_stk st;

  for (int i = 0; i < k; i++)
    st.push(v[i]);
  cout << st.min() << ' ' << st.max() << '\n';

  for (int i = k; i < n; i++) {
      st.push(v[i]); st.pop();
      cout << st.min() << ' ' << st.max() << '\n';
  }
  return 0;
}