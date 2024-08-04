#include <bits/stdc++.h>
using namespace std;


// y_combinator from @neal template
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 


void solve() {
    
  /*------------------------without y_combinator------------------------------*/

  // auto gcd = [](auto &&self, int a, int b) -> int {
  //   return b == 0 ? a : self(self, b, a % b);
  // };
  // cout << gcd(gcd, 20, 30) << '\n';

  /*--------------------------------------------------------------------------*/

  /*------------------------with y_combinator------------------------------*/

    auto gcd = y_combinator([](auto gcd, int a, int b) -> int {
        return b == 0 ? a : gcd(b, a % b);
    });
    cout << gcd(20, 30) << '\n';

  /*--------------------------------------------------------------------------*/

  /*-----------------------with y_combinator 2.0------------------------------*/

    // auto almost_gcd = [](auto gcd, int a, int b) -> int {
    //   return b == 0 ? a : gcd(b, a % b);
    // };
    // auto gcd = y_combinator(std::ref(almost_gcd));
    // cout << gcd(20, 30) << '\n';

  /*--------------------------------------------------------------------------*/
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); solve(); return 0;
}