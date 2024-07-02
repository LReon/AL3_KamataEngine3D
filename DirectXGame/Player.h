#include <Model.h>
#include <WorldTransform.h>
#include "MathUtilityForText.h"

enum class LRDirection {
	kRight,
	kLeft
};


class Player {
public:
	void Initialize(Model* model, ViewProjection* viewProjection,const Vector3& position);
	void Update();
	void Draw();
	static inline const float kAcceleration = 0.05f;
	static inline const float kAttenuation = 0.1f;
	static inline const float kLimitRunSpeed = 5.0f;
	Vector3 velocity_ = {};

	WorldTransform GetWorldTransform();

	LRDirection lrDirection_ = LRDirection::kRight;
	float turnFirstRotationY_ = 0.0f;
	float turnTimer_ = 0.0f;
	static inline const float kTimeTurn = 0.3f;

	bool onGround_ = true;

	static inline const float kGravityAcceleration = 0.5f;
	static inline const float kLimitFallSpeed = 0.5f;
	static inline const float kJumpAcceleration = 1.5f;

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* modelPlayer_ = nullptr;



	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewProjection_ = nullptr;
};