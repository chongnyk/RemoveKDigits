class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> order;
        if(num.size() <= k) return "0";
        string result;

        for(int i = 0; i < num.size(); i++){
            while(!order.empty() && num[i] < order.top() && k > 0){
                order.pop();
                k--;
            }
            order.push(num[i]);
        }

        while(k > 0 && !order.empty()){
            order.pop();
            k--;
        }

        while(!order.empty()){
            result += order.top(); //must do result += order.top() then reverse(result).
            //if you do result = order.top() + result, will get memory limit exceeded error
            order.pop();
        }
        reverse(result.begin(), result.end());

        for(int i = 0; i < result.size(); i++){
            if(result[i] != '0'){
                result = result.substr(i);
                break;
            }
            else if(i == result.size() - 1) result = "";
        }

        return (result.size() == 0) ? "0" : result;
    }
};
