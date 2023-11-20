#include<iostream>

int fibonacci(int n) {
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    std::cout << "Enter the nth value of the fibonacci sequence: ";
    std::cin >> n;
    std::cout << "The " << n << "th number in the fibonacci sequence is: " << fibonacci(n);
    return 0;
}
