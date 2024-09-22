// https://ksp.mff.cuni.cz/kurz/#task/30-Z1-2

#include <bits/stdc++.h>
#include <fmt/format.h>

int main() {
    for (int j = 0; j < 6; ++j) {
        int N, K;
        std::freopen(fmt::format("0{}.in", j+1).c_str(), "r", stdin);

        std::cin >> N >> K;

        std::vector<int> w(N);

        for (int i = 0; i < N; ++i) {
            std::cin >> w[i];
        }

        std::sort(w.begin(), w.end());
        int l = 0;
        int r = N - 1;

        int result = 0;

        while (r >= l) {
            if (w[r] + w[l] <= K) {
                l++;
            }
            r--;
            result++;
        }
        std::freopen(fmt::format("output{}.txt", j+1).c_str(), "w", stdout);

        std::cout << result << "\n";
    }
}
