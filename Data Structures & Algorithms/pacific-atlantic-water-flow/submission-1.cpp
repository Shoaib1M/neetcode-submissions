class Solution {
    vector<vector<int>> res;
    int n, m;

    bool dfs(vector<vector<int>>& heights, vector<vector<int>>& vis,
             int row, int col, int id, bool &pacific, bool &atlantic) {

        vis[row][col] = id;

        if (row == 0 || col == 0)
            pacific = true;

        if (row == n - 1 || col == m - 1)
            atlantic = true;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                heights[nrow][ncol] <= heights[row][col] &&
                vis[nrow][ncol] != id) {

                dfs(heights, vis, nrow, ncol, id, pacific, atlantic);
            }
        }

        return pacific && atlantic;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int id = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                id++;

                bool pacific = false;
                bool atlantic = false;

                dfs(heights, vis, i, j, id, pacific, atlantic);

                if (pacific && atlantic)
                    res.push_back({i, j});
            }
        }

        return res;
    }
};