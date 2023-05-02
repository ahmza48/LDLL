#include <iostream>
using namespace std;

template <class T>
class List;

template <class T>
class Node{
private:
	friend List<T>;
	T info;
	Node<T>* next;
	Node<T>* prev;
public:
	Node(T val) {
		info = val;
		next = NULL;
		prev = NULL;
	}
};

template <class T>
class List {
private:
	Node<T>* head;
public:
	List() {
		head = NULL;
	}
	//yet to be completed...
	//Destructor
	//~List() {

	//}

	//Copy Constructor
	//List(const List& lhs) {

	//}

	void insertAtHead(T val) {
		if (!head) {
			Node<T>* NewNode = new Node<T>(val);
			head = NewNode;
			return;
		}
		Node<T>* NewNode = new Node<T>(val);
		NewNode->next = head;
		head->prev = NewNode;
		/*NewNode->prev = NULL;*/
		head = NewNode;
	}

	void insertAtTail(T val) {
		if (!head) {
			Node<T>* NewNode = new Node<T>(val);
			head = NewNode;
			return;
		}
		if (!head->next) {
			Node<T>* NewNode = new Node<T>(val);
			NewNode->prev = head;
			head->next = NewNode;
			return;
		}

		Node<T>*temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		Node<T>* NewNode = new Node<T>(val);
		temp->next = NewNode;
		NewNode->prev = temp;
		NewNode->next = NULL;
		return;
	}

	void removetAtHead() {
		if (!head) {
			return;
		}
		if (!head->next) {
			delete head;
			head = NULL;
			return;
		}

		Node<T>* temp = head;
		head = head->next;
		delete temp;
		head->prev = NULL;
		return;
	
	}

	void removetAtTail() {
		if (!head) {
			return;
		}
		if (!head->next) {
			Node<T>*temp = head;
			delete temp;
			head = NULL;
			return;
		}

		Node<T>*temp = head;
		while (temp->next->next)
		{
			temp = temp->next;
		}
		/*Node<T>* NewNode = new Node<T>(val)*/;
		delete temp->next;
		temp->next = NULL;
		return;

	}

	bool deleteAfter(T key) {
		if (!head) {
			return false;
		}
		Node<T>*temp = head;
		while (temp->info != key) {
			temp = temp->next;
		}
		if (!temp || !temp->next) {
			return false;
		}
		if (temp->next->next) {
			temp = temp->next;
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			return true;
		}
		if (!temp->next->next) {
			delete temp->next;
			temp->next = NULL;
			return true;
		}
		return false;

	}

	bool deleteBefore(T key) {
		if (!head || !head->next) {
			return false;
		}
		if (head->info == key) {
			return false;
		}
		if (head->next->info == key)
		{
			Node<T>*temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		if (head->next->info != key) {
			Node<T>*temp = head;
			while (temp->info != key)
			{
				temp = temp->next;
			}
			Node<T>*toDelete = temp->prev;
			temp->prev = temp->prev->prev;
			toDelete->prev->next = temp;
			/*temp->prev->next = temp;*/
			delete toDelete;
			return true;
		}
		return false;
	}
	void printList() {
		if (!head) {
			cout << "List is Empty!" << endl;
			return;
		}
		else {
			cout << "Elements in List Are:" << endl;
			Node<T>* temp = head;
			while (temp) {
				cout << temp->info << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	bool insertAfter(T key, T val) {
		if (!head)
		{
			return false;
		}

		if (!head->next && head->info == key) {
			Node<T>* NewNode = new Node<T>(val);
			head->next = NewNode;
			NewNode->prev = head;
			NewNode->next = NULL;
			return true;
		}


		Node<T>* temp = head;
		while (temp)
		{
			if (temp->info == key && temp->next)
			{
				Node<T>* NewNode = new Node<T>(val);
				temp->next->prev = NewNode;
				NewNode->next = temp->next;
				temp->next = NewNode;
				NewNode->prev = temp;
				return true;
			}
			if (temp->info == key && !temp->next)
			{
				Node<T>* NewNode = new Node<T>(val);
				temp->next = NewNode;
				NewNode->prev = head;
				NewNode->next = NULL;
				return true;
			}
			temp = temp->next;
		}
		return false;

	}

	//----------------------------------------------

	bool insertBefore(T key, T val) {
		if (!head)
		{
			return false;
		}

		if (!head->next && head->info == key) {
			Node<T>* NewNode = new Node<T>(val);
			head->next = NewNode;
			NewNode->prev = head;
			NewNode->next = NULL;
			return true;
		}


		Node<T>* temp = head;
		while (temp)
		{
			if (temp->info == key && temp->next)
			{
				Node<T>* NewNode = new Node<T>(val);
				temp->next->prev = NewNode;
				NewNode->next = temp->next;
				temp->next = NewNode;
				NewNode->prev = temp;
				return true;
			}
			if (temp->info == key && !temp->next)
			{
				Node<T>* NewNode = new Node<T>(val);
				temp->next = NewNode;
				NewNode->prev = head;
				NewNode->next = NULL;
				return true;
			}
			temp = temp->next;
		}
		return false;

	}

};

int main() {
	List<int> l1;
	l1.insertAtHead(1);
	l1.insertAtHead(2);
	l1.insertAtHead(3);
	l1.insertAtHead(4);
	
	l1.insertBefore(1, 8);
	l1.printList();

	/*l1.insertAtTail(1);*/
	//l1.insertAtTail(2);
	//l1.insertAtTail(3);
	//l1.insertAtTail(4);

	cout << "Before Deleting:" << endl;
	l1.printList();

	/*cout << "After Deleting:" << endl;
	l1.deleteBefore(1);
	l1.printList();*/

	//cout << "After Deleting:" << endl;
	//l1.deleteAfter(4);
	//l1.printList();

	//l1.removetAtHead();
	//l1.printList();

	cout << "Insert After Called:" << endl;
	l1.insertAfter(1,8);
	l1.printList();


	cout << "Insert BEFORE Called:" << endl;
	l1.insertBefore(1, 8);
	l1.printList();

	return 0;
}