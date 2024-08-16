class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        
int i=0, j=numbers.size()-1;
vector<int>result;
        while(i<j){
            int s=numbers[i] + numbers[j];
            if(s==target){
                
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
                
                
            
            }
            else if(s<target){
                i++;
            }
            else{
                j--;
            }
        }
                    return result;

    }
        
};