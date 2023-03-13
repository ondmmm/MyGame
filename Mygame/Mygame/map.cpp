#include "map.h"
#include "mapnode.h"

GameMapdata::GameMapdata() {
	deapth = 1;
	Mapnode* s = new Mapnode(0, 2);
	start_node = s;
	current_node = start_node;
}
GameMapdata::GameMapdata(int d, int n) {
	srand((unsigned int)time(NULL));
	deapth = d;
	stage_num = n;
	Mapnode* s = new Mapnode(0, 2, rand() % 9 + stage_num*10 + 1);
	start_node = s;
	current_node = start_node;
	gen_mapdata();
}
GameMapdata::~GameMapdata() {
	if(current_node->get_left_node() != nullptr){
		node_change(1);
		test_move();
		current_node = current_node->get_prev_node();
	}
	if(current_node->get_middle_node() != nullptr){
		node_change(2);
		test_move();
		current_node = current_node->get_prev_node();
	}
	if(current_node->get_right_node() != nullptr){
		node_change(3);
		test_move();
		current_node = current_node->get_prev_node();
	}
	if (current_node != nullptr) {
		delete current_node;
	}
}
void GameMapdata::gen_mapdata() {
	srand((unsigned int)time(NULL));
	if (start_node == nullptr)return;
	bool isCon = false;//道がつながっているかの確認
	bool mid2left = false;
	bool mid2right = false;
	Mapnode* middle = start_node;
	Mapnode* left = nullptr;
	Mapnode* right = nullptr;
	Mapnode* nmiddle = nullptr;
	Mapnode* nleft = nullptr;
	Mapnode* nright = nullptr;
	for (int i = 1; i < deapth-1;i++) {
		nmiddle = nullptr;
		nleft = nullptr;
		nright = nullptr;
		Mapnode* m = new Mapnode(i, 2, rand() % 9 + stage_num*10 + 1);
		Mapnode* l = new Mapnode(i, 1, rand() % 9 + stage_num*10 + 1);
		Mapnode* r = new Mapnode(i, 3, rand() % 9 + stage_num*10 + 1);
		mid2left = false;
		mid2right = false;
		isCon =false;
		while (!isCon) {//少なくとも1つ先のノードが生成されるまで
			if (middle != nullptr) {
				if ((rand() % 3) >= 1) {
					nmiddle = m;
					middle->set_next2(nmiddle);
					isCon = true;
				}
				if ((rand() % 2) == 1 && !mid2left) {
					nleft = l;
					middle->set_next1(nleft);
					isCon = true;
					mid2left = true;
				}
				if ((rand() % 2) == 1 && !mid2right) {
					nright = r;
					middle->set_next3(nright);
					isCon = true;
					mid2right = true;
				}
			}else {
				isCon = true;
			}
		}
		isCon = false;
		while (!isCon) {//少なくとも1つ先のノードが生成されるまで
			if (left != nullptr) {
				if ((rand() % 2) == 0 && !mid2left) {
					nmiddle = m;
					left->set_next2(nmiddle);
					isCon = true;
					mid2left = true;
				}
				if ((rand() % 2) == 0 || mid2left) {
					nleft = l;
					left->set_next1(nleft);
					isCon = true;
				}
			}
			else {
				isCon = true;
			}
		}
		isCon = false;
		while (!isCon) {//少なくとも1つ先のノードが生成されるまで
			if (right != nullptr) {
				if ((rand() % 2) == 0 && !mid2right) {
					nmiddle = m;
					right->set_next2(nmiddle);
					isCon = true;
					mid2right = true;
				}
				if ((rand() % 2) == 0 || mid2right) {
					nright = r;
					right->set_next3(nright);
					isCon = true;
				}
			}
			else {
				isCon = true;
			}
		}
		middle = nmiddle;
		left = nleft;
		right = nright;
	}
	Mapnode* f = new Mapnode(deapth-1, 2,stage_num*10);//層内の最終node
	if (middle != nullptr) {
		middle->set_next2(f);
	}
	if (left != nullptr) {
		left->set_next2(f);
	}
	if (right != nullptr) {
		right->set_next2(f);
	}
}
void GameMapdata::node_change(int d) {
	if (current_node->get_deapth() == deapth)return;
	if (d == 0 && start_node != nullptr) {
		current_node = start_node;
	}
	if (d == 1 && current_node->get_left_node() != nullptr) {
		current_node->get_left_node()->set_prev(current_node);
		current_node = current_node->get_left_node();
	}
	if (d == 2 && current_node->get_middle_node() != nullptr) {
		current_node->get_middle_node()->set_prev(current_node);
		current_node = current_node->get_middle_node();
	}
	if (d == 3 && current_node->get_right_node() != nullptr) {
		current_node->get_right_node()->set_prev(current_node);
		current_node = current_node->get_right_node();
	}
}
Mapnode* GameMapdata::get_start_node() {
	return start_node;
}
Mapnode* GameMapdata::get_current_node() {
	return current_node;
}
int GameMapdata::get_deapth(){
	return deapth;
}
void GameMapdata::test_print() {
	node_change(0);
	test_move();
	node_change(0);
}
void GameMapdata::test_move() {
	current_node->test_print();
	if(current_node->get_left_node() != nullptr){
		node_change(1);
		test_move();
		current_node = current_node->get_prev_node();
	}
	if(current_node->get_middle_node() != nullptr){
		node_change(2);
		test_move();
		current_node = current_node->get_prev_node();
	}
	if(current_node->get_right_node() != nullptr){
		node_change(3);
		test_move();
		current_node = current_node->get_prev_node();
	}
}
void GameMapdata::print_tree(){
	//int node[deapth][3];
	int **node = new int*[3];
	for (int i = 0; i < 3; i++) {
		node[i] = new int[deapth];
	}
	//bool path[deapth][7];
	bool **path = new bool*[7];
	for (int i = 0; i < 7; i++) {
		path[i] = new bool[deapth];
	}
	for(int d = 0; d < deapth; d++){
		for(int n = 0; n < 3; n++){
			node[d][n] = 0;
		}
		for(int p = 0; p < 7; p++){
			path[d][p] = false;
		}
	}
	node_change(0);
	test_move_tree(node, path);
	for(int d = 1; d <= deapth; d++){
		for(int p = 0; p < 7; p++){
			if((path[deapth-d][p]) && (p == 0)){
				std::cout << "|";
			}else if((path[deapth-d][p]) && (p == 1)){
				std::cout << "/";
			}else if((path[deapth-d][p]) && (p == 2)){
				std::cout << "\\";
			}else if((path[deapth-d][p]) && (p == 3)){
				std::cout << "|";
			}else if((path[deapth-d][p]) && (p == 4)){
				std::cout << "/";
			}else if((path[deapth-d][p]) && (p == 5)){
				std::cout << "\\";
			}else if((path[deapth-d][p]) && (p == 6)){
				std::cout << "|";
			}else{
				std::cout << " ";
			}
			std::cout << " ";
		}
		std::cout << "" << std::endl;
		for(int n = 0; n < 3; n++){
			if((node[deapth-d][n] != 0) && (n == 0)){
				std::cout << "[" << std::to_string(node[deapth-d][n]) << "]";
			}else if((node[deapth-d][n] != 0) && (n == 1)){
				std::cout << "[" << std::to_string(node[deapth-d][n]) << "]";
			}else if((node[deapth-d][n] != 0) && (n == 2)){
				std::cout << "[" << std::to_string(node[deapth-d][n]) << "]";
			}else{
				std::cout << "    ";
			}
			std::cout << " ";
		}
		std::cout << "" << std::endl;
	}
	delete node;
	delete path;
}
void GameMapdata::test_move_tree(int* node[], bool* path[]) {
	if(current_node->get_left_node() != nullptr){
		if(current_node->get_pos()==1){
			path[current_node->get_deapth()][0] = true;
		}else if(current_node->get_pos()==2){
			path[current_node->get_deapth()][2] = true;
		}
		node_change(1);
		test_move_tree(node, path);
		current_node = current_node->get_prev_node();
	}
	if(current_node->get_middle_node() != nullptr){
		if(current_node->get_pos()==1){
			path[current_node->get_deapth()][1] = true;
		}else if(current_node->get_pos()==2){
			path[current_node->get_deapth()][3] = true;
		}else if(current_node->get_pos()==3){
			path[current_node->get_deapth()][5] = true;
		}
		node_change(2);
		test_move_tree(node, path);
		current_node = current_node->get_prev_node();
	}
	if(current_node->get_right_node() != nullptr){
		if(current_node->get_pos()==2){
			path[current_node->get_deapth()][4] = true;
		}else if(current_node->get_pos()==3){
			path[current_node->get_deapth()][6] = true;
		}
		node_change(3);
		test_move_tree(node, path);
		current_node = current_node->get_prev_node();
	}
	if(current_node->get_pos()==1){
		node[current_node->get_deapth()][0] = current_node->get_event();
	}else if(current_node->get_pos()==2){
		node[current_node->get_deapth()][1] = current_node->get_event();
	}else if(current_node->get_pos()==3){
		node[current_node->get_deapth()][2] = current_node->get_event();
	}
}