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

class Texture
{
public:
	IDirect3DTexture9 * pTexture;
	// �R���X�g���N�^
	Texture();
	// �f�X�g���N�^
	~Texture();
	// �摜�f�[�^�ǂݍ���
	bool Load(IDirect3DDevice9* pDevice3D, const char* FileName);
};