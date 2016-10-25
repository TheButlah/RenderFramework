#pragma once

#include "glm/mat4x4.hpp"

class Camera {
  public:
    /**
     * Creates a new Camera.
     * @param x  X location in world coordinates
     * @param y  Y location in world coordinates
     * @param z  Z location in world coordinates
     * @param rx Degrees "up" to look
     * @param ry Degrees "right" to look
     * @param rz Degrees clockwise to rotate head
     *           (Will cause world to rotate counter-clockwise)
     */
    Camera(float x, float y, float z, float rx, float ry, float rz);

    ~Camera();

    /**
     * Gets the view matrix representing all the necessary transforms required
     * to convert from world-space to camera-space.
     * Note: DO NOT MODIFY THE RETURNED MATRIX!!!
     * This function returns the object used internally in direcly for speed.
     * Modifying this array will have unforeseen consequences.
     * @return A 4x4 matrix representing the 4x4 view matrix.
     */
    glm::mat4 getViewMatrix();

    /**
     * Sets the location of this camera
     * @param x X location in world coordinates
     * @param y Y location in world coordinates
     * @param z Z location in world coordinates
     */
    void setLocation(float x, float y, float z);

    /**
     * Sets the rotation of this camera
     * @param rx Degrees "up" to look
     * @param ry Degrees "right" to look
     * @param rz Degrees clockwise to rotate "head"
     *           (Will cause world to rotate counter-clockwise)
     */
    void setRotation(float rx,float ry, float rz);

    /**
     * Changes the location of this camera.
     * @param x X distance to move in world coordinates
     * @param y Y distance to move in world coordinates
     * @param z Z distance to move in world coordinates
     */
    void changeLocationBy(float x, float y, float z);

    /**
     * Changes the rotation of this camera.
     * @param rx Degrees "up" to look
     * @param ry Degrees "right" to look
     * @param rz Degrees clockwise to rotate head
     *           (Will cause world to rotate counter-clockwise)
     */
    void changeRotationBy(float rx,float ry, float rz);

    float getX();
    float getY();
    float getZ();
    float getRX();
    float getRY();
    float getRZ();

  private:
    float x,y,z,rx,ry,rz;
    glm::mat4 viewMatrix;
    bool matrixNeedsUpdating;

    void updateMatrix();
};
