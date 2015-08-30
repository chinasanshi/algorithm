#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// 1. 求二叉树中的节点个数
// 2. 求二叉树的深度
// 3. 前序遍历，中序遍历，后序遍历
// 4.分层遍历二叉树（按层次从上往下，从左往右）
// 5. 将二叉查找树变为有序的双向链表
// 6. 求二叉树第K层的节点个数
// 7. 求二叉树中叶子节点的个数
// 8. 判断两棵二叉树是否结构相同
// 9. 判断二叉树是不是平衡二叉树
// 10. 求二叉树的镜像
// 11. 求二叉树中两个节点的最低公共祖先节点
// 12. 求二叉树中节点的最大距离
// 13. 由前序遍历序列和中序遍历序列重建二叉树
// 14.判断二叉树是不是完全二叉树

class BiTreeArray
{
public:
	BiTreeArray() {
		for (int i = 0; i < _max_size; ++i) {
			_data[i] = ' ';
		}
		_tree_length = 0;
		_max_node = 0;
	}
	~BiTreeArray() {

	}

	bool treeEmpty() {
		if (_tree_length == 0) {
			return true;
		}
		return false;
	}

	void clearTree() {
		for (int i = 0; i < _max_node; ++i) {
			_data[i] = ' ';
		}
		_tree_length = 0;
		_max_node = 0;
	}

	int getParent(int node) {
		if (node != 0) {
			return (node - 1) / 2;
		}
	}

	int getLeftChild(int node) {
		if (2 * node + 1 <= _max_node) {
			return 2 * node + 1;
		}
	}

	int getRightChild(int node) {
		if (2 * node + 2 <= _max_node) {
			return 2 * node + 2;
		}
	}

	char getValue(int node) {
		if (node >= 0 && node <= _max_node) {
			return _data[node];
		}
	}

	bool setValue(int node, char value) {
		_data[node] = value;
	}

	bool insertValue(int node, char value) {
		if (node > 0 && node < _max_size) {
			_data[node] = value;
			_tree_length++;
			if (_max_node < node) {
				_max_node = node;
			}
		}
	}

	// bool insertChild(int node, bool left_right, int value) {
	// 	//left_right is true repreant the left child; false means the right child
	// 	if (left_right == true && (2 * node + 1) < _max_size) {
	// 		_data[2 * node + 1] = value;
	// 		return ture;
	// 	}
	// 	else if (left_right == false && (2 * node + 2) < _max_size) {
	// 		_data[2 * node + 2] = value;
	// 		return true;
	// 	}
	// 	return false;
	// }

	// int deleteChild(int node, bool left_right) {
	// 	int temp = 0;
	// 	//left_right is true repreant the left child; false means the right child
	// 	if (left_right == true && (2 * node + 1) < _max_size) {
	// 		temp = _data[2 * node + 1];
	// 		_data[2 * node + 1] = 0;
	// 		return temp;
	// 	}
	// 	else if (left_right == false && (2 * node + 2) < _max_size) {
	// 		temp = _data[2 * node + 2];
	// 		_data[2 * node + 2] = 0;
	// 		return temp;
	// 	}
	// }

	bool insertChild(int node, bool left_right, char value) {
		//left_right is true repreant the left child; false means the right child
		if (left_right == true && (getLeftChild(node)) < _max_size) {
			_data[getLeftChild(node)] = value;
			_tree_length++;
			if (_max_node < getLeftChild(node)) {
				_max_node = getLeftChild(node);
			}
			return true;
		}
		else if (left_right == false && (getRightChild(node)) < _max_size) {
			_data[getRightChild(node)] = value;
			_tree_length++;
			if (_max_node < getRightChild(node)) {
				_max_node = getRightChild(node);
			}
			return true;
		}
		return false;
	}

	char deleteChild(int node, bool left_right) {
		char temp = ' ';
		//left_right is true repreant the left child; false means the right child
		if (left_right == true && (getLeftChild(node)) < _max_size) {
			temp = _data[getLeftChild(node)];
			_data[getLeftChild(node)] = 0;
			_tree_length--;
			if (getLeftChild(node) == _max_node) {
				//don't know how to deal with the _max_node
				_max_node--;
			}
			return temp;
		}
		else if (left_right == false && (getRightChild(node)) < _max_size) {
			temp = _data[getRightChild(node)];
			_data[getRightChild(node)] = 0;
			_tree_length--;
			if (getRightChild(node) == _max_node) {
				//don't know how to deal with the _max_node
				_max_node--;
			}
			return temp;
		}
	}

private:
	static const int _max_size = 100;
	char _data[_max_size];
	int _tree_length;
	int _max_node;
};

