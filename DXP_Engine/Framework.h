#pragma once

// Window
#include <Windows.h>
#include <assert.h>

// Standard Library
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <functional>
#include <thread>
#include <mutex>

using namespace std;

// DX12 Library
#include <d3d11.h>
#include <D3DX11.h>
#include <D3DX10.h>
#include <D3DX10math.h>
#include <D3Dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")
#pragma comment(lib, "d3dcompiler.lib")

// FMOD
#include <fmod.hpp>
//#pragma comment(lib, "fmod_vc.lib")

// ImGui
#include <ImGui\imgui.h>
#include <ImGui\imgui_impl_dx12.h>
#include <ImGui\imgui_impl_win32.h>


// Framework Headers
#include <Systems\D3D.h>
