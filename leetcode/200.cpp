// 200.岛屿数量
#include <vector>
#include <queue>
using namespace std;

/*
(1) 深度优先搜索（递归）
扫描整个二维网格。如果一个位置为 1，则以其为起始节点开始进行深度优先搜索。
在深度优先搜索的过程中，每个搜索到的 1 都会被重新标记为 0。
*/

class Solution1 {
private:
    int count = 0;
    void dfs(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || x > grid.size()-1 || y < 0 || y > grid[0].size()-1) return; // 超出边界
        if (grid[x][y] == '0') return; // 遇到海洋

        grid[x][y] = '0'; //将当前陆地设为0
        dfs(grid, x-1, y); // 上
        dfs(grid, x+1, y); // 下
        dfs(grid, x, y-1); // 左
        dfs(grid, x, y+1); // 右
    }
public:
    int numIslands(vector<vector<char>>& grid) {
       for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j]=='1'){
                dfs(grid, i, j);
                count++; // 发现新岛屿
            }
        }
       }
       return count; 
    }
};

/*
(2) 广度优先搜索(迭代)
可以扫描整个二维网格。如果一个位置为 1，则将其加入队列，开始进行广度优先搜索。
在广度优先搜索的过程中，每个搜索到的 1 都会被重新标记为 0。直到队列为空，搜索结束。
*/

class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0; // 记录岛屿数量
        int rows = grid.size();
        int cols = grid[0].size();
        
        // 遍历每个位置
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') { // 找到新的岛屿
                    bfs(grid, i, j);     // 使用BFS遍历整个岛屿
                    count++;             // 计数加1
                }
            }
        }
        return count;
    }

private:
    void bfs(vector<vector<char>>& grid, int x, int y) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;  // 定义队列存储要访问的坐标
        q.push({x, y});           // 初始位置入队
        grid[x][y] = '0';         // 标记为已访问

        // 方向数组，分别代表上下左右四个方向
        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        // 广度优先搜索
        while (!q.empty()) {
            auto [curX, curY] = q.front();
            q.pop();

            // 遍历四个方向的相邻格子
            for (auto [dx, dy] : directions) {
                int newX = curX + dx;
                int newY = curY + dy;

                // 检查是否越界以及是否是陆地
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == '1') {
                    q.push({newX, newY}); // 新的陆地格子入队
                    grid[newX][newY] = '0'; // 标记为已访问
                }
            }
        }
    }
};