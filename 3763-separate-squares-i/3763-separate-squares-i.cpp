class Solution {
public:
    double findArea(double line, vector<vector<int>>& squares) {
        int n = squares.size();
        double areaAbove = 0, areaBelow = 0;
        for (int i = 0; i < n; i++) {
            int x = squares[i][0];
            int y = squares[i][1];
            int l = squares[i][2];
            double area = (double)l * l;
            if (line <= y) {
                areaAbove += area;
            } else if (line>= y+l) {
                areaBelow += area;
            } else {
                double aboveHeight = (y + l) - line;
                double belowHeight = line - y;
                areaAbove += l * aboveHeight;
                areaBelow += l * belowHeight;
            }
        }
        return areaAbove - areaBelow;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0, high = 2 * 1e9;
        int n = squares.size();

        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2.0;
            double area = findArea(mid, squares);
            if (area > 0) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return high;
    }
};