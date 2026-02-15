#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string result;
        result.reserve(max(a.size(), b.size()) + 1);

        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            
            result.push_back((carry % 2) + '0');
            carry /= 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};