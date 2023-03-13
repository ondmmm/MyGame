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

class Sprite
{
public:
	// �|���S�����_���
	struct Vertex {
		float x, y, z;// 3�������W
		float rhw;	// 2D�ϊ��ς݃t���O
		float u, v;	// UV���W
	};
	// FVF�i�_��Ȓ��_�\���̐錾�j�t���O
	static const DWORD SPRITE_FVF = D3DFVF_XYZRHW | D3DFVF_TEX1;

	// �X�v���C�g�ʒu
	D3DXVECTOR2 pos;
	// �X�v���C�g�T�C�Y
	int width;
	int height;
	// ��]�l�i���W�A���j
	float rotate;

	// �R���X�g���N�^
	Sprite();
	// �f�X�g���N�^
	~Sprite();

	void SetPos(float x, float y);
	void SetWidth(int Width, int Height);
	void SetRotate(float Rotate);
	void UpdatePos(float x, float y);
	void UpdateRotate(float Rotate);
	void Draw(IDirect3DDevice9* pDevice3D, IDirect3DTexture9* pTexture, bool isTurn = false);
	float getcenterx();
	float getcentery();
};
bool IsHitTest(const Sprite& sprite1, const Sprite& sprite2);