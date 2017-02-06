#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<=n; i++)
        {
            cout<<"2^"<<i<<" = "<<(1<<i)<<"\n";
        }
    }
    return 0;
}
