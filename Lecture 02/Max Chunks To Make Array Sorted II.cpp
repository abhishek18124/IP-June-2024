class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int>st;
        st.push(arr[0]);
        for(int i=1;i<arr.size();i++){
            if (arr[i] > st.top()) { 
                st.push(arr[i]);
            }else{
                int maxEl=st.top();
                while(st.size()>0 && arr[i]<st.top()){
                    st.pop();
                }
                st.push(maxEl);
            }            
        }
        return st.size();
    }
};
