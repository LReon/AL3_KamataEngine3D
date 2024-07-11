#pragma once
#include "ViewProjection.h"
#include "MathUtilityForText.h"

class Player;


class CameraController {

public:

	
	void Initialize();

	void Update();

	void SetTarget(Player* target) { target_ = target; }

	void Reset();

	Vector3 targetOffset_ = {0, 0, -15.0f};

private:

	ViewProjection viewProjection_;

	Player* target_ = nullptr;

};
