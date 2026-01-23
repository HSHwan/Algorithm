#include <iostream>
#include <string>

using namespace std;

int main(){
    string parse_str;
    cin >> parse_str;

    int leftCnt = 0,  rightCnt = 0, parseSum = 0;
    for (int i = 0; i < parse_str.length(); i++){
        if (parse_str[i] == '('){
            leftCnt++;
            parseSum++;
        } else if (parse_str[i] == ')'){
            rightCnt++;
            parseSum--;
        }
        if (parseSum == 0){
            leftCnt = 0;
        } else if (parseSum < 0){
            cout << rightCnt;
            break;
        }
    }
    if (parseSum > 0)   cout << leftCnt;
}