#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include"Obj3D.h"

class Enemy
{
public:
	//�p�[�c
	enum VOID_PARTS
	{
		VOID_WAIST,
		VOID_LEG2L,
		VOID_LEG2R,
		VOID_LEG1L,
		VOID_LEG1R,
		VOID_BODY,
		VOID_ARM1L,
		VOID_ARM1R,
		VOID_ARM2L,
		VOID_ARM2R,
		VOID_HEAD,
		VOID_HEARL,
		VOID_HEARR,

		VOID_PARTE_NUM
	};

	//�R���X�g���N�^�ƃf�X�g���N�^
	Enemy();
	~Enemy();
	//������
	void Initialize();
	//�X�V����
	void Update();
	//���f���̍X�V
	void VoidUp();
	//�`�揈��
	void Draw();

	const DirectX::SimpleMath::Vector3& GetTranslation();

	void SetTranslation(DirectX::SimpleMath::Vector3& trans);
	const DirectX::SimpleMath::Matrix& GetLocalWorld();
	const DirectX::SimpleMath::Vector3 GetRotation();
	void SetRotation(DirectX::SimpleMath::Vector3& Rotate);
	float GetShortAngleRad(float y,float a);

protected:
	std::vector<obj3d> m_Voidoll;

	//�L�[�{�[�h
	DirectX::Keyboard* m_pKeyboard;
	DirectX::Keyboard::KeyboardStateTracker m_KeyboardTracker;

	int m_Timer;
	float m_DistAngle;
};