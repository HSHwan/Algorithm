#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

struct Node {
    int num;
    Node* left = NULL;
    Node* right = NULL;
    Node (int num) {
        this->num = num;
    }
};

void insert(Node*& node, int n) {
    if (node == NULL) {
        node = new Node(n);
    }
    else if (node->num > n) {
        insert(node->left, n);
    }
    else    insert(node->right, n);
}

void search_post(Node* node) {
    if (node == NULL)   return;
    search_post(node->left);
    search_post(node->right);
    cout << node->num << '\n';
}

int main() {
    FAST_IO
    int n;
    Node* root = NULL;
    while (cin >> n) {
        insert(root, n);
    }
    search_post(root);
}