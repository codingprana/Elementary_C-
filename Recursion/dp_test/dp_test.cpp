#include <iostream>
#include <vector>
#include <climits>

using namespace std;

unsigned long long factorial(unsigned int);
unsigned long long fibonacci(unsigned int);
unsigned long long factorial2(unsigned int);
unsigned long long fibonacci2(unsigned int);

int main()
{
    for (unsigned int num = 0; num < 94; ++num) {
        cout << "Factorial(" << num << ") = "<< factorial2(num) << "\t";
        cout << "Fibonacci(" << num << ") = "<< fibonacci2(num) << endl;
    }
    cout << ULLONG_MAX;
    return 0;
}

unsigned long long factorial(unsigned int n) {
    if (n <= 1) return 1;
    return n*factorial(n-1);
}

unsigned long long fibonacci(unsigned int n) {
    if (!n) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

unsigned long long factorial2(unsigned int n) {
    static vector<unsigned long long> v{1};
    if (v.size() < n + 1) {
      v.push_back(n * factorial2(n-1));
    }
    return v[n];
}

unsigned long long fibonacci2(unsigned int n) {
    static vector<unsigned long long> vv{0, 1};
    if (vv.size() < n + 1) {
        vv.push_back(fibonacci2(n-1) + fibonacci2(n-2));
    }
    return vv[n];
}
