#include <cassert>
#include <limits>
#include <stack>

namespace suman {

template <typename T> class Stk {
  private:
    std::stack<T> stk;
    std::stack<T> min_stk;
    std::stack<T> max_stk;

  public:
    Stk() {
        min_stk.push(std::numeric_limits<T>::max());
        max_stk.push(std::numeric_limits<T>::min());
    }

    void push(T x) {
        stk.push(x);
        min_stk.push(std::min(min_stk.top(), x));
        max_stk.push(std::max(max_stk.top(), x));
    }

    T pop() {
        assert(!stk.empty());
        T res = stk.top();
        stk.pop();
        min_stk.pop();
        max_stk.pop();
        return res;
    }

    bool empty() { return stk.empty(); }

    T max() { return max_stk.top(); }

    T min() { return min_stk.top(); }
};

template <typename T> class MNX_stk {
  private:
    Stk<T> stk1, stk2;

  public:
    void push(T x) { stk2.push(x); }

    void pop() {
        assert(!stk1.empty() || !stk2.empty());
        if (stk1.empty()) {
            while (!stk2.empty()) {
                stk1.push(stk2.pop());
            }
        }
        stk1.pop();
    }

    T max() {
        assert(!stk1.empty() || !stk2.empty());
        return std::max(stk1.max(), stk2.max());
    }

    T min() {
        assert(!stk1.empty() || !stk2.empty());
        return std::min(stk1.min(), stk2.min());
    }
};

} // namespace suman

#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    suman::MNX_stk<int> stk;

    for (int i = 0; i < k; i++) {
        stk.push(v[i]);
    }

    std::cout << stk.min() << ' ' << stk.max() << '\n';

    for (int i = k; i < n; i++) {
        stk.push(v[i]);
        stk.pop();
        std::cout << stk.min() << ' ' << stk.max() << '\n';
    }

    return 0;
}
