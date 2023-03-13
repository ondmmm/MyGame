#include "bullet.h"
#include "chara.h"
#include "model.h"

Bullet::Bullet() : game_obj() {
	attack_rate = 0;
	move_type = -1;
	timer = 0;
	killtimer = 0;
	chara = nullptr;
}
Bullet::Bullet(Model* m) : game_obj(m) {
	attack_rate = 0;
	move_type = -1;
	timer = 0;
	killtimer = 0;
	chara = nullptr;
	radius = 8;
}
Bullet::Bullet(int type, int k,Chara* c) : game_obj() {
	if (type == 0) {
		attack_rate = 1;
	}
	else {
		attack_rate = 1;
	}
	move_type = type;
	killtimer = k;
	chara = c;
	timer = 0;
}
Bullet::~Bullet(){}
void Bullet::move(){
	if (move_type == 0) {
		set_pos_x(get_pos_x() + get_velocity()*get_vec_x());
		set_pos_y(get_pos_y() + get_velocity()*get_vec_y());
	}
}
bool Bullet::isKill(){
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
void Bullet::shot(float posx, float posy, float vecx, float vecy, float vel, int t, int time, int killtime) {
	if (isActive) { // Šù‚É”­ŽËÏ‚Ý‚Ì‚à‚Ì‚ª—ˆ‚Ä‚µ‚Ü‚Á‚½ê‡A‰½‚à‚¹‚¸•Ô‚·
		return;
	}
	if (t == 0) {
		attack_rate = 1;
	}
	pos_x = posx;
	pos_y = posy;
	vector_x = vecx;
	vector_y = vecy;
	velocity = vel;
	timer = time;
	if (killtime == -1) {
		killtimer = -1;

	}
	else{
		killtimer = time + killtime;
	}
	isActive = true;
}
void Bullet::set_chara(Chara* c) {
	chara = c;
}
void Bullet::set_rate(float r){
	attack_rate = r;
}
void Bullet::set_move_type(int t){
	move_type = t;
}
void Bullet::set_kill_timer(float k){
	killtimer = k;
}
void Bullet::set_timer(int t) {
	timer = t;
}
int Bullet::get_move_type(){
	return move_type;
}
int Bullet::get_attack(){
	return chara->get_off_p()*attack_rate;
}
int Bullet::get_kill_timer(){
	return killtimer;
}