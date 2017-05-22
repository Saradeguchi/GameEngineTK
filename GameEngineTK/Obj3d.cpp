#include "Obj3d.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//静的メンバ変数の実体
//デバイス
Microsoft::WRL::ComPtr<ID3D11Device>           obj3d::m_d3dDevice;
//デバイスコンテキスト
Microsoft::WRL::ComPtr<ID3D11DeviceContext>     obj3d::m_d3dContext;
//カメラ
Camera* obj3d::m_Camera;
//汎用描画ステート
std::unique_ptr<DirectX::CommonStates> obj3d::m_states;

//エフェクトファクトリー
std::unique_ptr<DirectX::EffectFactory> obj3d::m_factory;

void obj3d::InitializeStatic(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext, Camera * camera)
{
	m_d3dDevice = d3dDevice;
	m_d3dContext = d3dContext;
	m_Camera = camera;

	 m_states=std::make_unique<CommonStates>(m_d3dDevice.Get());

	 m_factory = std::make_unique<EffectFactory>(m_d3dDevice.Get());
	 m_factory->SetDirectory(L"Resources");
}

obj3d::obj3d()
{
}

void obj3d::LoadModel(const wchar_t * fileName)
{
}

void obj3d::Update()
{
	//主に行列の計算
}

void obj3d::Draw()
{
	//描画
}
