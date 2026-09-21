class Solution {
public:
    int rob(vector<int>& nums) {
          int n=nums.size();
       if(n==1){
         return nums[0];
       } 

       int pp=0;
       int p=nums[0];
       for(int i=2; i<=n; i++){
        int steal=nums[i-1]+pp;
        int skip=p;
        int temp= max(steal,skip);

        pp=p;
        p=temp;
       }
       return p;
    }
};