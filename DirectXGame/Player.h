#include <Model.h>
#include <WorldTransform.h>

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

	LRDirection lrDirection_ = LRDirection::kRight;
private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* modelPlayer_ = nullptr;



	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewProjection_ = nullptr;
};