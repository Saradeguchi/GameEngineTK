#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include"Obj3D.h"

class Player
{
public:
	//パーツ
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

	//コンストラクタとデストラクタ
	Player(DirectX::Keyboard* keyboard);
	~Player();
	//初期化
	void Initialize();
	//更新処理
	void Update();
	//モデルの更新
	void VoidUp();
	//描画処理
	void Draw();

	//弾丸を発射
	void FireBullet();
	//弾丸を装填
	void ResetBullet();

	const DirectX::SimpleMath::Vector3& GetTranslation();

	void SetTranslation(DirectX::SimpleMath::Vector3& trans);
	const DirectX::SimpleMath::Matrix& GetLocalWorld();
	const DirectX::SimpleMath::Vector3 GetRotation();
	void SetRotation(DirectX::SimpleMath::Vector3& Rotate);

protected:
	std::vector<obj3d> m_Voidoll;

	// 速度
	DirectX::SimpleMath::Vector3 m_Velocity;

	//キーボード
	
	DirectX::Keyboard* m_pKeyboard;
	DirectX::Keyboard::KeyboardStateTracker m_KeyboardTracker;

	//弾丸の速度ベクトル
	DirectX::SimpleMath::Vector3 m_BulletVel;

	//弾丸の発射flag
	bool m_Fireflag;
};