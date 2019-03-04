template<typename T>
class TreeNode {
private:

public:
	T data;
	TreeNode *left = NULL, *right = NULL;
	TreeNode(T input, TreeNode *llink, TreeNode *rlink) : data(input), left(llink), right(rlink) {}
	TreeNode(T input) : data(input) {}
	T get_data() { return data; }
	//cout << 연산자 인식
	friend ostream& operator<<(ostream& os, const TreeNode<T> *node) {
		os << "data : " << node->data;
		if (node->left != NULL) {
			os << ", left : " << node->left->data;
		}
		if (node->right != NULL) {
			os << ", right : " << node->right->data;
		}
		cout << endl;
		return os;
	}
};

//중복 허용 버전
template<typename T>
class Tree {
private:
	TreeNode<T> *root = NULL;
public:
	~Tree() {
		cout << "Deleting Tree Progressing..." << endl;
		while (root != NULL) {
			remove(root->data);
		}
	}
	TreeNode<T>* get_root() {
		return root;
	}
	T get_Max() {
		TreeNode<T> *current = root;
		while (current->right != NULL) {
			current = current->right;
		}
		return current->data;
	}
	T get_Min() {
		TreeNode<T> *current = root;
		while (current->left != NULL) {
			current = current->left;
		}
		return current->data;
	}
	TreeNode<T>* search(TreeNode<T> *current, T target) {
		if (current == NULL) return NULL;
		if (current->data == target) { return current; }
		else if (current->data > target) { return search(current->left, target); }
		else { return search(current->right, target); }
	}
	void insert(T input) {
		if (root == NULL) {
			root = new TreeNode<T>(input);
			//cout << "insert Root : " << input << endl;
			return;
		}

		TreeNode<T> *current = root, *parent = NULL;
		while (current != NULL) {
			parent = current;
			if (current->data >= input) { current = current->left; }
			else { current = current->right; }
		}
		if (parent->data >= input) { parent->left = new TreeNode<T>(input); }
		else { parent->right = new TreeNode<T>(input); }
		//cout << "insert : " << input << ", Parent : " << parent;
	}
	void remove(T target) {
		TreeNode<T> *target_node = root, *target_parent = NULL;
		//값 있는지 탐색
		while (target_node != NULL && target_node->data != target) {
			target_parent = target_node;
			target_node = target_node->data >= target ? target_node->left : target_node->right;
		}
		//값 없음
		if (target_node == NULL) {
			cout << target << " doesn't exist" << endl;
			return;
		}

		if (target_node->left == NULL && target_node->right == NULL) {
			if (target_parent == NULL) root = NULL;
			else if (target_parent->data >= target) {
				target_parent->left = NULL;
			}
			else {
				target_parent->right = NULL;
			}
		} //말단 노드인 경우
		else if (target_node->left != NULL && target_node->right != NULL) {
			TreeNode<T> *replace = target_node->left, *replace_parent = target_node;

			while (replace->right != NULL) {
				replace_parent = replace;
				replace = replace->right;
			}
			if (replace_parent->right == replace) replace_parent->right = replace->left;
			else replace_parent->left = replace->left;
			target_node->data = replace->data;
			target_node = replace;
		}//자식이 두개
		else {
			TreeNode<T> *target_child = target_node->right == NULL ? target_node->left : target_node->right;
			//root 노드 지울 때
			if (target_parent == NULL) {
				root = target_child;
				return;
			}

			if (target_parent->data >= target) {
				target_parent->left = target_child;
			}
			else {
				target_parent->right = target_child;
			}
		}//자식이 한개

		delete target_node;
	}
	void remove_Max() {
		TreeNode<T> *current = root;
		while (current->right != NULL) {
			current = current->right;
		}
		remove(current->data);
	}
	void remove_Min() {
		TreeNode<T> *current = root;
		while (current->left != NULL) {
			current = current->left;
		}
		remove(current->data);
	}
	

	void preorder_search(TreeNode<T> *current, vector<T> *all_element) {
		if (current == NULL) return;
		(*all_element).push_back(current->data);
		preorder_search(current->left, all_element);
		preorder_search(current->right, all_element);
	}
	void postorder_search(TreeNode<T> *current, vector<T> *all_element) {
		if (current == NULL) return;
		postorder_search(current->left, all_element);
		postorder_search(current->right, all_element);
		(*all_element).push_back(current->data);
	}
	void inorder_search(TreeNode<T> *current, vector<T> *all_element) {
		if (current == NULL) return;
		inorder_search(current->left, all_element);
		(*all_element).push_back(current->data);
		inorder_search(current->right, all_element);
	}
};
