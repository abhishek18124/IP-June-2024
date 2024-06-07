class Solution {
public:
    void swap(vector<int>& arr,int index){
        for(int k=0;k<=index/2;k++){
            int temp=arr[k];
            arr[k]=arr[index-k];
            arr[index-k]=temp;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        for(int i=n;i>=1;i--)
        {
            int index=-1;
            for(int j=0;j<n;j++){
                if(i==arr[j]){
                    index=j;
                    break;
                }
            }
            if(index!=0){
                ans.push_back(index+1);
                swap(arr,index);
            }
            ans.push_back(i);
            swap(arr,i-1);
        }
        return ans;
    }
};
