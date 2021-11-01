#define CAC_PROJ_NAME "no-mirror-portal"
#include <Cacao>

class $redirect(PlayLayer) {
public:
	void toggleFlipped(bool a, bool b){}
} PlayLayerHook;

$apply();
