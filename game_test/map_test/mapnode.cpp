#include "mapnode.h"

Mapnode::Mapnode() {
	deapth = 0;
	pos = 2;
	event_num = 0;
	next1 = nullptr;
	next2 = nullptr;
	next3 = nullptr;
	prev = nullptr;
}
Mapnode::Mapnode(int d,int p){
	deapth = d;
	pos = p;
	event_num = 0;
	next1 = nullptr;
	next2 = nullptr;
	next3 = nullptr;
	prev = nullptr;
}
Mapnode::Mapnode(int d, int p,int e) {
	deapth = d;
	pos = p;
	event_num = e;
	next1 = nullptr;
	next2 = nullptr;
	next3 = nullptr;
	prev = nullptr;
}
Mapnode::~Mapnode(){
	free(this);
}
void Mapnode::set_pos(int i){
	pos = i;
}
void Mapnode::set_event(int i){
	event_num = i;
}
void Mapnode::set_next1(Mapnode* n){
	if (n == nullptr) {
		return;
	}
	next1 = n;
}
void Mapnode::set_next2(Mapnode* n){
	if (n == nullptr) {
		return;
	}
	next2 = n;
}
void Mapnode::set_next3(Mapnode* n) {
	if (n == nullptr) {
		return;
	}
	next3 = n;
}
void Mapnode::set_prev(Mapnode* n) {
	if (n == nullptr) {
		return;
	}
	prev = n;
}
int Mapnode::get_deapth(){
	return deapth;
}
int Mapnode::get_pos(){
	return pos;
}
int Mapnode::get_event(){
	return event_num;
}
Mapnode* Mapnode::get_left_node() {
	if (next1 == nullptr) {
		return nullptr;
	}
	return next1;
}
Mapnode* Mapnode::get_middle_node(){
	if (next2 == nullptr) {
		return nullptr;
	}
	return next2;
}
Mapnode* Mapnode::get_right_node(){
	if (next3 == nullptr) {
		return nullptr;
	}
	return next3;
}
Mapnode* Mapnode::get_prev_node(){
	if (prev == nullptr) {
		return nullptr;
	}
	return prev;
}
void Mapnode::test_print(){
	//デバッグ用のノード情報表示
	std::cout << "-------------------------\n";
    std::cout<< "deapth : " << deapth <<"\n";
	std::cout<< "position : " << pos <<"\n";
	std::cout<< "node_event : " << search_event(event_num) <<"\n";
	if(next1 != nullptr)std::cout<< "left_node exists\n";
	if(next2 != nullptr)std::cout<< "middle_node exists\n";
	if(next3 != nullptr)std::cout<< "right_node exists\n";
	if(prev != nullptr)std::cout<< "prev_node : ("<<get_prev_node()->get_deapth()<<","<<get_prev_node()->get_pos()<<")/(deapth,position)\n";
	std::cout << "-------------------------\n" <<std::endl;
}
std::string Mapnode::search_event(int n){
	int stage = n / 10;
	std::string stage_genre = "";
	if(n - stage * 10 == 0){
		stage_genre = "Boss";
	}else if((n - stage * 10 >= 1) && (n - stage * 10 <= 3)){
		stage_genre = "shooting";
	}else if((n - stage * 10 >= 4) && (n - stage * 10 <= 6)){
		stage_genre = "random_event";
	}else if(n - stage * 10 == 7){
		stage_genre = "shop_event";
	}else if(n - stage * 10 == 8){
		stage_genre = "rest_event";
	}else if(n - stage * 10 == 9){
		stage_genre = "gamble_event";
	}else{
		stage_genre = "error_event";
	}
	return "Event is "+stage_genre+" in stage " + std::to_string(stage);
}