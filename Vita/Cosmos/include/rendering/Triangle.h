#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <rendering/RenderObject.h>

class Triangle : public RenderObject
{
    public:
        Triangle (void);
        Triangle (Color color);
        Triangle (const Triangle & rhs);
        ~Triangle (void);

        void setColor (Color color);

    private:
        Color color_;
};

#endif