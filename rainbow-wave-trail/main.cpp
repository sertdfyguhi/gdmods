#define CAC_PROJ_NAME "rainbow-wave-trail"
#include <Cacao>
#include <cocos2dx/cocos2d.h>

bool first = true;

class $redirect(PlayerObject) {
public:
	void update(float a) {
		if ($PlayerObject::_isDart()) {
			HardStreak *streak = this->_waveStreak();
			cocos2d::ccColor3B color = streak->getColor();
			if (first) {
				first = false;
				color.r = 255;
				color.g = 0;
				color.b = 0;
			}
			// lmao
			if (color.r == 255 && color.g != 255 && color.b == 0) {
				color.g += 1;
			} else if (color.r != 0 && color.g == 255 && color.b == 0) {
				color.r -= 1;
			} else if (color.r == 0 && color.g == 255 && color.b != 255) {
				color.b += 1;
			} else if (color.r == 0 && color.g != 0 && color.b == 255) {
				color.g -= 1;
			} else if (color.r != 255 && color.g == 0 && color.b == 255) {
				color.r += 1;
			} else if (color.r == 255 && color.g == 0 && color.b != 0) {
				color.b -= 1;
			}
			streak->setColor(color);
		}

		$PlayerObject::update(a);
	}

	void toggleDartMode(bool a) {
		first = true;
		$PlayerObject::toggleDartMode(a);
	}
} PlayerObjectHook;

$apply();
