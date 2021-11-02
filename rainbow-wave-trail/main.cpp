#define CAC_PROJ_NAME "rainbow-wave-trail"
#include <Cacao>
#include <cocos2dx/cocos2d.h>

bool first = true;

cocos2d::ccColor3B shiftHue(cocos2d::ccColor3B &color, int shift, int max, int min) {
	if (color.r == max && color.g != max && color.b == min) {
		color.g += shift;
	} else if (color.r != min && color.g == max && color.b == min) {
		color.r -= shift;
	} else if (color.r == min && color.g == max && color.b != max) {
		color.b += shift;
	} else if (color.r == min && color.g != min && color.b == max) {
		color.g -= shift;
	} else if (color.r != max && color.g == min && color.b == max) {
		color.r += shift;
	} else if (color.r == max && color.g == min && color.b != min) {
		color.b -= shift;
	}
	return color;
}

class $redirect(PlayerObject) {
public:
	void update(float a) {
		if (this->_isDart()) {
			HardStreak *streak = this->_waveStreak();
			cocos2d::ccColor3B color = streak->getColor();
			if (first) {
				first = false;
				color.r = 222;
				color.g = 0;
				color.b = 0;
			}
			streak->setColor(shiftHue(color, 1, 222, 0));
		}

		$PlayerObject::update(a);
	}

	void toggleDartMode(bool a) {
		first = true;
		$PlayerObject::toggleDartMode(a);
	}
} PlayerObjectHook;

$apply();
