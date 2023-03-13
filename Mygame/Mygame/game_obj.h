#pragma once
#include "texture.h"
#include "sprite.h"
#include "model.h"
class Model;
class Texture;
class game_obj {				// ���@��e���̃N���X�̌p�����ƂȂ��{�N���X
	protected:
		Model * model;			// �Ǘ������Model�N���X�ւ̎Q�ƁA�����ɊǗ�����邽�N���X�ւ̃A�N�Z�X�Ɏg�p
		float pos_x;			// �I�u�W�F�N�g��x���W
		float pos_y;			// �I�u�W�F�N�g��y���W
		float vector_x;			// �I�u�W�F�N�g��x�����ւ̌���(�O�p�֐��Ƒ����𗘗p�ŔC�ӂ̌�����)
		float vector_y;			// �I�u�W�F�N�g��y�����ւ̌���(�O�p�֐��Ƒ����𗘗p�ŔC�ӂ̌�����)
		float velocity;			// �I�u�W�F�N�g�̑���
		float radius;			// �����蔻��ƂȂ锼�a�������A����͉~���m�ōs��
		bool isActive;			// �A�N�e�B�u��ԂɂȂ��Ă��邩�A�Q�[����ŉ�ʂɉf��ׂ���ԂɂȂ��Ă��邩
		bool delay;				// ������Ԃ��𔻕ʂ��܂�
	public:
		game_obj() {			// �R���X�g���N�^
			model = nullptr;
			isActive = false;
			pos_x = 0;
			pos_y = 0;
			vector_x = 0;
			vector_y = 0;
			delay = false;
		}
		game_obj(Model* m) {	// �R���X�g���N�^
			model = m;
			isActive = false;
			pos_x = 0;
			pos_y = 0;
			vector_x = 0;
			vector_y = 0;
			delay = false;
		}
		game_obj(Model* m, float x, float y, float v_x, float v_y, float v) {	// �R���X�g���N�^
			model = m;
			isActive = false;
			pos_x = x;
			pos_y = y;
			vector_x = v_x;
			vector_y = v_y;
			velocity = v;
			delay = false;
		}
		~game_obj() {}					// �f�X�g���N�^
		void set_pos_x(float x) {		// �����œ����l��x���W���X�V����Z�b�^�֐�
			pos_x = x;
		}
		void set_pos_y(float y) {		// �����œ����l��y���W���X�V����Z�b�^�֐�
			pos_y = y;
		}
		void set_vec_x(float x) {		// �����œ����l��x�����̌������X�V����Z�b�^�֐�
			vector_x = x;
		}
		void set_vec_y(float y) {		// �����œ����l��y�����̌������X�V����Z�b�^�֐�
			vector_y = y;
		}
		void set_velocity(float v) {	// �����œ����l�ł𑬂��X�V����Z�b�^�֐�
			velocity = v;
		}
		void set_Active(bool b) {		// �����œ����l�ŃA�N�e�B�u��Ԃ��X�V����Z�b�^�֐�
			isActive = b;
		}
		void set_radius(float f){		// �����œ����l�Ŕ��a���X�V����Z�b�^�֐�
			radius = f;
		}
		float get_pos_x() {				// x���W�̃Q�b�^�֐�
			return pos_x;
		}
		float get_pos_y() {				// y���W�̃Q�b�^�֐�
			return pos_y;
		}
		float get_vec_x() {				// x�����̃Q�b�^�֐�
			return vector_x;
		}
		float get_vec_y() {				// y�����̃Q�b�^�֐�
			return vector_y;
		}
		float get_velocity() {			// �����̃Q�b�^�֐�
			return velocity;
		}
		bool get_Active() {				// �A�N�e�B�u��Ԃ̃Q�b�^�֐�
			if (this == nullptr) {
				return false;
			}
			return isActive;
		}
		float get_radius() {			// ���a�̃Q�b�^�֐�
			return radius;
		}
		void update() {					// �p�����[�^�ɂ���č��W���X�V���܂�
			if (isActive) {
				float d = 1;
				if (delay) {
					d = 0.5f;
				}
				pos_x = pos_x + vector_x * velocity * d;
				pos_y = pos_y + vector_y * velocity * d;
			}
		}
		void set_delay(bool d) {		// ������Ԃ̐ݒ���s���Z�b�^�֐�
			delay = d;
		}
		bool get_delay() {				// ������Ԃ���Ԃ��Q�b�^�֐�
			return delay;
		}
};