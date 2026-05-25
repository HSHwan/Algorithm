#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string n_str = to_string(n);
    for (char ch : n_str)
        answer += ch - '0';

    return answer;
}