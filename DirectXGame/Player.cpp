#include "Player.h"
#include "WorldTransform.h"
#include <numbers>
#include "MapChipField.h"

#include <Model.h>
#include <WorldTransform.h>
#include "cassert"


void Player::Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection) {
	// NULLポインタチェック

	worldTransform_.Ini

	assert(model);


	model_ = model;
	textureHandle_ = textureHandle;
	// 引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;


//void Player::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) {
//
//	worldTransform_.Initialize();
//	worldTransform_.translation_ = position;
//
//	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
//
//	
//
//}
