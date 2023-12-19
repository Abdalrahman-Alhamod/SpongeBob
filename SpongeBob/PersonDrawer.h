#ifndef PERSON_DRAWER_H
#define PERSON_DRAWER_H

#include "Point.h"
#include "Constraints.h"
#include "Color.h"
#include "Camera.h"

/**
 * @class PersonDrawer
 * @brief A utility class for drawing personModel
 */
class PersonDrawer {
private:
	Vector3dStruct View;        ///< View direction vector.
	Vector3dStruct RightVector; ///< Right vector.
	Vector3dStruct Up;           ///< Up vector.
	Vector3dStruct Position;     ///< person position vector.

	GLfloat RotatedX, RotatedY, RotatedZ; ///< Rotation angles around X, Y, and Z axes.

public:
	PersonDrawer();
	int textures[6];

	void drawPerson(const Point& position,const float rotation, const float size);
};


#endif // PERSON_DRAWER_H
