#include <iostream>
#include <vector>
#define MAX_ELEMENT 1000
using namespace std;

template<typename T>
class HeapNode {
private :
	T data;
public:
	HeapNode() {}
	HeapNode(T input) : data(input) {}

	T get_data() {
		return data;
	}
	void set_data(T input) {
		data = input;
	}
};
template<typename T>
bool default_compare(T t1, T t2) {
	return t1 < t2;
}

template<typename T>
class Heap {
private :
	HeapNode<T> node[MAX_ELEMENT];
	int heap_size = 0;
	bool(*compare) (T, T) = default_compare;
public:
	Heap() {}
	Heap(bool(*compFunc) (T, T)) : compare(compFunc) {}
	void insert(T input) {
		int i = ++heap_size;
		while (i != 1 && compare(node[i / 2].get_data(), input)) {
			node[i] = node[i / 2];
			i /= 2;
		}
		node[i].set_data(input);
	}
	T remove() {
		int parent = 1, child = 2;
		T item, temp;

		item = node[1].get_data();
		temp = node[heap_size--].get_data();
		while (child <= heap_size) {
			if (child < heap_size && compare(node[child].get_data(), node[child + 1].get_data())) child++;
			if (compare(node[child].get_data(), temp)) break;
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent].set_data(temp);
		return item;
	}
	int size() {
		return heap_size;
	}
	
	void printHeap() {
		//cout << sizeof(node) << endl;
		cout << "Heap : ";
		for (int i = 1; i <= heap_size; i++) {
			cout << ", " << node[i].get_data();
		}cout << endl;
	}
};

int main() {
	//HeapNode<int> h1(10), h2(100), h3(14), h4(0), h5(0), h6(0);
	Heap<int> heap;
	cout << sizeof(HeapNode<int>) << endl;

	heap.insert(10);
	heap.insert(100);
	heap.insert(5);

	cout << "remove : " << heap.remove() << endl;
	//cout << "remove : " << heap.remove() << endl;

	heap.printHeap();

	system("pause");
	return 0;
}
