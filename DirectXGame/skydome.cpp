#include "skydome.h"
#include <cassert>

void Skydome::Initialize(Model* model, ViewProjection* viewProjection) {

	assert(model);

	worldTransform_.Initialize();

	model_ = model;
	
	// 引数の内容をメンバ変数に記録
	viewProjection_ = viewProjection;

}

void Skydome::Update() {
	worldTransform_.TransferMatrix();

}

void Skydome::Deaw() {
	model_->Draw(worldTransform_, *viewProjection_);
}
