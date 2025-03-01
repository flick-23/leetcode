class Solution {
public:
    vector<vector<int>> generate(int n) {
        int i,j;
        vector<vector<int>> a( n , vector<int>(n));  

        for(i=0;i<n;i++){
            a[i].resize(i + 1);
            for(j=0;j<i+1;j++){
                if(j==0 || (i==j)){
                    a[i][j]=1;
                }
                else{
                    a[i][j]=a[i-1][j]+a[i-1][j-1];
                }
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        return a;
    }
};