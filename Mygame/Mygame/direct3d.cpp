#include "direct3d.h"

// コンストラクタ
Direct3D::Direct3D() {
	pD3D9 = NULL;
	pDevice3D = NULL;
}
// デストラクタ
Direct3D::~Direct3D() {
	// DirectXの変数は必ず後処理をすること
	if (pDevice3D != NULL)
		pDevice3D->Release();
	if (pD3D9 != NULL)
		pD3D9->Release();
}


// デバイス作成
bool Direct3D::Create(HWND hWnd, int Width, int Height) {

	// Direct3D9オブジェクトの作成	
	pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	// ディスプレイ情報取得
	D3DDISPLAYMODE Display;
	pD3D9->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &Display);

	D3DPRESENT_PARAMETERS	D3DParam = {			// スワップチェイン設定
		Width,Height,Display.Format,1,D3DMULTISAMPLE_NONE,0,
		D3DSWAPEFFECT_DISCARD,hWnd,TRUE,TRUE,D3DFMT_D24S8,0,0,D3DPRESENT_INTERVAL_DEFAULT
	};

	// HALモードで3Dデバイス作成
	if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DParam.hDeviceWindow,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &pDevice3D)))
		if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DParam.hDeviceWindow,
			D3DCREATE_MIXED_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &pDevice3D)))
			// REFモードで3Dデバイス作成
			if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, D3DParam.hDeviceWindow,
				D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &pDevice3D)))
				if (FAILED(pD3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, D3DParam.hDeviceWindow,
					D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &D3DParam, &pDevice3D)))
				{
					// 3Dデバイス作成失敗(このグラフィックボードではDirectXが使えない)
					pD3D9->Release();
					return false;
				}

	return true;
}