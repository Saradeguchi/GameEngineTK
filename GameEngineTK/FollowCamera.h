/// <summary>
/// 自機に追従するカメラクラス
/// </summary>

#pragma once
#include "Camera.h"

class FollowCamera:public Camera
{
public:
	//自機とカメラの距離
	static const float CAMERA_DISTANCE;
	//コンストラクタ
	FollowCamera(int Width, int Height);
	//毎フレーム更新
	void Update() override;

	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetpos);

	void SetTargetAngle(float targetangle);

protected:
	//自機の座標
	DirectX::SimpleMath::Vector3 m_targetPos;
	//自機の回転角
	float m_targetAngle;

};
