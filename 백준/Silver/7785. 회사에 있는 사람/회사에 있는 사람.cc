#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    
    map<string, bool> logs;
    string name, log;
    for (int i = 0; i < n; i++){
        cin >> name >> log;
        if (log == "enter") logs[name] = true;
        else    logs[name] = false;
    }

    vector<string> logs_vec;
    for(auto& log : logs){
        if (log.second) logs_vec.push_back(log.first);
    }
    
    sort(logs_vec.rbegin(), logs_vec.rend());
    
    for(auto& log : logs_vec)   cout << log << '\n';
}