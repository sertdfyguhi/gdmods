#define CAC_PROJ_NAME "no-flip-gravity"
#include <Cacao>

class $redirect(PlayerObject) {
public:
    void flipGravity(bool b, bool c) {}
	void hardFlipGravity() {}
} hook1;

class $redirect(PlayLayer) {
public:
    virtual void flipGravity(PlayerObject* a, bool b, bool c) {}
} hook2;

class $redirect(GJBaseGameLayer) {
public:
    void flipGravity(PlayerObject* a, bool b, bool c) {}
} hook3;

class $redirect(LevelEditorLayer) {
public:
    void flipGravity(PlayerObject* a, bool b, bool c) {}
} hook4;

$apply();