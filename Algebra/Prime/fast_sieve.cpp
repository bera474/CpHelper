#include <bits/stdc++.h>
using namespace std;

/**  If you just want primes, this is pretty fast too.
*** Source : https://codeforces.com/blog/entry/117775?#comment-1045646
**/

template <int N = 1'000'000, bool compute_primes = true>
struct fast_sieve {
    std::bitset<N / 3 + 1> sieve;
    vector<int> primes;
    inline bool is_prime(int n) {
        return n == 2 || n == 3 || ((n & 1) && (n % 3) && (sieve[n / 3]));
    }

    void fill_sieve() {
        sieve.set();
        for (int p = 5, d = 4, i = 1, sqn = int(std::sqrt(N)); p <= sqn;
             p += d = 6 - d, i++) {
            if (!sieve[i]) continue;
            for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,
                     qe = (int)sieve.size();
                 q < qe; q += r = s - r)
                sieve[q] = 0;
        }
    }

    vector<int> get_primes() {
        vector<int> ret{2, 3};
        for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)
            if (sieve[i]) ret.push_back(p);
        while (!ret.empty() && ret.back() > N) ret.pop_back();
        return ret;
    }
    
    fast_sieve() {
        fill_sieve();
        if (compute_primes) primes = get_primes();
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fast_sieve<1000> fst;
  for (int p : fst.primes)
    cout << p << ' ';
  cout << '\n';
  
  return 0;
}