#pragma once
#include <iostream>
#include <string>
#include "area.h"
#include "map.h"
#include "itemlist.h"
class area;
class Model {
private:
	int gametimer;  // 単位秒での時間
	int frame;      // フレーム数の管理のための変数
    int scene;
    area* stage;
	itemlist* i_list;
	GameMapdata* map;
public:
	Model();
	~Model();
	void update();
	int get_timer();
    int get_scene();
	GameMapdata* get_map();
    void set_scene(int);
};