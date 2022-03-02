#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (obstacleGrid[i - 1][j - 1] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp.back().back();
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    cout << "--------------------" << endl;
    return 0;
}
