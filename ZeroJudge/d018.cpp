#include <bits/stdc++.h>
using namespace std;
const size_t BUFFER_SIZE = 1<<20;
char buffer[BUFFER_SIZE];

int main(void) {
    while((fgets(buffer, BUFFER_SIZE-1, stdin))!=NULL) {
        stringstream ss(buffer);
        string rs;
        int id=0;
        double num=0.0L;
        double sum=0.0L;
        while(ss>>rs) {
            stringstream rss(rs);
            char c;
            rss >> id >> c >> num;
            if (id&1) sum+=num;
            else sum-=num;
        }
        cout << sum << endl;
    }
    return 0;
}
