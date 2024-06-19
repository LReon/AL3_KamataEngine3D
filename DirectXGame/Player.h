#include <Model.h>
#include <WorldTransform.h>

//enum clsss LRDirection {
//	kRight,
//
//};

class Player {
public:
	void Initialize(Model* model, ViewProjection* viewProjection,const Vector3& position);
	void Update();
	void Draw();
	static inline const float kAcceleration = 1.0f;
	Vector3 velocity_ = {};

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* modelPlayer_ = nullptr;




	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewProjection_ = nullptr;
};