#pragma once
#include "mapnode.h"
#include <cstdlib> 
#include <string>
#include <time.h>

class GameMapdata {
	/*
	マップはノードがいくつか集まり、それぞれが次への参照情報を保持することでマップを形成します。
	イメージ図としては以下のようになります。（マップの層数が4の場合）
	　〇		最下段の〇が初期ノード、最上段が最終ノードに当たります
	 /|\		最下段、最上段のみ中央位置のノードになり、その間の層の道がランダムに生成されるようになっています。
	〇〇〇		
	|\|/|		
	〇〇〇		
	 \|/		
	　〇		
	
	*/
private:
	int deapth;				// マップの層数
	Mapnode* start_node;	// そのマップ内での初期node
	Mapnode* current_node;	// 現在マップのどの位置にいるのかを管理
	int stage_num;			// マップが何ステージ目か
public:
	GameMapdata();
	GameMapdata(int,int);				// インストラクタ、層数を引数として持ちます。
	~GameMapdata();					// デストラクタ
	void gen_mapdata();				// 層数情報を参考に初期ノードから次のノードを接続していきます。
	void node_change(int);			// 引数で向きを得て、その方向にcurrent_nodeを移動させます。
	Mapnode* get_start_node();		// 初期ノード情報を取得します。
	Mapnode* get_current_node();	// 現在のノード情報を取得します。
	void test_print();				// デバッグ用の関数です。標準出力にマップを構成するノードの情報を表示させます。
	void test_move();				// デバッグ用の関数です。再帰的に現在ノードを移動させてノード間のつながりを確認します。
	void print_tree();				// デバッグ用の関数です。木構造を可視化するために使用します。
	void test_move_tree(int (*node)[3], bool (*path)[7]);			// // デバッグ用の関数です。再帰的に現在ノードを移動させて構造情報を取得します。
};