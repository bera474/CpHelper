#include <bits/stdc++.h>
using namespace std;

// Source : https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/

vector<int> p_factors(int n) { // O(sqrt(n))
  vector<int> fct;
  while (n % 2 == 0) {
    fct.push_back(2);
    n = n / 2;
  }

  int sqr = sqrt(n);
  for (int i = 3; i <= sqr; i += 2) {
    while (n % i == 0) {
      fct.push_back(i);
      n = n / i;
    }
  }

  if (n > 2)
    fct.push_back(n);
  return fct;
}

// vector<int> p_factors(int x) { // O(log(n))
//   vector<int> ret;
//   while (x != 1) {
//     ret.push_back(spf[x]);
//     x = x / spf[x];
//   }
//   return ret;
// }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = 315;
  vector<int> fcts = p_factors(n);
  for (int x : fcts)
    cout << x << ' ';
  return 0;
}
