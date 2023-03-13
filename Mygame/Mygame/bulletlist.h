#pragma once

class Model;
class Bullet;
class BulletList {
private:
	Bullet* b_list[50];				 // 1�̃N���X��50�܂ł̒e���Ǘ����܂�
public:
	BulletList();                    // �R���X�g���N�^
	BulletList(Model*);				 // �R���X�g���N�^
	~BulletList();                   // �f�X�g���N�^
	Bullet* get_bullet(int);	   	 // ����̒e�f�[�^���擾�������ꍇ�Ɏg�p���܂�
	Bullet* get_useful();			 // ��A�N�e�B�u���(���˂��Ă��Ȃ����)�̒e��1�擾���܂�
	void set_bullet(Bullet*);		 // �V���ɒe�f�[�^��o�^�������ꍇ�Ɏg�p���܂�
	void update(int);				 // �e�̏����X�V����ۂɎg�p���܂�
	void reset_bullets();			 // �S�Ă̒e���A�N�e�B�u��Ԃɂ��܂�
};