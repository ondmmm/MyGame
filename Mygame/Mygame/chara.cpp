#include "chara.h"
#include "model.h"
#include "bullet.h"
#include "bulletlist.h"
#include "enemy.h"
#include "enemylist.h"
#include "itemlist.h"

Chara::Chara() : game_obj(){
	level = 1;
	health = 3;
	bomb = 3;
	exp = 0;
	radius = 16;
	velocity = 5;
}
Chara::Chara(Model* m) : game_obj(m) {
	pos_x = model->WINDOW_WIDTH / 2;
	pos_y = model->WINDOW_HEIGHT;
	level = 1;
	health = 3;
	bomb = 3;
	exp = 0;
	tip = 0;
	radius = 16;
	velocity = 5;
}
Chara::~Chara() {}
void Chara::level_check() {
	if (level == 10) {
		return;
	}
	if (get_ne_exp() <= exp) {
		exp = exp - get_ne_exp();
		level++;
	}
}
bool Chara::isHit(Bullet* b){
	if (!(b->get_Active())) {
		return false;
	}
	if (pow(pos_x-b->get_pos_x(),2)+pow(pos_y - b->get_pos_y(),2) <= pow(radius+b->get_radius(),2)) {
		return true;
	}
	else {
		return false;
	}
}
bool Chara::isHit(Enemy* e) {
	if (!(e->get_Active())) {
		return false;
	}
	if (pow(pos_x - e->get_pos_x(), 2) + pow(pos_y - e->get_pos_y(), 2) <= pow(radius + e->get_radius(), 2)) {
		return true;
	}
	else {
		return false;
	}
}
void Chara::add_exp() {
	exp = exp + 1 + model->get_itemlist()->get_boost(model->get_itemlist()->EXP);
}
void Chara::add_tip() {
	tip++;
}
void Chara::sub_tip(int i) {
	tip = tip - i;
}
void Chara::set_level(int i){
	level = i;
}
void Chara::set_health(int i){
	health = i;
}
void Chara::set_bomb(int i){
	bomb = i;
}
void Chara::set_d_timer(int i) {
	shot_delay = i;
}
int Chara::get_level(){
	return level;
}
int Chara::get_health(){
	return health;
}
int Chara::get_bomb(){
	return bomb;
}
int Chara::get_off_p(){
	return offensive_point[get_level()-1];
}
int Chara::get_ne_exp(){
	return necessary_exp[get_level()-1];
}
int Chara::get_exp(){
	return exp;
}
int Chara::get_tip() {
	return tip;
}
int Chara::get_d_timer() {
	return shot_delay;
}
void Chara::update() {
	if (isActive) {
		float d = 1;
		if (delay) {
			d = 0.0f;
		}
		pos_x = pos_x + vector_x * velocity * d;
		pos_y = pos_y + vector_y * velocity * d;
		delay=false;
	}
	if (model->WINDOW_WIDTH - radius < pos_x) {
		pos_x = model->WINDOW_WIDTH - radius;
	}
	if (model->WINDOW_HEIGHT - radius < pos_y) {
		pos_y = model->WINDOW_HEIGHT - radius;
	}
	if (0 + radius > pos_x) {
		pos_x = 0 + radius;
	}
	if (0 + radius > pos_y) {
		pos_y = 0 + radius;
	}
}
void Chara::update(BulletList* bl) {
	Bullet* b;
	for (int i = 0; i < 50; i++) {
		b = bl->get_bullet(i);
		if (isHit(b)) {
			health--;
			b->set_Active(false);
			pos_x = model->WINDOW_WIDTH / 2;
			pos_y = model->WINDOW_HEIGHT;
		}
	}
}
void Chara::update(EnemyList* el) {
	Enemy* e;
	for (int i = 0; i < 20; i++) {
		e = el->get_enemy(i);
		if (isHit(e)) {
			health--;
			pos_x = model->WINDOW_WIDTH / 2;
			pos_y = model->WINDOW_HEIGHT;
		}
	}
}
void Chara::update(Enemy* e) {
	if (isHit(e)) {
		health--;
		pos_x = model->WINDOW_WIDTH / 2;
		pos_y = model->WINDOW_HEIGHT;
	}
}
void Chara::reset_status() {
	pos_x = model->WINDOW_WIDTH / 2;
	pos_y = model->WINDOW_HEIGHT;
	level = 1;
	health = 3;
	bomb = 3;
	exp = 0;
	tip = 0;
}