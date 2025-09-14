#include<iostream>
#include<memory>

using namespace std;

template<typename T>
class Node
{
public:
	T data;
	std::unique_ptr<Node<T>> next;

	Node(T value):data(value), next(nullptr){ }
};

template<typename T>
class LinkedList
{
private:
	std::unique_ptr<Node<T>> head;

	//std::unique_ptr<Node<T>> tail;
	//This makes tail own another node, which breaks the logic.
	//Only head should own the entire list.
	//tail should be a raw pointer to the last node, not a smart pointer.
	Node<T>* tail;

	int count;

public:
	LinkedList():head(nullptr), tail(nullptr), count(0){ }
	~LinkedList(){ }

	void push_back(T value)
	{
		std::unique_ptr<Node<T>> newNode = make_unique<Node<T>>(value);

		if (head == nullptr)
		{
			/*head = tail = newNode;	
			* //you are trying to assign a std::unique_ptr<Node<T>> (newNode) to both head and tail
			* //The ownership of the node to move to head.
			* //tail is then pointing to a moved-from unique_ptr, which is now nullptr — so your tail becomes invalid.
			count++;
			return;*/

			head = std::move(newNode);
			tail = head.get();
			count++;
			return;
		}

		/*tail->next = newNode;
		tail = newNode;*/

		tail->next = std::move(newNode);
		tail = tail->next.get();
		count++;
		return;
	}

	void push_front(T value)
	{
		std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);

		if (head == nullptr)
		{
			head = std::move(newNode);
			tail = head.get();
			count++;
			return;
		}
		//newNode->next = head.get();	//Here, newNode->next is a unique_ptr<Node<T>>, but head.get() returns a raw pointer (Node<T>*).
										//You're trying to assign a raw pointer to a unique pointer — this is not allowed and will cause a compilation error.

		newNode->next = std::move(head);  // Transfer ownership of old head
		head = std::move(newNode);	// Make newNode the new head
		count++;
		return;

	}

	T pop_back()
	{
		if (head == nullptr)
			throw::std::runtime_error("List is empty");

		T valuePopped;
		Node<T>* current = head.get();
		if (current == tail)
		{
			valuePopped = head->data;
			head.reset();	//This line deletes the object owned by the unique_ptr and sets the pointer to nullptr.
			tail = nullptr;
			count--;
			return valuePopped;
		}

		while (current->next->next != nullptr)
		{
			current = current->next;
		}

		Node<T>* temp = current->next.get();
		valuePopped = temp->data;
		current->next.reset();
		count--;
		//tail = current.get();   //current is not a smart pointer. As it is a raw pointer, just assign it to tail
		tail = current;

		return valuePopped;
	}

	T pop_front()
	{
		if (head == nullptr)
			throw runtime_error("List is empty");

		T valuePopped;


		valuePopped = head->data;
		head = std::move(head->next);
		count--;
		return valuePopped;

		//Here, instead of calling .reset(), you move head->next into head.
		//1. head->next transfers ownership into head.
		//2. The old head unique_ptr (the one pointing to the node being popped) is overwritten.
		//3. As soon as that happens, the destructor of the old unique_ptr is called automatically, which deletes the old front node.

	}


	void Print()
	{
		Node<T>* temp = head.get();	//Safe traversal
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next.get();
		}
		cout << endl;
	}

	int size() const { return count; }

};

int main()
{
	LinkedList<int> list;
	list.push_back(2);
	//list.push_back(3);
	//list.push_back(5);
	//list.push_back(7);
	//list.push_back(9);
	//list.push_front(10);
	//list.push_front(12);
	//list.push_front(14);
	list.pop_back();


	list.Print();

	return 0;
}