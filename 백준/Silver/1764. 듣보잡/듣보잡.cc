#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<string> noSeen, noHeard, offBrand;

    string name;
    for (int i = 0; i < N; i++){
        cin >> name;
        noSeen.push_back(name);
    }
    for (int i = 0; i < M; i++){
        cin >> name;
        noHeard.push_back(name);
    }
    sort(noSeen.begin(), noSeen.end());
    sort(noHeard.begin(), noHeard.end());

    set_intersection(noSeen.begin(), noSeen.end(), \
                    noHeard.begin(), noHeard.end(), \
                    std::back_inserter(offBrand));

    cout << offBrand.size() << "\n";
    for (auto& name : offBrand) cout << name << "\n";    

}