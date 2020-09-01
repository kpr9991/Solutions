//Common sense , but oldcolor==newcolor condition chudaledu anuko, fuckedup.

class Solution {
public:
    int oldcolor=0;
    void dfs(vector<vector<int> > &grid,int i,int j,int newcolor,int rows,int cols){
        if(i<0 || j<0 || i>=rows || j>=cols)
            return ;
        if(grid[i][j]!=oldcolor)
            return ;
        grid[i][j]=newcolor;
        dfs(grid,i,j+1,newcolor,rows,cols);
        dfs(grid,i+1,j,newcolor,rows,cols);
        dfs(grid,i-1,j,newcolor,rows,cols);
        dfs(grid,i,j-1,newcolor,rows,cols);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oldcolor=0;
        if(image.size()==0)
            return image;
        int rows=image.size();
        int cols=image[0].size();
        oldcolor=image[sr][sc];
        if(oldcolor==newColor)
            return image;
        
        dfs(image,sr,sc,newColor,rows,cols);
        return image;
    }
};
