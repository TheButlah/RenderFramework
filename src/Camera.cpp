#include "Camera.hpp"
#include "glm/gtc/matrix_transform.hpp"

Camera::Camera(float x, float y, float z, float rx, float ry, float rz) :
  x(x), y(y), z(z), rx(rx), ry(ry), rz(rz), matrixNeedsUpdating(true) {
  updateMatrix();
}

void Camera::updateMatrix() {
  viewMatrix = glm::mat4(1.0f);
  viewMatrix = glm::translate(viewMatrix, glm::vec3(-x,-y,-z));
  viewMatrix = glm::rotate(viewMatrix, rx, glm::vec3(-1.f,0.f,0.f));
  viewMatrix = glm::rotate(viewMatrix, ry, glm::vec3(0.f,1.f,0.f));
  viewMatrix = glm::rotate(viewMatrix, rz, glm::vec3(0.f,0.f,1.f));
  matrixNeedsUpdating = false;
}

glm::mat4 Camera::getViewMatrix() {
  if (matrixNeedsUpdating) updateMatrix();
  return viewMatrix;
}

void Camera::setLocation(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
  matrixNeedsUpdating = true;
}

void Camera::setRotation(float rx, float ry, float rz) {
  this->rx = rx;
  this->ry = ry;
  this->rz = rz;
  matrixNeedsUpdating = true;
}

void Camera::changeLocationBy(float x, float y, float z) {
  this->x += x;
  this->y += y;
  this->z += z;
  matrixNeedsUpdating = true;
}

void Camera::changeRotationBy(float rx, float ry, float rz) {
  this->rx += rx;
  this->ry += ry;
  this->rz += rz;
  matrixNeedsUpdating = true;
}

float Camera::getX() {
  return this->x;
}

float Camera::getY() {
  return y;
}

float Camera::getZ() {
  return z;
}

float Camera::getRX() {
  return x;
}

float Camera::getRY() {
  return y;
}

float Camera::getRZ() {
  return z;
}
