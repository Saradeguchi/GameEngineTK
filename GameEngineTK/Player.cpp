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

	m_Fireflag = false;

}

void Player::Update()
{
	Keyboard::State keystate = m_pKeyboard->GetState();
	m_KeyboardTracker.Update(keystate);

	// １フレームでの旋回速度<ラジアン>
	const float ROT_SPEED = 0.03f;

	if (keystate.IsKeyDown(Keyboard::Keys::A))
	{
		// 現在の角度を取得
		Vector3 rot = m_Voidoll[VOID_WAIST].GetRotation();
		rot.y += ROT_SPEED;
		// 回転後の角度を反映
		m_Voidoll[VOID_WAIST].SetRotation(rot);
	}
	if (keystate.IsKeyDown(Keyboard::Keys::D))
	{
		// 現在の角度を取得
		Vector3 rot = m_Voidoll[VOID_WAIST].GetRotation();
		rot.y -= ROT_SPEED;
		// 回転後の角度を反映
		m_Voidoll[VOID_WAIST].SetRotation(rot);
	}

	// 前進/後退
	if (keystate.IsKeyDown(Keyboard::Keys::W))
	{
		// 現在の座標・回転角を取得
		Vector3 trans = m_Voidoll[VOID_WAIST].GetTranslation();
		float rot_y = m_Voidoll[VOID_WAIST].GetRotation().y;
		// 移動ベクトル(Z座標前進)
		SimpleMath::Vector3 moveV(0, 0, -0.1f);
		Matrix rotm = Matrix::CreateRotationY(rot_y);
		// 移動ベクトルを回転する
		moveV = Vector3::TransformNormal(moveV, rotm);
		// 移動
		trans += moveV;
		// 移動した座標を反映
		m_Voidoll[VOID_WAIST].SetTranslation(trans);
	}
	if (keystate.IsKeyDown(Keyboard::Keys::S))
	{
		// 現在の座標・回転角を取得
		Vector3 trans = m_Voidoll[VOID_WAIST].GetTranslation();
		float rot_y = m_Voidoll[VOID_WAIST].GetRotation().y;
		// 移動ベクトル(Z座標後退)
		Vector3 moveV(0, 0, +0.1f);
		Matrix rotm = Matrix::CreateRotationY(rot_y);
		// 移動ベクトルを回転する
		moveV = Vector3::TransformNormal(moveV, rotm);
		// 移動
		trans += moveV;
		// 移動した座標を反映
		m_Voidoll[VOID_WAIST].SetTranslation(trans);
	}

	// 弾丸を前進させる
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

	//発射するパーツのワールド座標の取得
	Matrix worldm = m_Voidoll[VOID_HEARR].GetWorld();

	//ワールド行列から各要素を抽出
	Vector3 scale;					//ワールドスケーリング
	Quaternion rotation;			//ワールド回転
	Vector3 translation;			//ワールド座標

	worldm.Decompose(scale, rotation, translation);

	//発射パーツを親から分離して独立
	m_Voidoll[VOID_HEARR].SetPalent(nullptr);
	m_Voidoll[VOID_HEARR].SetScale(scale);
	m_Voidoll[VOID_HEARR].SetRotation(rotation);
	m_Voidoll[VOID_HEARR].SetTranslation(translation);

	//弾丸の速度を設定
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