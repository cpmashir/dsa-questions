#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        // Loop as long as there are digits to process or a carry remains
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i--] - '0'; // Convert char to int
            }
            if (j >= 0) {
                sum += b[j--] - '0'; // Convert char to int
            }
            
            // Append the bit (sum % 2) and update carry (sum / 2)
            result += to_string(sum % 2);
            carry = sum / 2;
        }

        // The result was built backwards, so reverse it
        reverse(result.begin(), result.end());
        return result;
    }
};