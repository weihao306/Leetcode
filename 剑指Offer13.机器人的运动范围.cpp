/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的
格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，
因为3+5+3+8=19。请问该机器人能够到达多少个格子？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof

提示：
    1 <= n,m <= 100
    0 <= k <= 20
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        return dfs(0, 0, m, n, k);
    }
private:
    bool visit[101][101] = {false};     //标记节点是否访问过
    int dfs(int i, int j, int m, int n, int k) 
    {
        if (i<0 || i==m || j<0 || j==n || visit[i][j] || i%10+i/10+j%10+j/10>k)
            return 0;
        visit[i][j] = true;
        return dfs(i+1, j, m, n, k) + 
               dfs(i-1, j, m, n, k) + 
               dfs(i, j+1, m, n, k) + 
               dfs(i, j-1, m, n, k) + 1;
    }
};

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    Solution sol;
    cout << sol.movingCount(m, n, k);
    return 0;
}