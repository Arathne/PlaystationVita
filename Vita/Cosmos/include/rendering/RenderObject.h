#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

#include <rendering/Color.h>
#include <rendering/Transform.h>
#include <vector>
#include <glm/glm.hpp>

class RenderObject
{
    public:
        RenderObject (void);
        ~RenderObject (void);

        int getVertexStride (void) const;
        int getColorStride (void) const;
        Transform & getTransform (void);
        const glm::mat4 & getModelMatrix (void);

        unsigned int getTotalVertices (void) const;
        const float* getLocalVertices (void) const; 
        const float* getVertexColors (void) const;

    private:
        float* vertexArray_;
        float* colorArray_;

    protected:
        std::vector<glm::vec3> vertices_;
        std::vector<glm::vec4> colors_;
        Transform transform_;

        void updateArrays (void);
};

#endif