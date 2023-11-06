#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// int get_fibonacci_huge_fast(long long n, long long m) {
//     // write your code here
//     if (n <= 1) {
//         return n;
//     }

//     int fib_array[n];
//     fib_array[0] = 0;
//     fib_array[1] = 1;

//     for (int i = 2; i <= n; i++){
//         fib_array[i] = fib_array[i-1]+fib_array[i-2];
//     }

//     return (fib_array[n])%m;
// }

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1) {
        return n % m;
    }

    long long previous = 0;
    long long current = 1;

    // Initialize an array to store the remainder of Fibonacci numbers.
    long long fib_array[n + 1];
    fib_array[0] = 0;
    fib_array[1] = 1;

    for (long long i = 2; i <= n; i++) {
        fib_array[i] = (fib_array[i - 1] + fib_array[i - 2]) % m;
        previous = current;
        current = fib_array[i];
        
        // Detect a Pisano period.
        if (previous == 0 && current == 1) {
            long long period = i - 1;
            return fib_array[n % period];
        }
    }

    return fib_array[n];
}




int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
