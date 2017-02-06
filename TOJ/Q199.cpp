#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

inline int ab(int &a,int &b)
{
    int t = a-b;
    return t>0 ? t:-t;
}

int main(void)
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<ab(a,c)+ab(b,d)<<"\n";
    return 0;
}