class LinkNode
{
public:
	LinkNode(): data('#'), left_child(nullptr), right_child(nullptr) {}
	~LinkNode() {}
	char data;
	LinkNode* left_child;
	LinkNode* right_child;
};

class BiTreeLink
{
public:
	BiTreeLink() {
		_root = nullptr;
	}
	~BiTreeLink() {
		clearTree(_root);
	}

	void clearTree(LinkNode* &node) {
		destory_node(node);
	}

	void destory_node(LinkNode* &node) {
		if (node) {
			destory_node(node->left_child);
			destory_node(node->right_child);
			destory_node(node);
			node = nullptr;
		}
	}


	void creatTree(LinkNode* &node) {
		char value;
		cin >> value;
		if (value == '#') {
			node = nullptr;
		}
		else {
			node = new LinkNode;
			node->data = value;
			creatTree(node->left_child);
			creatTree(node->right_child);
		}
	}

	// void cT() {
	// 	// creatTree(_root);
	// 	string tree_value = "ABD###CE##F##";
	// 	for (int i = 0; i < tree_value.size(); ++i) {
	// 		if (tree_value[i] == '#') {
	// 			node = nullptr;
	// 		}
	// 		else {
	// 			node = new LinkNode;
	// 			node->data = tree_value[i];

	// 		}
	// 	}
	// }

	LinkNode* insertLeftChild(LinkNode* &node, char value) {
		LinkNode* temp = new LinkNode;
		temp->data = value;
		node->left_child = temp;
		return temp;
	}

	LinkNode* insertRightChild(LinkNode* &node, char value) {
		LinkNode* temp = new LinkNode;
		temp->data = value;
		node->right_child = temp;
		return temp;
	}

	void visit(LinkNode* node) {
		// std::cout << node->data << std::endl;
		std::cout << node->data << " ";
	}

	void preOrder(LinkNode* node) {
		if (node) {
			visit(node);
			preOrder(node->left_child);
			preOrder(node->right_child);
		}
	}

	void inOrder(LinkNode* node) {
		if (node) {
			inOrder(node->left_child);
			visit(node);
			inOrder(node->right_child);
		}
	}

	void postOrder(LinkNode* node) {
		if (node) {
			postOrder(node->left_child);
			postOrder(node->right_child);
			visit(node);
		}
	}

	// (1)根结点非空，则入队列
	// (2)队列非空，队首元素出队列，输出结点值，若结点有左孩子，左孩子入队列；若结点有右孩子，右孩子也入队列。
	// (3)重复步骤(2)直到队列为空
	void levelOrder(LinkNode* node) {
		if (node == nullptr) {
			return;
		}
		else {
			queue<LinkNode*> node_queue;
			node_queue.push(node);
			while (!node_queue.empty()) {
				LinkNode* temp = node_queue.front();
				node_queue.pop();
				visit(temp);
				if (temp->left_child) {
					node_queue.push(temp->left_child);
				}
				if (temp->right_child) {
					node_queue.push(temp->right_child);
				}
			}
		}
	}



	// 递归算法非常的简单。先访问跟节点，然后访问左节点，再访问右节点。如果不用递归，那该怎么做呢？仔细看一下递归程序，就会发现，其实每次都是走树的左分支(left)，直到左子树为空，然后开始从递归的最深处返回，然后开始恢复递归现场，访问右子树。

	// 其实过程很简单：一直往左走 root->left->left->left...->null，由于是先序遍历，因此一遇到节点，便需要立即访问；由于一直走到最左边后，需要逐步返回到父节点访问右节点，因此必须有一个措施能够对节点序列回溯。有两个办法：
	// 1.用栈记忆：在访问途中将依次遇到的节点保存下来。由于节点出现次序与恢复次序是反序的，因此是一个先进后出结构，需要用栈。
	// 使用栈记忆的实现有两个版本。第一个版本是模拟递归的实现效果，跟LX讨论的，第二个版本是直接模拟递归。
	// 2.节点增加指向父节点的指针：通过指向父节点的指针来回溯（后来发现还要需要增加一个访问标志，来指示节点是否已经被访问，不知道可不可以不用标志直接实现回溯？想了一下，如果不用这个标志位，回溯的过程会繁琐很多。暂时没有更好的办法。）

