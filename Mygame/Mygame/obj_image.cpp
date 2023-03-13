#include "obj_image.h"
#include "chara.h"
#include "bullet.h"
#include "enemy.h"

obj_image::obj_image() : Sprite() {
	chara_obj = nullptr;
	bullet_obj = nullptr;
	enemy_obj = nullptr;
}
obj_image::obj_image(Chara* g) : Sprite() {
	chara_obj = g;
	bullet_obj = nullptr;
	enemy_obj = nullptr;
}
obj_image::obj_image(Bullet* g) : Sprite() {
	chara_obj = nullptr;
	bullet_obj = g;
	enemy_obj = nullptr;
}
obj_image::obj_image(Enemy* g) : Sprite() {
	chara_obj = nullptr;
	bullet_obj = nullptr;
	enemy_obj = g;
}
obj_image::~obj_image(){}
void obj_image::update(IDirect3DDevice9* pDevice3D, IDirect3DTexture9* pTexture, bool isTurn = false){
	if (chara_obj->get_Active()) {
		pos.x = chara_obj->get_pos_x();
		pos.y = chara_obj->get_pos_y();
		Draw(pDevice3D,pTexture,isTurn);
	}else if (bullet_obj->get_Active()) {
		pos.x = bullet_obj->get_pos_x();
		pos.y = bullet_obj->get_pos_y();
		Draw(pDevice3D, pTexture, isTurn);
	}
	else if(enemy_obj->get_Active()) {
		pos.x = enemy_obj->get_pos_x();
		pos.y = enemy_obj->get_pos_y();
		Draw(pDevice3D, pTexture, isTurn);
	}
}
Chara* obj_image::get_chara_obj(){
	return chara_obj;
}
Enemy* obj_image::get_enemy_obj() {
	return enemy_obj;
}
Bullet* obj_image::get_bullet_obj() {
	return bullet_obj;
}