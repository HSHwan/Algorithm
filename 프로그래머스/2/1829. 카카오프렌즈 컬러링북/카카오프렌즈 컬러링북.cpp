#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> pictureColored;

bool isSameColor(const vector<vector<int>>& picture, const vector<int>& dot, const int& color){
    if (dot[0] >= picture.size() || dot[1] >= picture[0].size() || dot[0] < 0 || dot[1] < 0)
        return false;
    return (!pictureColored[dot[0]][dot[1]] && picture[dot[0]][dot[1]] == color);
}

int BFSColorPicture(const vector<vector<int>>& picture, const vector<int>& dot, const int& nowColor){
    int areaSize = 1;
    vector<int> nowDot = dot;
    queue<vector<int>> colorDots;
    colorDots.push(nowDot);
    pictureColored[nowDot[0]][nowDot[1]] = true;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    while (!colorDots.empty()){
        nowDot = colorDots.front();
        colorDots.pop();
        for (int i = 0; i < 4; i ++){
            vector<int> nextDot = {nowDot[0] + dir[i][0], nowDot[1] + dir[i][1]};
            if (isSameColor(picture, nextDot, nowColor)){
                colorDots.push(nextDot);
                areaSize++;
                pictureColored[nextDot[0]][nextDot[1]] = true;
            }
        }
    }
    return areaSize;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<bool>>(m, vector<bool>(n, false)).swap(pictureColored);
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (!pictureColored[i][j] && picture[i][j]){
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, BFSColorPicture(picture, {i, j}, picture[i][j]));
            }            
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}