#include <bits/stdc++.h>
using namespace std;

/*--------------------Sieve of Eratosthenes--------------------*/
const int N = 1e5;
bool prime[N + 1];

void sieve() {
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = 0;
  for (int i = 2; i * i <= N; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }
}
/*------------------------------------------------------------*/


/*--------------------------is_prime----------------------------------*/
bool is_prime(int n) {
  if (n < 2)
    return 0;
  for (int i = 2; i * i <= n; i++) {
    if ((n % i) == 0)
      return 0;
  }
  return 1;
}
/*------------------------------------------------------------*/



/*--------------prime factors of a number------------------*/
set<int> primeFactors(int n) {
  set<int> p_fct;
  while (n % 2 == 0) {
    p_fct.insert(2);
    n = n / 2;
  }

  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      p_fct.insert(i);
      n = n / i;
    }
  }

  if (n > 2)
    p_fct.insert(n);
  return p_fct;
}
/*------------------------------------------------------------*/


/*------------------------------------------------------------*/

int main() { return 0; }