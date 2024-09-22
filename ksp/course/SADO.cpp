#include <bits/stdc++.h>
#include <fmt/format.h>

int main() {
    for (int j = 0; j < 6; ++j) {
        int a, b, x, y;
        std::freopen(fmt::format("0{}.in", j+1).c_str(), "r", stdin);

        std::cin >> a >> b >> x >> y;

        int n = 0;

        for (int i = a; i <= b; ++i){
            if(i % x == 0 && i % y == 0){
                n++;
            }
        }
        std::freopen(fmt::format("output{}.txt", j+1).c_str(), "w", stdout);

        std::cout << n << "\n";

    }
}
