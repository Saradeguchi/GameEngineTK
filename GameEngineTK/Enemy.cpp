#include "Enemy.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Enemy::Enemy()
{
	Initialize();
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	//Voidパーツ読み込み
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

	//腰を大親に
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

	//パーツ位置を再設定
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

	//
	Vector3 pos;
	pos.x = rand()%100-50;
	pos.y = 1.7f;
	pos.z = rand()%100-50;

	this->SetTranslation(pos);

	m_Timer = 0;
	m_DistAngle = 0;
}

void Enemy::Update()
{
	m_Timer--;
	if (m_Timer < 0)
	{
		m_Timer = 180;

		float rad = (float)rand() / RAND_MAX - 0.5f;
		rad *= 180.0f;
		rad *= XMConvertToRadians(rad);
		m_DistAngle += rad;
	}

	{
		Vector3 rotv = m_Voidoll[VOID_WAIST].GetRotation();
		float angle = m_DistAngle - rotv.y;
		if (angle > XM_PI)
		{
			angle -= XM_2PI;
		}

		if (angle < -XM_PI)
		{
			angle += XM_2PI;
		}
		//float angle = GetShortAngleRad(rotv.y, XMConvertToRadians(m_DistAngle));
		rotv.y += angle*0.05f;
		m_Voidoll[VOID_WAIST].SetRotation(rotv);
	}

	{
		// 移動量のベクトル
		Vector3 moveV(0, 0, -0.1f);
		// 移動量ベクトルを自機の角度分回転させる
		//moveV = Vector3::TransformNormal(moveV, tank_world);
		float angle = m_Voidoll[VOID_WAIST].GetRotation().y;
		Matrix rotmat = Matrix::CreateRotationY(angle);
		moveV = Vector3::TransformNormal(moveV, rotmat);
		// 自機の座標を移動させる
		Vector3 pos = m_Voidoll[VOID_WAIST].GetTranslation();
		m_Voidoll[VOID_WAIST].SetTranslation(pos + moveV);
	}

	VoidUp();
}

void Enemy::VoidUp()
{
	for (std::vector<obj3d>::iterator it = m_Voidoll.begin(); it != m_Voidoll.end(); it++)
	{
		it->Update();
	}
}

void Enemy::Draw()
{
	for (std::vector<obj3d>::iterator it = m_Voidoll.begin(); it != m_Voidoll.end(); it++)
	{
		it->Draw();
	}
}

const DirectX::SimpleMath::Vector3 & Enemy::GetTranslation()
{
	return m_Voidoll[VOID_WAIST].GetTranslation();
}

void Enemy::SetTranslation(DirectX::SimpleMath::Vector3& trans)
{
	m_Voidoll[VOID_WAIST].SetTranslation(trans);
}

const DirectX::SimpleMath::Matrix & Enemy::GetLocalWorld()
{
	return m_Voidoll[VOID_WAIST].GetWorld();
}

const DirectX::SimpleMath::Vector3 Enemy::GetRotation()
{
	return m_Voidoll[VOID_WAIST].GetRotation();
}

void Enemy::SetRotation(DirectX::SimpleMath::Vector3 & Rotate)
{
	m_Voidoll[VOID_WAIST].SetRotation(Rotate);
}

float Enemy::GetShortAngleRad(float y, float a)
{
	return 0.0f;
}
