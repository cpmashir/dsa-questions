class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int count_of_ones = 0;
        
        int i = n - 2;
        
        while (i >= 0 && bits[i] == 1) {
            count_of_ones++;
            i--;
        }
        
        return count_of_ones % 2 == 0;
    }
};