#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "affine.h"

GameScene::GameScene() {}

GameScene::~GameScene() {
	
	delete debugCamera_;

	delete modelBlock_;
	
	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {

			delete worldTransformBlock;
		}
		

	}
	worldTransformBlocks_.clear();

	delete modelSkydome_;
	
}

void GameScene::Initialize() {

	debugCamera_ = new DebugCamera(1280, 720);


	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	modelSkydome_ = Model::CreateFromOBJ("SkyDome", true);	
	skydome_ = new Skydome();
	skydome_->Initialize(modelSkydome_, &viewProjection_);

	viewProjection_.Initialize();
	modelBlock_ = Model::Create();
	const uint32_t kNumBlockVirtical = 10;
	const uint32_t kNumBlockHrizonal = 20;
	const float kBlockWidth = 2.0f;
	const float kBlockHeight = 2.0f;

	worldTransformBlocks_.resize(kNumBlockHrizonal);

	for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {
		worldTransformBlocks_[i].resize(kNumBlockHrizonal);
		for (uint32_t j = 0; j < kNumBlockHrizonal; ++j) {
			
				if ((i+j)%2==1) {
				continue;
			}

					worldTransformBlocks_[i][j] = new WorldTransform();
					worldTransformBlocks_[i][j]->Initialize();
					worldTransformBlocks_[i][j]->translation_.x = kBlockWidth * j;
					worldTransformBlocks_[i][j]->translation_.y = kBlockHeight * i;
				
			
		}
	}

	


}

void GameScene::Update() {
	debugCamera_->Update();

	#ifdef  _DEBUG

	if (input_->TriggerKey(DIK_SPACE)) {
		debugCameraActive_ = !debugCameraActive_;
	}

#endif //  _DEBUG


	if (debugCameraActive_) {

		debugCamera_->Update();

		viewProjection_.matView = debugCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;
		viewProjection_.TransferMatrix();
	} else {
		viewProjection_.UpdateMatrix();
	}


	skydome_->Update();

	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			if (!worldTransformBlock)
				continue;
			worldTransformBlock->UpdateMatrix();
		}
	}
	
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	skydome_->Deaw();

	/*for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine){
			if (!worldTransformBlock)
				continue;
			modelBlock_->Draw(*worldTransformBlock, viewProjection_);
			
	}
}
	*/
	
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
