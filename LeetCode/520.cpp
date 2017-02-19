/*
//In LeetCode
//Difficulty: Easy
using namespace std;
if(word.empty()) return true;
string::size_type i;
if(islower(word[0])) {
    for(i=1; i<word.length() && islower(word[i]); ++i);
} else {//isupper
    if(word.length()>1 && islower(word[1])) {//second letter is lower
        for(i=2; i<word.length() && islower(word[i]); ++i);
    } else {
        for(i=1; i<word.length() && isupper(word[i]); ++i);
    }
}
return (i==word.length());
*/
#include <iostream>
#include <string>

int main(void) {
    std::string str1;
    while(std::cin>>str1) {
        using namespace std;
        if(str1.empty()) continue; //This shouldn't happen.
        string::size_type i;
        if(islower(str1[0])) {
            for(i=1; i<str1.length() && islower(str1[i]); ++i);
        } else {//isupper
            if(str1.length()>1 && islower(str1[1])) {//second letter is lower
                for(i=2; i<str1.length() && islower(str1[i]); ++i);
            } else {
                for(i=1; i<str1.length() && isupper(str1[i]); ++i);
            }
        }
        cout << (i==str1.length()?"True\n":"False\n");
    }
    return 0;
}
