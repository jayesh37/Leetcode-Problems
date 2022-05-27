class Solution {
public:
    int numberOfSteps(int num) {
        int count=0;
        while(num)
        {
            count++;
            
            if(num%2)
                num--;
            else
                num /= 2;
        }
        return count;
    }
};