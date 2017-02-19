/*
//On Leet Code
//Difficulty: Easy
class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end(), less<int>() );
        sort(b.begin(), b.end(), less<int>() );
        vector<int> res;
        for(vector<int>::iterator i=a.begin(), j=b.begin(); i!=a.end() && j!=b.end(); ++i) {
            for(; j!=b.end() && *j<*i; ++j);
            if(j!=b.end() && *j==*i) { //same element
                if(res.empty() || *(res.end()-1)!=*i) res.push_back(*i); //unique
            }
        }
        return res;
    }
};
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::vector;
using std::sort;
using std::less;
using std::cin;
using std::cout;
using std::endl;

template<class T>
class Solution { //Compute the intersection between two vector
protected:
    vector<T> X, Y; // Just a good habit ;)
public:
    inline vector<T> &intersection(vector<T> &res) { //You need to allocate res first.
        //And this function will clear your 'res' object first...
        res.clear();
        vector<T> *a = new vector<T>(this->X); //allocate temp a
        vector<T> *b = new vector<T>(this->Y); //allocate temp b
        sort(a->begin(), a->end(), less<T>() ); //sorted a
        sort(b->begin(), b->end(), less<T>() ); //sorted b
        typedef typename vector<T>::iterator iteT;
        for( iteT i=a->begin(), j=b->begin(); i!=a->end() && j!=b->end(); ++i) {
            for(; j!=b->end() && *j<*i; ++j);
            if(j!=b->end() && *j==*i) { //same element
                if(res.empty() || *(res.rbegin())!=*i) res.push_back(*i); //unique
            }
        }
        delete a; delete b;
        //Size O(n); Time O(nlogn)?
        return res;
    }
    Solution(vector<T> const &a, vector<T> const &b) { this->X=a; this->Y=b; } //Initialize the elements
    ~Solution() {this->X.clear(); this->Y.clear();}
};

int main(void) {
    vector<int> a, b, c;
    int az, bz;
    #define READINT(X) \
    { \
        int temp; \
        std::cin>>temp; \
        X.push_back(temp); \
    }
    cin>>az>>bz;
    for(int i=0; i!=az; ++i) READINT(a);
    for(int i=0; i!=bz; ++i) READINT(b);
    Solution<int> solv(a, b);
    solv.intersection(c);
    for(vector<int>::iterator i=c.begin(); i!=c.end(); ++i) cout<<*i<<endl;
    return 0;
}
