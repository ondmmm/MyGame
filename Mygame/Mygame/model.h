#pragma once
#include <iostream>
#include <string>


class Chara;
class EnemyList;
class Enemy;
class BulletList;
class GameMapdata;
class itemlist;
class area;
class View;
class Model {
private:
	View* view;
	std::string text;
	std::string textbox;
	std::string textpeople;
	std::string itemname;
	std::string itemtext;
	std::string itemprice;
	int scene = 1;
	int titlepointer = 0;
	int mappointer = 0;
	Chara* chara;
	EnemyList* enemy_list;
	Enemy* boss_enemy;
	BulletList* bullet_list;
	BulletList* enemy_bullet_list;
	GameMapdata* mapdata;
	area* stage;
	itemlist* i_list;
	int gametimer;
	int frame;
	int map_num;
	int deapth;
	int deapth_map[3] = {4,4,5};
public:
	int WINDOW_WIDTH = 640;
	int WINDOW_HEIGHT = 480;
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
	int down_SHIFT = 0x0021;
	Model();
	~Model();
	void update();
	void setView(View*);
	void settext(std::string);
	std::string gettext();
	void setscene(int);
	int getscene();
	void resettext();
	int get_title_p();
	int get_map_p();
	int get_deapth();
	void stage_clear();
	void change_titlep(int);
	int TITLE = 1;
	int MAP = 2;
	int SHOOTING = 3;
	int SCORE = 4;
	int PAUSE = 5;
	int ERROR_MODE = -1;
	Chara* get_chara();
	EnemyList* get_enemy_list();
	Enemy* get_boss_enemy();
	BulletList* get_bullet_list();
	BulletList* get_enemy_bullet_list();
	GameMapdata* get_map();
	area* get_stage();
	itemlist* get_itemlist();
	int get_timer();
	void v2mtext(std::string);
	void m2vtext();
	void setSignal(int);
	void set_scene(int);
	std::string get_textbox();
	std::string get_textpeople();
	std::string get_itemname();
	std::string get_itemtext();
	void set_textbox(std::string);
	void set_textpeople(std::string);
	void set_itemname(std::string);
	void set_itemtext(std::string);
	std::string get_itemprice();
	void set_itemprice(std::string);
};