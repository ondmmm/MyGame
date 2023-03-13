#pragma once
#include <iostream>
#include <string>

class Model {
private:
	int TITLE = 1;
	int GAME = 2;
	int SHOOTING = 3;
	int SCORE = 4;
	int ERROR_MODE = -1;
	int gametimer = 0;
	int f = 0;
public:
	Model();
	~Model();
	void update();
	int get_timer();
};