class Solution {
    set<vector<int>> res;

    void bfs(vector<vector<int>>& heights, vector<vector<int>>& vis, int row, int col) {
        int n = heights.size();
        int m = heights[0].size();

        int startRow = row;
        int startCol = col;

        bool pacific = false;
        bool atlantic = false;

        vis[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();

            if (row == 0 || col == 0)
                pacific = true;

            if (row == n - 1 || col == m - 1)
                atlantic = true;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    heights[nrow][ncol] <= heights[row][col] &&
                    !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        if (pacific && atlantic)
            res.insert({startRow, startCol});
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                vector<vector<int>> vis(n, vector<int>(m, 0));

                bfs(heights, vis, i, j);
            }
        }

        vector<vector<int>> ans;

        for (auto x : res)
            ans.push_back(x);

        return ans;
    }
};