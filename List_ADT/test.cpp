#include <iostream>

using namespace std;

int main()
{
    int a[] = {12, 34};
    int *p = a;
    int *p2 = p;
    p = new int[2];
    p[0] = 11;
    p[1] = 22;
    delete[] p;
    cout << a[0] << " " << p[0] << " " << p2[0];

    p[0] = 1;
    p[1] = 2;
    cout << a[0] << " " << p[0] << " " << p2[0];


    return 0;
}