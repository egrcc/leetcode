// class Solution {
// public:
//     double myPow(double x, int n) {
//         if (n < 0) {
//             return myPow(1 / x, -n);
//         } else {
//             if (n == 0) return 1;
//             if (n == 1) return x;
//             return x * myPow(x, n - 1);
//         }       
//     }
// };

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            if (n % 2 == 0) {
                double result = myPow(x, n / 2);
                return result * result;
            } else {
                return myPow(1 / x, -n);
            }
        } else {
            if (n == 0) return 1;
            if (n == 1) return x;
            if (n % 2 == 0) {
                double result = myPow(x, n / 2);
                return result * result;
            } else {
                double result = myPow(x, (n - 1) / 2);
                return result * result * x;
            }
        }       
    }
};