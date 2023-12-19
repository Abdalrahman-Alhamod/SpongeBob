#include "PersonDrawer.h"
#include <GL/glut.h>  
#include "Point.h"
#include "Color.h"
#include "Constants.h"
#include "Texture.h"
#include "Box.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "PrimitiveDrawer.h"

// Constructor for PersonDrawer, initializes textures using BMP files for different body parts.
PersonDrawer::PersonDrawer()
{
    textures[3] = LoadTexture((char*)"assets/materials/Front.bmp", 255);
    textures[2] = LoadTexture((char*)"assets/materials/Back.bmp", 255);
    textures[5] = LoadTexture((char*)"assets/materials/Left.bmp", 255);
    textures[4] = LoadTexture((char*)"assets/materials/Right.bmp", 255);
    textures[1] = LoadTexture((char*)"assets/materials/Up.bmp", 255);
    textures[0] = LoadTexture((char*)"assets/materials/Down.bmp", 255);
}

// Function to draw a person at a specified position with given rotation and size.
void PersonDrawer::drawPerson(const Point& position, const float rotation)
{
    // Push the current matrix onto the stack.
    glPushMatrix();

    // Translate and rotate the entire person based on the provided position and rotation.
    glTranslatef(position.x + 25, position.y - 70, position.z + 20);
    glRotatef(rotation, 0, 1, 0);

    // Draw the torso of the person using a textured box.
    Box torso = Box();
    torso.drawOutside(50, 20, 50, textures);

    // Move to the right shoulder position.
    glTranslatef(-10, 10, 10);
    glColor3f(1, 0.85, 0);

    // Draw the right arm, including the hand and palm.
    glPushMatrix();
    glRotatef(45, 0, 0, 1);
    glRotated(25 * sin((position.x + position.y + position.z) * 0.1), 1, 1, 0);
    Cylinder rightHand = Cylinder(1.5, 1.5, 32);
    rightHand.setUpAxis(1);
    rightHand.draw();

    glTranslatef(-15, 0, 0);
    Sphere rightPalm = Sphere(3);
    rightPalm.draw();
    // PrimitiveDrawer().drawSphere(3, Color(1*255, 0.85 * 255, 0.0 * 255));
    glTranslatef(15, 0, 0);

    // Restore the matrix to the previous state.
    glPopMatrix();

    // Move to the left shoulder position.
    glTranslatef(70, 0, 0);

    // Draw the left arm, including the hand and palm.
    glPushMatrix();
    glRotatef(-45, 0, 0, 1);
    glRotated(25 * sin((position.x + position.y + position.z) * 0.1) + 10, 1, 1, 0);
    Cylinder leftHand = Cylinder(1.5, 1.5, 32);
    leftHand.setUpAxis(1);
    leftHand.draw();

    glTranslatef(15, 0, 0);
    Sphere leftPalm = Sphere(3);
    leftPalm.draw();
    // PrimitiveDrawer().drawSphere(3, Color(1*255, 0.85 * 255, 0.0 * 255));
    glTranslatef(-15, 0, 0);

    // Restore the matrix to the previous state.
    glPopMatrix();

    // Move to the hip position.
    glTranslatef(-45, -25, 0);

    // Draw the right leg and right shoe.
    glPushMatrix();
    glColor3f(1, 0.85, 0);
    glRotated(25 * sin((position.x + position.y + position.z) * 0.1), 1, 0, 0);
    Cylinder rightLeg = Cylinder(1.5, 1.5, 30);
    rightLeg.setUpAxis(2);
    rightLeg.draw();

    glColor3f(0.545, 0.271, 0.075);
    glTranslatef(0, -15, 0);
    Cylinder leftShoes = Cylinder(3, 1.5, 5);
    leftShoes.setUpAxis(2);
    leftShoes.draw();
    glTranslatef(0, 15, 0);

    // Restore the matrix to the previous state.
    glPopMatrix();

    // Move to the other hip position.
    glTranslatef(20, 0, 0);

    // Draw the left leg and left shoe.
    glPushMatrix();
    glColor3f(1, 0.85, 0);
    glRotated(25 * sin((position.x + position.y + position.z) * 0.1 + 10), 1, 0, 0);
    Cylinder leftLeg = Cylinder(1.5, 1.5, 30);
    leftLeg.setUpAxis(2);
    leftLeg.draw();

    glColor3f(0.545, 0.271, 0.075);
    glTranslatef(0, -15, 0);
    Cylinder rightShoes = Cylinder(3, 1.5, 5);
    rightShoes.setUpAxis(2);
    rightShoes.draw();
    glTranslatef(0, +15, 0);

    // Restore the matrix to the previous state.
    glPopMatrix();

    // Set the color to white for subsequent drawings.
    glColor4f(1, 1, 1, 1);

    // Pop the matrix from the stack, restoring the original state.
    glPopMatrix();
}
