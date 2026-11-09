#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> orders;

string parse_head(string str) {
    int head_len = 0;
    for (char ch : str) {
        if (ch >= '0' && ch <= '9') break;
        head_len++;
    }
    string head = str.substr(0, head_len);
    transform(head.begin(), head.end(), head.begin(), ::tolower);
    return head;
}

int parse_number(string str, int start) {
    int number = 0;
    for (int i = start; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9')   break;
        number = 10 * number + str[i] - '0';
    }
    return number;
}

bool comp(string a, string b) {
    string a_head = parse_head(a), b_head = parse_head(b);
    if (a_head == b_head) {
        int a_number = parse_number(a, a_head.size()), b_number = parse_number(b, b_head.size());
        if (a_number == b_number)   return orders[a] < orders[b];
        return a_number < b_number;
    }
    return a_head < b_head;
}

vector<string> solution(vector<string> files) {
    for (int i = 0; i < files.size(); i++) {
        orders[files[i]] = i;
    }
    sort(files.begin(), files.end(), comp);
    return files;
}