	// (还有其他办法可以回溯么？)

	//二叉树非递归实现时，要采用栈去模拟
	//前序遍历顺序：根、左、右；对于任一节点都可看做是根节点，因此直接访问，若左孩子不为空，按相同顺序访问其左子树；左子树访问完以后，再访问其右子树。
	//步骤：对于任一节点Ｐ
	//１：访问节点Ｐ，并将节点Ｐ压栈。让Ｐ指向其左孩子
	//２：若左孩子不为空，循环到步骤１；若Ｐ为空，并将Ｐ指向栈顶，将栈顶元素出栈，然后将Ｐ指向Ｐ的右孩子，循环到步骤１
	//３：直到Ｐ为nullptr,且栈为空

	// 基本思路是先输出结点值，再入栈，然后遍历左子树。退栈时，遍历栈顶结点的右子树，
	void preOrder2(LinkNode* node) {
		stack<LinkNode*> node_stack;
		LinkNode* temp = node;
		// 每次都将遇到的节点压入栈，当左子树遍历完毕后才从栈中弹出最后一个访问的节点，访问其右子树。
		// 在同一层中，不可能同时有两个节点压入栈，因此栈的大小空间为O(h)，h为二叉树高度。
		// 时间方面，每个节点都被压入栈一次，弹出栈一次，访问一次，复杂度为O(n)
		while (temp || !node_stack.empty()) {
			// 遇到节点就访问并入栈
			while (temp) {
				visit(temp);
				node_stack.push(temp);
				temp = temp->left_child;
			}
			// 当节点不存在左孩子时，将该节点出栈；并将右孩子指针赋予temp,然后访问temp，并继续遍历其左孩子
			// 只有当左孩子不存在时才访问一次右孩子；
			if (!node_stack.empty()) {
				//find the nullptr's parent node
				temp = node_stack.top();
				node_stack.pop();
				temp = temp->right_child;
			}
		}
	}


	/*	前序遍历思想：先让根进栈，只要栈不为空，就可以做弹出操作，
	每次弹出一个结点，记得把它的左右结点都进栈，记得右子树先进栈，这样可以保证右子树在栈中总处于左子树的下面。	*/

	// 每次将节点压入栈，然后弹出，压右子树，再压入左子树，在遍历过程中，遍历序列的右节点依次被存入栈，左节点逐次被访问。
	// 同一时刻，栈中元素为m-1个右节点和1个最左节点，最高为h，所以空间也为O(h)；
	// 每个节点同样被压栈一次，弹栈一次，访问一次，时间复杂度O(n)
	// 该先序遍历将左右节点压入栈后，根节点就再也用不着了；而中序和后序却不一样，左右节点入栈后，根节点后面还需要访问。
	void preOrder3(LinkNode* node) {
		stack<LinkNode*> node_stack;
		LinkNode* temp = node;
		if (temp) {
			node_stack.push(temp);
		}
		while (!node_stack.empty()) {
			temp = node_stack.top();
			node_stack.pop();
			visit(temp);
			if (temp->right_child) {
				node_stack.push(temp->right_child);
			}
			if (temp->left_child) {
				node_stack.push(temp->left_child);
			}
		}
	}


	// 先序不同的是，中序是先进栈，再遍历左子树；出栈时，才输出结点值，然后遍历右子树
	void inOrder2(LinkNode* node) {
		stack<LinkNode*> node_stack;
		LinkNode* temp = node;
		while (temp || !node_stack.empty()) {
			while (temp) {
				node_stack.push(temp);
				temp = temp->left_child;
			}
			if (!node_stack.empty()) {
				temp = node_stack.top();
				node_stack.pop();
				visit(temp);
				temp = temp->right_child;
			}
		}
	}



	// 从直觉上来说，后序遍历对比中序遍历难度要增大很多。因为中序遍历节点序列有一点的连续性，而后续遍历则感觉有一定的跳跃性。
	// 先左，再右，最后才中间节点；访问左子树后，需要跳转到右子树，右子树访问完毕了再回溯至根节点并访问之。

