class Solution {
public:
    int reverse(int x) {
        int r = 0;
        int temp;
        for (; x; x /= 10) {
            temp = r * 10 + x % 10;
            if ((temp - x % 10) / 10 != r) {
                return 0;
            }
            r = temp;
        }
        return r;
    }
};