#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int getgcd(int x, int y)
{
    return x%y?getgcd(y,x%y):y;
}

int main(void)
{
    int term;
    int a, b;
    cin>>term;
    while(term--)
    {
        cin>>a>>b;
        cout<<getgcd(a,b)<<"\n";
    }
    return 0;
}
