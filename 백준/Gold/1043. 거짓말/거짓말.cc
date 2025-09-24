#include <iostream>
#include <vector>
#include <set>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n, m;
vector<vector<int>> parties;
vector<set<int>> network;
vector<bool> checked;

void dfs(int num) {
    for (int i : network[num]) {
        if (!checked[i]) {
            checked[i] = true;
            dfs(i);
        }
    }
}

int main() {
    FAST_IO
    cin >> n >> m;
    parties.assign(m, vector<int>());
    network.assign(n + 1, set<int>());
    checked.assign(n + 1, false);

    int known;
    cin >> known;
    vector<int> known_list(known);
    for (int i = 0; i < known; i++) cin >> known_list[i];
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int people_num;
            cin >> people_num;
            parties[i].push_back(people_num);
        }
    }

    for (vector<int> party : parties) {
        for (int i = 0; i < party.size(); i++) {
            for (int j = i + 1; j < party.size(); j++) {
                network[party[i]].insert(party[j]);
                network[party[j]].insert(party[i]);
            }
        }
    }

    for (int i : known_list) {
        checked[i] = true;
        dfs(i);
    }

    int lie_num = m;
    for (vector<int> party : parties) {
        for (int i : party) {
            if (checked[i]) {
                lie_num--;
                break;
            }
        }
    }
    
    cout << lie_num;
}