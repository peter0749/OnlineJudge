#include <iostream>

int san_n_jia_i(int n);

int main()
{
    int n;
    while (std::cin >> n)
    {
        std::cout << san_n_jia_i(n) << "\n";
        std::cout << san_n_jia_i(san_n_jia_i(san_n_jia_i(n))) << std::endl;
    }
    return 0;
}

int san_n_jia_i(int n)
{
    if(n==1)    return 1;
    if(n&1)     return 3*n+1;
    return n>>1;
}
