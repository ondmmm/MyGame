#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <string>
#include "game_obj.h"
#include "view.h"
#include "obj_image.h"
#include "chara.h"
#include "enemy.h"
#include "bullet.h"
#include "model.h"
#include "enemylist.h"
#include "bulletlist.h"
#include "map.h"
#include "mapnode.h"
#include "area.h"

// Direct3D�ɕK�v�ȃw�b�_�[�ƃ��C�u���� 

#define D3D_DEBUG_INFO	// Direct3D�f�o�b�N�t���O

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dxof.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")
#include <comdef.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <mmsystem.h>

#include <string>
#include <Windows.h>
#include <vector>
#include <tchar.h>
#include <locale.h>

#include "direct3d.h"
#include "texture.h"
#include "sprite.h"
#include "directxtext.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int FPS = 60;

//�t���[�����[�g�v�Z�N���X
class FrameRateCalculator {
	long long cnt = 0;
	const int limit = 60;
	std::string fpsStr = "0fps";
	long long time = currentTime();

	//���ݎ������擾����֐�
	long long currentTime() {
		std::chrono::system_clock::duration d = std::chrono::system_clock::now().time_since_epoch();
		return std::chrono::duration_cast<std::chrono::milliseconds>(d).count();
	}

	//�t���[�����[�g�̌v�Z�ƌ��ʕ�������\�z����
	void updateStr() {
		//fps���v�Z���A������Ƃ��ĕێ�����
		long long end = currentTime();
		double fpsResult = (double)(1000) / (end - time) * cnt;
		time = end;
		fpsStr = std::to_string(fpsResult).substr(0,5) + "fps";
		cnt = 0;
	}
public:

	//�t���[�����[�g�X�V���\�b�h
	std::string* update() {
		cnt++;
		//�K��t���[�����ɂȂ�����t���[�����[�g�̍X�V
		if (limit <= cnt) {
			updateStr();
		}
		return &fpsStr;
	}
};
// �E�B���h�E�v���V�[�W���A�E�B���h�E�ɑ΂��郁�b�Z�[�W�������s��
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
		// �E�B���h�E���j�����ꂽ�Ƃ�
	case WM_DESTROY:
		PostQuitMessage(0);	// WM_QUIT���b�Z�[�W�����b�Z�[�W�L���[�ɑ���
		return 0;
	}
	// �f�t�H���g�̃��b�Z�[�W�������s��
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

