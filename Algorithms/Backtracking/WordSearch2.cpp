//https://leetcode.com/problems/word-search-ii/

class Solution {
public:
    unordered_map<string,int>umap;
    vector<string>res;
    bool isrange(int i ,int j,int row,int col){
        return i>=0 && j>=0 && i<row && j<col;
    }
    void searchwords(vector<vector<char>>& board,int i ,int j,int row,int col,string str,vector<int>& visited){
        str+=board[i][j];
        if(umap[str]==2){
            res.push_back(str);
            umap[str]=1;
        }
        visited[i*col+j]=1;
        if(isrange(i-1,j,row,col) && umap[str+board[i-1][j]]>0 && !visited[(i-1)*col+j]){
            searchwords(board,i-1,j,row,col,str,visited);
        }
        if(isrange(i,j+1,row,col) && umap[str+board[i][j+1]]>0 && !visited[i*col+j+1]){
            searchwords(board,i,j+1,row,col,str,visited);
        }
        if(isrange(i+1,j,row,col) && umap[str+board[i+1][j]]>0 && !visited[(i+1)*col+j]){
            searchwords(board,i+1,j,row,col,str,visited);
        }
        if(isrange(i,j-1,row,col) && umap[str+board[i][j-1]]>0 && !visited[i*col+(j-1)]){
            searchwords(board,i,j-1,row,col,str,visited);
        }
        visited[i*col+j]=0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto& s:words){
            string str="";
            for(auto& c:s){
                str+=c;
                if(!umap[str])
                umap[str]=1;
            }
            umap[str]=2;
        }
        int w=board.size(),h=board[0].size();
        vector<int>visited(w*h+1,0);
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                string s="";
                if(umap[s+board[i][j]])
                searchwords(board,i,j,w,h,"",visited);
            }
        }
        return res;
    }
};
