#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include"Obj3D.h"

class Player
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
	Player(DirectX::Keyboard* keyboard);
	~Player();
	//������
	void Initialize();
	//�X�V����
	void Update();
	//���f���̍X�V
	void VoidUp();
	//�`�揈��
	void Draw();

	//�e�ۂ𔭎�
	void FireBullet();
	//�e�ۂ𑕓U
	void ResetBullet();

	const DirectX::SimpleMath::Vector3& GetTranslation();

	void SetTranslation(DirectX::SimpleMath::Vector3& trans);
	const DirectX::SimpleMath::Matrix& GetLocalWorld();
	const DirectX::SimpleMath::Vector3 GetRotation();
	void SetRotation(DirectX::SimpleMath::Vector3& Rotate);

protected:
	std::vector<obj3d> m_Voidoll;

	// ���x
	DirectX::SimpleMath::Vector3 m_Velocity;

	//�L�[�{�[�h
	
	DirectX::Keyboard* m_pKeyboard;
	DirectX::Keyboard::KeyboardStateTracker m_KeyboardTracker;

	//�e�ۂ̑��x�x�N�g��
	DirectX::SimpleMath::Vector3 m_BulletVel;

	//�e�ۂ̔���flag
	bool m_Fireflag;
};