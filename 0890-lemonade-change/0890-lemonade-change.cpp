class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n = bills.size();
        
        int countFive = 0;
        int countTen = 0;
        int countTwentys = 0;

        for(auto it: bills){

            if(it == 5) countFive++;

            else if( it == 10 && countFive >= 1){
                countFive--;
                countTen++;
            }
            else if(it == 20){
                if(countTen >=1 && countFive >=1){
                    countTen--;
                    countFive--;
                }
                else if(countFive >=3){
                    countFive -= 3;
                }
                else return false;
            }
            else return false;
        }
        return true;
    }
};