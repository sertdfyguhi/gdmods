#define CAC_PROJ_NAME "no-wave-pulse"
#include <Cacao>

class $redirect(PlayerObject) {
public:
		void update(float a) {
			$PlayerObject::update(a);

			if ($PlayerObject::_isDart()) {
				$PlayerObject::_waveStreak()->m_waveSize = 0.14;
			}
		}
} hook1;

$apply();