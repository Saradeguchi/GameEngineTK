//
//カメラの制御
//

#pragma once

#include <d3d11.h>
#include <SimpleMath.h>


class Camera
{
public:
	Camera(int Width,int Height);
	virtual ~Camera();

	//更新処理
	virtual void Update();

	//ビュー行列を取得
	const DirectX::SimpleMath::Matrix& GetViewMatrix();
	//射影行列を取得
	const DirectX::SimpleMath::Matrix& GetProjectionMatrix();

	//視点をセット
	void SetEyePos(const DirectX::SimpleMath::Vector3& eyepos);
	//注視点をセット
	void SetRefPos(const DirectX::SimpleMath::Vector3& refpos);
	//上方向ベクトルをセット
	void SetUpVec(const DirectX::SimpleMath::Vector3& upvec);

	//垂直方向視野角をセット
	void SetFovY(float fovY);
	//アスペクト比をセット
	void SetAspect(float aspect);
	//手前の表示限界距離のセット
	void SetNearClip(float nearclip);
	//奥の表示限界距離のセット
	void SetFarClip(float farclip);

protected:
	//ビュー行列
	DirectX::SimpleMath::Matrix View;
	//何処から見るのか（視点）
	DirectX::SimpleMath::Vector3 Eyepos;
	//何処を見るのか（注視点）
	DirectX::SimpleMath::Vector3 Refpos;
	//どちらが画面の上方向か（上方向ベクトル）
	DirectX::SimpleMath::Vector3 Upvec;

	//プロジェクション行列
	DirectX::SimpleMath::Matrix Proj;
	//垂直方向視野角
	float FovY;
	//アスペクト比（横・縦の比率）
	float Aspect;
	//手前の表示限界距離
	float Nearclip;
	//奥の表示限界距離
	float Farclip;
};
