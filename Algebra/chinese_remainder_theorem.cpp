struct Congruence { ll a, m };

ll mod_inv(ll a, ll m) {
    return bin_exp(a, m - 2, m);
}

ll chinese_remainder_theorem(vector<Congruence> const &congruences) {
  ll M = 1, solution = 0;
  for (auto const &congruence : congruences) M *= congruence.m;

  for (auto const &congruence : congruences) {
    ll a_i = congruence.a;
    ll M_i = M / congruence.m;
    ll N_i = mod_inv(M_i, congruence.m);
    solution = (solution + a_i * M_i % M * N_i) % M;
  }
  return solution;
}