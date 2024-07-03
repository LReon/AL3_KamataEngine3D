#pragma once
#include "ViewProjection.h"

class CameraController {

public:
	void Initialize();

	void Update();

private:

	ViewProjection viewProjection_;

};
