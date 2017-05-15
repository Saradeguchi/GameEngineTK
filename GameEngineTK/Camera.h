//
//�J�����̐���
//

#pragma once

#include <d3d11.h>
#include <SimpleMath.h>


class Camera
{
public:
	Camera(int Width,int Height);
	virtual ~Camera();

	//�X�V����
	virtual void Update();

	//�r���[�s����擾
	const DirectX::SimpleMath::Matrix& GetViewMatrix();
	//�ˉe�s����擾
	const DirectX::SimpleMath::Matrix& GetProjectionMatrix();

	//���_���Z�b�g
	void SetEyePos(const DirectX::SimpleMath::Vector3& eyepos);
	//�����_���Z�b�g
	void SetRefPos(const DirectX::SimpleMath::Vector3& refpos);
	//������x�N�g�����Z�b�g
	void SetUpVec(const DirectX::SimpleMath::Vector3& upvec);

	//������������p���Z�b�g
	void SetFovY(float fovY);
	//�A�X�y�N�g����Z�b�g
	void SetAspect(float aspect);
	//��O�̕\�����E�����̃Z�b�g
	void SetNearClip(float nearclip);
	//���̕\�����E�����̃Z�b�g
	void SetFarClip(float farclip);

protected:
	//�r���[�s��
	DirectX::SimpleMath::Matrix View;
	//�������猩��̂��i���_�j
	DirectX::SimpleMath::Vector3 Eyepos;
	//����������̂��i�����_�j
	DirectX::SimpleMath::Vector3 Refpos;
	//�ǂ��炪��ʂ̏�������i������x�N�g���j
	DirectX::SimpleMath::Vector3 Upvec;

	//�v���W�F�N�V�����s��
	DirectX::SimpleMath::Matrix Proj;
	//������������p
	float FovY;
	//�A�X�y�N�g��i���E�c�̔䗦�j
	float Aspect;
	//��O�̕\�����E����
	float Nearclip;
	//���̕\�����E����
	float Farclip;
};
