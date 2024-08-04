#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 2e18;

vector<ll> v;

struct mnx_stk {
  deque<int> mx_dq, mn_dq;

  // push i-th element (0-based) into the stack
  void push(int i) {
    while (!mx_dq.empty() && v[mx_dq.back()] <= v[i])
      mx_dq.pop_back();
    while (!mn_dq.empty() && v[mn_dq.back()] >= v[i])
      mn_dq.pop_back();
    mx_dq.push_back(i), mn_dq.push_back(i);
  }

  // pop elements upto the i-th idx inclusive (0-based)
  void pop(int i) {
    while (!mx_dq.empty() && mx_dq.front() <= i)
      mx_dq.pop_front();
    while (!mn_dq.empty() && mn_dq.front() <= i)
      mn_dq.pop_front();
  }

  // returns max element in the stack
  ll max() { return (mx_dq.empty() ? -inf : v[mx_dq.front()]); }
  // returns min element in the stack
  ll min() { return (mn_dq.empty() ? inf : v[mn_dq.front()]); }
};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  v.resize(n);
  for (ll &x : v)
    cin >> x;

  mnx_stk st;

  for (int i = 0; i < k; i++)
    st.push(i);
  cout << st.min() << ' ' << st.max() << '\n';

  for (int i = k; i < n; i++) {
    st.push(i), st.pop(i - k);
    cout << st.min() << ' ' << st.max() << '\n';
  }
  return 0;
}