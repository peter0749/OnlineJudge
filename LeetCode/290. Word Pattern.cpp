class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> hashmap;
        unordered_map<string,char> inv_hashmap;
        stringstream ss;
        ss << s;
        int i=0;
        while(ss) {
            string value;
            ss >> value;
            if (value.length() == 0)
                break;
            if (i == pattern.length())
                return false;
            char key = pattern[i];
            if (hashmap.count(key) == 0)
                hashmap[key] = value;
            if (hashmap[key] != value)
                return false;
            if (inv_hashmap.count(value) == 0)
                inv_hashmap[value] = key;
            if (inv_hashmap[value] != key)
                return false;
            ++i;
        }
        return i==pattern.length();
    }
};