	/*后续遍历非递归思路１：对于任一节点Ｐ，将其压栈，然后沿其左子树一直往下搜索，直到搜索到没有左孩子的节点，此时该节点在栈顶的位置，但此时并不能将其出栈并访问，因为其右孩子还未被访问。
	整个过程中，每个节点都两次出现在栈顶，只有第二次出现在栈顶时才能访问它。故需要一个新的类来表示此节点是否是第一次出现在栈顶*/
private:
	class node_with_order
	{
	public:
		node_with_order(): node(nullptr), is_first(true) {}
		LinkNode* node;
		bool is_first;
	};
public:
	void postOrder2_2(LinkNode* node) {
		stack<node_with_order*> node_stack;
		LinkNode* temp = node;
		node_with_order *save_node = nullptr;
		while (temp || !node_stack.empty()) {
			while (temp) {
				node_with_order* save_node_temp = new node_with_order;
				save_node_temp->node = temp;
				save_node_temp->is_first = true;
				node_stack.push(save_node_temp);
				temp = temp->left_child;
			}
			if (!node_stack.empty()) {
				save_node = node_stack.top();
				node_stack.pop();
				if (save_node->is_first) {
					save_node->is_first = false;
					node_stack.push(save_node);
					temp = save_node->node->right_child;
				}
				else {
					visit(save_node->node);
					temp = nullptr;
					delete save_node;
				}
			}
		}
	}

	// 因为后序遍历的顺序是左子树->右子树->根结点，所以我们在遍历过程中得标记左右子树的状态。
	// 这里我们用一个bool变量标识结点p的右子树遍历状态，false表示右子树未遍历，true则表示右子树已遍历。
	void postOrder2(LinkNode* node) {
		stack < pair<LinkNode*, bool>> node_stack;
		LinkNode* temp_node = node;
		while (temp_node || !node_stack.empty()) {
			if (temp_node) {
				node_stack.push(make_pair(temp_node, false));//false表示根结点p的右子树未访问
				temp_node = temp_node->left_child;
			}
			else {
				if (node_stack.top().second == false) {
					temp_node = node_stack.top().first->right_child;//遍历右子树
					node_stack.top().second = true;//根结点的右子树未访问
				}
				//右子树已访问
				else {
					visit(node_stack.top().first);//输出根结点值
					node_stack.pop();//根结点出栈
				}
			}
		}

	}

	/*非递归后续遍历思路二：为了保证根节点在其左孩子和右孩子之后访问，因此对于任一节点首先Ｐ，需先将其压栈（先进后出）。如果Ｐ不存在左右孩子，或者其左右孩子已经被访问过了，则可以将其出栈并访问该节点。否则将Ｐ的右孩子、左孩子依次入栈，这样就保证了每次取栈顶元素时，左孩子在右孩子前面被访问，左右孩子在根节点前面被访问*/
	void postOrder3(LinkNode* node) {
		stack<LinkNode*> node_stack;
		if (node) {
			node_stack.push(node);
		}
		LinkNode* cur_node = node;
		//不可以将pre_node设置成nullptr，否则若某个节点没有某个子节点（子节点为nullptr），会误认为该节点的所有子节点已经被访问过了，这样该节点的子节点都不会再被访问
		LinkNode* pre_node = node;
		while (!node_stack.empty()) {
			cur_node = node_stack.top();
			// 因为根节点在其左右子节点之前先进栈，所以只有根节点的左右节点都出栈以后，根节点才会出栈，这样前一次访问的节点是其左右孩子之一均表示其所有子节点已经访问过了
			if ((cur_node->left_child == nullptr && cur_node->right_child == nullptr) || (cur_node != nullptr && (pre_node == cur_node->left_child || pre_node == cur_node->right_child))) {

				visit(cur_node);
				node_stack.pop();
				pre_node = cur_node;
			}
			else {
				if (cur_node->right_child) {
					node_stack.push(cur_node->right_child);
				}
				if (cur_node->left_child) {
					node_stack.push(cur_node->left_child);
				}
			}
		}
	}

