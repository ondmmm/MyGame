#pragma once
#include <iostream>
#include <string>
#include "area.h"
class area;
class Model {
private:
	int gametimer;  // 単位秒での時間
	int frame;      // フレーム数の管理のための変数
    int scene;
    area* stage;
public:
	Model();
	~Model();
	void update();
	int get_timer();
    int get_scene();
    void set_scene(int);
};