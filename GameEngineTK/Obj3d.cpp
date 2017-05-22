#include "Obj3d.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//�ÓI�����o�ϐ��̎���
//�f�o�C�X
Microsoft::WRL::ComPtr<ID3D11Device>           obj3d::m_d3dDevice;
//�f�o�C�X�R���e�L�X�g
Microsoft::WRL::ComPtr<ID3D11DeviceContext>     obj3d::m_d3dContext;
//�J����
Camera* obj3d::m_Camera;
//�ėp�`��X�e�[�g
std::unique_ptr<DirectX::CommonStates> obj3d::m_states;

//�G�t�F�N�g�t�@�N�g���[
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
	//��ɍs��̌v�Z
}

void obj3d::Draw()
{
	//�`��
}
