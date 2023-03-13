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

#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <stdio.h>

class DirectXText
{
private:
	ID3DXFont * pFont;	// Direct3D�t�H���g
	RECT				Rect;	// �`��̈�
	std::vector<TCHAR>	Buf;	// ������o�b�t�@
public:

	// �R���X�g���N�^
	DirectXText();
	// �f�X�g���N�^
	virtual ~DirectXText();

	// DirectX�t�H���g�쐬
	bool Create(IDirect3DDevice9* pD3DDevice, int FontHeight = 16);

	// ������̕`��
	void Draw(DWORD Color, int x, int y, const TCHAR* Str, ...);
};