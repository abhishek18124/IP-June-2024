class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,majel=-1;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                majel=nums[i];
                cnt=1;
            }else{
                if(nums[i]==majel){
                    cnt++;
                }else{
                    cnt--;
                }
            }
        }
        return majel;
    }
};
