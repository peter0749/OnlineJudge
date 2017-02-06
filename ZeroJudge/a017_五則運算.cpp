#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#define WORDLEN 12
#define MAXOP 10000

using namespace std;

char postod[MAXOP][WORDLEN] = {{0}};
int stk[MAXOP];
char buffer[MAXOP][WORDLEN] = {{0}};
int intop, postop, stktop;
const char token[]=" \n";

inline bool is_digit(char *ptr)
{
    return (*ptr <= '9' && *ptr >= '0' );
}

inline int is_operand(char *ptr)
{
    switch(*ptr)
    {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '%':
        return 4;
    default:
        return 0;
    }
}

inline bool is_lq(char *ptr)
{
    return (*ptr=='(');
}

inline bool is_rq(char *ptr)
{
    return (*ptr==')');
}

int parsing(char *input)
{
    char *ptr=NULL;
    int priority(0);
    intop = postop = -1;
    ptr = strtok(input,token);
    while(ptr!=NULL)
    {
        if(is_digit(ptr))   strcpy(postod[++postop],ptr);
        else if(is_lq(ptr))
        {
            //puts(ptr);
            strcpy(buffer[++intop],ptr);
        }
        else if(is_rq(ptr))
        {
            while(intop!=-1&&is_lq(buffer[intop])==false) //Note intop==-1 when it is empty
            {
                //cout<<buffer[intop]<<endl;
                strcpy(postod[++postop],buffer[intop]);
                intop--;
                //puts(buffer[intop]);
            }
            if(intop!=-1)   intop--;
        }
        else if(priority = is_operand(ptr))
        {
            while(intop!=-1&&priority<=is_operand(buffer[intop]))
            {
                strcpy(postod[++postop],buffer[intop--]);
            }
            strcpy(buffer[++intop],ptr);
        }
        ptr = strtok(NULL,token);
    }
    while(intop!=-1)
    {
        strcpy(postod[++postop],buffer[intop--]);
    }
    return postop;
}

int calcu(int n)
{
    int i;
    stktop = -1;
    for(i=0; i<=n; i++)
    {
        if(is_digit(postod[i]))
        {
            stk[++stktop] = atoi(postod[i]);
        }
        else if(is_operand(postod[i]))
        {
            switch(postod[i][0])
            {
            case '+':
                stk[stktop-1] = stk[stktop]+stk[stktop-1];
                stktop--;
                break;
            case '-':
                stk[stktop-1] = stk[stktop-1] - stk[stktop];
                stktop--;
                break;
            case '*':
                stk[stktop-1] = stk[stktop] * stk[stktop-1];
                stktop--;
                break;
            case '/':
                stk[stktop-1] = stk[stktop-1] / stk[stktop];
                stktop--;
                break;
            case '%':
                stk[stktop-1] = stk[stktop-1] % stk[stktop];
                stktop--;
                break;
            }
        }
    }
    return stk[stktop];
}

void ptrout(int n)
{
    cout<<postod[0];
    for(int i=1; i<=n; i++)
    {
        cout<<' '<<postod[i];
    }
    cout<<endl;
}

int main(void)
{
    char temp[100000];
    int counter(0);
    while((cin.getline(temp,100000))!=NULL)
    {
        counter = parsing(temp);
        //ptrout(counter);
        cout<<calcu(counter)<<'\n';
    }

    return 0;
}
