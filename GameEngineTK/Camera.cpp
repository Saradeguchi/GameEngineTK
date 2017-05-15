//
//�J�����̐���
//

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
	Nearclip = 0.1f;
	Farclip = 1000.0f;

	//�r���[�s��𐶐�
	View = Matrix::CreateLookAt(Eyepos, Refpos, Upvec);
	//�ˉe�s��̐����i�������e�j
	Proj = Matrix::CreatePerspectiveFieldOfView(FovY, Aspect, Nearclip, Farclip);
}

Camera::~Camera()
{
}

void Camera::Update()
{
	//�r���[�s��𐶐�
	View = Matrix::CreateLookAt(Eyepos, Refpos, Upvec);
	//�ˉe�s��̐����i�������e�j
	Proj = Matrix::CreatePerspectiveFieldOfView(FovY, Aspect, Nearclip, Farclip);
}

const DirectX::SimpleMath::Matrix& Camera::GetViewMatrix()
{
	return View;
}

const DirectX::SimpleMath::Matrix& Camera::GetProjectionMatrix()
{
	return Proj;
}

void Camera::SetEyePos(const DirectX::SimpleMath::Vector3& eyepos)
{
	Eyepos = eyepos;
}

void Camera::SetRefPos(const DirectX::SimpleMath::Vector3& refpos)
{
	Refpos = refpos;
}

void Camera::SetUpVec(const DirectX::SimpleMath::Vector3& upvec)
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


