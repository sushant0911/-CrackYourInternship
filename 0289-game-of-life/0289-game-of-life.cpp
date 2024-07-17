class Solution {
public:
    int noOfLive(int i , int j , vector<vector<int>> &board){
        int m = board.size();
        int n = board[0].size();
        int live = 0;
        if(i+1 < m && board[i+1][j] == 1) live++;
        if(j+1 < n && board[i][j+1] == 1) live++;
        if(i-1 >= 0 && board[i-1][j] == 1) live++;
        if(j-1 >= 0 && board[i][j-1] == 1) live++;
        
        if(i+1 < m && j+1 < n && board[i+1][j+1] == 1) live++;
        if(i-1 >= 0 && j+1 < n && board[i-1][j+1] == 1) live++;
        if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == 1) live++;
        if(i+1 < m && j-1 >= 0 && board[i+1][j-1] == 1) live++;
        
        return live;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> clone (m, vector<int> (n,0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                clone[i][j] = board[i][j];
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 1){
                    if(noOfLive(i,j,board) == 2 || noOfLive(i,j,board) == 3){
                        clone[i][j] = 1; 
                    }
                    else{
                        clone[i][j] = 0;
                    }
                }  
                else{
                    if(noOfLive(i,j,board) == 3){
                        clone[i][j] = 1;
                    }
                    else{
                        clone[i][j] = 0;
                    }
                }
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                board[i][j] = clone[i][j];
            }
        }
        return;
    }
};