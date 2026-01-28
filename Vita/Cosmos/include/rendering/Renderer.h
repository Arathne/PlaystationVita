#ifndef RENDERER_H
#define RENDERER_H

#include <rendering/Color.h>
#include <rendering/RenderObject.h>
#include <vitaGL.h>

class Renderer 
{
    public:
        Renderer (void);
        ~Renderer (void);

        void setClearColor (Color color);

        void clear (void);
        void swap (void);
        void draw (RenderObject & object);
};

#endif