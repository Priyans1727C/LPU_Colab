// You are using GCC
#include <iostream>
#include <queue>

int main() {
    std::queue<int> numQueue;
    int N;

    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        numQueue.push(num);
    }

    int sum = 0;
    while (!numQueue.empty()) {
        sum += numQueue.front();
        numQueue.pop();
    }

    if (sum == 0) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << sum << std::endl;
    }

    return 0;
}
