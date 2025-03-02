class Solution {
public:
    int uniquePaths(int rows, int cols) {
        int j,i;
        vector<vector<int>> a(rows, vector<int>(cols, 0));
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                a[i][j]=0;
            }
        }
        a[0][0]=1;
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                if(j!=cols-1){
                    a[i][j+1]+=a[i][j];
                }
                if(i!=rows-1){
                    a[i+1][j]+=a[i][j];
                }
            }
        }
        return a[rows-1][cols-1];
    }
};