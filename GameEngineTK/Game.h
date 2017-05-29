//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>
#include <Keyboard.h>
#include <vector>
#include "DebugCamera.h"
#include "FollowCamera.h"
#include "Obj3d.h"


// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

	//���@�p�[�c
	enum PLAYER_PARTS
	{
		PLAYER_TANK,
		PLAYER_BODY,
		PLAYER_HEAD,
		PLAYER_SHIELD,
		PLAYER_BULLET,

		PLAYER_PARTE_NUM
	};

	enum VOID_PARTS
	{
		VOID_LEG2,
		VOID_LEG1,
		VOID_WAIST,
		VOID_BODY,
		VOID_ARM1,
		VOID_ARM2,
		VOID_HEAD,
		VOID_HEAR,

		VOID_PARTE_NUM
	};

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_batch;
	std::unique_ptr<DirectX::BasicEffect> m_effect;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;

	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;

	//�f�o�b�O�J����
	std::unique_ptr<DebugCamera> m_debugCamera;

	//�G�t�F�N�g�t�@�N�g���[
	std::unique_ptr<DirectX::EffectFactory> m_factory;
	//�n�ʃ��f��
	std::unique_ptr<DirectX::Model> m_modelGround;
	//�V�����f��
	obj3d m_objSkydome;
	//�����f��
	std::unique_ptr<DirectX::Model> m_modelBall;
	//�����[���h�s��
	DirectX::SimpleMath::Matrix m_worldBall[20];
	DirectX::SimpleMath::Matrix m_worldBallTest;
	//�e�B�[�|�b�g���f��
	std::unique_ptr<DirectX::Model> m_modelTeapot;
	DirectX::SimpleMath::Matrix m_worldTeapot[20];
	////���{�b�g�̓����f��
	//std::unique_ptr<DirectX::Model> m_modelHead;
	//�L�[�{�[�h
	std::unique_ptr<DirectX::Keyboard> keyboard;
	//���@�̍��W
	DirectX::SimpleMath::Vector3 tank_pos;
	////���@�̃��[���h�s��
	//DirectX::SimpleMath::Matrix tank_world;
	////���@�̃��[���h�s��2
	//DirectX::SimpleMath::Matrix tank_world2;

	//���@�̂R�c�I�u�W�F�N�g
	//obj3d m_ObjPlayer1;
	//obj3d m_ObjPlayer2;
	std::vector<obj3d> m_ObjPlayer;
	//�T�C���p�̈����ƂȂ�p�x
	float m_sinAngle;
	//���@�̉�]�p
	float rotHead;

	//�J����
	std::unique_ptr<FollowCamera> m_Camera;

	float rotY[20];
	float x[20];
};