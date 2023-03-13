#pragma once
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

// Direct3D�N���X
class Direct3D
{
public:
	IDirect3D9 * pD3D9;			// Direct3D�f�o�C�X�����p�I�u�W�F�N�g
	IDirect3DDevice9*		pDevice3D;		// Direct3D�̃f�o�C�X

											// �R���X�g���N�^
	Direct3D();
	// �f�X�g���N�^
	~Direct3D();

	// �f�o�C�X�쐬
	bool Create(HWND hWnd, int Width, int Height);
};