#include <fmt/format.h>

#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    for (int j = 5; j < 6; ++j) {
        int N, K;
        std::freopen(fmt::format("0{}.in", j + 1).c_str(), "r", stdin);
        std::cin >> N >> K;
        int a, b;
        std::vector<std::array<int, 3>> friends;
        for (int i = 0; i < N; ++i) {
            std::cin >> a >> b;
            friends.push_back(std::array<int, 3>{a, b, i});
        }
        std::sort(friends.begin(), friends.end(),
                  [](std::array<int, 3>& a, std::array<int, 3>& b) {
                      if (a[1] == b[1]) {
                          return a[0] < b[0];
                      }
                      return a[1] < b[1];
                  });

        int n;
        std::vector<std::pair<int, int>> atractions;
        std::vector<int> results(N * K, -1);
        for (int k = 0; k < N * K; ++k) {
            std::cin >> n;
            atractions.push_back(std::pair<int, int>(n, k));
        }
        std::sort(atractions.begin(), atractions.end());

        for (int k = 0; k < N; ++k) {
            auto it = std::lower_bound(
                atractions.begin(), atractions.end(),
                std::make_pair(friends[k][0], 0),
                [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                    return a.first < b.first;
                });
            int idx = std::distance(atractions.begin(), it);

            for (int i = idx; i < idx + K; ++i) {
                results[atractions[idx].second] = friends[k][2];
                atractions.erase(atractions.begin() + idx);
            }
        }
        std::freopen(fmt::format("output{}.txt", j + 1).c_str(), "w", stdout);

        for (int i = 0; i < N * K; ++i) {
            std::cout << results[i] << " ";
        }
    }
}
