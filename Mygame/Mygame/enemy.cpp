#include "enemy.h"
#include "bullet.h"
#include "bulletlist.h"
#include "model.h"
Enemy::Enemy() : game_obj() {
	tear = 0;
	health = 0;
	drop_exp = 0;
	status_check();
}
Enemy::Enemy(Model* m) : game_obj(m) {
	tear = 0;
	health = 0;
	drop_exp = 0;
	radius = 16;
	status_check();
}
Enemy::Enemy(Model* m, int te,float h, int d) : game_obj(m) {
	tear = te;
	health = h;
	drop_exp = d;
	status_check();
}
Enemy::~Enemy(){}
void Enemy::status_check(){
	if (tear != 0) {
		set_health(get_health() * health_rate[get_tear()]);
	}
}
bool Enemy::isHit(Bullet* b){
	if (!(b->get_Active())) {
		return false;
	}
	if (pow(pos_x - b->get_pos_x(), 2) + pow(pos_y - b->get_pos_y(), 2) <= pow(radius + b->get_radius(), 2)) {
		return true;
	}
	else {
		return false;
	}
}
void Enemy::set_tear(int t){
	tear = t;
}
void Enemy::set_health(float h){
	health = h;
}
void Enemy::set_drop_exp(int e){
	drop_exp = e;
}
int Enemy::get_tear(){
	return tear;
}
float Enemy::get_health(){
	return health;
}
int Enemy::get_drop_exp() {
	return drop_exp;
}
void Enemy::update(BulletList* bl) {
	if (!(isActive)) {
		return;
	}
	Bullet* b;
	for (int i = 0; i < 50; i++) {
		b = bl->get_bullet(i);
		if (isHit(b)) {
			health = health - b->get_attack();
			b->set_Active(false);
		}
		if (health <= 0) {
			isActive = false;
		}
	}
}
void Enemy::update(Bullet* b) {
	if (!(isActive)) {
		return;
	}
	if (isHit(b)) {
		health = health - b->get_attack();
		b->set_Active(false);
	}
	if (health <= 0) {
		isActive = false;
	}
}
void Enemy::spawn(int t, float h, int exp, int posx, int posy, float vecx, float vecy, float vel) {
	tear = t;
	health = h;
	drop_exp = exp;
	pos_x = posx;
	pos_y = posy;
	vector_x = vecx;
	vector_y = vecy;
	velocity = vel;
	status_check();
	isActive = true;
}