#include <iostream>

using namespace std;

//数组实现线性表
class ArrayList {
public:
	ArrayList() {
		clearlist();//构造函数中清空线性表
	}

	~ArrayList() {

	}

	bool isempty() {
		if (0 == _length) {
			return true;
		}
		else {
			return false;
		}
	}

	//将存储线性表的数组所有值清零，并将线性表长度设为0
	void clearlist() {
		for (int j = 0; j < _max_size; ++j) {
			_data[j] = 0;
		}
		_length = 0;
	}

	//检查线性表的索引是否是有效数字
	bool isrightindex(int i) {
		if (i > 0 && i <= _length) {
			return true;
		}
		else {
			std::cout << "i is out of the list" << std::endl;
			return false;
		}
	}

	//获得线性表的长度
	int getLength() {
		return _length;
	}

	//获得索引值所对应的元素
	int getelement(int i) {
		if (isrightindex(i)) {
			return _data[i - 1];
		}
	}

	//查找元素是否在线性表
	int locateelement(const int value) {
		for (int j = 0; j < _length; ++j) {
			if (value == _data[j]) {
				return j + 1;
			}
		}
		return -1;//找不到时返回-1
	}

	//向线性表尾部中添加元素
	void addelement(int value) {
		if (_max_size == _length) {
			std::cout << "the list is full" << std::endl;
		}
		else {
			_data[_length] = value;
			++_length;
		}
	}

	//向线性表的任意位置插入元素
	void insert(int i, int value) {
		if (_max_size == _length) {
			std::cout << "the list is full" << std::endl;
		}

		if (i == _length + 1) {
			addelement(value);
		}
		else if (isrightindex(i)) {
			for (int j = _length - 1; j >= i - 1; --j) {
				_data[j + 1] = _data[j];
			}
			_data[i - 1] = value;
			++_length;
		}
	}

	//删除索引位置的元素
	int deleteelement(int i) {
		if (isrightindex(i)) {
			int temp = _data[i - 1];
			for (int j = i - 1; j < _length - 1; ++j) {
				_data[j] = _data[j + 1];
			}
			--_length;
			return temp;
		}
	}

	//打印线性表
	void printlist() {
		for (int j = 0; j < _length; ++j) {
			std::cout << _data[j] << " ";
		}
		std::cout << std::endl;
	}

private:
	static const int _max_size = 100;
	int _data[_max_size];
	int _length;//数组的下标
};

//单链表
class SingleLinkedListNode {
public:
	SingleLinkedListNode(): data(0), next(nullptr) {}
	int data;
	SingleLinkedListNode* next;
};

class SingleLinkedList {
public:

	//不带参数的构造函数只创建一个头结点
	SingleLinkedList() {
		listheadnode = new SingleLinkedListNode;//从堆上分配一个内存，用来存储链表头结点
		listheadnode->next = nullptr;
	}

	//带参数的构造函数，构造n个节点，节点值为0
	SingleLinkedList(int n) {
		listheadnode = new SingleLinkedListNode;
		SingleLinkedListNode* temp;
		temp = listheadnode;//temp节点首先保存头结点
		for (int i = 0; i < n; ++i) {
			node = new SingleLinkedListNode;
			node->data = 0;
			temp->next = node;
			temp = node;
		}
		node->next = nullptr;
	}

	~SingleLinkedList() {
		//析构函数首先删除第一个节点，然后依次向后删除，知道节点为空节点；最后删除头结点
		//SingleLinkedListNode* temp;
		//node = listheadnode->next;
		//while (node){
		//	temp = node;//node是马上要被删除的节点
		//	node = node->next;//保存要删除的节点的下一个节点，这样可以循环删除之后的节点
		//	delete temp;
		//}
		//delete listheadnode;//头结点也要删除

		SingleLinkedListNode* temp;
		node = listheadnode;
		while (node) {
			temp = node;
			node = node->next;
			delete temp;
		}
	}

	//在链表中查找索引为i的元素，若存在返回该节点的指针
	SingleLinkedListNode* search(int i) {
		int j = 1;
		node = listheadnode->next;//由链表指针找到第一个节点
		while (node && j < i) {
			node = node->next;
			++j;
		}
		if (!node || j > i) {
			std::cout << "i is over the list" << std::endl;
			return nullptr;//若未找到该节点则返回空指针
		}
		else {
			return node;//返回找到的节点指针
		}
	}

