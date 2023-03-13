#include "bulletlist.h"
#include "bullet.h"
#include "model.h"

BulletList::BulletList() {
	for (int i = 0; i < 50; i++) {
		b_list[i] = new Bullet();
	}
}
BulletList::BulletList(Model* m) {
	for (int i = 0; i < 50; i++) {
		b_list[i] = new Bullet(m);
	}
}
BulletList::~BulletList() {
	for (int i = 0; i < 50; i++) {
		delete b_list[i];
	}
}
Bullet* BulletList::get_bullet(int i){
	return b_list[i];
}
Bullet* BulletList::get_useful() {
	for (int i = 0; i < 50; i++) {
		if (!(b_list[i]->get_Active())) {	// 非アクティブなら
			return b_list[i];
		}
	}
	return nullptr;
}
void BulletList::set_bullet(Bullet* b){
	for (int i = 0; i < 50; i++) {
		if (!(b_list[i]->get_Active())) {
			delete b_list[i];
			b_list[i] = b;
			//発射関数
			return;
		}
	}
}
void BulletList::update(int t){
	for (int i = 0; i < 50; i++) {
		b_list[i]->update();
		if (b_list[i]->get_Active()) {
			b_list[i]->set_timer(t);
		}
		if (b_list[i]->isKill()) {
			b_list[i]->set_Active(false);
		}
	}
}
void BulletList::reset_bullets() {
	for (int i = 0; i < 50; i++) {
		b_list[i]->set_Active(false);
	}
}