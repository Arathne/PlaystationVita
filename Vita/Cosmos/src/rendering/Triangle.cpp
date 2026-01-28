#include <rendering/Triangle.h>

Triangle::Triangle (void) 
{
    vertices_.push_back(glm::vec3( 0.0f,  1.0f,  0.0f));
    vertices_.push_back(glm::vec3(-1.0f, -1.0f,  0.0f));
    vertices_.push_back(glm::vec3( 1.0f, -1.0f,  0.0f));
    Triangle::setColor(Color(255, 0, 0));
    transform_.setScale(glm::vec3(1.0f, 1.0f, 0.0f));
}

Triangle::Triangle (Color color) 
{
    vertices_.push_back(glm::vec3( 0.0f,  1.0f,  0.0f));
    vertices_.push_back(glm::vec3(-1.0f, -1.0f,  0.0f));
    vertices_.push_back(glm::vec3( 1.0f, -1.0f,  0.0f));
    Triangle::setColor(color);
    transform_.setScale(glm::vec3(1.0f, 1.0f, 0.0f));
}

Triangle::Triangle (const Triangle & rhs)
{
    vertices_ = rhs.vertices_;
    colors_ = rhs.colors_;
    transform_ = rhs.transform_;

    color_ = rhs.color_;
    RenderObject::updateArrays();
}

Triangle::~Triangle (void) {}

void Triangle::setColor (Color color)
{   
    for (int i = 0; i < vertices_.size(); i++)
    {
        colors_.push_back(color.normalize());
    }

    RenderObject::updateArrays();
}