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

class Sprite
{
public:
	// 板ポリゴン頂点情報
	struct Vertex {
		float x, y, z;// 3次元座標
		float rhw;	// 2D変換済みフラグ
		float u, v;	// UV座標
	};
	// FVF（柔軟な頂点構造体宣言）フラグ
	static const DWORD SPRITE_FVF = D3DFVF_XYZRHW | D3DFVF_TEX1;

	// スプライト位置
	D3DXVECTOR2 pos;
	// スプライトサイズ
	int width;
	int height;
	// 回転値（ラジアン）
	float rotate;

	// コンストラクタ
	Sprite();
	// デストラクタ
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