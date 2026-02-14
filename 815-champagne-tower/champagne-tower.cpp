class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row(101, 0.0);
        row[0] = poured;

        for (int i = 0; i < query_row; ++i) {
            // Update row in reverse to use the same vector for the next level
            for (int j = i; j >= 0; --j) {
                double overflow = max(0.0, (row[j] - 1.0) / 2.0);
                row[j + 1] += overflow;
                row[j] = overflow; // The current glass 'j' now only holds its share of overflow
            }
        }
        return min(1.0, row[query_glass]);
    }
};