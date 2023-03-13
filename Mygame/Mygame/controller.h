#pragma once
#include <string>
#include "model.h"
#include "view.h"

class View;
class Model;
class Controller {
private:
	Model * model;
	View* view;
public:
	int down_SPACE = 0x0000;
	int down_ENTER = 0x0001;
	int down_ESCAPE = 0x0002;
	int down_LEFT = 0x0003;
	int down_UP = 0x0004;
	int down_RIGHT = 0x0005;
	int down_DOWN = 0x0006;
	int down_A = 0x0007;
	int down_B = 0x0008;
	int down_C = 0x0009;
	int down_D = 0x000A;
	int down_E = 0x000B;
	int down_F = 0x000C;
	int down_G = 0x000D;
	int down_H = 0x000E;
	int down_I = 0x000F;
	int down_J = 0x0010;
	int down_K = 0x0011;
	int down_L = 0x0012;
	int down_M = 0x0013;
	int down_N = 0x0014;
	int down_O = 0x0015;
	int down_P = 0x0016;
	int down_Q = 0x0017;
	int down_R = 0x0018;
	int down_S = 0x0019;
	int down_T = 0x001A;
	int down_U = 0x001B;
	int down_V = 0x001C;
	int down_W = 0x001D;
	int down_X = 0x001E;
	int down_Y = 0x001F;
	int down_Z = 0x0020;
	void v2mtext(std::string);
	void m2vtext();
	void setSignal(int);
	void setView(View*);
	void setModel(Model*);
};