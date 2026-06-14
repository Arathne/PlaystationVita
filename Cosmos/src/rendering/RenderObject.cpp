#include <rendering/RenderObject.h>

RenderObject::RenderObject (void):
    vertexArray_(nullptr),
    colorArray_(nullptr)
{}

RenderObject::~RenderObject (void) 
{
    if (vertexArray_ != nullptr)
        delete[] vertexArray_;

    if (colorArray_ != nullptr)
        delete[] colorArray_;
}

int RenderObject::getVertexStride (void) const
{ 
    return 3;
}

int RenderObject::getColorStride (void) const
{ 
    return 4; 
}

Transform & RenderObject::getTransform (void)
{
    return transform_;
}

const glm::mat4 & RenderObject::getModelMatrix (void) 
{ 
    return transform_.getMatrix(); 
}

unsigned int RenderObject::getTotalVertices (void) const 
{ 
    return vertices_.size(); 
}

const float* RenderObject::getLocalVertices (void) const
{
    return vertexArray_;
} 

const float* RenderObject::getVertexColors (void) const 
{
    return colorArray_;
}

void RenderObject::updateArrays (void)
{
    if (vertexArray_ != nullptr)
        delete[] vertexArray_;

    vertexArray_ = new float[vertices_.size()*3];

    for (int i = 0; i < vertices_.size(); i++) 
    {
        glm::vec3 vertex = vertices_.at(i);
        vertexArray_[i*3] = vertex.x;
        vertexArray_[i*3+1] = vertex.y;
        vertexArray_[i*3+2] = vertex.z;
    }

    if (colorArray_ != nullptr)
        delete[] colorArray_;

    colorArray_ = new float[colors_.size()*4];

    for (int i = 0; i < colors_.size(); i++) 
    {
        glm::vec4 color = colors_.at(i);
        colorArray_[i*4] = color.r;
        colorArray_[i*4+1] = color.g;
        colorArray_[i*4+2] = color.b;
        colorArray_[i*4+3] = color.a;
    }
}