	//求得索引为i的元素的值data
	int getelement(int i) {
		//int value = 0;
		node = search(i);
		if (node) {
			std::cout << "find the element" << std::endl;
			//value = node->data;
			//return value;
			return node->data;
		}
	}

	//在头结点插入新的元素
	void headinsert(int value) {
		SingleLinkedListNode* newnode = new SingleLinkedListNode;
		newnode->data = value;
		newnode->next = listheadnode->next;//将新节点的next指针指向原来链表的第一个节点
		listheadnode->next = newnode;//并将新节点设置为第一个节点，头结点之后的节点
	}

	//在尾节点插入新的元素
	void tailinsert(int value) {
		node = listheadnode;
		//while循环中判断此节点的next指针非空，若是最后一个节点会跳出循环
		while (node->next) {
			node = node->next;
		}
		SingleLinkedListNode* newnode = new SingleLinkedListNode;
		newnode->data = value;
		newnode->next = nullptr;
		node->next = newnode;//原链表的最后一个节点的next指针指向新节点
	}

	void insert(int i, int value) {
		//如果链表为空且要插入第一个元素
		if (1 == i && listheadnode->next == nullptr) {
			SingleLinkedListNode* newnode = new SingleLinkedListNode;
			newnode->data = value;
			newnode->next = nullptr;
			listheadnode->next = newnode;
		}
		else {
			node = search(i - 1);//找到第i-1个节点
			if (node) {
				SingleLinkedListNode* newnode = new SingleLinkedListNode;
				newnode->data = value;
				newnode->next = node->next;//新节点的next指针指向i-1节点的next指针指向的节点
				node->next = newnode;//i-1节点的next指针指向新节点
				std::cout << "node insert suessed" << std::endl;
			}
		}
	}

	void deleteelement(int i) {
		node = search(i - 1);
		SingleLinkedListNode* temp;
		//如果不是尾节点
		if (node->next) {
			temp = node->next;
			node->next = node->next->next;
			delete temp;
		}
		else {
			std::cout << "the node is not exit" << std::endl;
		}
	}

	void clearlist() {
		SingleLinkedListNode* temp;
		node = listheadnode->next;
		while (node) {
			temp = node;
			node = node->next;
			delete temp;
		}
		listheadnode->next = nullptr;//并不删除头结点，只是将链表清空
	}

	void printlist() {
		node = listheadnode->next;
		while (node)
		{
			std::cout << node->data << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}

	SingleLinkedListNode *listheadnode;
private:
	SingleLinkedListNode *node;//暂时保存创建新的临时节点
};

//双链表
class DoubleListNode {
public:
	DoubleListNode() : data(0), prior(nullptr), next(nullptr) {}
	int data;
	DoubleListNode* prior;
	DoubleListNode* next;
};

class DoubleList {
public:
	DoubleList() {
		listheadnode = new DoubleListNode;
		listheadnode->prior = listheadnode;
		listheadnode->next = listheadnode;
	}
	DoubleList(int n) {
		listheadnode = new DoubleListNode;
		DoubleListNode* temp = listheadnode;
		for (int i = 0; i < n; ++i) {
			node = new DoubleListNode;
			node->data = 0;
			node->prior = temp;//新节点的prior指针指向链表的前一个节点
			temp->next = node;//temp保存了上一次创建的新节点，这样就将上一次创建的节点的next指针指向了新创建的节点
			temp = node;
		}
		node->next = listheadnode;
		listheadnode->prior = node;
	}

	~DoubleList() {
		DoubleListNode* temp;
		node = listheadnode->next;
		while (node != listheadnode) {
			temp = node;
			node = node->next;
			delete temp;
		}
		delete listheadnode;
	}

	DoubleListNode* search(int i) {
		int j = 1;
		node = listheadnode->next;
		while (j < i && node->next != listheadnode) {
			node = node->next;
			++j;
		}
		if (j > i || node == listheadnode) {
			std::cout << "i is over" << std::endl;
			return nullptr;
		}
		else {
			return node;
		}
	}

	void insert(int i, int value) {
		if (1 == i) {
			node = new DoubleListNode;
			node->data = value;
			node->next = listheadnode->next;
			node->prior = listheadnode;
			listheadnode->next->prior = node;
			listheadnode->next = node;
		}
		else {
			DoubleListNode* temp;
			temp = search(i - 1);//temp保存索引为i-1的节点
			if (temp) {
				node = new DoubleListNode;
				node->data = value;
				node->next = temp->next;//为node和temp的prior和next指针赋值时要注意顺序
				node->prior = temp;
				temp->next->prior = node;
				temp->next = node;
			}
		}
	}

