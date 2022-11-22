#pragma once
#include "Systems/IExcute.h"

class Main : public IExcute {
public:
	virtual void Initialize() override;
	virtual void Destroy() override;

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

	virtual void ResizeScreen() override;

private:
	void Push(IExcute* excute);

private:
	vector<IExcute*> excutes;

private:
	UINT g_Width;
	UINT g_Height;
	HWND g_Hwnd;
	LPCTSTR g_Title;

};