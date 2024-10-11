#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define sz(x) ((int)(x).size())

typedef long long ll;

ll expo(ll a, ll b, ll mod) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(ll a, ll b, ll *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  ll x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
} // pass an arry of size1 3
ll mminv(ll a, ll b) {
  ll arr[3];
  extendgcd(a, b, arr);
  return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_add(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m

struct Hashing {
  string s;
  int n;
  int primes;
  vector<long long> hashPrimes = {1000000009, 100000007};
  const long long base = 31;
  vector<vector<long long>> hashValues;
  vector<vector<long long>> powersOfBase;
  vector<vector<long long>> inversePowersOfBase;
  Hashing(string a) {
    primes = sz(hashPrimes);
    hashValues.resize(primes);
    powersOfBase.resize(primes);
    inversePowersOfBase.resize(primes);
    s = a;
    n = s.length();
    for (int i = 0; i < sz(hashPrimes); i++) {
      powersOfBase[i].resize(n + 1);
      inversePowersOfBase[i].resize(n + 1);
      powersOfBase[i][0] = 1;
      for (int j = 1; j <= n; j++) {
        powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
      }
      inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
      for (int j = n - 1; j >= 0; j--) {
        inversePowersOfBase[i][j] =
            mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
      }
    }
    for (int i = 0; i < sz(hashPrimes); i++) {
      hashValues[i].resize(n);
      for (int j = 0; j < n; j++) {
        hashValues[i][j] =
            ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
        hashValues[i][j] =
            (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) %
            hashPrimes[i];
      }
    }
  }
  vector<long long> substringHash(int l, int r) // O(1)
  {
    vector<long long> hash(primes);
    for (int i = 0; i < primes; i++) {
      long long val1 = hashValues[i][r];
      long long val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
      hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]),
                        inversePowersOfBase[i][l], hashPrimes[i]);
    }
    return hash;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  string str;
  cin >> str;
  struct Hashing h = Hashing(str); // O(n)
  int l, r;
  cin >> l >> r;
  vector<ll> hashCheck = h.substringHash(l, r); // O(1)
  return 0;
}



/*

ll expo(ll a, ll b, ll mod) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
 
ll mminvprime(ll a, ll b) { 
  return expo(a, b - 2, b); 
}
 
ll mod_add(ll a, ll b, ll m) {
  a = a % m, b = b % m;
  return (((a + b) % m) + m) % m;
}
 
ll mod_mul(ll a, ll b, ll m) {
  a = a % m, b = b % m;
  return (((a * b) % m) + m) % m;
}
 
ll mod_sub(ll a, ll b, ll m) {
  a = a % m, b = b % m;
  return (((a - b) % m) + m) % m;
}
 
struct Hashing {
  string s;
  int n, pr_cnt;
  const ll base = 31;
  vector<vector<ll>> hash, pwr, inv_pwr;
  vector<ll> primes = {1000000009, 100000007};
 
  Hashing(string a) {
    pr_cnt = primes.size();
    hash.resize(pr_cnt);
    pwr.resize(pr_cnt);
    inv_pwr.resize(pr_cnt);
    s = a; n = s.length();
    for (int i = 0; i < primes.size(); i++) {
      pwr[i].resize(n + 1);
      inv_pwr[i].resize(n + 1);
      pwr[i][0] = 1;
      for (int j = 1; j <= n; j++) 
        pwr[i][j] = (base * pwr[i][j - 1]) % primes[i];
      inv_pwr[i][n] = mminvprime(pwr[i][n], primes[i]);
      for (int j = n - 1; j >= 0; j--) 
        inv_pwr[i][j] = mod_mul(inv_pwr[i][j + 1], base, primes[i]);
    }
    for (int i = 0; i < primes.size(); i++) {
      hash[i].resize(n);
      for (int j = 0; j < n; j++) {
        hash[i][j] = ((s[j] - 'a' + 1LL) * pwr[i][j]) % primes[i];
        hash[i][j] = (hash[i][j] + (j > 0 ? hash[i][j - 1] : 0LL)) % primes[i];
      }
    }
  }
 
  vector<ll> subStrHash(int l, int r) {
    vector<ll> res(pr_cnt);
    for (int i = 0; i < pr_cnt; i++) {
      ll val1 = hash[i][r], val2 = l > 0 ? hash[i][l - 1] : 0LL;
      res[i] =
          mod_mul(mod_sub(val1, val2, primes[i]), inv_pwr[i][l], primes[i]);
    }
    return res;
  }
};

*/