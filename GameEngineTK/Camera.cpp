//
//カメラの制御
//

#include "Game.h"
#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


Camera::Camera(int Width, int Height)
{
	//メンバ変数の初期化
	Eyepos = Vector3(0, 0, 5.0f);
	Refpos = Vector3(0, 3, 0);
	Upvec = Vector3(0, 1, 0);
	FovY = XMConvertToRadians(60.0f);
	Aspect= (float)Width / Height;

	//ビュー行列を生成

	//射影行列の生成（透視投影）

}

Camera::~Camera()
{
}

void Camera::Update()
{
	//ビュー行列を生成

	//射影行列の生成（透視投影）
}

DirectX::SimpleMath::Matrix Camera::GetViewMatrix()
{
	return View;
}

DirectX::SimpleMath::Matrix Camera::GetProjectionMatrix()
{
	return Proj;
}

void Camera::SetEyePos(DirectX::SimpleMath::Vector3 eyepos)
{
	Eyepos = eyepos;
}

void Camera::SetRefPos(DirectX::SimpleMath::Vector3 refpos)
{
	Refpos = refpos;
}

void Camera::SetUpVec(DirectX::SimpleMath::Vector3 upvec)
{
	Upvec = upvec;
}

void Camera::SetFovY(float fovY)
{
	FovY = fovY;
}

void Camera::SetAspect(float aspect)
{
	Aspect = aspect;
}

void Camera::SetNearClip(float nearclip)
{
	Nearclip = nearclip;
}

void Camera::SetFarClip(float farclip)
{
	Farclip = farclip;
}


