#include <iostream>

using namespace std;

int main() {

}

int findnegatives(listNode * l) {
    if (l == NULL)
        return 0;
    int count = findnegatives(l->next);
    if (l->data < 0)
        count++;
    return count;
}

int findLargest(Node * root) {
    // Understand the base case
    // The largest number is only valid when 
    // you have a number
    // if you consider the empty tree as a base
    // case, what would you return?

    // Just for safety
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)
        return root->data;

    // KING OF THE HILL!
    int leftmax = findLargest(root->left);
    int rightmax = findLargest(root->right);
    int maxNum = root->data;

    if (left-)
}