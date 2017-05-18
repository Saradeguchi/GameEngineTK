/// <summary>
/// ���@�ɒǏ]����J�����N���X
/// </summary>

#include "FollowCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//�ÓI�����o�ϐ��̏����� �J�����̈ʒu��ς���i�l�����Ȃ����FPS�̂悤�ɁA�������TPS�̂悤�ɂȂ�j
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

	//C�L�[���������Ƃ�FPS/TPS��؂�ւ�
	if (m_keyboardTracker.IsKeyPressed(Keyboard::Keys::C))
	{
		//�t���O�̐؂�ւ�
		m_flag = !m_flag;
	}

	//���_�A�Q�Ɠ_���W
	Vector3 eyepos, refpos;
	//���_�̐؂�ւ�
	if (m_flag == true)
	{
		//FPS���_
		//���@�̖ڂ̂���������_�Ƃ���
		eyepos = m_targetPos + Vector3(0, 0.6f, 0);
		//�Q�Ɠ_�Ǝ��_�̍����x�N�g��
		Vector3 cameraV(0, 0, -CAMERA_DISTANCE);
		//���@�̌��ɉ�荞�ނ��߂̉�]�s��𐶐�
		Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
		//�����x�N�g������]������
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		//�Q�Ɠ_���W���v�Z
		refpos = eyepos + cameraV;
	}
	else if (m_flag == false)
	{
		//TPS���_
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
	}

	//���_�����݈ʒu�����Ԃ���
	eyepos = Eyepos + (eyepos - Eyepos)*0.06f;
	//�Q�Ɠ_�����݈ʒu�����Ԃ���
	refpos = Refpos + (refpos - Refpos)*0.06f;

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

void FollowCamera::Setkeyboard(DirectX::Keyboard * keyboard)
{
	m_keyboard = keyboard;
}
