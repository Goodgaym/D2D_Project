#pragma once

struct D3DDesc {
	LPCTSTR Appname;
	HINSTANCE Instance;
	HWND Handle;
	float Width;
	float Height;
	bool bVsync;
	bool bFullScreen;
	D3DXCOLOR Background;
};

class D3D {
public:
	static D3D& instance();

	static void Create();
	static void Delete();

	static ID3D11Device* GetDevice();
	static ID3D11DeviceContext* GetDC();
	static IDXGISwapChain* GetSwapChain();
	static const HWND& GetHandle();

public:
	void SetRenderTarget(ID3D11RenderTargetView* rtv = nullptr, ID3D11DepthStencilView* dsv = nullptr);

	void Clear(D3DXCOLOR color = D3DXCOLOR(0xFFFFFFFF), ID3D11RenderTargetView* rtv = nullptr, ID3D11DepthStencilView* dsv = nullptr);
	void Present();

	void ResizeScreen(float width, float height);

	ID3D11DepthStencilView* DSV() { return depthStencilView; }

private:
	D3D() {};
	~D3D() {};
	
	void CreateSwapChainAndDevice();

	void CreateBackBuffer(float width, float height);
	void DeleteBackBuffer();

public:
	static D3DDesc d3dDesc;

// Static Private
private:
	static D3D* instance;

	static ID3D11Device* device;
	static ID3D11DeviceContext deviceContext;
	static IDXGISwapChain* swapChain;

// 
private:
	ID3D11Texture2D* backBuffer;
	ID3D11DepthStencilView* depthStencilView;
	ID3D11RenderTargetView* renderTargetView;

};