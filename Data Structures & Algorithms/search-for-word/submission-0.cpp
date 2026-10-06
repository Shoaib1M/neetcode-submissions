class Solution {
public:
    int rows,cols;
    set<pair<int,int>> path;
    bool dfs(vector<vector<char>>& board,string word,int r, int c, int i){
    if(i == word.length()){
        return true;
    }
    if(r<0 || c<0 || r>=rows || c>=cols || board[r][c]!=word[i] || path.count({r,c})){
        return false;
    }
    path.insert({r,c});

    bool res = dfs(board,word,r+1,c,i+1) || dfs(board,word,r-1,c,i+1) || dfs(board,word,r,c+1,i+1) || dfs(board,word, r,c-1,i+1);
    path.erase({r,c});
    return res;
}
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for(int r = 0;r<rows;r++){
            for(int c = 0;c<cols;c++){
                if(dfs(board,word,r,c,0)){
                    return true;
                }
            }
        }
        return false;
    }
};

