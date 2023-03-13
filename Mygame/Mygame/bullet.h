#pragma once
#include "game_obj.h"
#include <math.h>

class Chara;
class Model;
class game_obj;
class Bullet : public game_obj {
private:
	float attack_rate;
	int move_type;
	int timer;
	int killtimer;
	Chara* chara;
public:
	Bullet();
	Bullet(Model*);
	Bullet(int,int,Chara*);
	~Bullet();
	void move();
	bool isKill();
	void shot(float posx,float posy,float vecx,float vecy,float vel,int t,int time,int killtime);	// 第一から順にスポーンするx座標とy座標、進んでいくx方向のベクトル、y方向のベクトル、進む速さ、スポーンする時間、消滅するまでの時間をとる
	void set_chara(Chara*);
	void set_rate(float);
	void set_move_type(int);
	void set_kill_timer(float);
	void set_timer(int);
	int get_move_type();
	int get_attack();
	int get_kill_timer();
};