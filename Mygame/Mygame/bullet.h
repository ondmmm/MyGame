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
	void shot(float posx,float posy,float vecx,float vecy,float vel,int t,int time,int killtime);	// ��ꂩ�珇�ɃX�|�[������x���W��y���W�A�i��ł���x�����̃x�N�g���Ay�����̃x�N�g���A�i�ޑ����A�X�|�[�����鎞�ԁA���ł���܂ł̎��Ԃ��Ƃ�
	void set_chara(Chara*);
	void set_rate(float);
	void set_move_type(int);
	void set_kill_timer(float);
	void set_timer(int);
	int get_move_type();
	int get_attack();
	int get_kill_timer();
};