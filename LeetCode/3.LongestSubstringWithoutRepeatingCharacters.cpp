#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        using namespace std;
        bool checkup[300]={0}; // char range [0, 255]
        int lp=0, rp=0; // [lp, rp), so that the length of longest substring is rp-lp
        int maxlen = 0; // answer
        while(lp<s.length()) {
            if ( rp<s.length() && !checkup[s[rp]] ) checkup[s[rp++]] = true; // check and push
            else checkup[s[lp++]] = false; // pop and uncheck
            maxlen = max(maxlen, rp-lp); // update answer
        }
        return maxlen;
    }
};

int main(void) {
    std::string s;
    std::cin >> s;
    std::cout << Solution().lengthOfLongestSubstring(s) << std::endl;
    return 0;
}
