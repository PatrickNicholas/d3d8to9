/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#include "d3dx9.hpp"
#include "d3d8to9.hpp"

//PFN_D3DXAssembleShader D3DXAssembleShader = nullptr;
//PFN_D3DXDisassembleShader D3DXDisassembleShader = nullptr;
//PFN_D3DXLoadSurfaceFromSurface D3DXLoadSurfaceFromSurface = nullptr;

#ifndef D3D8TO9NOLOG
 // Very simple logging for the purpose of debugging only.
std::ofstream LOG;
#endif

extern "C" D3D8TO9_API IDirect3D8 *WINAPI Direct3DCreate8(UINT SDKVersion)
{
#ifndef D3D8TO9NOLOG
	static bool LogMessageFlag = true;

	if (!LOG.is_open())
	{
		LOG.open("d3d8.log", std::ios::trunc);
	}

	if (!LOG.is_open() && LogMessageFlag)
	{
		LogMessageFlag = false;
		MessageBox(nullptr, TEXT("Failed to open debug log file \"d3d8.log\"!"), nullptr, MB_ICONWARNING);
	}

	LOG << "Redirecting '" << "Direct3DCreate8" << "(" << SDKVersion << ")' ..." << std::endl;
	LOG << "> Passing on to 'Direct3DCreate9':" << std::endl;
#endif

	IDirect3D9 *const d3d = Direct3DCreate9(D3D_SDK_VERSION);

	if (d3d == nullptr)
	{
		return nullptr;
	}

	// Load D3DX
//	if (!D3DXAssembleShader || !D3DXDisassembleShader || !D3DXLoadSurfaceFromSurface)
//	{
//		const HMODULE module = LoadLibrary(TEXT("d3dx9_43.dll"));
//
//		if (module != nullptr)
//		{
//			D3DXAssembleShader = reinterpret_cast<PFN_D3DXAssembleShader>(GetProcAddress(module, "D3DXAssembleShader"));
//			D3DXDisassembleShader = reinterpret_cast<PFN_D3DXDisassembleShader>(GetProcAddress(module, "D3DXDisassembleShader"));
//			D3DXLoadSurfaceFromSurface = reinterpret_cast<PFN_D3DXLoadSurfaceFromSurface>(GetProcAddress(module, "D3DXLoadSurfaceFromSurface"));
//		}
//		else
//		{
//#ifndef D3D8TO9NOLOG
//			LOG << "Failed to load d3dx9_43.dll! Some features will not work correctly." << std::endl;
//#endif
//			if (MessageBox(nullptr, TEXT(
//				"Failed to load d3dx9_43.dll! Some features will not work correctly.\n\n"
//				"It's required to install the \"Microsoft DirectX End-User Runtime\" in order to use d3d8to9.\n\n"
//				"Please click \"OK\" to open the official download page or \"CANCEL\" to continue anyway."), nullptr, MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND | MB_OKCANCEL | MB_DEFBUTTON1) == IDOK)
//			{
//				ShellExecute(nullptr, TEXT("open"), TEXT("https://www.microsoft.com/download/details.aspx?id=35"), nullptr, nullptr, SW_SHOW);
//
//				return nullptr;
//			}
//		}
//	}

	return new Direct3D8(d3d);
}

D3D8TO9_API HRESULT WINAPI
D3DXCreateTextureFromFileInMemoryEx(
	LPDIRECT3DDEVICE8         pDevice,
	LPCVOID                   pSrcData,
	UINT                      SrcDataSize,
	UINT                      Width,
	UINT                      Height,
	UINT                      MipLevels,
	DWORD                     Usage,
	D3DFORMAT                 Format,
	D3DPOOL                   Pool,
	DWORD                     Filter,
	DWORD                     MipFilter,
	D3DCOLOR                  ColorKey,
	D3DXIMAGE_INFO* pSrcInfo,
	PALETTEENTRY* pPalette,
	LPDIRECT3DTEXTURE8* ppTexture) {
	LPDIRECT3DTEXTURE9 pTexture9 = NULL;
	auto pDevice8 = dynamic_cast<Direct3DDevice8*>(pDevice);
	HRESULT hr = D3DXCreateTextureFromFileInMemoryEx(
		pDevice8->GetProxyInterface(),
		pSrcData,
		SrcDataSize,
		Width, Height,
		MipLevels,
		Usage,
		Format,
		Pool,
		Filter,
		MipFilter,
		ColorKey,
		pSrcInfo,
		pPalette,
		&pTexture9
	);
	if (SUCCEEDED(hr) && ppTexture != NULL) {
		*ppTexture = new Direct3DTexture8(pDevice8, pTexture9);
	}
	return hr;
}

D3D8TO9_API HRESULT WINAPI
D3DXCreateTexture(
	LPDIRECT3DDEVICE8         pDevice,
	UINT                      Width,
	UINT                      Height,
	UINT                      MipLevels,
	DWORD                     Usage,
	D3DFORMAT                 Format,
	D3DPOOL                   Pool,
	LPDIRECT3DTEXTURE8* ppTexture) {
	LPDIRECT3DTEXTURE9 pTexture9 = NULL;
	auto pDevice8 = dynamic_cast<Direct3DDevice8*>(pDevice);
	HRESULT hr = D3DXCreateTexture(
		pDevice8->GetProxyInterface(),
		Width, Height,
		MipLevels,
		Usage,
		Format,
		Pool,
		&pTexture9
	);
	if (SUCCEEDED(hr) && ppTexture != NULL) {
		*ppTexture = new Direct3DTexture8(pDevice8, pTexture9);
	}
	return hr;
}

