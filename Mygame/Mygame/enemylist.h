#pragma once

class Model;
class Enemy;
class BulletList;
class EnemyList {
private:
	Enemy * e_list[20];
public:
	EnemyList();                    // �K��R���X�g���N�^�A�����g��Ȃ�
	EnemyList(Model*);				// �R���X�g���N�^�A���������g��
	~EnemyList();                   // �f�X�g���N�^
	Enemy* get_enemy(int);	   		// ����̓G�f�[�^���擾�������ꍇ�Ɏg�p���܂�
	void set_enemy(Enemy*);			// �V���ɓG�f�[�^��o�^�������ꍇ�Ɏg�p���܂�
	void update(BulletList*);		// �G�̏����X�V����ۂɎg�p���܂�
	void reset_enemyss();			// �S�Ă̓G���A�N�e�B�u��Ԃɂ��܂�
};