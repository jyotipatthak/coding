class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> result;   
      int cnt1=0, cnt2=0;
      int ele1=INT_MIN,  ele2=INT_MIN;
       int n=nums.size();  
      int mini = n / 3 + 1;
     
      for(int i=0; i<n; i++){
        if(cnt1==0 && ele2 != nums[i]){
            cnt1=1;
            ele1=nums[i];
        }
        else if(cnt2==0 && ele1 !=nums[i]){
            cnt2=1;
            ele2=nums[i];
        }
        else if(nums[i]==ele1){
            cnt1++;
        }
        else if(nums[i]==ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
      }

        cnt1 = 0, cnt2 = 0; 
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) cnt1++; 
            if(nums[i] == ele2) cnt2++;
        }

       if (cnt1 >= mini) {
            result.push_back(ele1);
        }
        if (cnt2 >= mini && ele1 != ele2) {
            
            result.push_back(ele2); 
        }
     return result;
    }
};