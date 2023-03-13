#pragma once
#include "game_obj.h"
#include <math.h>
class game_obj;
class Bullet;
class BulletList;
class Enemy : public game_obj {
private:
	int tear;											// “G‚Ì‹­‚³‚ğ•\‚µ‚Ü‚·A“ïˆÕ“x‚É‰‚¶‚Ä‘Ì—Í—Ê‚ğ•Ï‰»‚³‚¹‚Ü‚·
	float health;										// “G‚ÌHP‚ğ¦‚µ‚Ü‚·A©‹@’e‚ÉÚG‚·‚é‚ÆUŒ‚—Í•ªŒ¸Z‚³‚ê‚Ü‚·
	float health_rate[4] = { 1.0f,1.2f,1.5f,2.0f };		// “ïˆÕ“x‚É‰‚¶‚½“G‘Ì—Í‚Ì•Ï‰»‚ğ¦‚µ‚Ü‚·
	int drop_exp;										// “G‚ğ“|‚·‚Æ“¾‚ç‚ê‚éŒoŒ±’l‚Å‚·A“¯—Ê‚Ì‚¨‹à‚àŠl“¾‚Å‚«‚é‚Æ‚µ‚Ü‚·
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