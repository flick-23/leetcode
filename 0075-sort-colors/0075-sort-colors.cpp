class Solution {
public:
    void sortColors(vector<int>& a) {
        int i,n=a.size(),x=0,y=0,z=0;
        for(i=0;i<n;i++){
            if(a[i]==0)
                x++;
            else if(a[i]==1)
                y++;
            else
                z++;
        }
        for(i=0;i<n;i++){
            if(x!=0){
                a[i]=0;
                x--;
            } 
            else if(y!=0){
                a[i]=1;
                y--;
            }
            else{
                a[i]=2;
                z--;
            }
        }
    }
};