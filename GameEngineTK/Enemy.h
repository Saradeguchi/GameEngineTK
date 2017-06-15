#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include"Obj3D.h"

class Enemy
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
	Enemy();
	~Enemy();
	//初期化
	void Initialize();
	//更新処理
	void Update();
	//モデルの更新
	void VoidUp();
	//描画処理
	void Draw();

	const DirectX::SimpleMath::Vector3& GetTranslation();

	void SetTranslation(DirectX::SimpleMath::Vector3& trans);
	const DirectX::SimpleMath::Matrix& GetLocalWorld();
	const DirectX::SimpleMath::Vector3 GetRotation();
	void SetRotation(DirectX::SimpleMath::Vector3& Rotate);
	float GetShortAngleRad(float y,float a);

protected:
	std::vector<obj3d> m_Voidoll;

	//キーボード
	DirectX::Keyboard* m_pKeyboard;
	DirectX::Keyboard::KeyboardStateTracker m_KeyboardTracker;

	int m_Timer;
	float m_DistAngle;
};