#include <rendering/Transform.h>

#define ZERO_VECTOR glm::vec3(0.0f, 0.0f, 0.0f)
#define IDENTITY_MATRIX glm::mat4(1.0f)

Transform::Transform (void):
    translation_(ZERO_VECTOR),
    rotation_(ZERO_VECTOR),
    scale_(ZERO_VECTOR),
    matrix_(IDENTITY_MATRIX),
    update_(false)
{}

Transform::Transform (const Transform & rhs):
    translation_(rhs.translation_),
    rotation_(rhs.rotation_),
    scale_(rhs.scale_),
    matrix_(rhs.matrix_),
    update_(rhs.update_)
{}

void Transform::translate (glm::vec3 offset) 
{
    translation_ += offset;
    update_ = true;
}

void Transform::translateX (float x) 
{
    translation_.x += x;
    update_ = true;
}

void Transform::translateY (float y) 
{
    translation_.y += y;
    update_ = true;
}

void Transform::translateZ (float z) 
{
    translation_.z += z;
    update_ = true;
}

void Transform::rotate (glm::vec3 angles) 
{
    rotation_.x = fmod(rotation_.x + angles.x, 360);
    rotation_.y = fmod(rotation_.y + angles.y, 360);
    rotation_.z = fmod(rotation_.z + angles.z, 360);
    update_ = true;
}

void Transform::rotateX (float x) 
{
    rotation_.x = fmod(rotation_.x + x, 360);
    update_ = true;
}

void Transform::rotateY (float y) 
{
    rotation_.y = fmod(rotation_.y + y, 360);
    update_ = true;
}

void Transform::rotateZ (float z) 
{
    rotation_.z = fmod(rotation_.z + z, 360);
    update_ = true;
}

void Transform::setPosition (glm::vec3 position) 
{
    translation_ = position;
    update_ = true;
}

void Transform::setPositionX (float x) 
{
    translation_.x = x;
    update_ = true;
}

void Transform::setPositionY (float y) 
{
    translation_.y = y;
    update_ = true;
}

void Transform::setPositionZ (float z) 
{
    translation_.z = z;
    update_ = true;
}

void Transform::setRotation (glm::vec3 angles) 
{
    rotation_.x = fmod(angles.x, 360);
    rotation_.y = fmod(angles.y, 360);
    rotation_.z = fmod(angles.z, 360);
    update_ = true;
}

void Transform::setRotationX (float x) 
{
    rotation_.x = fmod(x, 360);
    update_ = true;
}

void Transform::setRotationY (float y) 
{
    rotation_.y = fmod(y, 360);
    update_ = true;
}

void Transform::setRotationZ (float z) 
{
    rotation_.z = fmod(z, 360);
    update_ = true;
}

void Transform::setScale (glm::vec3 scale) 
{
    scale_ = scale;
    update_ = true;
}

void Transform::setScaleX (float x) 
{
    scale_.x = x;
    update_ = true;
}

void Transform::setScaleY (float y) 
{
    scale_.y = y;
    update_ = true;
}

void Transform::setScaleZ (float z) 
{
    scale_.z = z;
    update_ = true;
}

glm::vec3 Transform::getPosition (void) const 
{
    return translation_;
}

glm::vec3 Transform::getRotation (void) const 
{
    return rotation_;
}

glm::vec3 Transform::getScale (void) const 
{
    return scale_;
}

void Transform::updateMatrix (void) 
{
    matrix_ = IDENTITY_MATRIX;

    //matrix_ = glm::scale(matrix_, scale_);
    matrix_ = glm::rotate(matrix_, glm::radians(rotation_.x), glm::vec3(1.0f, 0.0f, 0.0f));
    matrix_ = glm::rotate(matrix_, glm::radians(rotation_.y), glm::vec3(0.0f, 1.0f, 0.0f));
    matrix_ = glm::rotate(matrix_, glm::radians(rotation_.z), glm::vec3(0.0f, 0.0f, 1.0f));
    matrix_ = glm::translate(matrix_, translation_);

    //glm::mat4 scaleMatrix = glm::scale(IDENTITY_MATRIX, scale_);
    //glm::mat4 rotationMatrix = glm::rotate(IDENTITY_MATRIX, glm::radians(rotation_.x), glm::vec3(1.0f, 0.0f, 0.0f));
    //glm::mat4 translationMatrix = glm::translate(IDENTITY_MATRIX, translation_);

    //rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation_.y), glm::vec3(0.0f, 1.0f, 0.0f));
    //rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation_.z), glm::vec3(0.0f, 0.0f, 1.0f));

    //matrix_;
    //matrix_ = scaleMatrix * rotationMatrix * translationMatrix;
    //matrix_ = translationMatrix * rotationMatrix * scaleMatrix;
}

const glm::mat4 & Transform::getMatrix (void)
{
    if (update_) 
    {
        Transform::updateMatrix();
        update_ = false;
    }

    return matrix_;
}

const Transform & Transform::operator = (const Transform & rhs) 
{
    if (&rhs != &(*this))
	{
        translation_ = rhs.translation_;
        rotation_ = rhs.rotation_;
        scale_ = rhs.scale_;
        matrix_ = rhs.matrix_;
        update_ = rhs.update_;
    }

    return *this;
}

bool Transform::operator == (const Transform & rhs)
{
    if (&rhs == &(*this))
        return true;

    if (translation_ == rhs.translation_ && rotation_ == rhs.rotation_ && scale_ == rhs.scale_) {
        if (matrix_ == rhs.matrix_ && update_ == rhs.update_) {
            return true;
        }
    }

    return false;
}

bool Transform::operator != (const Transform & rhs)
{
    return !(*this == rhs);
}