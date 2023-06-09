#pragma once
#include "game_obj.h"
#include <math.h>
class game_obj;
class Bullet;
class BulletList;
class Enemy : public game_obj {
private:
	int tear;											// 敵の強さを表します、難易度に応じて体力量を変化させます
	float health;										// 敵のHPを示します、自機弾に接触すると攻撃力分減算されます
	float health_rate[4] = { 1.0f,1.2f,1.5f,2.0f };		// 難易度に応じた敵体力の変化を示します
	int drop_exp;										// 敵を倒すと得られる経験値です、同量のお金も獲得できるとします
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