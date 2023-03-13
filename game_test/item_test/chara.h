#pragma once
#include <math.h>

class Chara {
private:
	float pos_x;
	float pos_y;
	float vector_x;
	float vector_y;
	float velocity;
	float radius;
	bool isActive;
    int level;
	int health;
	int bomb;
	int offensive_point[10] = {1,1,2,2,2,3,3,3,4,5};
	int total_exp;
	int necessary_exp[10] = {16,32,64,64,128,128,128,256,512,-1 };
	int exp;
public:
    int MIN_RADIUS = 1;
	Chara() {}
	~Chara() {}
	void set_pos_x(float x) {}
	void set_pos_y(float y) {}
	void set_vec_x(float x) {}
	void set_vec_y(float y) {}
	void set_velocity(float v) {}
	void set_Active(bool b) {}
	void set_radius(float f){}
	float get_pos_x() {}
	float get_pos_y() {}
	float get_vec_x() {}
	float get_vec_y() {}
	float get_velocity() {}
	bool get_Active() {}
	float get_radius() {}
    void update();
	void level_check();
	bool isHit();
	void set_level(int);
	void set_health(int);
	void set_bomb(int);
    void set_exp(int);
	int get_level();
	int get_health();
	int get_bomb();
	int get_off_p();
	int get_total_exp();
	int get_ne_exp();
	int get_exp();
};