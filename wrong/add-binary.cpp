class Solution {
public:
    string addBinary(string a, string b) {
        int p = 0, q = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            if (a[i] == '1') {
                p += pow(2, i);
            }
        }
        for (int i = b.length() - 1; i >= 0; i--) {
            if (b[i] == '1') {
                q += pow(2, i);
            }
        }
        int sum = p + q;
        if (sum == 0) return "0";
        string result;
        while (sum > 0) {
            sum = sum / 2;
            if (sum % 2 == 1) {
                result = '1' + result;
            } else {
                result = '0' + result;
            }
            
        }
        return result;
    }
};