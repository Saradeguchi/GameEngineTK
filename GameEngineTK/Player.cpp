#include "Player.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Player::Player(DirectX::Keyboard* keyboard)
{
	m_pKeyboard = keyboard;
	Initialize();
}

Player::~Player()
{
}

void Player::Initialize()
{
	//Void�p�[�c�ǂݍ���
	m_Voidoll.resize(VOID_PARTE_NUM);
	m_Voidoll[VOID_LEG2L].LoadModel(L"Resources\\VoidLeg2.cmo");
	m_Voidoll[VOID_LEG2R].LoadModel(L"Resources\\VoidLeg2.cmo");
	m_Voidoll[VOID_LEG1L].LoadModel(L"Resources\\VoidLeg1.cmo");
	m_Voidoll[VOID_LEG1R].LoadModel(L"Resources\\VoidLeg1.cmo");
	m_Voidoll[VOID_WAIST].LoadModel(L"Resources\\Voidkos.cmo");
	m_Voidoll[VOID_BODY].LoadModel(L"Resources\\VoidBody.cmo");
	m_Voidoll[VOID_HEAD].LoadModel(L"Resources\\VoidHead.cmo");
	m_Voidoll[VOID_ARM2L].LoadModel(L"Resources\\VoidArem2.cmo");
	m_Voidoll[VOID_ARM2R].LoadModel(L"Resources\\VoidArem2.cmo");
	m_Voidoll[VOID_ARM1L].LoadModel(L"Resources\\VoidArem1.cmo");
	m_Voidoll[VOID_ARM1R].LoadModel(L"Resources\\VoidArem1.cmo");
	m_Voidoll[VOID_HEARL].LoadModel(L"Resources\\VoidHear.cmo");
	m_Voidoll[VOID_HEARR].LoadModel(L"Resources\\VoidHear.cmo");

	//�����e��
	m_Voidoll[VOID_LEG2L].SetPalent(&m_Voidoll[VOID_LEG1L]);
	m_Voidoll[VOID_LEG2R].SetPalent(&m_Voidoll[VOID_LEG1R]);
	m_Voidoll[VOID_LEG1L].SetPalent(&m_Voidoll[VOID_WAIST]);
	m_Voidoll[VOID_LEG1R].SetPalent(&m_Voidoll[VOID_WAIST]);
	m_Voidoll[VOID_ARM2L].SetPalent(&m_Voidoll[VOID_ARM1L]);
	m_Voidoll[VOID_ARM2R].SetPalent(&m_Voidoll[VOID_ARM1R]);
	m_Voidoll[VOID_ARM1L].SetPalent(&m_Voidoll[VOID_BODY]);
	m_Voidoll[VOID_ARM1R].SetPalent(&m_Voidoll[VOID_BODY]);
	m_Voidoll[VOID_HEARL].SetPalent(&m_Voidoll[VOID_HEAD]);
	m_Voidoll[VOID_HEARR].SetPalent(&m_Voidoll[VOID_HEAD]);
	m_Voidoll[VOID_HEAD].SetPalent(&m_Voidoll[VOID_BODY]);
	m_Voidoll[VOID_BODY].SetPalent(&m_Voidoll[VOID_WAIST]);

	//�p�[�c�ʒu���Đݒ�
	m_Voidoll[VOID_WAIST].SetTranslation(Vector3(0, 1.7f, 0));
	m_Voidoll[VOID_LEG1L].SetRotation(Vector3(90.0f, 90.0f, 0));
	m_Voidoll[VOID_LEG1R].SetRotation(Vector3(0, 90.0f, 0));
	m_Voidoll[VOID_LEG1L].SetTranslation(Vector3(0.3f, -0.6f, 0));
	m_Voidoll[VOID_LEG1R].SetTranslation(Vector3(-0.3f, -0.6f, 0));
	m_Voidoll[VOID_LEG2L].SetScale(Vector3(0.7f));
	m_Voidoll[VOID_LEG2R].SetScale(Vector3(0.7f));
	m_Voidoll[VOID_LEG2L].SetTranslation(Vector3(0, -0.3f, 0));
	m_Voidoll[VOID_LEG2R].SetTranslation(Vector3(0, -0.3f, 0));
	m_Voidoll[VOID_LEG2L].SetRotation(Vector3(0.8f, 0, 0));
	m_Voidoll[VOID_LEG2R].SetRotation(Vector3(-0.8f, 0, 0));
	m_Voidoll[VOID_BODY].SetTranslation(Vector3(0, 0.3f, 0));
	m_Voidoll[VOID_HEAD].SetTranslation(Vector3(-0.13f, 1.2f, 0));
	m_Voidoll[VOID_ARM1L].SetTranslation(Vector3(-0.4f, 0.65f, 0));
	m_Voidoll[VOID_ARM1R].SetTranslation(Vector3(0.4f, 0.65f, 0));
	m_Voidoll[VOID_ARM1L].SetRotation(Vector3(0, 0, -0.5f));
	m_Voidoll[VOID_ARM1R].SetRotation(Vector3(0, 0, 0.5f));
	m_Voidoll[VOID_ARM2L].SetTranslation(Vector3(0, -1.1f, 0));
	m_Voidoll[VOID_ARM2R].SetTranslation(Vector3(0, -1.1f, 0));
	m_Voidoll[VOID_HEARL].SetTranslation(Vector3(-0.4f, -0.1f, 0));
	m_Voidoll[VOID_HEARR].SetTranslation(Vector3(0.6f, -0.1f, 0));
	m_Voidoll[VOID_HEARL].SetRotation(Vector3(0, 0, -0.5f));
	m_Voidoll[VOID_HEARR].SetRotation(Vector3(0, 0, 0.5f));
	m_Voidoll[VOID_HEARL].SetScale(Vector3(1.3f));
	m_Voidoll[VOID_HEARR].SetScale(Vector3(1.3f));

	m_Fireflag = false;

}

