#include <numbers>
#include "Player.h"
#include "cassert"
#include <Input.h>
#include <algorithm>

void Player::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) {
	// NULLポインタチェック
	/*assert(model);*/

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
	modelPlayer_ = model;

	modelPlayer_ = Model::CreateFromOBJ("player",true);
	
	
	

	/*textureHandle_ = textureHandle;*/
	// 引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;
}

void Player::Update() {
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
	
	

	if (Input::GetInstance()->PushKey(DIK_RIGHT) || Input::GetInstance()->PushKey(DIK_LEFT)) {
	
	Vector3 acceleration = {};
		if (Input::GetInstance()->PushKey(DIK_RIGHT)) {
		
			if (lrDirection_ != LRDirection::kRight) {
			
			lrDirection_ = LRDirection::kRight;
			
			}

			if (velocity_.x < 0.0f) {
				velocity_.x *= (1.0f - kAttenuation);
			}


			acceleration.x += kAcceleration;


		} else if (Input::GetInstance()->PushKey(DIK_LEFT)) {

			if (lrDirection_ != LRDirection::kLeft) {
				lrDirection_ = LRDirection::kLeft;
			
			}
			
			if (velocity_.x > 0.0f) {
			
				velocity_.x *= (1.0f - kAttenuation);
			}

			acceleration.x -= kAcceleration;
		} 
		velocity_.x += acceleration.x;
		velocity_.x = std::clamp(velocity_.x, -kLimitRunSpeed, kLimitRunSpeed);
	
	} else {
		velocity_.x *= (1.0f - kAttenuation);
	}

	float destinationRotationYTable[] = {
		std::numbers::pi_v<float> / 2.0f, 
		std::numbers::pi_v<float> * 3.0f / 2.0f
	};

	float destinationRotationY = destinationRotationYTable[static_cast<uint32_t>(lrDirection_)];

	worldTransform_.rotation_.y = destinationRotationY;
	

	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.y += velocity_.y;
	worldTransform_.translation_.z += velocity_.z;
	worldTransform_.UpdateMatrix();
}

void Player::Draw() {
	// 3Dモデルを描画
	modelPlayer_->Draw(worldTransform_, *viewProjection_, textureHandle_);
}