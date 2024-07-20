class Solution {
public:
    int removeElement(vector<int>& num, int val) {
        int k=0;
        for(int i=0;i<num.size();i++)
        {
            if(num[i]!=val){
                num[k]=num[i];
                k++;
            }
        }
        return k;
    }
};