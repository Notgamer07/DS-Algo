class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size();
        vector<int> res;
        for (int i=0; i<size; i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    int greater = nums2[j];
                    for (int k=j+1;k<nums2.size();k++){
                        if(nums2[k] > greater){
                            greater = nums2[k];
                            break;
                        }                       
                    }
                    greater = (greater == nums2[j])?(-1):(greater);
                    res.push_back(greater);
                }
            }
        }
        return res;
    }
};