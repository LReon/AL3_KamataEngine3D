#pragma once
#include "Model.h"

class DeathParticles {

	void Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position);

	void Update();

	void Draw();

};
