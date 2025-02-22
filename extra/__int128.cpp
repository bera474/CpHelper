#include <iostream>
#include <algorithm>

__int128 read() {
    std::string s;
    std::cin >> s;
    __int128 x = 0, f = 1;
    int i = 0;
    if (s[0] == '-') {
        f = -1; i = 1;
    }
    for (; i < s.size(); i++) {
        x = x * 10 + (s[i] - '0');
    }
    return x * f;
}

void print(__int128 x) {
    if (x == 0) {
        std::cout << "0\n";
        return;
    }
    if (x < 0) {
        std::cout << "-";
        x = -x;
    }
    std::string s;
    while (x > 0) {
        s.push_back((x % 10) + '0');
        x /= 10;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        __int128 a = read();
        __int128 b = read();
        print(a + b);
    }
    return 0;
}
