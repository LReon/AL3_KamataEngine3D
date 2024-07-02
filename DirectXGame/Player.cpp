#define NOMINMAX
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
	
	bool landing = false;

	if (velocity_.y < 0) {
	
		if (worldTransform_.translation_.y <= 1.0f) {
			landing = true;
		}

	}

	
	if (onGround_) {

		


		if (Input::GetInstance()->PushKey(DIK_RIGHT) || Input::GetInstance()->PushKey(DIK_LEFT)) {

			Vector3 acceleration = {};
			if (Input::GetInstance()->PushKey(DIK_RIGHT)) {

				if (lrDirection_ != LRDirection::kRight) {

					lrDirection_ = LRDirection::kRight;

					// worldTransform_.rotation_.y = turnFirstRotationY_;
					turnFirstRotationY_ = worldTransform_.rotation_.y;

					turnTimer_ = kTimeTurn;
				}

				if (velocity_.x < 0.0f) {
					velocity_.x *= (1.0f - kAttenuation);
				}

				acceleration.x += kAcceleration;

			} else if (Input::GetInstance()->PushKey(DIK_LEFT)) {

				if (lrDirection_ != LRDirection::kLeft) {
					lrDirection_ = LRDirection::kLeft;
					turnFirstRotationY_ = worldTransform_.rotation_.y;
					turnTimer_ = kTimeTurn;
				}

				if (velocity_.x > 0.0f) {

					velocity_.x *= (1.0f - kAttenuation);
				}

				acceleration.x -= kAcceleration;
			}
			velocity_.x += acceleration.x;
			velocity_.x = std::clamp(velocity_.x, -kLimitRunSpeed, kLimitRunSpeed);

		} 
		else {
			velocity_.x *= (1.0f - kAttenuation);
			//velocity_.z *= (1.0f - kAttenuation);

		}

		if (Input::GetInstance()->PushKey(DIK_UP)) {
			velocity_ += Vector3(0, kJumpAcceleration, 0);
		}

	} else {
		velocity_ += Vector3(0, -kGravityAcceleration, 0);
		velocity_.y = std::max(velocity_.y, -kLimitFallSpeed);

	}

	

	if (turnTimer_ > 0.0f) {

		turnTimer_ -= 1.0f / 60.0f;

		float destinationRotationYTable[] = {std::numbers::pi_v<float> / 2.0f, std::numbers::pi_v<float> * 3.0f / 2.0f};

		float destinationRotationY = destinationRotationYTable[static_cast<uint32_t>(lrDirection_)];

		worldTransform_.rotation_.y = EaseInOut(destinationRotationY,turnFirstRotationY_,turnTimer_ / kTimeTurn);
	}

	if (velocity_.y > 0.0f) {
		onGround_ = false;

	} else {

		if (landing) {

			worldTransform_.translation_.y = 1.5f;
			velocity_.x *= (1.0f - kAttenuation);
			velocity_.y = 0.0f;
			onGround_ = true;
		}
	}

	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.y += velocity_.y;
	worldTransform_.translation_.z += velocity_.z;
	worldTransform_.UpdateMatrix();
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Player::Draw() {
	// 3Dモデルを描画
	modelPlayer_->Draw(worldTransform_, *viewProjection_, textureHandle_);
}

void Player::GetWorldTransform() {}
