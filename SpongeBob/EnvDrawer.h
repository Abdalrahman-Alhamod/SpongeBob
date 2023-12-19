#ifndef ENV_DRAWER_H
#define ENV_DRAWER_H

#include "Point.h"
#include "Constraints.h"
#include "Color.h"


/**
 * @class EnvDrawer
 * @brief A utility class for drawing environmental elements such as trees, tanks, land, and skyboxes.
 */
class EnvDrawer {
public:
	/**
	 * @brief Constructor for the EnvDrawer class.
	 */
	EnvDrawer();
	/**
	 * @brief Draw a skybox at the specified position and constraints.
	 * @param position The position where the skybox will be drawn.
	 * @param constraints The constraints defining the size of the skybox.
	 */
	void drawSkyBox(const Point& position, const Constraints& constraints);

private:
	int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;
};

#endif // ENV_DRAWER_H
