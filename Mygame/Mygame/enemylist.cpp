#include "enemylist.h"
#include "enemy.h"
#include "bulletlist.h"
#include "model.h"

EnemyList::EnemyList() {
	for (int i = 0; i < 20; i++) {
		e_list[i] = new Enemy();
	}
}
EnemyList::EnemyList(Model* m) {
	for (int i = 0; i < 20; i++) {
		e_list[i] = new Enemy(m);
	}
}
EnemyList::~EnemyList() {
	for (int i = 0; i < 20; i++) {
		delete e_list[i];
	}
}
Enemy* EnemyList::get_enemy(int i) {
	return e_list[i];
}
void EnemyList::set_enemy(Enemy* e) {
	for (int i = 0; i < 20; i++) {
		if (!(e_list[i]->get_Active())) {
			delete e_list[i];
			e_list[i] = e;
			return;
		}
	}
}
void EnemyList::update(BulletList* bl) {
	for (int i = 0; i < 20; i++) {
		if (e_list[i]->get_Active()) {
			e_list[i]->update(bl);
		}
	}
}
void EnemyList::reset_enemyss() {
	for (int i = 0; i < 20; i++) {
		e_list[i]->set_Active(false);
	}
}