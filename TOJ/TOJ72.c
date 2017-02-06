#include <stdio.h>
#include <stdlib.h>
#define TEA 3
#define MAX 15
#define ERR 0.0000000001

double F(int n, const double formu[MAX][TEA], const double x)
{
    int i, j;
    double max=-99999;
    double temp=0.0;
    double sq=0.0;
    //char w[MAX];
    for(i=0; i<n; i++)
    {
        //printf("%lf %lf %lf\n",formu[i][0],formu[i][1],formu[i][2]);
        //gets(w);
        sq = x-formu[i][1];
        if( (temp = formu[i][0]*sq*sq+formu[i][2]) > max )
            max = temp;
    }
    //printf("%.3lf\n",temp);
    return max;
}

int main(void)
{
    int term;
    int n, i, j;
    double p1,p2,p3,p4;
    // a,b,c;
    double func[MAX][TEA];
    scanf("%d",&term);
    while(term--)
    {
        p1 = p2 = p3 = p4 = 0.0;
        p4 = 300.0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<TEA; j++)
                scanf("%lf",&func[i][j]);
        }
        while(p4-p1>ERR)
        {
            p2 = p1+(p4-p1)/3.0;
            p3 = p4-(p4-p1)/3.0;
            if(F(n,func,p1)>F(n,func,p2)&&F(n,func,p2)>F(n,func,p3)&&F(n,func,p3)>F(n,func,p4))p1=p2;
            else if(F(n,func,p1)<F(n,func,p2)&&F(n,func,p2)<F(n,func,p3)&&F(n,func,p3)<F(n,func,p4))p4=p3;
            else if(F(n,func,p1)>F(n,func,p2)&&F(n,func,p2)>F(n,func,p3)&&F(n,func,p3)<F(n,func,p4))p1=p2;
            else if(F(n,func,p1)>F(n,func,p2)&&F(n,func,p2)<F(n,func,p3)&&F(n,func,p3)<F(n,func,p4))p4=p3;
            else
            {
                p1=p2;
                p4=p3;
            }
            //printf("## %lf %lf\n",p1,p4);
        }
        printf("%.5lf\n",F(n,func,p1));
    }
    return 0;
}
