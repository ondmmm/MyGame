#pragma once
#include "game_obj.h"
#include <math.h>

class EnemyBullet : public game_obj {
private:
	int move_type;
	float timer;
	float killtimer;
public:
	EnemyBullet( int, float);
	~EnemyBullet();
	void move();
	bool isKill();
	void set_move_type(int);
	void set_kill_timer(float);
	int get_move_type();
	float get_kill_timer();
};