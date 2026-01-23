#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N, num;
	stack<int> perm;
	deque<int> deq, nge;

	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> num;
		perm.push(num);
	}

	while(!perm.empty()){
		while(!deq.empty() && perm.top() >= deq.front()){
			deq.pop_front();
		}
		if(deq.empty())	nge.push_front(-1);
		else	nge.push_front(deq.front());
		deq.push_front(perm.top());
		perm.pop();
	}

	for (auto& nge_n : nge){
		cout << nge_n << ' ';
	}
}