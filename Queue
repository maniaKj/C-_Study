#include <iostream>
#include <string>
using namespace std;

//Node---------------
template<typename T>
class Node {
public:
	T data;
	Node<T> *llink = NULL;
	Node<T> *rlink = NULL;

	Node(T input):data(input) {}
	~Node() {
		cout << "deleting node (" << this->data << ")" << endl;
	}
};

//Queue --------------------
template<typename T>
class queue {
public:
	Node<T> *front_node = NULL, *rear_node = NULL;
	int length = 0;

	~queue() {
		Node<T> *rear = rear_node;
		while (rear != NULL) {
			Node<T> *old = rear;
			rear = old->llink;
			delete old;
		}
	}
	void enqueue_back(T input) {
		if (front_node == NULL && rear_node == NULL) {
			front_node = new Node<T>(input);
			rear_node = front_node;
		}
		else {
			Node<T> *old = rear_node;
			rear_node = new Node<T>(input);
			old->rlink = rear_node;
			rear_node->llink = old;
		}
		length++;
	}
	void enqueue_front(T input) {
		if (front_node == NULL && rear_node == NULL) {
			front_node = new Node<T>(input);
			rear_node = front_node;
		}
		else {
			Node<T> *old = front_node;
			front_node = new Node<T>(input);
			old->llink = front_node;
			front_node->rlink = old;
		}
		length++;
	}
	T dequeue_back() {
		if (length > 1) {
			T rear_data = rear_node->data;
			Node<T> *old = rear_node;
			rear_node = rear_node->llink;
			rear_node->rlink = NULL;
			delete old;
			length--;
			return rear_data;
		}
		else if (length == 1) {
			T rear_data = rear_node->data;
			delete rear_node;
			rear_node = NULL;
			front_node = NULL;
			length--;
			return rear_data;
		}
		else {
			cout << "No data in queue" << endl;
			return NULL;
		}
	}
	T dequeue_front() {
		if (length > 1) {
			T front_data = front_node->data;
			Node<T> *old = front_node;
			front_node = front_node->rlink;
			front_node->llink = NULL;
			delete old;
			length--;
			return front_data;
		}
		else if (length == 1) {
			T front_data = front_node->data;
			delete front_node;
			rear_node = NULL;
			front_node = NULL;
			length--;
			return front_data;
		}
		else {
			cout << "No data in queue" << endl;
			return NULL;
		}
	}
	int get_length() {
		return length;
	}
	T front() {
		if (front_node != NULL) return front_node->data;
		else return NULL;
	}
	T rear() {
		if (rear_node != NULL) return rear_node->data;
		else return NULL;
	}

};

//main----------------------
int main() {
	queue<char> qu;
	cout << "queue Initialized : " << qu.front() << ", " << qu.rear() << ", pop back : " << qu.dequeue_back() << ", pop front : " << qu.dequeue_front() << ", length : " << qu.get_length() << endl;

	qu.enqueue_back('A');
	qu.enqueue_back('B');
	qu.enqueue_back('C');
	qu.enqueue_front('Z');

	cout << "queue_length : " << qu.get_length() << ", front : " << qu.front() << ", rear : " << qu.rear()<< endl;

	qu.dequeue_front();

	cout << "queue_length : " << qu.get_length() << ", front : " << qu.front() << ", rear : " << qu.rear() << endl;

	qu.dequeue_back();

	cout << "queue_length : " << qu.get_length() << ", front : " << qu.front() << ", rear : " << qu.rear() << endl;

	qu.dequeue_back();
	qu.dequeue_back();
	qu.dequeue_back();

	cout << "queue_length : " << qu.get_length() << ", front : " << qu.front() << ", rear : " << qu.rear() << endl;

	qu.enqueue_back('A');
	qu.enqueue_front('B');
	qu.enqueue_back('C');
	qu.enqueue_front('Z');

	cout << "queue_length : " << qu.get_length() << ", front : " << qu.front() << ", rear : " << qu.rear() << endl;

	return 0;
}
