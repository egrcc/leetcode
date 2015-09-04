class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        while (true) {
            if (digits[index] == 9) {
                digits[index] = 0;
                index--;
                if (index < 0) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
            } else {
                digits[index] += 1;
                break;
            }
        }
        return digits;
    }
};