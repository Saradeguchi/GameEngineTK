/// <summary>
/// 3Dオブジェクトのクラス
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
	//静的メンバ変数
public:
	//静的メンバ変数の初期化
	static void InitializeStatic(
		Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice,
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext,
		Camera* camera);

private:
	//デバイス
	static Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
	//デバイスコンテキスト
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
	//カメラ
	static Camera* m_Camera;
	//汎用描画ステート
	static std::unique_ptr<DirectX::CommonStates> m_states;

	//エフェクトファクトリー
	static std::unique_ptr<DirectX::EffectFactory> m_factory;

public:
	//コンストラクタ
	obj3d();

	//モデルをロード
	void LoadModel(const wchar_t* fileName);

	//更新
	void Update();
	
	//描画
	void Draw();

	//setter
	//スケーリング（xyz）
	void SetScale(DirectX::SimpleMath::Vector3& Scale)
	{
		m_Scale = Scale;
	}

	//回転角（xyz）
	void SetRotation(DirectX::SimpleMath::Vector3& Rotation)
	{
		m_Rotation = Rotation;
	}

	//平行移動（xyz）
	void SetTranslation(DirectX::SimpleMath::Vector3& Translation)
	{
		m_Translation = Translation;
	}
	//親の3Dオブジェクトのポインタ
	void SetPalent(obj3d* palent) 
	{
		m_parent = palent; 
	}


	//getter
	//スケーリング（xyz）
	const DirectX::SimpleMath::Vector3& GetScale()
	{
		return m_Scale; 
	}

	//回転角（xyz）
	const DirectX::SimpleMath::Vector3& GetRotation() 
	{
		return m_Rotation;
	}

	//平行移動（xyz）
	const DirectX::SimpleMath::Vector3& GetTranslation()
	{ 
		return m_Translation; 
	}

	//ワールド行列
	const DirectX::SimpleMath::Matrix& GetWorld()
	{
		return m_World; 
	}

	//親の3Dオブジェクトのポインタ
	obj3d* GetPalent()
	{
		return m_parent; 
	}

private:
	//メンバ変数
	//3Dモデル
	//ロボットの頭モデル
	std::unique_ptr<DirectX::Model> m_model;

	//スケーリング（xyz）
	DirectX::SimpleMath::Vector3 m_Scale;

	//回転角（xyz）
	DirectX::SimpleMath::Vector3 m_Rotation;

	//平行移動（xyz）
	DirectX::SimpleMath::Vector3 m_Translation;

	//ワールド行列
	DirectX::SimpleMath::Matrix m_World;

	//親の3dオブジェクトクラスのポインタ
	obj3d* m_parent;
};
