#pragma once
// Direct3Dに必要なヘッダーとライブラリ 

#define D3D_DEBUG_INFO	// Direct3Dデバックフラグ

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
	// コンストラクタ
	Texture();
	// デストラクタ
	~Texture();
	// 画像データ読み込み
	bool Load(IDirect3DDevice9* pDevice3D, const char* FileName);
};