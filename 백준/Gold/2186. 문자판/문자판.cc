#include <iostream>
#include <vector>
#include <queue>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100
#define MAX_LEN 80
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

struct Word {
    pii pos;
    int wordIdx;
};

int row, column, maxMoveCount;
char letterBoard[MAX + 1][MAX + 1];
int posCount[MAX][MAX][MAX_LEN];
string targetWord;
vector<Word> initWords;
queue<Word> wordQ;

void setInitWords() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (letterBoard[i][j] == targetWord[0])
                initWords.push_back({{i, j}, 0});
        }
    }
}

bool isOutOfRange(pii pos) {
    return pos.X < 0 || pos.X >= row || pos.Y < 0 || pos.Y >= column;
}

bool isNextTarget(pii pos, int idx) {
    if (isOutOfRange(pos) || idx >= targetWord.size())  return false;
    return letterBoard[pos.X][pos.Y] == targetWord[idx];
}

int findWordCaseCount() {
    int wordCount = 0;
    Word nowWord;
    for (Word word : initWords) {
        if (!posCount[word.pos.X][word.pos.Y][0])
            wordQ.push(word);
        posCount[word.pos.X][word.pos.Y][0]++;
    }
        
    vector<pii> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!wordQ.empty()) {
        nowWord = wordQ.front();
        wordQ.pop();
        pii nowPos = nowWord.pos;
        int nowWordIdx = nowWord.wordIdx;

        if (nowWordIdx == targetWord.size() - 1) {
            wordCount += posCount[nowPos.X][nowPos.Y][nowWordIdx];
            posCount[nowPos.X][nowPos.Y][nowWordIdx] = 0;
            continue;
        }

        for (pii dir : dirs) {
            for (int i = 1; i <= maxMoveCount; i++) {
                pii nextPos = {nowPos.X + i * dir.X, nowPos.Y + i * dir.Y};
                int nextWordIdx = nowWordIdx + 1;
                if (!isNextTarget(nextPos, nextWordIdx))  continue;
                if (!posCount[nextPos.X][nextPos.Y][nextWordIdx])
                    wordQ.push({nextPos, nextWordIdx});
                posCount[nextPos.X][nextPos.Y][nextWordIdx] += posCount[nowPos.X][nowPos.Y][nowWordIdx];
            }
        }
        posCount[nowPos.X][nowPos.Y][nowWordIdx] = 0;
    }

    return wordCount;
}

int main() {
    FAST_IO

    cin >> row >> column >> maxMoveCount;
    for (int i = 0; i < row; i++)
        cin >> letterBoard[i];
    cin >> targetWord;   

    setInitWords();
    int wordCount = findWordCaseCount();
    cout << wordCount;
}