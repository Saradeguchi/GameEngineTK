/// <summary>
/// ���@�ɒǏ]����J�����N���X
/// </summary>

#include "FollowCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//�ÓI�����o�ϐ��̏�����
const float		FollowCamera::CAMERA_DISTANCE = 5.0f;

FollowCamera::FollowCamera(int Width, int Height)
	:Camera(Width,Height)
{
	m_targetPos = Vector3::Zero;
	m_targetAngle = 0.0f;
}

void FollowCamera::Update()
{
	//���_�A�Q�Ɠ_���W
	Vector3 eyepos, refpos;
	//���@�̏��QM���Q�Ɠ_�Ƃ���
	refpos = m_targetPos + Vector3(0, 2, 0);
	//�Q�Ɠ_�Ǝ��_�̍����x�N�g��
	Vector3 cameraV(0, 0, CAMERA_DISTANCE);
	//���@�̌��ɉ�荞�ނ��߂̉�]�s��𐶐�
	Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
	//�����x�N�g������]������
	cameraV = Vector3::TransformNormal(cameraV, rotmat);
	//���_���W���v�Z
	eyepos = refpos + cameraV;

	SetEyePos(eyepos);
	SetRefPos(refpos);

	//���N���X�̍X�V
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
