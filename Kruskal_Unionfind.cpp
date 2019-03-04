#include <iostream>
#include <vector>
#include <tuple>
#define MAX_ELEMENT 1000
using namespace std;
//union - find 알고리즘 *******************************
int parent[MAX_ELEMENT];
int num[MAX_ELEMENT];

void set_init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
		num[i] = 1;
	}
}
int set_find(int vertex) {
	int p, s, i = -1;
	for (i = vertex; (p = parent[i]) >= 0; i = p) {
		;
	}
	s = i;
	for (i = vertex; (p = parent[i]) >= 0; i = p) {
		parent[i] = s;
	}
	return s;
}
void set_union(int s1, int s2) {
	if (num[s1] < num[s2]) {
		parent[s1] = s2;
		num[s2] += num[s1];
	}
	else {
		parent[s2] = s1;
		num[s1] += num[s2];
	}
}

//heap *******************************
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

//기본 최댓값 비교
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

//사용자 지정 비교 함수
bool comp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
	return get<2>(t1) > get<2>(t2);
}

//크루스컬 알고리즘
void kruskal(int n) {
	int edge_accepted = 0;
	Heap<tuple<int, int, int>> graph(comp);
	int uset, vset;

	graph.insert(make_tuple(0, 1, 29));
	graph.insert(make_tuple(1, 2, 16));
	graph.insert(make_tuple(2, 3, 12));
	graph.insert(make_tuple(3, 4, 22));
	graph.insert(make_tuple(4, 5, 27));
	graph.insert(make_tuple(5, 0, 10));
	graph.insert(make_tuple(6, 1, 15));
	graph.insert(make_tuple(6, 3, 18));
	graph.insert(make_tuple(6, 4, 25));

	// union - find 알고리즘 -> 순환하는 간선이 있는지 확인
	set_init(n);
	while (edge_accepted < n - 1) {
		tuple<int, int, int> t = graph.remove();
		uset = set_find(get<0>(t));
		vset = set_find(get<1>(t));
		if (uset != vset) {
			cout << "(" << get<0>(t) << ", " << get<1>(t) << "), " << get<2>(t) << endl;
			edge_accepted++;
			set_union(uset, vset);
		}
	}
}

int main() {
	kruskal(7); // 정점의 개수를 인자로 입력

	system("pause");
	return 0;
}