	// 双堆栈的后续遍历
	void postOrder4(LinkNode* node) {
		stack<LinkNode*> node_stack;//先使用根左右的顺序遍历所有节点保存在node_stack中
		stack<LinkNode*> node_stack_for_visit;//按后续遍历相反的顺序将节点压栈，用于访问
		LinkNode* cur_node = node;
		if (cur_node) {
			node_stack.push(cur_node);
		}
		while (!node_stack.empty()) {
			cur_node = node_stack.top();
			node_stack.pop();
			node_stack_for_visit.push(cur_node);
			if (cur_node->left_child) {
				node_stack.push(cur_node->left_child);
			}
			if (cur_node->right_child) {
				node_stack.push(cur_node->right_child);
			}
		}
		while (!node_stack_for_visit.empty()) {
			visit(node_stack_for_visit.top());
			node_stack_for_visit.pop();
		}
	}
	// 采用第一个思想，就是跟踪指针移动 用栈保存中间结果的实现方式，先序与中序难度一致，后序很困难。先序与中序只需要修改一下访问的位置即可。
	// 采用第二个思想，直接用栈来模拟递归，先序非常简单；而中序与后序难度一致。先序简单是因为节点可以直接访问，访问完毕后无需记录。
	// 而中序与后序时，节点在弹栈后还不能立即访问，还需要等其他节点访问完毕后才能访问，因此节点需要设置标志位来判定，因此需要额外的O(n)空间。

	void postOrder5(LinkNode* node) {
		stack<LinkNode*> node_stack;
		LinkNode* temp = node;
		//记录上次访问的结点，主要是用在：判定根结点是否能访问，如果根结点的右孩子是刚访问的，那么就能访问根结点了
		LinkNode* visit_node = NULL;
		while (temp || !node_stack.empty()) {
			//把最左分支压入栈，类似于中序遍历
			while (temp) {
				node_stack.push(temp);
				temp = temp->left_child;
			}
			temp = node_stack.top();
			//如果右子树是空，那么后序遍历就是中序遍历
			//如果如果上次访问的是右结点，那么可以访问根结点
			if (!temp->right_child || temp->right_child == visit_node) {
				visit(temp);
				node_stack.pop();
				visit_node = temp;
				temp = NULL;
			}
			else {
				//指向右子树，为下次循环，压栈做准备
				temp = temp->right_child;
			}
		}
	}


	int getNodeNum(LinkNode* node) {
		if (node == nullptr) {
			return 0;
		}
		else {
			return getNodeNum(node->left_child) + getNodeNum(node->right_child) + 1;
		}
	}

	int getDepth(LinkNode* node) {
		if (node == nullptr) {
			return 0;
		}
		int left_child_depth = getDepth(node->left_child);
		int right_child_depth = getDepth(node->right_child);
		return left_child_depth > right_child_depth ? (left_child_depth + 1) : (right_child_depth + 1);
	}

	// 第K层节点的个数
	int getLevelNodeNum(LinkNode* node, int k) {
		if (!node || k < 1) {
			return 0;
		}
		if (k == 1) {
			return 1;
		}
		int left_child_node_num = getLevelNodeNum(node->left_child, k - 1);
		int right_child_node_num = getLevelNodeNum(node->right_child, k - 1);
		return left_child_node_num + right_child_node_num;
	}

	// 第K层叶子节点的个数
	int getLevelLeafNodeNum(LinkNode* node, int k) {
		if (!node || k < 1) {
			return 0;
		}
		if (k == 1) {
			if (node->left_child == nullptr && node->right_child == nullptr) {
				return 1;
			}
			else {
				return 0;
			}
		}
		int left_child_node_num = getLevelLeafNodeNum(node->left_child, k - 1);
		int right_child_node_num = getLevelLeafNodeNum(node->right_child, k - 1);
		return left_child_node_num + right_child_node_num;
	}

	// 求二叉树叶子节点的个数
	int getLeafNum(LinkNode* node) {
		if (!node) {
			return 0;
		}
		else if (!node->left_child && !node->right_child) {
			return 1;
		}

		int left_leaf = getLeafNum(node->left_child);
		int right_leaf = getLeafNum(node->right_child);
		return left_leaf + right_leaf;
	}

	// 判断两棵二叉树是否结构相同
	bool isSameTree(LinkNode* first_node, LinkNode* second_node) {
		if (first_node == nullptr && second_node == nullptr) {
			return true;
		}
		else if (first_node == nullptr || second_node == nullptr) {
			return false;
		}
		bool left_same = isSameTree(first_node->left_child, second_node->left_child);
		bool right_same = isSameTree(first_node->right_child, second_node->right_child);
		return (left_same && right_same);
	}



