#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}


int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    int period = 60; 

    int remainder = n % period;

    int previous = 0;
    int current = 1;

    if (remainder == 0)
        return 0;

    for (int i = 2; i <= remainder; ++i) {
        int temp = (previous + current) % 10;
        previous = current;
        current = temp;
    }

    int sum = (current + 1) % 10;

    return sum;
}


int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_fast(n);
}
