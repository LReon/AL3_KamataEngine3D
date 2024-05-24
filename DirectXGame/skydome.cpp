#include "skydome.h"
#include <cassert>

void Skydome::Initialize(Model* skymodel, ViewProjection* viewProjection) {

	assert(skymodel);

	worldTransform_.Initialize();

	skymodel_ = skymodel;
	
	
	viewProjection_ = viewProjection;

}

void Skydome::Update() {
	worldTransform_.TransferMatrix();
	
}

void Skydome::Deaw() {
	skymodel_->Draw(worldTransform_, *viewProjection_);
}
