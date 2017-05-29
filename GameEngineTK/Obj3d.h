/// <summary>
/// 3D�I�u�W�F�N�g�̃N���X
/// </summary>
#pragma once

#include <windows.h>
#include <wrl/client.h>
#include <d3d11_1.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>
#include "Camera.h"

class obj3d
{
	//�ÓI�����o�ϐ�
public:
	//�ÓI�����o�ϐ��̏�����
	static void InitializeStatic(
		Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice,
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext,
		Camera* camera);

private:
	//�f�o�C�X
	static Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
	//�f�o�C�X�R���e�L�X�g
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
	//�J����
	static Camera* m_Camera;
	//�ėp�`��X�e�[�g
	static std::unique_ptr<DirectX::CommonStates> m_states;

	//�G�t�F�N�g�t�@�N�g���[
	static std::unique_ptr<DirectX::EffectFactory> m_factory;

public:
	//�R���X�g���N�^
	obj3d();

	//���f�������[�h
	void LoadModel(const wchar_t* fileName);

	//�X�V
	void Update();
	
	//�`��
	void Draw();

	//setter
	//�X�P�[�����O�ixyz�j
	void SetScale(DirectX::SimpleMath::Vector3& Scale)
	{
		m_Scale = Scale;
	}

	//��]�p�ixyz�j
	void SetRotation(DirectX::SimpleMath::Vector3& Rotation)
	{
		m_Rotation = Rotation;
	}

	//���s�ړ��ixyz�j
	void SetTranslation(DirectX::SimpleMath::Vector3& Translation)
	{
		m_Translation = Translation;
	}
	//�e��3D�I�u�W�F�N�g�̃|�C���^
	void SetPalent(obj3d* palent) 
	{
		m_parent = palent; 
	}


	//getter
	//�X�P�[�����O�ixyz�j
	const DirectX::SimpleMath::Vector3& GetScale()
	{
		return m_Scale; 
	}

	//��]�p�ixyz�j
	const DirectX::SimpleMath::Vector3& GetRotation() 
	{
		return m_Rotation;
	}

	//���s�ړ��ixyz�j
	const DirectX::SimpleMath::Vector3& GetTranslation()
	{ 
		return m_Translation; 
	}

	//���[���h�s��
	const DirectX::SimpleMath::Matrix& GetWorld()
	{
		return m_World; 
	}

	//�e��3D�I�u�W�F�N�g�̃|�C���^
	obj3d* GetPalent()
	{
		return m_parent; 
	}

private:
	//�����o�ϐ�
	//3D���f��
	//���{�b�g�̓����f��
	std::unique_ptr<DirectX::Model> m_model;

	//�X�P�[�����O�ixyz�j
	DirectX::SimpleMath::Vector3 m_Scale;

	//��]�p�ixyz�j
	DirectX::SimpleMath::Vector3 m_Rotation;

	//���s�ړ��ixyz�j
	DirectX::SimpleMath::Vector3 m_Translation;

	//���[���h�s��
	DirectX::SimpleMath::Matrix m_World;

	//�e��3d�I�u�W�F�N�g�N���X�̃|�C���^
	obj3d* m_parent;
};
