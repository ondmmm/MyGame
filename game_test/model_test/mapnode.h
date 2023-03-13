#pragma once
#include <iostream>
#include <string>

class Mapnode {
	/*
	nodeのイメージ図は以下のようになります
	
	[left_node]	[middle_node]	[right_node]
		\			|				/
				[current_node]
					|	
				[prev_node]

	次のnodeを三方向、一つ前のnode情報を1つ保持できる構造になってます。
	前のnodeに関してはnode遷移時に直前のnode情報を保持します。
	この時、nodeについて「次」や「前」といった情報が層として扱われます。
	各層のnodeは左右中央で配置されます。
	nodeはイベント情報を持ち、そのnodeで起きるイベントが何になるかを管理します。
	*/
private:
	int deapth;		// nodeが何層目にあるかを示す
	int pos;		// nodeが層内のどの位置にあるかを示す
	int event_num;	// node内で起きるイベントの番号
	Mapnode* next1;	// 左側node
	Mapnode* next2;	// 中央node
	Mapnode* next3;	// 右側node
	Mapnode* prev;	// 前のnode
public:
	Mapnode();
	Mapnode(int,int);
	Mapnode(int,int,int);
	~Mapnode();
	const int LEFT = 1;
	const int MIDDLE = 2;
	const int RIGHT = 3;
	void set_pos(int);
	void set_event(int);
	void set_next1(Mapnode*);
	void set_next2(Mapnode*);
	void set_next3(Mapnode*);
	void set_prev(Mapnode*);
	int get_deapth();
	int get_pos();
	int get_event();
	Mapnode* get_left_node();
	Mapnode* get_middle_node();
	Mapnode* get_right_node();
	Mapnode* get_prev_node();
    void test_print();
	std::string search_event(int);
};