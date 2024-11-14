#include <iostream>

using namespace std;

// 노드 구조체 정의
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 이진 검색 트리 클래스 정의
class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    // 노드 삽입 함수
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Pre-order 순회 함수
    void preOrderTraversal() {
        preOrder(root);
        cout << endl;
    }

    // In-order 순회 함수
    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    // Post-order 순회 함수
    void postOrderTraversal() {
        postOrder(root);
        cout << endl;
    }

private:
    // 재귀를 이용한 노드 삽입 함수
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    // Pre-order 순회 구현
    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // In-order 순회 구현
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Post-order 순회 구현
    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BinarySearchTree bst;

    // 트리에 정수 삽입
    int values[] = {6, 2, 4, 9, 8, 3, 10};
    for (int value : values) {
        bst.insert(value);
    }

    // 순회 결과 출력
    cout << "Pre-order traversal: ";
    bst.preOrderTraversal();

    cout << "In-order traversal: ";
    bst.inOrderTraversal();

    cout << "Post-order traversal: ";
    bst.postOrderTraversal();

    return 0;
}


