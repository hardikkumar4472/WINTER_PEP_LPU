// https://atcoder.jp/contests/abc237/tasks/abc237_d
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    Node* head = new Node(0);
    Node* tail = head;
    Node* curr = head;
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(i + 1);
        if (s[i] == 'L') {
            newNode->right = curr;
            newNode->left = curr->left;
            if (curr->left){
                curr->left->right = newNode;
            }
            else{
                head = newNode;
            }
            curr->left = newNode;
        } else {
            newNode->left = curr;
            newNode->right = curr->right;
            if (curr->right){
                curr->right->left = newNode;
            }
            else{
                tail = newNode;
            }
            curr->right = newNode;
        }
        curr = newNode;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }

    return 0;
}