	void headinsert(int value) {
		node = new DoubleListNode;
		node->data = value;
		node->prior = listheadnode;
		node->next = listheadnode->next;
		listheadnode->next->prior = node;
		listheadnode->next = node;
	}

	void tailinsert(int value) {
		node = new DoubleListNode;
		node->data = value;
		node->prior = listheadnode->prior;
		node->next = listheadnode;
		listheadnode->prior->next = node;
		listheadnode->prior = node;
	}

	void deleteelement(int i) {
		node = search(i);
		if (node && node != listheadnode) {
			node->prior->next = node->next;
			node->next->prior = node->prior;
			delete node;
		}
		else {
			std::cout << "delete error" << std::endl;
		}
	}

	void printlist() {
		node = listheadnode->next;
		while (node != listheadnode) {
			std::cout << node->data << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}

	DoubleListNode* listheadnode;
	DoubleListNode* node;
};

//数组实现的栈
class StackArray {
public:

	StackArray(): _stack_length(0) {
		for (int i = 0; i < _max_size; ++i) {
			_data[i] = 0;
		}
	}
	~StackArray() {}

	bool stackEmpty() {
		if (0 == _stack_length) {
			return true;
		}
		else {
			return false;
		}
	}

	void clearStack() {
		for (int i = 0; i < _stack_length; ++i) {
			_data[i] = 0;
		}
		_stack_length = 0;
	}

	int getTop() {
		if (!stackEmpty()) {
			return _data[_stack_length - 1];
		}
		else {
			std::cout << "栈为空" << std::endl;
		}
	}

	void push(int value) {
		if (_stack_length < _max_size) {
			_data[_stack_length] = value;
			_stack_length++;
		}
		else {
			std::cout << "栈已满" << std::endl;
		}
	}

	int pop() {
		if (!stackEmpty()) {
			int temp = _data[_stack_length];
			_data[_stack_length] = 0;
			_stack_length--;
			return temp;
		}
		else {
			std::cout << "栈为空" << std::endl;
		}
	}

	int getLength() {
		return _stack_length;
	}


private:
	static const int _max_size = 100;
	int _data[_max_size];
	int _stack_length;
};

//链表实现的栈
class StackLink {
public:
	StackLink() {
		_link_head = new SingleLinkedListNode;//新节点的next指针会在SingleLinkedListNode中设置为nullptr
		//_stack_top->next = _link_head;
		_stack_top = _link_head;
		_stack_length = 0;
	}
	~StackLink() {
		SingleLinkedListNode* node = _stack_top, *temp;
		while (node && node != _link_head) {
			temp = node;
			node = node->next;
			delete temp;
		}
		delete _link_head;
	}

	void clearStack() {
		SingleLinkedListNode *node = _link_head->next, *temp;
		while (node) {
			temp = node;
			node = node->next;
			delete temp;
		}
		_stack_length = 0;
	}

	bool stackEmpty() {
		if (_stack_top == _link_head) {
			return true;
		}
		else {
			return false;
		}
	}

	int getTop() {
		if (_stack_top != _link_head) {
			return _stack_top->data;
		}
	}

	void push(int value) {
		SingleLinkedListNode* node = new SingleLinkedListNode;
		node->data = value;
		node->next = _stack_top;
		_stack_top = node;
		_stack_length++;
	}

	int pop() {
		if (_stack_top != _link_head) {
			SingleLinkedListNode* node = _stack_top->next;
			int value = _stack_top->data;
			delete _stack_top;
			_stack_top = node;
			_stack_length--;
			return value;
		}
	}

	int getLength() {
		return _stack_length;
	}

private:
	SingleLinkedListNode *_link_head;//实现栈的链表头结点
	SingleLinkedListNode *_stack_top;//实现栈的链表头结点
	size_t _stack_length;
};

//数组实现的队列
class QueueArray {
public:
	QueueArray() {
		for (int i = 0; i < _max_size; ++i) {
			_data[i] = 0;
		}

		_queue_length = 0;
	}
	~QueueArray() {

	}

	void clearQueue() {
		for (int i = 0; i < _queue_length; ++i) {
			_data[i] = 0;
		}
		_queue_length = 0;
	}

