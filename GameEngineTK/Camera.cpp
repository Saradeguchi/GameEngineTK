//
//�J�����̐���
//

#include "Game.h"
#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


Camera::Camera(int Width, int Height)
{
	//�����o�ϐ��̏�����
	Eyepos = Vector3(0, 0, 5.0f);
	Refpos = Vector3(0, 3, 0);
	Upvec = Vector3(0, 1, 0);
	FovY = XMConvertToRadians(60.0f);
	Aspect= (float)Width / Height;

	//�r���[�s��𐶐�

	//�ˉe�s��̐����i�������e�j

}

Camera::~Camera()
{
}

void Camera::Update()
{
	//�r���[�s��𐶐�

	//�ˉe�s��̐����i�������e�j
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


