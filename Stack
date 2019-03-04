#include <iostream>
using namespace std;

//Node---------------
template<typename T>
class Node {
public:
	T data;
	Node<T> *prevNode;

	Node(T data);
	~Node();
};

template<typename T>
Node<T>::Node(T data) {
	this->data = data;
}
template<typename T>
Node<T>::~Node() {
	cout << "deleting node (" << this->data << ")" << endl;
}

//Stack --------------------
template<typename T>
class stack {
public:
	Node<T> *topNode;
	int length = 0;
	stack() {
		topNode = NULL;
	}
	~stack() {
		Node<T> *top = topNode;
		while (top != NULL) {
			Node<T> *old = top;
			top = old->prevNode;
			delete old;
		}
	}

	void push(T data) {
		if (topNode == NULL) {
			topNode = new Node<T>(data);
		}
		else {
			Node<T> *old = topNode;
			topNode = new Node<T>(data);
			topNode->prevNode = old;
		}
		length++;
		cout << "push : " << data << " , length : " << length << endl;
	}
	T pop() {
		
		if (topNode == NULL) {
			cout << "no Data in stack" << endl;
			return NULL;
		}
		else {
			T topData = topNode->data;
			Node<T> *old = topNode;
			topNode = topNode->prevNode;
			delete old; // 나중에 delete 순서 바꿔 보기
			length--;

			cout << "pop : " << topData << endl;
			return topData;
		}
	}

	int getlength() { 
		return length; 
	}
	T top() {
		if (topNode != NULL) {
			return topNode->data;
		}
		else {
			return NULL;
		}
		
	}
};


//main----------------------
int main() {
	//cout << "asdf" << endl;
	stack<double> st;
	cout << "current length : " << st.getlength() << ", top data : " << st.top() << endl;

	st.pop();

	st.push(1.2);
	st.push(3.2);
	st.push(5.2);

	cout << "current length : " << st.getlength() << ", top data : " << st.top() << endl;

	st.pop();
	st.pop();
	st.push(4.3);
	st.pop();

	cout << "current length : " << st.getlength() << ", top data : " << st.top() << endl;

	st.pop();

	cout << "current length : " << st.getlength() << ", top data : " << st.top() << endl;

	st.push(4.5);
	st.push(3.1);
	cout << "current length : " << st.getlength() << ", top data : " << st.top() << endl;

	return 0;
}
