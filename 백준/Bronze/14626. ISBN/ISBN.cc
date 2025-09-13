#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int find_digit(string isbn) {
	int mul_num = 1, total = 0;
	for (int i = 0; i < isbn.size(); i++) {
		if (i % 2) {
			if (isbn[i] == '*') {
				mul_num = 3;
				continue;
			}
			total += (isbn[i] - '0') * 3;
		}
		else if (isbn[i] != '*') {
			total += isbn[i] - '0';
		}
	}

	for (int i = 0; i < 10; i++) {
		if ((total + mul_num * i) % 10 == 0)	return i;
	}
	return -1;
}

int main() {
	FAST_IO

	string isbn;
	cin >> isbn;
	cout << find_digit(isbn);
}