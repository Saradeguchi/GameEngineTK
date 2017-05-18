/// <summary>
/// ���@�ɒǏ]����J�����N���X
/// </summary>

#pragma once
#include "Camera.h"
#include <Keyboard.h>

class FollowCamera:public Camera
{
public:
	//���@�ƃJ�����̋���
	static const float CAMERA_DISTANCE;
	//�R���X�g���N�^
	FollowCamera(int Width, int Height);
	//���t���[���X�V
	void Update() override;

	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetpos);

	void SetTargetAngle(float targetangle);

	//�L�[�{�[�h���Z�b�g
	void Setkeyboard(DirectX::Keyboard* keyboard);

protected:
	//���@�̍��W
	DirectX::SimpleMath::Vector3 m_targetPos;
	//���@�̉�]�p
	float m_targetAngle;
	//�L�[�{�[�h
	DirectX::Keyboard* m_keyboard;
	//�L�[�{�[�h�g���b�J�[
	DirectX::Keyboard::KeyboardStateTracker m_keyboardTracker;
	//���_�̐؂�ւ�
	bool m_flag;
};
