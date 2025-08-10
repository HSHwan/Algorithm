#include <string>

#define X first
#define Y second

using namespace std;

const int MAX = 5;

int solution(string dirs) {
    int max_len = 4 * MAX + 1;
    bool visited[max_len][max_len][max_len][max_len];
    int answer = 0;
    
    pair<int, int> pos = {MAX, MAX};
    for (char dir : dirs) {
        pair<int, int> past = pos;
        switch (dir) {
            case 'L': {
                if (pos.X != 0) {
                    pos.X--;
                }
                break;
            }
            case 'R': {
                if (pos.X != 10) {
                    pos.X++;
                }
                break;
            }
            case 'U': {
                if (pos.Y != 10) {
                    pos.Y++; 
                }
                break;
            }
            case 'D': {
                if (pos.Y != 0) {
                    pos.Y--;
                }
                break;
            }
        }
        
        if (past != pos && !visited[past.X][past.Y][pos.X][pos.Y]) {
            visited[past.X][past.Y][pos.X][pos.Y] = true;
            visited[pos.X][pos.Y][past.X][past.Y] = true;
            answer++;
        }
    }
    
    return answer;
}