	bool queueEmpty() {
		if (_queue_length == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int getHead() {
		if (!queueEmpty()) {
			return _data[0];
		}
	}

	bool enQueue(int value) {
		if (_queue_length < _max_size) {
			_data[_queue_length] = value;
			_queue_length++;
			return true;
		}
		return false;
	}

	int deQueue() {
		if (!queueEmpty()) {
			int temp = _data[0];
			for (int i = 0; i < _queue_length - 1; ++i) {
				_data[i] = _data[i + 1];
			}
			return temp;
		}
	}

	int getLength() {
		return _queue_length;
	}

private:
	static const int _max_size = 100;
	int _data[_max_size];
	int _queue_length;
	//int _front;
	//int _rear;
};

//循环队列
class CycleQueue {
public:
	CycleQueue() {
		for (int i = 0; i < _max_size; ++i) {
			_data[i] = 0;
		}
		// _queue_length = 0;
		_front = 0;
		_rear = 0;
	}
	~CycleQueue() {

	}

	void clearQueue() {
		if (_rear >= _front) {
			for (int i = _front; i < _rear; ++i) {
				_data[i] = 0;
			}
		}
		else {
			for (int i = 0; i < _rear; ++i) {
				_data[i] = 0;
			}
			for (int i = _front; i < _max_size; ++i) {
				_data[i] = 0;
			}
		}
		// _queue_length = 0;
		_front = _rear = 0;
	}

	bool queueEmpty() {
		if (_front == _rear) {
			return true;
		}
		return false;
	}

	int getHead() {
		if (!queueEmpty()) {
			return _data[_front];
		}
	}

	bool enQueue(int value) {
		//if the arrary is full
		if ((_rear + 1) % _max_size == _front) {
			return false;
		}
		_data[_rear] = value;
		_rear = (_rear + 1) % _max_size;
		return true;
	}

	int deQueue() {
		if (!queueEmpty()) {
			int temp = _data[_front];
			_data[_front] = 0;
			_front = (_front + 1) % _max_size;
			return temp;
		}
	}

	int getLength() {
		return (_rear - _front + _max_size) % _max_size;
	}

private:
	static const int _max_size = 100;
	int _data[_max_size];
	// int _queue_length;
	int _front;
	int _rear;
};

//链表实现的队列
class QueueLink {
public:
	QueueLink() {
		_queue_head = new SingleLinkedListNode;
		_rear = _queue_head;
		_queue_length = 0;
	}
	~QueueLink() {
		SingleLinkedListNode* node = _queue_head, *temp;
		while (node) {
			temp = node;
			node = node->next;
			delete temp;
		}
	}

	void clearQueue() {
		SingleLinkedListNode* node = _queue_head->next, *temp;
		while (node) {
			temp = node;
			node = node->next;
			delete temp;
		}
		_queue_length = 0;
		_rear = _queue_head;
	}

	bool queueEmpty() {
		if (_queue_head->next == nullptr) {
			return true;
		}
		return false;
	}

	int getHead() {
		if (!queueEmpty()) {
			return _queue_head->next->data;
		}
	}

	bool enQueue(int value) {
		SingleLinkedListNode *node = new SingleLinkedListNode;
		node->data = value;
		_rear->next = node;
		_rear = node;
		_queue_length++;
		return true;
	}

	int deQueue() {
		if (!queueEmpty()) {
			SingleLinkedListNode* node = _queue_head->next;
			int value = node->data;
			_queue_head->next = node->next;
			delete node;
			_queue_length--;
			return value;
		}
	}

	int getLength() {
		return _queue_length;
	}

private:
	SingleLinkedListNode* _queue_head;
	SingleLinkedListNode* _rear;
	int _queue_length;
};



int main() {
	ArrayList firstline;
	cout << firstline.isempty() << endl;
	cout << firstline.getLength() << endl;
	firstline.insert(1, 1);
	cout << firstline.getLength() << endl;
	firstline.printlist();
	firstline.insert(2, 1);
	cout << firstline.getLength() << endl;
	firstline.printlist();
	firstline.addelement(2);
	cout << firstline.getLength() << endl;
	firstline.printlist();
	firstline.deleteelement(2);
	cout << firstline.getLength() << endl;
	firstline.printlist();

	SingleLinkedList mylist;
	mylist.printlist();
	mylist.insert(1, 1);
	mylist.headinsert(11);
	mylist.printlist();
	mylist.insert(2, 22);
	mylist.printlist();
	mylist.tailinsert(21);
	mylist.printlist();
	mylist.insert(3, 33);
	mylist.printlist();
	cout << mylist.getelement(3) << endl;
	mylist.printlist();
	mylist.deleteelement(3);
	mylist.printlist();
	SingleLinkedList mylist2(10);
	mylist2.printlist();
	mylist2.headinsert(22);
	mylist2.printlist();
	mylist2.deleteelement(8);
	mylist2.printlist();

	DoubleList myDoubleList;
	myDoubleList.printlist();
	myDoubleList.headinsert(7);
	myDoubleList.headinsert(7);
	myDoubleList.tailinsert(17);
	myDoubleList.tailinsert(17);
	myDoubleList.insert(1, 11);
	myDoubleList.printlist();
	myDoubleList.insert(2, 22);
	myDoubleList.insert(3, 33);
	myDoubleList.insert(4, 21);
	myDoubleList.insert(5, 12);
	myDoubleList.printlist();
	myDoubleList.deleteelement(3);
	myDoubleList.printlist();
	myDoubleList.headinsert(119);
	myDoubleList.tailinsert(120);
	myDoubleList.printlist();
	DoubleList myDoubleList2(12);
	myDoubleList2.printlist();
	myDoubleList2.insert(3, 12);
	myDoubleList2.printlist();
	myDoubleList2.deleteelement(3);
	myDoubleList2.printlist();

	StackArray my_stack_array;
	cout<<my_stack_array.getLength()<<endl;
	my_stack_array.push(12);
	cout<<my_stack_array.getLength()<<endl;
	my_stack_array.push(11);
	my_stack_array.push(11);
	cout<<my_stack_array.getTop()<<endl;
	cout<<my_stack_array.pop()<<endl;
	cout<<my_stack_array.getLength()<<endl;
	my_stack_array.clearStack();
	cout<<my_stack_array.stackEmpty()<<endl;

	StackLink my_stack_link;
	cout << my_stack_link.getLength() << endl;
	cout << my_stack_link.stackEmpty() << endl;
	my_stack_link.push(11);
	cout << my_stack_link.getLength() << endl;
	my_stack_link.push(12);
	my_stack_link.push(12);
	my_stack_link.push(12);
	cout << my_stack_link.getLength() << endl;
	cout << my_stack_link.pop() << endl;
	cout << my_stack_link.getLength() << endl;
	my_stack_link.push(12);
	my_stack_link.push(12);
	my_stack_link.push(12);
	my_stack_link.clearStack();
	cout << my_stack_link.getLength() << endl;


	QueueArray my_queue_array;
	cout << my_queue_array.queueEmpty() << endl;
	my_queue_array.enQueue(11);
	my_queue_array.enQueue(11);
	my_queue_array.enQueue(11);
	my_queue_array.enQueue(11);
	cout << my_queue_array.getLength() << endl;
	cout << my_queue_array.getHead() << endl;
	cout << my_queue_array.deQueue() << endl;
	cout << my_queue_array.getLength() << endl;
	my_queue_array.clearQueue();
	cout << my_queue_array.getLength() << endl;

	CycleQueue my_cycle_queue;
	cout << my_cycle_queue.queueEmpty() << endl;
	my_cycle_queue.enQueue(11);
	cout << my_cycle_queue.getLength() << endl;
	my_cycle_queue.enQueue(12);
	my_cycle_queue.enQueue(13);
	my_cycle_queue.enQueue(14);
	my_cycle_queue.enQueue(15);
	cout << my_cycle_queue.getHead() << endl;
	cout << my_cycle_queue.getLength() << endl;
	my_cycle_queue.clearQueue();
	cout << my_cycle_queue.getLength() << endl;

	QueueLink my_queue_link;
	cout << my_queue_link.queueEmpty() << endl;
	my_queue_link.enQueue(11);
	cout << my_queue_link.getLength() << endl;
	my_queue_link.enQueue(12);
	my_queue_link.enQueue(13);
	my_queue_link.enQueue(14);
	my_queue_link.enQueue(15);
	my_queue_link.enQueue(16);
	cout << my_queue_link.deQueue() << endl;
	cout << my_queue_link.deQueue() << endl;
	cout << my_queue_link.deQueue() << endl;
	cout << my_queue_link.getLength() << endl;
	my_queue_link.clearQueue();
	cout << my_queue_link.getLength() << endl;

	return 0;
}
