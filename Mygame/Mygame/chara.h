#pragma once
#include "game_obj.h"
#include <math.h>
class Model;
class Bullet;
class BulletList;
class Enemy;
class EnemyList;
class game_obj;
class Chara : public game_obj {											// �Q�[�����ɓo�ꂷ��I�u�W�F�N�g�͌p�����s�����Ƃŏ璷�ɂȂ�΍���s��
private:
	Model* m;															// ���䂷��model�N���X�ւ̃|�C���^
	int level;															// �v���C���[���x���������A�o���l�ɉ����ď㏸���A�U���͂��オ��
	int health;															// �c�@����\���A�c�@0�܂ŃQ�[�����ł���A�c�@���}�C�i�X�ɂȂ�ƃQ�[���I�[�o�[
	int bomb;															// �{������\���A����邱�ƂœG�Ƀ_���[�W��^���A��ʏ�̒e�������ł���
	int offensive_point[10] = {1,1,2,2,2,3,3,3,4,5};					// ���x���ɉ������U���͂̃}�b�v
	int necessary_exp[10] = {16,32,64,64,128,128,128,256,512,-1 };		// ���x���A�b�v�ɕK�v�Ȍo���l�̃}�b�v�A�ő僌�x���̎���-1��Ԃ��A���̒l���}�C�i�X�̍ۂɂ̓��x���A�b�v�������Ȃ��l�ɋC��t����
	int exp;															// �l�������o���l�������A���x�����オ���0���璙�߂Ȃ����ɂȂ�A���ȏ�Ń��x�����܂��オ��
	int tip;															// �ێ����邨���������A�G��|�����тɏ㏸�����l�ƌ������邱�Ƃŕ֗��ɃQ�[�����i��
	int shot_delay;														// �A���Œe�𔭎˂���ꍇ�ɂ�����x���Ǘ��ɗ��p
	int opt_delay;														// �I�v�V�����̒x���Ǘ��Ɏg�p���܂�
	bool shield;														// ���U���𖳌��ɂł����Ԃ��ǂ�����\���܂�
public:
	Chara();
	Chara(Model*);
	~Chara();
	void level_check();
	bool isHit(Bullet*);
	bool isHit(Enemy*);
	void add_exp();
	void add_tip();
	void sub_tip(int);
	void set_level(int);
	void set_health(int);
	void set_bomb(int);
	void set_d_timer(int);
	int get_level();
	int get_health();
	int get_bomb();
	int get_off_p();
	int get_ne_exp();
	int get_exp();
	int get_tip();
	int get_d_timer();
	void update();
	void update(BulletList*);
	void update(EnemyList*);
	void update(Enemy*);
	void reset_status();
};