#include "Player.h"
<<<<<<< Updated upstream
#include "cassert"

void Player::Initialize(Model* model,uint32_t textureHandle,ViewProjection* viewProjection) {
	// NULLポインタチェック
	assert(model);
	
	worldTransform_.Initialize();

	model_ = model;
	textureHandle_ = textureHandle;
	// 引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;


=======
#include <cassert>


void Player::Initialize(Model* model, uint32_t textureHandle,ViewProjection* viewProjection) { 
	// NULLポインタチェック
	assert(model);

	worldTransform_.Initialize();

	model_ = model;
	textureHandle_ = textureHandle;
	// 引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;
	
>>>>>>> Stashed changes

}

void Player::Update() {
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Player::Draw() {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_, textureHandle_);
}
