#include <bits/stdc++.h>
using namespace std;

template<class T>
class RadixSort {
typedef typename vector<T>::iterator VITE;
    private:
        vector<T>data;
        T base;
        void count_sort(const T exp, T *count, vector<T> *&temp) {
            fill(count, count+base, 0x00);
            for(VITE v=data.begin(); v!=data.end(); ++v) {
                ++count[ (*v/exp)%base ];
            }
            partial_sum(count, count+base, count);
            for(int i=data.size()-1; i!=-1; --i) {
                temp->at(--count[(data.at(i)/exp)%base]) = data.at(i);
            }
            data=*temp;
        }
    public:
        void radix_sort() {
            T maxv=*max_element(data.begin(), data.end());
            vector<T> *temp = new vector<T>(data.size());
            T *count = new T[base];
            for(T v=1; maxv / v > 0; v*=base) count_sort(v, count, temp);
            delete[] count; count=NULL;
            delete temp; temp=NULL;
        }
        inline void push_back(T d) {
            data.push_back(d);
        }
        inline void insert(const VITE b, const VITE l, const VITE r) {
            data.insert(b,l,r);
        }
        inline T get(size_t n) { return data.at(n); }
        RadixSort() {
            this->base=10;
        }
        inline size_t size(void) {
            return data.size();
        }
        inline void clear(void) {
            data.clear();
        }
        RadixSort(T b) {
            this->base = b;
        }
};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    RadixSort<int> arr(255);
    int N;
    while(cin>>N) {
        for(int i=0; i<N; ++i) {
            int temp; cin>>temp;
            arr.push_back(temp);
        }
        arr.radix_sort();
        cout<<arr.get(0);
        for(int i=1; i!=arr.size(); ++i) cout<<' '<<arr.get(i);
        cout<<'\n';
        arr.clear();
    }
    return 0;
}