// WinMain�֐��i�A�v���P�[�V�����̊J�n�֐��j
// �R���\�[���A�v���P�[�V�����ƈႢ�A�R���\�[�����J���Ȃ�
int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//setlocale(LC_ALL, "Japanese");
	const TCHAR* WC_BASIC = _T("BASIC_WINDOW");
	// �V���v���E�B���h�E�N���X�ݒ�
	WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,WndProc, 0,0,hInstance,
		(HICON)LoadImage(NULL,MAKEINTRESOURCE(IDI_APPLICATION),IMAGE_ICON,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HCURSOR)LoadImage(NULL,MAKEINTRESOURCE(IDC_ARROW),IMAGE_CURSOR,0,0,LR_DEFAULTSIZE | LR_SHARED),
		(HBRUSH)GetStockObject(WHITE_BRUSH), NULL, WC_BASIC , NULL };

	// �V���v���E�B���h�E�N���X�쐬
	if (!RegisterClassEx(&wcex))
		return false;


	// �E�B���h�E�̍쐬
	HWND hWnd = CreateWindowEx(0, WC_BASIC,
		_T("Mygame"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

	///////////////////////////////////////////////////////////////////////////////////////////////
	View* view = new View();
	Model* model = new Model();
	view->setModel(model);
	model->setView(view);

	//	Direct3D�̏�����
	Direct3D direct3d;
	direct3d.Create(hWnd, WINDOW_WIDTH, WINDOW_HEIGHT);

	// �t�H���g�쐬
	DirectXText text;
	text.Create(direct3d.pDevice3D, 32);

	// �e�N�X�`���쐬
	Texture charatex;
	charatex.Load(direct3d.pDevice3D, _T("karigazou2.bmp"));//���@�̃e�N�X�`����o�^
	Texture bullettex;
	bullettex.Load(direct3d.pDevice3D, _T("karigazou1.bmp"));//���@�e�̃e�N�X�`����o�^
	Texture ebullettex;
	ebullettex.Load(direct3d.pDevice3D, _T("karigazou3.bmp"));//�G�e�̃e�N�X�`����o�^
	Texture enemytex;
	enemytex.Load(direct3d.pDevice3D, _T("karigazou4.bmp"));//�G�̃e�N�X�`����o�^
	Texture bosstex;
	bosstex.Load(direct3d.pDevice3D, _T("karigazou5.bmp"));//���G�̃e�N�X�`����o�^
	Texture opttex;
	opttex.Load(direct3d.pDevice3D, _T("karigazou6.bmp"));//���@�I�v�V�����e�̃e�N�X�`����o�^
	Texture cnodetex;
	cnodetex.Load(direct3d.pDevice3D, _T("karigazou7.bmp"));//�\���̃e�N�X�`����o�^

	// �X�v���C�g�쐬
	obj_image* chara = new obj_image(model->get_chara());
	chara->SetWidth(32, 32);
	chara->SetPos(model->get_chara()->get_pos_x(), model->get_chara()->get_pos_y());
	obj_image* boss = new obj_image(model->get_boss_enemy());
	boss->SetWidth(32, 32);
	boss->SetPos(model->get_boss_enemy()->get_pos_x(), model->get_boss_enemy()->get_pos_y());
	obj_image* enemies[20];
	for (int i = 0; i < 20; i++) {
		enemies[i] = new obj_image(model->get_enemy_list()->get_enemy(i));
		enemies[i]->SetWidth(16, 16);
		enemies[i]->SetPos(model->get_enemy_list()->get_enemy(i)->get_pos_x(), model->get_enemy_list()->get_enemy(i)->get_pos_y());
	}
	obj_image* bullets[50];
	for (int i = 0; i < 50; i++) {
		bullets[i] = new obj_image(model->get_bullet_list()->get_bullet(i));
		bullets[i]->SetWidth(16, 16);
		bullets[i]->SetPos(model->get_bullet_list()->get_bullet(i)->get_pos_x(), model->get_bullet_list()->get_bullet(i)->get_pos_y());
	}
	obj_image* enemy_bullets[50];
	for (int i = 0; i < 50; i++) {
		enemy_bullets[i] = new obj_image(model->get_enemy_bullet_list()->get_bullet(i));
		enemy_bullets[i]->SetWidth(32, 32);
		enemy_bullets[i]->SetPos(model->get_enemy_bullet_list()->get_bullet(i)->get_pos_x(), model->get_enemy_bullet_list()->get_bullet(i)->get_pos_y());
	}

	//���ݎ������}�C�N���b�Ŏ擾
	std::function<long long(void)> currentTimeMicro = []() {
		std::chrono::system_clock::duration d = std::chrono::system_clock::now().time_since_epoch();
		return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
	};

	//fps�v�Z�p�I�u�W�F�N�g
	FrameRateCalculator fr;

	MSG msg = {};

	//���ݎ������擾(1�b=1000000)
	long long end = currentTimeMicro();

	//���̍X�V���Ԃ��v�Z(1�b/�t���[�����[�g)
	long long next = end + (1000 * 1000 / FPS);

	BYTE key[256];
	int timer = 0;

	// ���b�Z�[�W���[�v
	while (msg.message != WM_QUIT) {
		// �A�v���P�[�V�����ɑ����Ă��郁�b�Z�[�W�����b�Z�[�W�L���[����擾����
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);	// �A�v���P�[�V�����̊e�E�B���h�E�v���V�[�W���Ƀ��b�Z�[�W��]������
		}

		// ���b�Z�[�W���������Ă��Ȃ��Ƃ�
		else {
			// �`��J�n
			if (SUCCEEDED(direct3d.pDevice3D->BeginScene()))
			{
				DWORD ClearColor = 0xff000000;	// �w�i�N���A�F
				// �w�i�N���A
				direct3d.pDevice3D->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER, ClearColor, 1.0f, 0);

				//�L�[���͂𓾂�
				GetKeyboardState(key);
				if (timer % 5 == 0) {
					view->awaitingInput(key);
					timer = 0;
				}
				// �e��f�[�^�̍X�V
				model->update();

				// ��ʕ`��
				if (view->getscene() == model->TITLE){
					model->get_chara()->set_Active(false);
					model->get_boss_enemy()->set_Active(false);
					for (int i = 0; i < 20; i++) {
						model->get_enemy_list()->get_enemy(i)->set_Active(false);
					}
					for (int i = 0; i < 50; i++) {
						model->get_bullet_list()->get_bullet(i)->set_Active(false);
					}
					for (int i = 0; i < 50; i++) {
						model->get_enemy_bullet_list()->get_bullet(i)->set_Active(false);
					}
				}
				if (view->getscene() == model->MAP) {
					model->get_chara()->set_Active(false);
					model->get_boss_enemy()->set_Active(false);
					for (int i = 0; i < 20; i++) {
						model->get_enemy_list()->get_enemy(i)->set_Active(false);
					}
					for (int i = 0; i < 50; i++) {
						model->get_bullet_list()->get_bullet(i)->set_Active(false);
					}
					for (int i = 0; i < 50; i++) {
						model->get_enemy_bullet_list()->get_bullet(i)->set_Active(false);
					}
					
				}
				if (view->getscene() == model->SHOOTING) {
					model->get_chara()->set_Active(true);
				}
				if (view->getscene() == model->PAUSE) {
					text.Draw(0xffff0000, 240, 200, _T("---PAUSE---"));
				}

				chara->update(direct3d.pDevice3D, charatex.pTexture, false);
				boss->update(direct3d.pDevice3D, bosstex.pTexture, false);
				for (int i = 0; i < 20; i++) {
					enemies[i]->update(direct3d.pDevice3D, enemytex.pTexture, false);
				}
				for (int i = 0; i < 50; i++) {
					bullets[i]->update(direct3d.pDevice3D, bullettex.pTexture, false);
				}
				for (int i = 0; i < 50; i++) {
					enemy_bullets[i]->update(direct3d.pDevice3D, ebullettex.pTexture, false);
				}

				// �����`�� �f�o�b�O�p�o�͊܂�
				//text.Draw(0xffff0000, 500, 0, _T("scene : %.d\n"),view->getscene());
				//text.Draw(0xffff0000, 500, 64, _T("deap : %.d\n"), model->get_deapth());
				//text.Draw(0xffff0000, 500, 32, _T("eve : %.d\n"), model->get_map()->get_current_node()->get_event());
				//text.Draw(0xffff0000, 0, 0, _T("time : %.d\n"), view->get_Model()->get_timer());
				text.Draw(0xffff0000, 0, 0, _T("level : %.d\n"), model->get_chara()->get_level());
				text.Draw(0xffff2ede, 0, 32, _T("health : %.d\n"), model->get_chara()->get_health());
				text.Draw(0xff00ff73, 0, 64, _T("bomb : %.d\n"), model->get_chara()->get_bomb());
				//text.Draw(0xffff0000, 0, 32, _T("map : levent = %.d\n"), model->get_map()->get_current_node()->get_left_node()->get_event());
				//text.Draw(0xffff0000, 0, 64, _T("map : mevent = %.d\n"), model->get_map()->get_current_node()->get_middle_node()->get_event());
				//text.Draw(0xffff0000, 0, 128, _T("map : revent = %.d\n"), model->get_map()->get_current_node()->get_right_node()->get_event());
				//text.Draw(0xffff0000, 0, 160, _T("map : mapp = %.d\n"), model->get_map_p());
				//text.Draw(0xffff0000, 0, 32, _T("map : event = %.d\n"), model->get_map()->get_current_node()->get_event());
				//text.Draw(0xffff0000, 0, 64, _T("map : event = %.d\n"), model->get_stage()->get_event_id());
				//text.Draw(0xffff0000, 0, 32, _T("chara_obj : x = %.1f y = %.1f\n"), model->get_chara()->get_pos_x(), model->get_chara()->get_pos_y());
				//text.Draw(0xffff0000, 0, 64, _T("chara_img : x = %.1f y = %.1f\n"), chara->pos.x, chara->pos.y);
				//text.Draw(0xffff0000, 0, 32, _T("bullet[0]_obj : x = %.1f y = %.1f\n"), model->get_bullet_list()->get_bullet(0)->get_pos_x(), model->get_bullet_list()->get_bullet(0)->get_pos_y());
				//text.Draw(0xffff0000, 0, 64, _T("bullet[0]_img : x = %.1f y = %.1f\n"), bullets[0]->pos.x, bullets[0]->pos.y);
				//text.Draw(0xffff0000, 0, 32, _T("boss_HP : %.1f"), model->get_boss_enemy()->get_health());
				//text.Draw(0xffff0000, 0, 64, _T("boss : x = %.1f y = %.1f\n"), model->get_boss_enemy()->get_pos_x(), model->get_boss_enemy()->get_pos_x());
				
				//text.Draw(0xffff0000, 0, 96, _T(view->gettext().c_str()));
				text.Draw(0xffff0000, 500, 448, _T(fr.update()->c_str()));
				text.Draw(0xffff0000, 16, 364, _T(model->get_textbox().c_str()));
				//view->title_text(0,text);
				int i = view->get_Model()->get_title_p();
				if (view->get_Model()->getscene()== view->get_Model()->TITLE) {
					//������ʂ̕`��
					if (i == 0) {
						text.Draw(0xff808000, 0, 416, _T("start\n"));
					}
					else {
						text.Draw(0xffffffff, 0, 416, _T("start\n"));
					}
					if (i == 1) {
						text.Draw(0xff808000, 0, 448, _T("score\n"));
					}
					else {
						text.Draw(0xffffffff, 0, 448, _T("score\n"));
					}
				}
				if (view->getscene() == model->MAP) {
					Mapnode* m = model->get_map()->get_current_node();
					if (m->get_left_node() != nullptr) {
						if (model->get_map_p() == 0) {
							text.Draw(0xff808000, 16, 224, _T(u8"��"));
						}
						else {
							text.Draw(0xffffffff, 16, 224, _T(u8"��"));
						}
					}
					else {
						text.Draw(0xff000000, 16, 224, _T(u8"��"));
					}
					if (m->get_middle_node() != nullptr) {
						if (model->get_map_p() == 1) {
							text.Draw(0xff808000, 270, 224, _T(u8"�܂�����"));
						}
						else {
							text.Draw(0xffffffff, 270, 224, _T(u8"�܂�����"));
						}
					}
					else {
						text.Draw(0xff000000, 270, 224, _T(u8"�܂�����"));
					}
					if (m->get_right_node() != nullptr) {
						if (model->get_map_p() == 2) {
							text.Draw(0xff808000, 600, 224, _T(u8"�E"));
						}
						else {
							text.Draw(0xffffffff, 600, 224, _T(u8"�E"));
						}
					}
					else {
						text.Draw(0xff000000, 600, 224, _T(u8"�E"));
					}
				}
				if (view->getscene() == model->SHOOTING) {
					if (model->get_stage()->get_area_scene() == 0) {
						text.Draw(0xffff0000, 200, 200, _T(model->get_stage()->get_title()));
					}
					if (model->get_stage()->get_area_scene() == 3) {
						text.Draw(0xffffffff, 16, 224, _T(u8"�O"));
						text.Draw(0xffffffff, 600, 224, _T(u8"��"));
						text.Draw(0xff808000, 160, 200, _T(model->get_itemname().c_str()));
						text.Draw(0xff808000, 160, 264, _T(model->get_itemtext().c_str()));
						text.Draw(0xffffffff, 16, 332, _T(model->get_textpeople().c_str()));
					}
					if (model->get_stage()->get_area_scene() == 4) {
						text.Draw(0xff808000, 160, 200, _T(model->get_itemname().c_str()));
						text.Draw(0xff808000, 160, 264, _T(model->get_itemtext().c_str()));
						text.Draw(0xff808000, 300, 264, _T(model->get_itemprice().c_str()));
						text.Draw(0xffffffff, 16, 332, _T(model->get_textpeople().c_str()));
						if (model->get_stage()->get_pointer_2(0)==0) {
							text.Draw(0xff808000, 420, 320, _T(u8"���"));
							text.Draw(0xffffffff, 500, 320, _T(u8"���Ȃ�"));
						}
						else{
							text.Draw(0xffffffff, 420, 320, _T(u8"���"));
							text.Draw(0xff808000, 500, 320, _T(u8"���Ȃ�"));
						}
					}
					if (model->get_stage()->get_area_scene() == 5) {
						text.Draw(0xffff0000, 200, 200, _T(u8"�X�e�[�W�N���A!!"));
					}
				}
				// �`��I��
				direct3d.pDevice3D->EndScene();
			}
			// �`�攽�f
			direct3d.pDevice3D->Present(NULL, NULL, NULL, NULL);
			timer++;
			
			//60fps�ɂȂ�悤�ɃX���b�h�ҋ@
			end = currentTimeMicro();
			if (end < next) {
				//�X�V���Ԃ܂őҋ@
				std::this_thread::sleep_for(std::chrono::microseconds(next - end));

				//���̍X�V���Ԃ��v�Z(1�b/�t���[�����[�g���Z)
				next += (1000 * 1000 / FPS);
			}
			else {
				//�X�V���Ԃ��߂����ꍇ�͌��ݎ������玟�̍X�V���Ԃ��v�Z
				next = end + (1000 * 1000 / FPS);
			}
		}
	}

	return 0;
}
View::View(){}
View::~View(){}
void View::title_text(int i,DirectXText t) {
	if (i == 0) {
		t.Draw(0xff808000, 0, 384, _T("start\n"));
	}
	else {
		t.Draw(0xffffffff, 0, 384, _T("start\n"));
	}
	if (i == 0) {
		t.Draw(0xff808000, 0, 416, _T("scoret\n"));
	}
	else {
		t.Draw(0xffffffff, 0, 416, _T("score\n"));
	}
	if (i == 0) {
		t.Draw(0xff808000, 0, 448, _T("quit\n"));
	}
	else {
		t.Draw(0xffffffff, 0, 448, _T("quit\n"));
	}
}
void View::setModel(Model* m) {
	model = m;
}
void View::awaitingInput(BYTE* K) {
	bool move = false; 
	if (K[VK_SHIFT] & 0x80) {
		std::cout << "shift�L�[��������܂���" << std::endl;
		model->setSignal(model->down_SHIFT);
		std::cout << text << std::endl;
	}
	if (K[VK_SPACE] & 0x80) {
		std::cout << "�X�y�[�X�L�[��������܂���" << std::endl;
	}
	if (K[VK_RETURN] & 0x80) {
		std::cout << "�G���^�[�L�[��������܂���" << std::endl;
		model->setSignal(model->down_ENTER);
		std::cout << text << std::endl;
	}
	if (K[VK_ESCAPE] & 0x80) {
		std::cout << "esc�L�[��������܂���" << std::endl;
		model->setSignal(model->down_ESCAPE);
	}
	if (K[VK_LEFT] & 0x80) {
		std::cout << "���L�[��������܂���" << std::endl;
		model->setSignal(model->down_LEFT);
		move = true;
	}
	if (K[VK_UP] & 0x80) {
		std::cout << "��L�[��������܂���" << std::endl;
		model->setSignal(model->down_UP);
		move = true;
	}
	if (K[VK_RIGHT] & 0x80) {
		std::cout << "�E�L�[��������܂���" << std::endl;
		model->setSignal(model->down_RIGHT);
		move = true;
	}
	if (K[VK_DOWN] & 0x80) {
		std::cout << "���L�[��������܂���" << std::endl;
		model->setSignal(model->down_DOWN);
		move = true;
	}
	if (K[0x41] & 0x80) {
		std::cout << "a�L�[��������܂���" << std::endl;
		model->setSignal(model->down_A);
	}
	if (K[0x42] & 0x80) {
		std::cout << "b�L�[��������܂���" << std::endl;
		model->setSignal(model->down_B);
	}
	if (K[0x43] & 0x80) {
		std::cout << "c�L�[��������܂���" << std::endl;
		model->setSignal(model->down_C);
	}
	if (K[0x44] & 0x80) {
		std::cout << "d�L�[��������܂���" << std::endl;
		model->setSignal(model->down_D);
	}
	if (K[0x45] & 0x80) {
		std::cout << "e�L�[��������܂���" << std::endl;
		model->setSignal(model->down_E);
	}
	if (K[0x46] & 0x80) {
		std::cout << "f�L�[��������܂���" << std::endl;
		model->setSignal(model->down_F);
	}
	if (K[0x47] & 0x80) {
		std::cout << "g�L�[��������܂���" << std::endl;
		model->setSignal(model->down_G);
	}
	if (K[0x48] & 0x80) {
		std::cout << "h�L�[��������܂���" << std::endl;
		model->setSignal(model->down_H);
	}
	if (K[0x49] & 0x80) {
		std::cout << "i�L�[��������܂���" << std::endl;
		model->setSignal(model->down_I);
	}
	if (K[0x4A] & 0x80) {
		std::cout << "j�L�[��������܂���" << std::endl;
		model->setSignal(model->down_J);
	}
	if (K[0x4B] & 0x80) {
		std::cout << "k�L�[��������܂���" << std::endl;
		model->setSignal(model->down_K);
	}
	if (K[0x4C] & 0x80) {
		std::cout << "l�L�[��������܂���" << std::endl;
		model->setSignal(model->down_L);
	}
	if (K[0x4D] & 0x80) {
		std::cout << "m�L�[��������܂���" << std::endl;
		model->setSignal(model->down_M);
	}
	if (K[0x4E] & 0x80) {
		std::cout << "n�L�[��������܂���" << std::endl;
		model->setSignal(model->down_N);
	}
	if (K[0x4F] & 0x80) {
		std::cout << "o�L�[��������܂���" << std::endl;
		model->setSignal(model->down_O);
	}
	if (K[0x50] & 0x80) {
		std::cout << "p�L�[��������܂���" << std::endl;
		model->setSignal(model->down_P);
	}
	if (K[0x51] & 0x80) {
		std::cout << "q�L�[��������܂���" << std::endl;
		model->setSignal(model->down_Q);
	}
	if (K[0x52] & 0x80) {
		std::cout << "r�L�[��������܂���" << std::endl;
		model->setSignal(model->down_R);
	}
	if (K[0x53] & 0x80) {
		std::cout << "s�L�[��������܂���" << std::endl;
		model->setSignal(model->down_S);
	}
	if (K[0x54] & 0x80) {
		std::cout << "t�L�[��������܂���" << std::endl;
		model->setSignal(model->down_T);
	}
	if (K[0x55] & 0x80) {
		std::cout << "u�L�[��������܂���" << std::endl;
		model->setSignal(model->down_U);
	}
	if (K[0x56] & 0x80) {
		std::cout << "v�L�[��������܂���" << std::endl;
		model->setSignal(model->down_V);
	}
	if (K[0x57] & 0x80) {
		std::cout << "w�L�[��������܂���" << std::endl;
		model->setSignal(model->down_W);
	}
	if (K[0x58] & 0x80) {
		std::cout << "x�L�[��������܂���" << std::endl;
		model->setSignal(model->down_X);
	}
	if (K[0x59] & 0x80) {
		std::cout << "y�L�[��������܂���" << std::endl;
		model->setSignal(model->down_Y);
	}
	if (K[0x5A] & 0x80) {
		std::cout << "z�L�[��������܂���" << std::endl;
		model->setSignal(model->down_Z);
	}
	if (!move) {
		model->setSignal(0xffff);
	}
	return;
}
void View::settext(std::string str) {
	text = str;
}
std::string View::gettext(){
	return text;
}
int View::getscene() {
	return model->getscene();
}
Model* View::get_Model(){
	return model;
}