	// 判断二叉树是不是平衡二叉树
	// 根据平衡二叉树的定义，如果任意节点的左右子树的深度相差不超过1，那这棵树就是平衡二叉树。
	bool isBalanceTree(LinkNode* node) {
		if (node == nullptr) {
			return true;
		}
		int depth_diff = getDepth(node->left_child) - getDepth(node->right_child);
		if (abs(depth_diff) > 1) {
			return false;
		}
		else {
			return (isBalanceTree(node->left_child) && isBalanceTree(node->right_child));
		}
	}


	// 求二叉树的镜像
	void mirror(LinkNode* &node) {
		if (!node) {
			return;
		}
		LinkNode* temp = nullptr;
		if (node->left_child || node->right_child) {
			temp = node->left_child;
			node->left_child = node->right_child;
			node->right_child = temp;
			mirror(node->left_child);
			mirror(node->right_child);
		}
	}



	// 前序遍历(规律：根在前；子树在根后且左子树比右子树靠前) :1 2 4 8 9 10 11 5 3 6 7；
	// 中序遍历(规律：根在中；左子树在跟左边，右子树在根右边) :8 4 10 9 11 2 5 1 6 3 7；
	// 后序遍历(规律：根在后；子树在根前且左子树比右子树靠前) :8 10 11 9 4 5 2 6 7 3 1；

	// 可以先由两个遍历画出二叉树。通过形象的二叉树来写出另一个遍历，写的方法如上（递归）。画出二叉树的方法如下：

	// 已知一棵二叉树的前序序列和中序序列，构造该二叉树的过程如下：
	// 1. 根据前序序列的第一个元素建立根结点；
	// 2. 在中序序列中找到该元素，确定根结点的左右子树的中序序列；
	// 3. 在前序序列中确定左右子树的前序序列；
	// 4. 由左子树的前序序列和中序序列建立左子树；
	// 5. 由右子树的前序序列和中序序列建立右子树。

	// 已知一棵二叉树的后序序列和中序序列，构造该二叉树的过程如下：
	// 1. 根据后序序列的最后一个元素建立根结点；
	// 2. 在中序序列中找到该元素，确定根结点的左右子树的中序序列；
	// 3. 在后序序列中确定左右子树的后序序列；
	// 4. 由左子树的后序序列和中序序列建立左子树；
	// 5. 由右子树的后序序列和中序序列建立右子树。



	// 由前序遍历序列和中序遍历序列重建二叉树

	// 二叉树前序遍历序列中，第一个元素总是树的根节点的值。中序遍历序列中，左子树的节点的值位于根节点的值的左边，
	// 右子树的节点的值位于根节点的值的右边。
	// 递归解法：
	// （1）如果前序遍历为空或中序遍历为空或节点个数小于等于0，返回NULL。
	// （2）创建根节点。前序遍历的第一个数据就是根节点的数据，在中序遍历中找到根节点的位置，可分别得知左子树和右子树的前序和中序遍
	// 历序列，重建左右子树。
	LinkNode* rebuildTree(char* pre_order, char* in_order, int node_num) {
		if (pre_order == nullptr || in_order == nullptr || node_num < 0) {
			return nullptr;
		}
		// 前序遍历的第一个数据就是根节点数据
		LinkNode* tree_root = new LinkNode;
		tree_root->data = *pre_order;
		// 查找根节点在中序遍历中的位置，中序遍历中，根节点左边为左子树，右边为右子树
		int preroot_in_inorder = -1;
		for (int i = 0; i < node_num; ++i) {
			if (in_order[i] == tree_root->data) {
				preroot_in_inorder = i;
				break;
			}
		}
		if (-1 == preroot_in_inorder) {
			std::cout << "输入有误" << std::endl;
			// std::throw std::exception("输入有误");
		}
		// 重建左子树
		char* pre_order_left_child = pre_order + 1;
		char* in_order_left_child = in_order;
		int node_num_left_child = preroot_in_inorder; //　中序遍历中根节点的左侧都是左子树
		tree_root->left_child = rebuildTree(pre_order_left_child, in_order_left_child, node_num_left_child);
		// 重建右子树
		char* pre_order_right_child = pre_order + node_num_left_child + 1;
		char* in_order_right_child = in_order + node_num_left_child + 1;
		int node_num_right_child = node_num - node_num_left_child - 1;
		tree_root->right_child = rebuildTree(pre_order_right_child, in_order_right_child, node_num_right_child);
		// 返回重建好的二叉树的根节点
		return tree_root;
	}


