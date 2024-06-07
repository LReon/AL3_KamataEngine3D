#pragma once
#include <Model.h>

#include "Player.h"

#include "cassert"

    class Player {
public:
	void Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection);

	void Update();

	void Draw();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewProjection_ = nullptr;

//class Player {
//public:
//	void Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position);
//
//MapChipField* mapChipField_;
//	WorldTransform worldTransform_;
//	ViewProjection* viewProjection_;
//	Model* model_ = nullptr;
//	uint32_t textureHandle_ = 0u;
//
//};
