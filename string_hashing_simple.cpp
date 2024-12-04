#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int base = 31;
const ll mod = 1000000009;
 
ll bin_exp(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
 
struct Hashing {
  int n;
  string s;
  vector<ll> hash, pwr, inv_pwr;
  Hashing(string a) {
    s = a;
    n = s.length();
    hash.resize(n);
    pwr.resize(n + 1);
    inv_pwr.resize(n + 1);
 
    pwr[0] = 1;
    for (int j = 1; j <= n; j++) {
      pwr[j] = (pwr[j - 1] * base) % mod;
    }
 
    inv_pwr[n] = bin_exp(pwr[n], mod - 2);
    for (int j = n - 1; j >= 0; j--) {
      inv_pwr[j] = (inv_pwr[j + 1] * base) % mod;
    }
 
    hash[0] = ((1LL + s[0] - 'a')) % mod;
    for (int j = 1; j < n; j++) {
      hash[j] = ((1LL + s[j] - 'a') * pwr[j]) % mod;
      hash[j] = (hash[j] + hash[j - 1]) % mod;
    }
  }
 
  // 0 based, both inclusive [l...r]
  ll subStrHash(int l, int r) {
    ll rgt = hash[r], lft = l > 0 ? hash[l - 1] : 0LL;
    return (((rgt - lft + mod) % mod) * inv_pwr[l]) % mod;
  }
};
 
void solve(){

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); solve(); return 0;
}
