
// bool isAVL(LinkNode* node) {
// 	int height = -1, left_height = -1, right_height = -1;
// 	if (!node) {
// 		height = 0;
// 		return true;
// 	}
// 	bool is_left_avl = isAVL(node->left_child);
// 	bool is_right_avl = isAVL(node->right_child);
// 	if (is_left_avl && is_right_avl && abs(left_height - right_height) <= 1) {
// 		height = max(left_height, right_height) + 1;
// 		return true;
// 	}
// 	else {
// 		height = max(left_height, right_height) + 1;
// 		return false;
// 	}
// }

#include <iostream>

using namespace std;

class TreeNode {
public:
	TreeNode() {
		value = 0;
		left_child = 0;
		right_child = 0;
	}
	~TreeNode() {}
	int value;
	TreeNode* left_child;
	TreeNode* right_child;
};

class BST {
public:
	BST() {}
	~BST() {}

	bool search(TreeNode* node, int key, TreeNode* f, TreeNode* p) {
		if (!node) {
			p = f;
			return false;
		}
		else if (node->value == key) {
			p = node;
			return true;
		}
		else if (node->value > key) {
			return search(node->left_child, key, node, p);
		}
		else {
			return search(node->right_child, key, node, p);
		}
	}

	bool insertNode(TreeNode* node, int key) {
		TreeNode* p = 0, s = 0;
		if (!search(node, key, f, p)) {
			s = new TreeNode;
			s->value = key;
			if (!p) {
				p = s;
			}
			else if (p->value > key) {
				p->left_child = s;
			}
			else {
				p->right_child = s;
			}
			return true;
		}
		else {
			return false;
		}
	}

	bool

};