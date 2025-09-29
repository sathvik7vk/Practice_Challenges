#include <iostream>
#include <vector>
using namespace std;

vector<int> fib(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp;
}

int main() {
    int n = 10;
    cout << "Fibonacci(" << n << ") = " <<  endl;

    std::vector<int> result = fib(n);
    for (auto elem : result)
        cout << elem << " ";
    return 0;
}
