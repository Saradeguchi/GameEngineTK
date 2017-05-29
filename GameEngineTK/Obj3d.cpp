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
	//スケールは０ではなく１倍が基本
	m_Scale = Vector3(1, 1, 1);
	m_parent = nullptr;
}

void obj3d::LoadModel(const wchar_t * fileName)
{
	//モデルの読み込み
	m_model = Model::CreateFromCMO(m_d3dDevice.Get(), fileName, *m_factory);
}

void obj3d::Update()
{
	//主に行列の計算
	Matrix scalemat = Matrix::CreateScale(m_Scale);

	Matrix rotmatZ= Matrix::CreateRotationZ(m_Rotation.z);
	Matrix rotmatY = Matrix::CreateRotationY(m_Rotation.y);
	Matrix rotmatX = Matrix::CreateRotationY(m_Rotation.x);
	Matrix rotmat = rotmatZ * rotmatX * rotmatY;
	Matrix transmat = Matrix::CreateTranslation(m_Translation);
	//ワールド行列を合成
	m_World = scalemat * rotmat * transmat;
	//親の行列をかける
	if (m_parent)
	{
		m_World *= m_parent->m_World;
	}
}

void obj3d::Draw()
{
	assert(m_Camera);

	if (m_model)
	{
		//描画
		m_model->Draw(m_d3dContext.Get(), *m_states, m_World, m_Camera->GetViewMatrix(), m_Camera->GetProjectionMatrix());
	}
}
