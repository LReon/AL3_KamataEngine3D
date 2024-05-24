#include "GameScene.h"
#include "WorldTransform.h"
#include "affine.h"
#include "Vector3.h"


void WorldTransform::UpdateMatrix() { 
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_); 

	TransferMatrix();
}




