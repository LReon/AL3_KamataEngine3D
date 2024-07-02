#pragma once
#include "ViewProjection.h"
#include "Player.h"
#include "MathUtilityForText.h"

class Player;

class CameraController {

public:
	void Initialize(/*ViewProjection viewProjection,Player* target*/);

	void Update();

	void SetTarget(Player* target) { target_ = target; }

	void Reset();

	Vector3 targetOffset_ = {0, 0, -15.0f};
	Player* target_ = nullptr;

	const ViewProjection& GetViewProjection() const { return viewProjection_; }

private:

	ViewProjection viewProjection_;


};
