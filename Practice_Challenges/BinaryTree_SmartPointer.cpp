#include<iostream>
#include<queue>
#include<memory>

using namespace std;

template <typename T>
class Node
{
public:
	T data;
	std::unique_ptr<Node<T>> right;
	std::unique_ptr<Node<T>> left;

	Node(T value) : data(value), right(nullptr), left(nullptr) {}
};

template<typename T>
class BinaryTree
{
private:
	std::unique_ptr<Node<T>> root;

	void InsertHelper(std::unique_ptr<Node<T>>& node, T value)
	{
		std::queue<Node<T>*> q;
		q.push(node.get());

		while (!q.empty())
		{
			Node<T>* temp = q.front();
			q.pop();
			if (temp->left == nullptr)
			{
				temp->left = make_unique<Node<T>>(value);
				break;
			}
			else
			{
				q.push(temp->left.get());
			}

			if (temp->right == nullptr)
			{
				temp->right = make_unique<Node<T>>(value);
				break;
			}
			else
			{
				q.push(temp->right.get());
			}
		}
	
	}

	void PrintHelper(Node<T>* node)
	{
		if (node == nullptr)
			return;

		PrintHelper(node->left.get());
		cout << node->data<<" ";
		PrintHelper(node->right.get());
	}

public:
	BinaryTree() : root(nullptr) {}
	~BinaryTree() {}

	void Insert(T value)
	{
		if (root == nullptr)
		{
			root = make_unique<Node<T>>(value);
		}
		else
		{
			InsertHelper(root, value);
		}
		
	}

	void Print()
	{
		if (root != nullptr)
		{
			PrintHelper(root.get());
		}
		else
		{
			cout << "Tree is Empty" << endl;
		}
	}

};

int main()
{
	BinaryTree<int> btree;

	btree.Insert(5);
	btree.Insert(3);
	btree.Insert(4);
	btree.Insert(7);
	btree.Insert(9);
	btree.Insert(8);
	btree.Insert(6);
	btree.Insert(2);

	btree.Print();



	return 0;
}