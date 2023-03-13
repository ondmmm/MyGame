#pragma once
#include "sprite.h"
#include "direct3d.h"

class Chara;
class Bullet;
class Enemy;
class obj_image : public Sprite {
private:
	Chara* chara_obj;
	Bullet* bullet_obj;
	Enemy* enemy_obj;
public:
	obj_image();
	obj_image(Chara*);
	obj_image(Bullet*);
	obj_image(Enemy*);
	~obj_image();
	void update(IDirect3DDevice9* pDevice3D, IDirect3DTexture9* pTexture, bool);
	Chara* get_chara_obj();
	Enemy* get_enemy_obj();
	Bullet* get_bullet_obj();
};