	// 中序遍历序列和后序遍历序列重建二叉树
	LinkNode* rebuildTree2(char *post_order, char *in_order, int node_num) {
		if (post_order == nullptr || in_order == nullptr || node_num < 0) {
			return nullptr;
		}
		// 后序遍历的第一个数据就是根节点数据
		LinkNode* tree_root = new LinkNode;
		tree_root->data = post_order[node_num - 1];
		// 查找根节点在中序遍历中的位置，中序遍历中，根节点左边为左子树，右边为右子树
		int postroot_in_inorder = -1;
		for (int i = 0; i < node_num; ++i) {
			if (in_order[i] == tree_root->data) {
				postroot_in_inorder = i;
			}
		}
		if (postroot_in_inorder == -1) {
			std::cout << "输入有误" << std::endl;
		}
		// 重建左子树
		char* post_order_left_child = post_order;
		char* in_order_left_child = in_order;
		int node_num_left_child = postroot_in_inorder;
		tree_root->left_child = rebuildTree2(post_order_left_child, in_order_left_child, node_num_left_child);
		// 重建右子树
		char* post_order_right_child = post_order + node_num_left_child;
		char* in_order_right_child = in_order + node_num_left_child + 1;
		int node_num_right_child = node_num - node_num_left_child - 1;
		tree_root->right_child = rebuildTree2(post_order_right_child, in_order_right_child, node_num_right_child);
		//
		return tree_root;
	}





	//*************************************
	//求一棵二叉树中距离相差最远的两个结点之间的距离。
	//
	//思路：注意指针声明了一定要赋值，否则会报错。
	//方法一：递归法
	//距离相差最远的两个结点，共有以下两种情况：
	//	(1)路径经过根结点，所以两个结点在根结点的不同分支上
	//	(2)路径不经过根结点，所以两个结点应该是次根结点中相聚最远的两个结点。(递归思想)
	//	递归本质上还是采用了后续遍历的方法。由于是从叶子结点开始的所以每次处理都是第一种情况。
	//方法二：非递归法
	//采用后序遍历二叉树的同时对二叉树的结点进行更新，每次更新都要更新最大距离。
	//
	//*************************************


	//
	//定义结点结构
	//
	struct NODE
	{
		NODE* pLeft;
		NODE* pRight;
		int nMaxLeft;
		int nMaxRight;
		char nValue;
	};
	int tMaxLength = 0;  //最大距离

	stack<NODE*> s;

	//
	//求最大距离(方法一)
	//
	void findMaxLength1(NODE* root)
	{
		//递归结束
		if (root == NULL)    return;

		//左树为空
		if (root->pLeft == NULL)
			root->nMaxLeft = 0;

		//右树为空
		if (root->pRight == NULL)
			root->pRight = 0;

		//左树不为空
		if (root->pLeft != NULL)
		{
			findMaxLength1(root->pLeft);
		}

		//右树不为空
		if (root->pRight != NULL)
		{
			findMaxLength1(root->pRight);
		}

		//求左子树最大距离
		if (root->pLeft != NULL)
		{
			int nTempMax = 0;
			if (root->pLeft->nMaxLeft > root->pLeft->nMaxRight)
				nTempMax = root->pLeft->nMaxLeft;
			else
				nTempMax = root->pLeft->nMaxRight;
			root->nMaxLeft = nTempMax + 1;
		}

		//求右子树最大距离
		if (root->pRight != NULL)
		{
			int nTempMax = 0;
			if (root->pRight->nMaxLeft > root->pRight->nMaxRight)
				nTempMax = root->pRight->nMaxLeft;
			else
				nTempMax = root->pRight->nMaxRight;
			root->nMaxRight = nTempMax + 1;
		}

		//更新最大距离
		if ((root->nMaxLeft + root->nMaxRight) > tMaxLength)
			tMaxLength = root->nMaxLeft + root->nMaxRight;
	}

	//
	//求最大距离(方法二)
	//