D3D8TO9_API HRESULT WINAPI
D3DXCreateTextureFromFileExA(
	LPDIRECT3DDEVICE8         pDevice,
	LPCSTR                    pSrcFile,
	UINT                      Width,
	UINT                      Height,
	UINT                      MipLevels,
	DWORD                     Usage,
	D3DFORMAT                 Format,
	D3DPOOL                   Pool,
	DWORD                     Filter,
	DWORD                     MipFilter,
	D3DCOLOR                  ColorKey,
	D3DXIMAGE_INFO* pSrcInfo,
	PALETTEENTRY* pPalette,
	LPDIRECT3DTEXTURE8* ppTexture) {
	LPDIRECT3DTEXTURE9 pTexture9 = NULL;
	auto pDevice8 = dynamic_cast<Direct3DDevice8*>(pDevice);
	HRESULT hr = D3DXCreateTextureFromFileExA(
		pDevice8->GetProxyInterface(),
		pSrcFile,
		Width, Height,
		MipLevels,
		Usage,
		Format,
		Pool,
		Filter,
		MipFilter,
		ColorKey,
		pSrcInfo,
		pPalette,
		&pTexture9
	);
	if (SUCCEEDED(hr) && ppTexture != NULL) {
		*ppTexture = new Direct3DTexture8(pDevice8, pTexture9);
	}
	return hr;
}

D3D8TO9_API HRESULT WINAPI
D3DXCreateTextureFromFileExW(
	LPDIRECT3DDEVICE8         pDevice,
	LPCWSTR                   pSrcFile,
	UINT                      Width,
	UINT                      Height,
	UINT                      MipLevels,
	DWORD                     Usage,
	D3DFORMAT                 Format,
	D3DPOOL                   Pool,
	DWORD                     Filter,
	DWORD                     MipFilter,
	D3DCOLOR                  ColorKey,
	D3DXIMAGE_INFO* pSrcInfo,
	PALETTEENTRY* pPalette,
	LPDIRECT3DTEXTURE8* ppTexture) {
	LPDIRECT3DTEXTURE9 pTexture9 = NULL;
	auto pDevice8 = dynamic_cast<Direct3DDevice8*>(pDevice);
	HRESULT hr = D3DXCreateTextureFromFileExW(
		pDevice8->GetProxyInterface(),
		pSrcFile,
		Width, Height,
		MipLevels,
		Usage,
		Format,
		Pool,
		Filter,
		MipFilter,
		ColorKey,
		pSrcInfo,
		pPalette,
		&pTexture9
	);
	if (SUCCEEDED(hr) && ppTexture != NULL) {
		*ppTexture = new Direct3DTexture8(pDevice8, pTexture9);
	}
	return hr;
}

D3D8TO9_API HRESULT WINAPI
D3DXSaveTextureToFileA(
	LPCSTR                    pDestFile,
	D3DXIMAGE_FILEFORMAT      DestFormat,
	LPDIRECT3DBASETEXTURE8    pSrcTexture,
	CONST PALETTEENTRY* pSrcPalette) {
	if (auto texture = dynamic_cast<Direct3DTexture8*>(pSrcTexture)) {
		return D3DXSaveTextureToFileA(
			pDestFile,
			DestFormat,
			texture->GetProxyInterface(),
			pSrcPalette
		);
	}
	else if (auto texture = dynamic_cast<Direct3DCubeTexture8*>(pSrcTexture)) {
		return D3DXSaveTextureToFileA(
			pDestFile,
			DestFormat,
			texture->GetProxyInterface(),
			pSrcPalette
		);
	}
	else if (auto texture = dynamic_cast<Direct3DVolumeTexture8*>(pSrcTexture)) {
		return D3DXSaveTextureToFileA(
			pDestFile,
			DestFormat,
			texture->GetProxyInterface(),
			pSrcPalette
		);
	}
	else {
		return -1;
	}
}

D3D8TO9_API HRESULT WINAPI
D3DXSaveTextureToFileW(
	LPCWSTR                   pDestFile,
	D3DXIMAGE_FILEFORMAT      DestFormat,
	LPDIRECT3DBASETEXTURE8    pSrcTexture,
	CONST PALETTEENTRY* pSrcPalette) {
	if (auto texture = dynamic_cast<Direct3DTexture8*>(pSrcTexture)) {
		return D3DXSaveTextureToFileW(
			pDestFile,
			DestFormat,
			texture->GetProxyInterface(),
			pSrcPalette
		);
	}
	else if (auto texture = dynamic_cast<Direct3DCubeTexture8*>(pSrcTexture)) {
		return D3DXSaveTextureToFileW(
			pDestFile,
			DestFormat,
			texture->GetProxyInterface(),
			pSrcPalette
		);
	}
	else if (auto texture = dynamic_cast<Direct3DVolumeTexture8*>(pSrcTexture)) {
		return D3DXSaveTextureToFileW(
			pDestFile,
			DestFormat,
			texture->GetProxyInterface(),
			pSrcPalette
		);
	}
	else {
		return -1;
	}
}