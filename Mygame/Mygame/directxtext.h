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

#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <stdio.h>

class DirectXText
{
private:
	ID3DXFont * pFont;	// Direct3Dフォント
	RECT				Rect;	// 描画領域
	std::vector<TCHAR>	Buf;	// 文字列バッファ
public:

	// コンストラクタ
	DirectXText();
	// デストラクタ
	virtual ~DirectXText();

	// DirectXフォント作成
	bool Create(IDirect3DDevice9* pD3DDevice, int FontHeight = 16);

	// 文字列の描画
	void Draw(DWORD Color, int x, int y, const TCHAR* Str, ...);
};