#include "Proteus_pch.h"
#include <Proteus.h>

class SandBox : public Proteus::Application {

public:

	SandBox() {

	}
	~SandBox() {

	}
};

Proteus::Application* Proteus::CreateApplication() {
	return new SandBox();
}
