//Binary tree

#include<iostream>
#include<memory>

using namespace std;

template<typename T>
class Node
{
public:
    T data;
    std::unique_ptr<Node<T>> left;
    std::unique_ptr<Node<T>> right;

    Node(T value) :data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree
{
private:
    std::unique_ptr<Node<T>> root;

    void InsertHelper(std::unique_ptr<Node<T>>& node, T value)
    {
        if (node == nullptr)
        {
            node = make_unique<Node<T>>(value);
            return;
        }

        if (value < node->data)
        {
            InsertHelper(node->left, value);
        }
        else if (value > node->data)
        {
            InsertHelper(node->right, value);
        }

    }

    void PrintHelper(Node<T>* root)
    {
        if (root == nullptr)
            return;

        PrintHelper(root->left.get());
        cout << root->data << " ";
        PrintHelper(root->right.get());
    }

public:
    BinarySearchTree() :root(nullptr) {}
    ~BinarySearchTree() {}

    void Insert(T value) {

        InsertHelper(root, value);

    }

    void Print()
    {
        PrintHelper(root.get());
    }

};

int main()
{
    BinarySearchTree<int> bst;
    bst.Insert(8);
    bst.Insert(5);
    bst.Insert(3);
    bst.Insert(4);
    bst.Insert(7);
    bst.Insert(9);
    bst.Insert(3);
    bst.Insert(2);

    bst.Print();
    return 0;
}