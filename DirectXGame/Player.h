#include <WorldTransform.h>
#include <Model.h>

class Player {
public:
	void Initialize(Model* model,uint32_t textureHandle,ViewProjection* viewProjection);
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
};
