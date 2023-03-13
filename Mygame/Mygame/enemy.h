#pragma once
#include "game_obj.h"
#include <math.h>
class game_obj;
class Bullet;
class BulletList;
class Enemy : public game_obj {
private:
	int tear;											// �G�̋�����\���܂��A��Փx�ɉ����đ̗͗ʂ�ω������܂�
	float health;										// �G��HP�������܂��A���@�e�ɐڐG����ƍU���͕����Z����܂�
	float health_rate[4] = { 1.0f,1.2f,1.5f,2.0f };		// ��Փx�ɉ������G�̗͂̕ω��������܂�
	int drop_exp;										// �G��|���Ɠ�����o���l�ł��A���ʂ̂������l���ł���Ƃ��܂�
public:
	Enemy();
	Enemy(Model*);
	Enemy(Model*,int,float,int);
	~Enemy();
	void status_check();
	bool isHit(Bullet*);
	void set_tear(int);
	void set_health(float);
	void set_drop_exp(int);
	int get_tear();
	float get_health();
	int get_drop_exp();
	void update(Bullet*);
	void update(BulletList*);
	void spawn(int t, float h, int exp, int posx, int posy, float vector_x, float vector_y, float velocity);
};