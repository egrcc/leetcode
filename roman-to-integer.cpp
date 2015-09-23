#include<iostream>
using namespace std;

class Solution {
public:
    inline int map(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }

    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && map(s[i]) > map(s[i - 1])) {
                result += map(s[i]) - 2*map(s[i - 1]);
            } else {
                result += map(s[i]);
            }
        }
        return result;
    }
};

int main()
{
    string s = "MCMLIV";
    Solution solution;
    int result = solution.romanToInt(s);
    cout << result << endl;
}