void Player::Update()
{
	Keyboard::State keystate = m_pKeyboard->GetState();
	m_KeyboardTracker.Update(keystate);

	// �P�t���[���ł̐��񑬓x<���W�A��>
	const float ROT_SPEED = 0.03f;

	if (keystate.IsKeyDown(Keyboard::Keys::A))
	{
		// ���݂̊p�x���擾
		Vector3 rot = m_Voidoll[VOID_WAIST].GetRotation();
		rot.y += ROT_SPEED;
		// ��]��̊p�x�𔽉f
		m_Voidoll[VOID_WAIST].SetRotation(rot);
	}
	if (keystate.IsKeyDown(Keyboard::Keys::D))
	{
		// ���݂̊p�x���擾
		Vector3 rot = m_Voidoll[VOID_WAIST].GetRotation();
		rot.y -= ROT_SPEED;
		// ��]��̊p�x�𔽉f
		m_Voidoll[VOID_WAIST].SetRotation(rot);
	}

	// �O�i/���
	if (keystate.IsKeyDown(Keyboard::Keys::W))
	{
		// ���݂̍��W�E��]�p���擾
		Vector3 trans = m_Voidoll[VOID_WAIST].GetTranslation();
		float rot_y = m_Voidoll[VOID_WAIST].GetRotation().y;
		// �ړ��x�N�g��(Z���W�O�i)
		SimpleMath::Vector3 moveV(0, 0, -0.1f);
		Matrix rotm = Matrix::CreateRotationY(rot_y);
		// �ړ��x�N�g������]����
		moveV = Vector3::TransformNormal(moveV, rotm);
		// �ړ�
		trans += moveV;
		// �ړ��������W�𔽉f
		m_Voidoll[VOID_WAIST].SetTranslation(trans);
	}
	if (keystate.IsKeyDown(Keyboard::Keys::S))
	{
		// ���݂̍��W�E��]�p���擾
		Vector3 trans = m_Voidoll[VOID_WAIST].GetTranslation();
		float rot_y = m_Voidoll[VOID_WAIST].GetRotation().y;
		// �ړ��x�N�g��(Z���W���)
		Vector3 moveV(0, 0, +0.1f);
		Matrix rotm = Matrix::CreateRotationY(rot_y);
		// �ړ��x�N�g������]����
		moveV = Vector3::TransformNormal(moveV, rotm);
		// �ړ�
		trans += moveV;
		// �ړ��������W�𔽉f
		m_Voidoll[VOID_WAIST].SetTranslation(trans);
	}

	// �e�ۂ�O�i������
	if (keystate.IsKeyDown(Keyboard::Keys::Space))
	{
		Vector3 pos = m_Voidoll[VOID_HEARR].GetTranslation();
		m_Voidoll[VOID_HEARR].SetTranslation(pos + m_BulletVel);
	}

	VoidUp();

	FireBullet();
}

void Player::VoidUp()
{
	for (std::vector<obj3d>::iterator it = m_Voidoll.begin(); it != m_Voidoll.end(); it++)
	{
		it->Update();
	}
}

void Player::Draw()
{
	for (std::vector<obj3d>::iterator it = m_Voidoll.begin(); it != m_Voidoll.end(); it++)
	{
		it->Draw();
	}
}

void Player::FireBullet()
{
	if (m_Fireflag) return;

	//���˂���p�[�c�̃��[���h���W�̎擾
	Matrix worldm = m_Voidoll[VOID_HEARR].GetWorld();

	//���[���h�s�񂩂�e�v�f�𒊏o
	Vector3 scale;					//���[���h�X�P�[�����O
	Quaternion rotation;			//���[���h��]
	Vector3 translation;			//���[���h���W

	worldm.Decompose(scale, rotation, translation);

	//���˃p�[�c��e���番�����ēƗ�
	m_Voidoll[VOID_HEARR].SetPalent(nullptr);
	m_Voidoll[VOID_HEARR].SetScale(scale);
	m_Voidoll[VOID_HEARR].SetRotation(rotation);
	m_Voidoll[VOID_HEARR].SetTranslation(translation);

	//�e�ۂ̑��x��ݒ�
	m_BulletVel = Vector3(0, 0, -0.1f);
	m_BulletVel = Vector3::Transform(m_BulletVel, rotation);

	m_Fireflag = true;
}

void Player::ResetBullet()
{
}

const DirectX::SimpleMath::Vector3 & Player::GetTranslation()
{
	return m_Voidoll[VOID_WAIST].GetTranslation();
}

void Player::SetTranslation(DirectX::SimpleMath::Vector3& trans)
{
	m_Voidoll[VOID_WAIST].SetTranslation(trans);
}

const DirectX::SimpleMath::Matrix & Player::GetLocalWorld()
{
	return m_Voidoll[VOID_WAIST].GetWorld();
}

const DirectX::SimpleMath::Vector3 Player::GetRotation()
{
	return m_Voidoll[VOID_WAIST].GetRotation();
}

void Player::SetRotation(DirectX::SimpleMath::Vector3 & Rotate)
{
	m_Voidoll[VOID_WAIST].SetRotation(Rotate);
}