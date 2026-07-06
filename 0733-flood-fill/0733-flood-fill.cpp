class Solution {
private:
    void traverse(vector<vector<int>>& image, int i , int j , int startcolor , int color , vector<vector<int>>& visited){
        int numofrow=image.size();
        int numofcol=image[0].size();
        visited[i][j]=1;
        image[i][j]=color;
        if(i>0 && image[i-1][j]==startcolor && !visited[i-1][j]) traverse(image,i-1,j,startcolor,color, visited);
        if(i<numofrow-1 && image[i+1][j]==startcolor && !visited[i+1][j]) traverse(image,i+1,j,startcolor,color,visited);
        if(j>0 && image[i][j-1]==startcolor && !visited[i][j-1]) traverse(image,i,j-1,startcolor,color,visited);
        if(j<numofcol-1 && image[i][j+1]==startcolor && !visited[i][j+1]) traverse(image,i,j+1,startcolor,color,visited);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int numofrow=image.size();
        int numofcol=image[0].size();
        vector<vector<int>> visited(numofrow,vector<int>(numofcol,0));
        traverse(image , sr,sc, image[sr][sc] , color , visited);
        return image;
    }
};