#include "Player.h"
#include "cassert"
#include <Input.h>
#include <numbers>

void Player::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) {
	// NULLポインタチェック
	/*assert(model);*/

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;

	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
	modelPlayer_ = model;

	modelPlayer_ = Model::CreateFromOBJ("player", true);

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

			acceleration.x += kAcceleration;

		} else if (Input::GetInstance()->PushKey(DIK_LEFT)) {

			acceleration.x -= kAcceleration;
		}
		velocity_.x += acceleration.x;
	}

	worldTransform_.translation_.z += velocity_.z;
	worldTransform_.UpdateMatrix();
}

void Player::Draw() {
	// 3Dモデルを描画
	modelPlayer_->Draw(worldTransform_, *viewProjection_, textureHandle_);
}
