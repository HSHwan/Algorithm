#include <iostream>
#include <map>
#include <string>
using namespace std;

int N,M;
string poketmon, problem;
string poketmon_book_name[100001];
map<string, int> poketmon_book_num;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> poketmon;
        poketmon_book_name[i+1] = poketmon;
        poketmon_book_num[poketmon] = i+1;
    }
    for (int i = 0; i < M; i++){
        cin >> problem;
        if(problem[0] >= 'A' && problem[0] <= 'Z'){
            cout << poketmon_book_num[problem] << '\n';
        }
        else {
            cout << poketmon_book_name[stoi(problem)] << '\n';
        }
    }
}