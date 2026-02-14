class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> res(101, 0.0);
        res[0] = poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = i; j >= 0; j--) {
                double overflow = max(0.0, (res[j] - 1.0) / 2.0);
                res[j + 1] += overflow;
                res[j] = overflow;
            }
        }
        return min(1.0, res[query_glass]);
    }
};