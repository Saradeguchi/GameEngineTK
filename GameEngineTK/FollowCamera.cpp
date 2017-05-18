/// <summary>
/// 自機に追従するカメラクラス
/// </summary>

#include "FollowCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//静的メンバ変数の初期化 カメラの位置を変える（値が少なければFPSのように、多ければTPSのようになる）
const float		FollowCamera::CAMERA_DISTANCE = 5.0f;

FollowCamera::FollowCamera(int Width, int Height)
	:Camera(Width,Height)
{
	m_targetPos = Vector3::Zero;
	m_targetAngle = 0.0f;
	m_keyboard = nullptr;
	m_flag = true;
}

void FollowCamera::Update()
{
	Keyboard::State keyboardState = m_keyboard->GetState();
	m_keyboardTracker.Update(keyboardState);

	//Cキーを押すごとにFPS/TPSを切り替え
	if (m_keyboardTracker.IsKeyPressed(Keyboard::Keys::C))
	{
		//フラグの切り替え
		m_flag = !m_flag;
	}

	//視点、参照点座標
	Vector3 eyepos, refpos;
	//視点の切り替え
	if (m_flag == true)
	{
		//FPS視点
		//自機の目のあたりを視点とする
		eyepos = m_targetPos + Vector3(0, 0.6f, 0);
		//参照点と視点の差分ベクトル
		Vector3 cameraV(0, 0, -CAMERA_DISTANCE);
		//自機の後ろに回り込むための回転行列を生成
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		//差分ベクトルを回転させる
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		//参照点座標を計算
		refpos = eyepos + cameraV;
	}
	else if (m_flag == false)
	{
		//TPS視点
		//自機の上空２Mを参照点とする
		refpos = m_targetPos + Vector3(0, 2, 0);
		//参照点と視点の差分ベクトル
		Vector3 cameraV(0, 0, CAMERA_DISTANCE);
		//自機の後ろに回り込むための回転行列を生成
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		//差分ベクトルを回転させる
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		//視点座標を計算
		eyepos = refpos + cameraV;
	}

	//視点を現在位置から補間する
	eyepos = Eyepos + (eyepos - Eyepos)*0.06f;
	//参照点を現在位置から補間する
	refpos = Refpos + (refpos - Refpos)*0.06f;

	SetEyePos(eyepos);
	SetRefPos(refpos);

	//基底クラスの更新
	Camera::Update();
}

void FollowCamera::SetTargetPos(const DirectX::SimpleMath::Vector3 & targetpos)
{
	m_targetPos = targetpos;
}

void FollowCamera::SetTargetAngle(float targetangle)
{
	m_targetAngle = targetangle;
}

void FollowCamera::Setkeyboard(DirectX::Keyboard * keyboard)
{
	m_keyboard = keyboard;
}
