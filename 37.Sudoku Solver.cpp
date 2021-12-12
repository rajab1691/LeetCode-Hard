/*
  1.Go row by row,check for every cell if it is not filled try (1-9)possibilty and recur from next col
  2.if col ends then go to next row
  3.if last row then return true
  
  T.C-O(n^2)
*/

bool isValid(vector<vector<char>>& board,int i,int j,char c){
        
        for(int x=0;x<9;x++){
            if(board[x][j]==c or board[i][x]==c){
                return false;
            }
        }
        
        int sx=(i/3)*3;
        int sy=(j/3)*3;
        
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                if(board[sx+x][sy+y]==c)
                    return false;
            }
        }
        return true;
    }
    bool helper(int i,int j,vector<vector<char>>& board){
        
        if(i==9){
            return true;
        }
        if(j==9){
            return helper(i+1,0,board);
        }
        
        if(board[i][j]!='.'){
            return helper(i,j+1,board);
        }
        
        for(char c='1';c<='9';c++){
            if(isValid(board,i,j,c)){
                board[i][j]=c;
                bool f=helper(i,j+1,board);
                if(f){
                    return true;
                }
               
            }
        }
         board[i][j]='.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(0,0,board);
    }
