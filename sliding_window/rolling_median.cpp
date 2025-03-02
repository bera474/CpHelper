#include <iostream>
#include <set>
#include <vector>

namespace suman {

template <typename T> class Median {
  private:
    std::multiset<T> L, R;

    void adjust() {
        while (L.size() > 1 + R.size()) {
            R.insert(*rbegin(L));
            L.erase(prev(end(L)));
        }

        while (L.size() < R.size()) {
            L.insert(*begin(R));
            R.erase(begin(R));
        }
    }

  public:
    void insert(T x) {
        if (!L.empty() && x > *prev(end(L))) {
            R.insert(x);
        } else {
            L.insert(x);
        }
        adjust();
    }

    void erase(T x) {
        if (R.find(x) != end(R)) {
            R.erase(R.find(x));
        } else {
            L.erase(L.find(x));
        }
        adjust();
    }

    size_t size() { return L.size() + R.size(); }

    double median() {
        double med = *rbegin(L);
        if (size() & 1)
            return med;
        med += *begin(R);
        return med / 2;
    }
};

} // namespace suman

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    suman::Median<int> md;
    for (int i = 0; i < k; i++) {
        md.insert(v[i]);
    }

    std::cout << md.median() << ' ';

    for (int i = k; i < n; i++) {
        md.insert(v[i]);
        md.erase(v[i - k]);
        std::cout << md.median() << ' ';
    }

    std::cout << '\n';
    return 0;
}
