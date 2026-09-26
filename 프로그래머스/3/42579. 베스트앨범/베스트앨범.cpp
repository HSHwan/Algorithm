#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b){
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> album_records;
    map<string, int> plays_sum;

    for (int i = 0; i < genres.size(); i++){
        album_records[genres[i]].push_back(make_pair(i, plays[i]));
        if (plays_sum.count(genres[i]) > 0){
            plays_sum[genres[i]] += plays[i];
        }
        else {
            plays_sum[genres[i]] = plays[i];
        }
    }
    vector<pair<string, int>> all_genre_plays_sum(plays_sum.begin(), plays_sum.end());
    sort(all_genre_plays_sum.begin(), all_genre_plays_sum.end(), [](pair<string, int> a, pair<string, int> b){return a.second > b.second;});
    
    for (const pair<string, int>& genre_plays : all_genre_plays_sum){
        sort(album_records[genre_plays.first].begin(), album_records[genre_plays.first].end(), comp);
        answer.push_back(album_records[genre_plays.first][0].first);
        if (album_records[genre_plays.first].size() >= 2)
            answer.push_back(album_records[genre_plays.first][1].first);
    }
    
    return answer;
}