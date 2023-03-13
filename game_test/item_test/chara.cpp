#include <chara.h>
Chara::Chara() {
	isActive = false;
	pos_x = 0;
	pos_y = 0;
	vector_x = 0;
	vector_y = 0;
}
Chara::~Chara() {}
void Chara::set_pos_x(float x) {
	pos_x = x;
}
void Chara::set_pos_y(float y) {
	pos_y = y;
}
void Chara::set_vec_x(float x) {
	vector_x = x;
}
void Chara::set_vec_y(float y) {
	vector_y = y;
}
void Chara::set_velocity(float v) {
	velocity = v;
}
void Chara::set_Active(bool b) {
	isActive = b;
}
void Chara::set_radius(float f){
	radius = f;
}
void Chara::set_exp(int e){
    exp = e;
}
float Chara::get_pos_x() {
	return pos_x;
}
float Chara::get_pos_y() {
	return pos_y;
}
float Chara::get_vec_x() {
	return vector_x;
}
float Chara::get_vec_y() {
	return vector_y;
}
float Chara::get_velocity() {
	return velocity;
}
bool Chara::get_Active() {
    return isActive;
}
float Chara::get_radius() {
	return radius;
}
bool Chara::isHit(){
	if (false/*pow(pos_x-o.get_pos_x(),2)+pow(pos_y - o.get_pos_y(),2) <= pow(radius+o.get_radius(),2)*/) {
		return true;
	}
	else {
		return false;
	}
}
void Chara::update() {
	if (isActive) {
		pos_x = pos_x + vector_x * velocity;
		pos_y = pos_y + vector_y * velocity;
        if((get_exp() >= get_ne_exp()) && get_level() < 10){
            set_exp(get_exp()-get_ne_exp());
            set_level(get_level()+1);
        }
	}
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
int Chara::get_total_exp(){
	return total_exp;
}
int Chara::get_ne_exp(){
	return necessary_exp[get_level()-1];
}
int Chara::get_exp(){
	return exp;
}