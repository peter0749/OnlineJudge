#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
    int T, N, P, a, b, i, data;
    long long int sum=0, sqsum=0, result=0;
    cin>>T;
    while(T--)
    {
        sum=0;
        sqsum=0;
        cin>>N;
        for(i=0;i<N;i++)
        {
            cin>>data;
            sum += data;
            sqsum += data*data;
        }
        result = ((sqsum*N)-(sum*sum));
        cout<<fixed<<setprecision(2)<<sqrt(result)/N<<"\n";
        cin>>P;
        while(P--)
        {
            cin>>a>>b;
            cout<<fixed<<setprecision(2)<<abs(a)*sqrt(result)/N<<"\n";
        }
        cout<<"\n";
    }

    return 0;
}
