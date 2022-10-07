class Solution {
public:
    bool canWinNim(int n) {
        // 1 2 3 4 5 6 7 8 9 10 11 12
        // o o o x o o o x o  o  o  x ...
        return n%4!=0;
    }
};
