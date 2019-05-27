//중복 가능, 노드 데이터 private 사용
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class TreeNode {			//노드 클래스
private:
	T data;
	TreeNode *left = NULL, *right = NULL;
public:
	TreeNode(T input, TreeNode *llink, TreeNode *rlink) : data(input), left(llink), right(rlink) {}
	TreeNode(T input) : data(input) {}
	T get_data() { return data; }
	TreeNode<T>* get_left() {
		return left;
	}
	TreeNode<T>* get_right() {
		return right;
	}
	void set_data(T input) {
		data = input;
	}
	void set_left(TreeNode<T>* link) {
		left = link;
	}
	void set_right(TreeNode<T>* link) {
		right = link;
	}
};

template<typename T>
bool default_comp(T t1, T t2) { return t1 < t2; }	//기본 비교 함수

//중복 허용 + call back 함수
template<typename T>
class Tree {						//트리 클래스
private:
	TreeNode<T> *root = NULL;	
	bool(*compare)(T, T) = default_comp;		//원소 데이터 비교 함수 설정
public:
	Tree() {}
	Tree(bool(*compFunc)(T, T)) : compare(compFunc) {}
	~Tree() {					//소멸자 호출 : 동적으로 할당한 메모리 제거
		cout << "Deleting Tree Progressing..." << endl;
		while (root != NULL) {
			remove(root->get_data());
		}
	}
	TreeNode<T>* get_root() {	//루트 원소 반환
		return root;
	}
	T get_Max() {			//최댓값 원소 반환
		TreeNode<T> *current = root;
		while (current->get_right() != NULL) {
			current = current->get_right();
		}
		return current->get_data();
	}
	T get_Min() {			//최솟값 원소 반환
		TreeNode<T> *current = root;
		while (current->get_left() != NULL) {
			current = current->get_left();
		}
		return current->get_data();
	}
	TreeNode<T>* search(TreeNode<T> *current, T target) {	//특정값을 탐색. 없을 시 nullptr 반환
		if (current == NULL) return NULL;	
		if (current->get_data() == target) { return current; }
		else if (compare(current->get_data(), target)) { return search(current->get_right(), target); } 
		else { return search(current->get_left(), target); }
	}
	void insert(T input) {			//노드 삽입
		if (root == NULL) {		//루트가 비어있을 경우 루트에 삽입
			root = new TreeNode<T>(input);
//			cout << "insert Root : " << input << endl;
			return;
		}

		TreeNode<T> *current = root, *parent = NULL;
		while (current != NULL) {	//반복적으로 값을 비교해가며 자신의 자리를 찾는다.
			parent = current;
			if (compare(current->get_data(), input)) { current = current->get_right(); } 
			else { current = current->get_left(); }
		}
		if (compare(parent->get_data(), input)) { parent->set_right(new TreeNode<T>(input)); }
		else { parent->set_left(new TreeNode<T>(input)); } 
//		cout << "insert : " << input << ", Parent : " << parent;
	}
	void remove(T target) {			//노드 삭제 함수
		TreeNode<T> *target_node = root, *target_parent = NULL;
		//값 있는지 탐색
		while (target_node != NULL && target_node->get_data() != target) {
			target_parent = target_node;
			target_node = target_node->get_data() >= target ? target_node->get_left() : target_node->get_right();
		}
		
		if (target_node == NULL) {	//해당하는 값 없는 경우
//			cout << target << " doesn't exist" << endl;
			return;
		}

		if (target_node->get_left() == NULL && target_node->get_right() == NULL) {
			if (target_parent == NULL) root = NULL;
			else if (compare(target_parent->get_data(), target)) {
				target_parent->set_right(NULL);
			}
			else {
				target_parent->set_left(NULL);
			}
		} //말단 노드인 경우
		else if (target_node->get_left() != NULL && target_node->get_right() != NULL) {
			TreeNode<T> *replace = target_node->get_left(), *replace_parent = target_node;

			while (replace->get_right() != NULL) {
				replace_parent = replace;
				replace = replace->get_right();
			}
			if (replace_parent->get_right() == replace) replace_parent->set_right(replace->get_left());
			else replace_parent->set_left(replace->get_left());
			target_node->set_data(replace->get_data());
			target_node = replace;
		}//자식이 두개인 경우 까다로움 -> 반례 주의할 것. 이 함수의 경우, 왼쪽 자식의 가장 오른쪽에 위치한 자식노드를 올려보냄.
		else {
			TreeNode<T> *target_child = target_node->get_right() == NULL ? target_node->get_left() : target_node->get_right();
			//root 노드 지울 때
			if (target_parent == NULL) {
				root = target_child;
				return;
			}

			if (compare(target_parent->get_data(), target)) {
				
				target_parent->set_right(target_child);
			}
			else {
				target_parent->set_left(target_child);
			}
		}//자식이 한개인 경우

		delete target_node;
	}
	void remove_Max() {		//최댓값 원소 지우기
		remove(get_Max());
	}
	void remove_Min() {		//최솟값 원소 지우기
		remove(get_Min());
	}

	//------------------순회 시리즈(전위, 중위, 후위)----------------------//
	void preorder_search(TreeNode<T> *current, vector<T> *all_element) {
		if (current == NULL) return;
		(*all_element).push_back(current->get_data());
		preorder_search(current->get_left(), all_element);
		preorder_search(current->get_right(), all_element);
	}
	void postorder_search(TreeNode<T> *current, vector<T> *all_element) {
		if (current == NULL) return;
		postorder_search(current->get_left(), all_element);
		postorder_search(current->get_right(), all_element);
		(*all_element).push_back(current->get_data());
	}
	void inorder_search(TreeNode<T> *current, vector<T> *all_element) {
		if (current == NULL) return;
		inorder_search(current->get_left(), all_element);
		(*all_element).push_back(current->get_data());
		inorder_search(current->get_right(), all_element);
	}
};


bool comp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first == p2.first ? p1.second >= p2.second : p1.first < p2.first;
}

int main() {
	Tree<pair<int, int>> tree(comp);
	tree.insert(make_pair(1, 3));
	tree.insert(make_pair(5, 4));
	tree.insert(make_pair(93, 5));
	tree.insert(make_pair(93, 5));
	tree.insert(make_pair(41, 6));
	tree.insert(make_pair(25, 7));
	tree.insert(make_pair(22, 13));
	tree.insert(make_pair(22, 1));
	tree.insert(make_pair(22, 9));
	tree.insert(make_pair(47, 1));
	tree.insert(make_pair(35, -4));
	tree.insert(make_pair(35, -4));
	tree.insert(make_pair(11, 21));
	tree.insert(make_pair(6, 48));
	tree.insert(make_pair(13, 25));
	tree.insert(make_pair(9, 18));

	tree.remove(make_pair(9, 18));

	vector<pair<int, int>> element;
	tree.preorder_search(tree.get_root(), &element);
	cout << "Preorder >> ";  for (auto iter : element) cout << iter.first << " " << iter.second << " :: "; cout << endl;
	element.clear();
	tree.inorder_search(tree.get_root(), &element);
	cout << "inorder >> ";  for (auto iter : element) cout << iter.first << " " << iter.second << " :: "; cout << endl;

	TreeNode<pair<int, int>>* found = tree.search(tree.get_root(), make_pair(22, 1));
	if (found != NULL) {
		cout << "Found node." << endl;
		//cout << found;
	}
	else {
		cout << "Not found node." << endl;
	}
	system("pause");
	return 0;
}

