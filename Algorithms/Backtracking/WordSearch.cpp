//https://leetcode.com/problems/word-search/

class Solution {
public:

    bool wordSearch(vector<vector<char>>& board, string word, int index, int i, int j,vector<vector<int>> &visited){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        if(visited[i][j]) return false;
        bool b = false;
        if(board[i][j]==word[index]){
            visited[i][j]=1;
            index++;
            if(index==word.length()) return true;
            b = wordSearch(board,word,index,i-1,j,visited) | wordSearch(board,word,index,i+1,j,visited) | wordSearch(board,word,index,i,j-1,visited) | wordSearch(board,word,index,i,j+1,visited);
            if(b) return true;
            visited[i][j]=0;
        }
        return b;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int index = 0;
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                bool b = wordSearch(board,word,0,i,j,visited);
                if(b) return true;
            }
        }
        return false;
    }
};
