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
	/**
	* @brief Draws a person at a specified 3D position with rotation.
	*
	* This function renders a simple person-like figure with textured body parts.
	*
	* @param position The 3D point representing the position of the person.
	* @param rotation The rotation angle (in degrees) around the y-axis.
	*/
	void drawPerson(const Point& position, const float rotation);
};


#endif // PERSON_DRAWER_H
