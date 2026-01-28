#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <math.h>

class Transform 
{
    public:
        /* Constructors */
        Transform (void);
        Transform (const Transform & rhs);
        
        /* Incremental State */
        void translate (glm::vec3 offset);
        void translateX (float x);
        void translateY (float y);
        void translateZ (float z);

        void rotate (glm::vec3 angles);
        void rotateX (float x);
        void rotateY (float y);
        void rotateZ (float z);

        /* Setters & Getters */
        void setPosition (glm::vec3 position);
        void setPositionX (float x);
        void setPositionY (float y);
        void setPositionZ (float z);

        void setRotation (glm::vec3 angles);
        void setRotationX (float x);
        void setRotationY (float y);
        void setRotationZ (float z);

        void setScale (glm::vec3 scale);
        void setScaleX (float x);
        void setScaleY (float y);
        void setScaleZ (float z);

        glm::vec3 getPosition (void) const;
        glm::vec3 getRotation (void) const;
        glm::vec3 getScale (void) const;

        const glm::mat4 & getMatrix (void);

        /* Operator Overloading */
        const Transform & operator = (const Transform & rhs);
        bool operator == (const Transform & rhs);
        bool operator != (const Transform & rhs);

    private:
        glm::vec3 translation_;
        glm::vec3 rotation_;
        glm::vec3 scale_; 
        glm::mat4 matrix_;

        bool update_;

        void updateMatrix (void);

};

#endif