	int findMaxLength2(LinkNode* node) {
		int max_length = 0;
		stack<LinkNode*> node_stack;
		LinkNode* temp = node;
		//记录上次访问的结点，主要是用在：判定根结点是否能访问，如果根结点的右孩子是刚访问的，那么就能访问根结点了
		LinkNode* visit_node = NULL;
		while (temp || !node_stack.empty()) {
			//把最左分支压入栈，类似于中序遍历
			while (temp) {
				node_stack.push(temp);
				temp = temp->left_child;
			}
			temp = node_stack.top();
			//如果右子树是空，那么后序遍历就是中序遍历
			//如果如果上次访问的是右结点，那么可以访问根结点
			if (!temp->right_child || temp->right_child == visit_node) {
				// visit(temp);
				//以下是求最大距离的代码，不属于后序遍历
				if (temp->left_child) {
					temp->max_left = max(temp->left_child->max_left, temp->left_child->max_right) + 1;
				}
				if (temp->right_child) {
					temp->max_right = max(temp->right_child->max_left, temp->right_child->max_right) + 1;
				}
				if (max_length > temp->max_left + temp->max_right) {
					max_length = temp->max_left + temp->max_right;
				}
				node_stack.pop();
				visit_node = temp;
				temp = NULL;
			}
			else {
				//指向右子树，为下次循环，压栈做准备
				temp = temp->right_child;
			}
		}
		return max_length;
	}

// private:
	LinkNode* _root;

};


int main() {

	// BiTreeArray my_bitree_array;
	// cout << my_bitree_array.treeEmpty() << endl;
	// my_bitree_array.insertValue(0, i2a(1));
	// my_bitree_array.insertValue(1, i2a(2));
	// my_bitree_array.insertValue(2, i2a(3));
	// my_bitree_array.insertValue(3, i2a(4));
	// my_bitree_array.insertValue(4, i2a(5));
	// my_bitree_array.insertValue(5, i2a(6));
	// my_bitree_array.insertValue(6, i2a(7));
	// my_bitree_array.insertValue(7, i2a(8));
	// my_bitree_array.insertValue(8, i2a(9));
	// my_bitree_array.insertValue(9, i2a(10));
	// my_bitree_array.insertValue(10, i2a(11));
	// my_bitree_array.insertValue(11, i2a(12));
	// my_bitree_array.insertValue(12, i2a(13));
	// my_bitree_array.insertValue(13, i2a(14));
	// my_bitree_array.insertValue(14, i2a(15));
	// my_bitree_array.insertValue(15, i2a(16));
	// my_bitree_array.insertValue(16, i2a(17));
	// my_bitree_array.insertValue(17, i2a(18));
	// my_bitree_array.insertValue(18, i2a(19));
	// my_bitree_array.insertChild(18, true, i2a(118));
	// my_bitree_array.insertChild(19, false, i2a(19));
	// my_bitree_array.deleteChild(0, false);

	BiTreeLink my_bitree_link;
	// my_bitree_link.cT();
	my_bitree_link.creatTree(my_bitree_link._root);
	cout << my_bitree_link._root << " " << my_bitree_link._root->data << endl;
	my_bitree_link.preOrder(my_bitree_link._root);
	cout << "preOrder" << endl;
	my_bitree_link.inOrder(my_bitree_link._root);
	cout << "inOrder" << endl;
	my_bitree_link.postOrder(my_bitree_link._root);
	cout << "postOrder" << endl;
	my_bitree_link.levelOrder(my_bitree_link._root);
	cout << "levelOrder" << endl;
	my_bitree_link.preOrder2(my_bitree_link._root);
	cout << "preOrder2" << endl;
	my_bitree_link.preOrder3(my_bitree_link._root);
	cout << "preOrder3" << endl;
	my_bitree_link.inOrder2(my_bitree_link._root);
	cout << "inOrder2" << endl;
	my_bitree_link.postOrder2(my_bitree_link._root);
	cout << "postOrder2" << endl;
	my_bitree_link.postOrder3(my_bitree_link._root);
	cout << "postOrder3" << endl;
	cout << "node num is " << my_bitree_link.getNodeNum(my_bitree_link._root) << endl;
	cout << "tree depth is " << my_bitree_link.getDepth(my_bitree_link._root) << endl;




	return 0;
}
