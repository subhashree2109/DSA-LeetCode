#include<iostream>
int sum(int n) {
    if (n == 0) return 0;
    return n + sum(n - 1);
}
int main(){
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Sum of first " << n << " natural numbers is " << sum(n) << std::endl;
    return 0;
}