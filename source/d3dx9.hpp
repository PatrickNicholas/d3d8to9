#pragma once

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <d3d9.h>
#include <d3dx9.h>

// #define D3DX_FILTER_NONE 1

//#define D3DXASM_DEBUG 0x0001
//#define D3DXASM_SKIPVALIDATION  0x0010
//
//#ifdef NDEBUG
//#define D3DXASM_FLAGS  0
//#else
//#define D3DXASM_FLAGS D3DXASM_DEBUG
//#endif // NDEBUG
//
//struct D3DXMACRO
//{
//	LPCSTR Name;
//	LPCSTR Definition;
//};
//
//typedef interface ID3DXBuffer *LPD3DXBUFFER;
//typedef interface ID3DXInclude *LPD3DXINCLUDE;
//
//DECLARE_INTERFACE_(ID3DXBuffer, IUnknown)
//{
//	// IUnknown
//	STDMETHOD(QueryInterface)(THIS_ REFIID iid, LPVOID *ppv) PURE;
//	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
//	STDMETHOD_(ULONG, Release)(THIS) PURE;
//
//	// ID3DXBuffer
//	STDMETHOD_(LPVOID, GetBufferPointer)(THIS) PURE;
//	STDMETHOD_(DWORD, GetBufferSize)(THIS) PURE;
//};
#define D3DXASM_DEBUG 0x0001
//#define D3DXASM_SKIPVALIDATION  0x0010
//
#ifdef NDEBUG
#define D3DXASM_FLAGS  0
#else
#define D3DXASM_FLAGS D3DXASM_DEBUG
#endif // NDEBUG
//
//struct D3DXMACRO
//{
//	LPCSTR Name;
//	LPCSTR Definition;
//};
//
//typedef interface ID3DXBuffer *LPD3DXBUFFER;
//typedef interface ID3DXInclude *LPD3DXINCLUDE;
//
//DECLARE_INTERFACE_(ID3DXBuffer, IUnknown)
//{
//	// IUnknown
//	STDMETHOD(QueryInterface)(THIS_ REFIID iid, LPVOID *ppv) PURE;
//	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
//	STDMETHOD_(ULONG, Release)(THIS) PURE;
//
//	// ID3DXBuffer
//	STDMETHOD_(LPVOID, GetBufferPointer)(THIS) PURE;
//	STDMETHOD_(DWORD, GetBufferSize)(THIS) PURE;
//};
//
//typedef HRESULT(WINAPI *PFN_D3DXAssembleShader)(LPCSTR pSrcData, UINT SrcDataLen, const D3DXMACRO *pDefines, LPD3DXINCLUDE pInclude, DWORD Flags, LPD3DXBUFFER *ppShader, LPD3DXBUFFER *ppErrorMsgs);
//typedef HRESULT(WINAPI *PFN_D3DXDisassembleShader)(const DWORD *pShader, BOOL EnableColorCode, LPCSTR pComments, LPD3DXBUFFER *ppDisassembly);
//typedef HRESULT(WINAPI *PFN_D3DXLoadSurfaceFromSurface)(LPDIRECT3DSURFACE9 pDestSurface, const PALETTEENTRY *pDestPalette, const RECT *pDestRect, LPDIRECT3DSURFACE9 pSrcSurface, const PALETTEENTRY *pSrcPalette, const RECT *pSrcRect, DWORD Filter, D3DCOLOR ColorKey);
//
//extern PFN_D3DXAssembleShader D3DXAssembleShader;
//extern PFN_D3DXDisassembleShader D3DXDisassembleShader;
//extern PFN_D3DXLoadSurfaceFromSurface D3DXLoadSurfaceFromSurface;
//
//typedef enum _D3DXIMAGE_FILEFORMAT
//{
//	D3DXIFF_BMP = 0,
//	D3DXIFF_JPG = 1,
//	D3DXIFF_TGA = 2,
//	D3DXIFF_PNG = 3,
//	D3DXIFF_DDS = 4,
//	D3DXIFF_PPM = 5,
//	D3DXIFF_DIB = 6,
//	D3DXIFF_HDR = 7,       //high dynamic range formats
//	D3DXIFF_PFM = 8,       //
//	D3DXIFF_FORCE_DWORD = 0x7fffffff
//
//} D3DXIMAGE_FILEFORMAT;
//
//typedef struct _D3DXIMAGE_INFO
//{
//	UINT                    Width;
//	UINT                    Height;
//	UINT                    Depth;
//	UINT                    MipLevels;
//	D3DFORMAT               Format;
//	D3DRESOURCETYPE         ResourceType;
//	D3DXIMAGE_FILEFORMAT    ImageFileFormat;
//
//} D3DXIMAGE_INFO;
