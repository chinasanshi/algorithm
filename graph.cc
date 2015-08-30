#include <iostream>
#include <queue>

using namespace std;

class graph_vertex_link
{
public:
	graph_vertex_link(): vertex_number(0), next_vertex(nullptr) {}
	~graph_vertex_link() {}
	int vertex_number;
	graph_vertex_link* next_vertex;

};

class graph_node_breadth
{
public:
	graph_node_breadth(): parent(nullptr), color(false), length(-1) {}

	graph_node_breadth* parent;
	bool color;
	int length;

};


class graph_node_depth
{
public:
	graph_node_depth(): parent(nullptr), color(false), detect(0), finish(0) {}
	~graph_node_depth() {}

	graph_node_depth* parent;
	bool color;
	int detect;
	int finish;
};

class graph
{
public:
	graph(): _vertex_num(0) {}
	~graph() {}



	// graph_vertex_link vertex_array[_vertex_num];
	graph_vertex_link vertex_array[100];
	void createGraph() {
		std::cout << "请输入图的顶点个数：" << std::endl;
		std::cin >> _vertex_num;
		// std::cout << "请输入图的边个数：" << std::endl;
		// std::cin >> _edge_num;
		for (int i = 0; i < _vertex_num; ++i) {
			std::cout << "第" << i << "个顶点的的标号为" << i << std::endl;
			vertex_array[i].vertex_number = i;
			std::cout << "请输入所有从定点" << i << "出发的边的定点号；若输入－１则表示结束" << std::endl;
			graph_vertex_link* temp_vertex = &vertex_array[i];
			int edge_second_vertex;
			cin >> edge_second_vertex;
			while (edge_second_vertex != -1) {
				graph_vertex_link* next_vertex = new graph_vertex_link;
				next_vertex->vertex_number = edge_second_vertex;
				temp_vertex->next_vertex = next_vertex;
				temp_vertex = next_vertex;
			}
		}
	}


	// void BFS(graph_node_breadth* &s) {
	// 	// 首先将所有节点涂成白色,长度为－１，父节点为ｎｕｌｌｐｔｒ;没有写相应代码


	// 	s->color = true;
	// 	s->length = 0;
	// 	s->parent = nullptr;
	// 	queue<graph_node_breadth*> gray_node_queue;
	// 	gray_node_queue.push(s);
	// 	while (!gray_node_queue.empty()) {
	// 		graph_node_breadth* u = gray_node_queue.front();
	// 		gray_node_queue.pop();
	// 		graph_node_breadth* v;
	// 		// ｖ遍历ｕ的邻接链表;不知道该怎样写
	// 		for (v; v != nullptr; ++v) {
	// 			if (!v->color) {
	// 				v->color = true;
	// 				v->parent = u;
	// 				v->length = u->length + 1;
	// 				gray_node_queue.push(v);
	// 			}
	// 		}
	// 	}
	// }


	// int node_time;//记录节点的发现和结束时间
	// void DFS() {
	// 	// 首先将所有节点涂成白色，父节点为nullptr，开始和结束时间设为０;没写代码

	// 	node_time = 0;
	// 	// 遍历图的每一个节点
	// 	for () {
	// 		if (u->color == false) {
	// 			DFS_VISIT(u);
	// 		}
	// 	}
	// }

	// void DFS_VISIT(graph_node_depth* &u) {
	// 	u->color = true;
	// 	node_time++;
	// 	u->detect = node_time;
	// 	// 遍历ｕ的邻接链表
	// 	graph_node_depth* v;
	// 	for () {
	// 		if (v->color == false) {
	// 			// 只在此处改变父节点的值
	// 			v->parent = u;
	// 			DFS_VISIT(v);
	// 		}
	// 	}
	// 	node_time++;
	// 	u->finish = node_time;
	// }

private:
	int _vertex_num;
	int _edge_num;
};

int main(int argc, char const *argv[])
{
	graph pic;
	pic.createGraph();
	return 0;
}