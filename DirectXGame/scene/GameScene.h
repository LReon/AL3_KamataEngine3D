#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "MapChipField.h"
#include "Player.h"
#include "CameraController.h"
#include "DebugCamera.h"


/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/*bool isDebugCameraActive = false;

	DebugCamera* debugCamera_ = nullptr;*/

	MapChipField* mapChipField_;

	Model* modelBlock_ = nullptr;

	ViewProjection viewProjection_;

	Player* player_ = nullptr;

	Model* modelPlayerResource_ = nullptr;
	


	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;



	void GenerateBlocks();

	CameraController* cameraController_;

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
