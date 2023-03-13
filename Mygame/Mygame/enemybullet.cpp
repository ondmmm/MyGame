#include "enemybullet.h"

int move_type;
float timer;
float killtimer;

EnemyBullet::EnemyBullet(int type, float kill_t) : game_obj() {
	move_type = type;
	timer = 0.0;
	killtimer = kill_t;
}
EnemyBullet::~EnemyBullet(){}
void EnemyBullet::move(){
	if (move_type == 0) {
		set_pos_x(get_pos_x() + get_velocity()*get_vec_x());
		set_pos_y(get_pos_y() + get_velocity()*get_vec_y());
	}
}
bool EnemyBullet::isKill(){
	if (killtimer == -1) {
		if (pos_x < -160.0 || pos_x > 800.0 || pos_y < -160 || pos_y > 540) {
			return TRUE;
		}
		return FALSE;
	}
	else {
		if (timer > killtimer) {
			return TRUE;
		}
		return FALSE;
	}
}
void EnemyBullet::set_move_type(int type){
	move_type = type;
}
void EnemyBullet::set_kill_timer(float time){
	killtimer = time;
}
int EnemyBullet::get_move_type(){
	return move_type;
}
float EnemyBullet::get_kill_timer(){
	return killtimer;
}