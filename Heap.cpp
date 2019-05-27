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
bool default_compare(T t1, T t2) { return t1 < t2; } //기본 비교 함수

template<typename T>
class Heap {
private :
	HeapNode<T> node[MAX_ELEMENT];			//힙 구조는 일차원 배열로 구현 가능
	int heap_size = 0;
	bool(*compare) (T, T) = default_compare;	//노드의 데이터 비교 함수 지정
public:
	Heap() {}
	Heap(bool(*compFunc) (T, T)) : compare(compFunc) {}
	void insert(T input) {				//노드 삽입 함수. 특정 노드의 부모 위치는 자기 위치 / 2 임을 활용
		int i = ++heap_size;			//힙에서 노드를 삽입할 때는 제일 마지막 자리에 삽입하고 부모와 자리를 바꾸는 구조
		while (i != 1 && compare(node[i / 2].get_data(), input)) {
			node[i] = node[i / 2];
			i /= 2;
		}
		node[i].set_data(input);
	}
	T remove() {					//노드 삭제 함수. 힙에서 노드를 삭제할 때는 첫번째 위치의 노드를 지우고
		int parent = 1, child = 2;		//마지막 노드를 첫번째 노드 위치로 이동 -> 자식 노드와 자리 바꾸기
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
	int size() {			//힙의 사이즈 반환
		return heap_size;
	}
	
	void printHeap() {		//힙 출력
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
