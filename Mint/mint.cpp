#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

// modular int from @snuke template

struct mint {
  ll x;
  mint() : x(0) {}
  mint(ll x) : x((x % mod + mod) % mod) {}
  mint &fix() { x = (x % mod + mod) % mod; return *this; }
  mint operator-() const { return mint(0) - *this; }
  mint &operator+=(const mint &a) {if((x += a.x)>=mod)x-=mod;return *this;}
  mint &operator-=(const mint& a) {if((x+=mod-a.x)>=mod)x-=mod;return *this;}
  mint &operator*=(const mint &a) { (x *= a.x) %= mod; return *this; }
  mint operator+(const mint &a) const { return mint(*this) += a; }
  mint operator-(const mint &a) const { return mint(*this) -= a; }
  mint operator*(const mint &a) const { return mint(*this) *= a; }
  bool operator<(const mint &a) const { return x < a.x; }
  bool operator==(const mint &a) const { return x == a.x; }
};
istream &operator>>(istream &i, mint &a) { i >> a.x; return i; }
ostream &operator<<(ostream &o, const mint &a) { o << a.x; return o; }


/*With more operators like division*/

// #define ll long long
// const int mod = 1000000007;

// // modular int from @snuke template

// struct mint {
//   ll x;
//   mint() : x(0) {}
//   mint(ll x) : x((x % mod + mod) % mod) {}
//   mint &fix() {x = (x % mod + mod) % mod;return *this;}
//   mint operator-() const { return mint(0) - *this; }
//   mint operator~() const { return mint(1) / *this; }
//   mint &operator+=(const mint &a) {if((x+=a.x)>=mod)x-=mod;return *this;}
//   mint &operator-=(const mint &a) {if((x+=mod-a.x)>=mod)x-=mod;return *this;}
//   mint &operator*=(const mint &a) {(x *= a.x) %= mod;return *this;}
//   mint &operator/=(const mint &a) {(x*=a.ex(mod-2).x)%=mod;return *this;}
//   mint operator+(const mint &a) const { return mint(*this) += a; }
//   mint operator-(const mint &a) const { return mint(*this) -= a; }
//   mint operator*(const mint &a) const { return mint(*this) *= a; }
//   mint operator/(const mint &a) const { return mint(*this) /= a; }
//   mint ex(ll t) const {if (!t) return 1;mint res = ex(t / 2);
//   res *= res; return (t & 1) ? res * x : res; }
//   bool operator<(const mint &a) const { return x < a.x; }
//   bool operator==(const mint &a) const { return x == a.x; }
// };
// istream &operator>>(istream &i, mint &a) { i >> a.x; return i; }
// ostream &operator<<(ostream &o, const mint &a) { o << a.x; return o; }

int main() {
  ios_base::sync_with_stdio(true);
  cin.tie(NULL);
  return 0;
}