#ifndef COLOR_H
#define COLOR_H

#include <glm/glm.hpp>

class Color 
{
    public:
        /* Constructors */
        Color (void);
        Color (int r, int g, int b);
        Color (int r, int g, int b, int a);
        Color (const Color & rhs);

        /* Setters & Getters */
        void setRed (int r);
        void setGreen (int g);
        void setBlue (int b);
        void setAlpha (int a);

        int getRed (void) const;
        int getGreen (void) const;
        int getBlue (void) const;
        int getAlpha (void) const;

        /* Operator Overloading */
        const Color & operator = (const Color & rhs);
        bool operator == (const Color & rhs);
        bool operator != (const Color & rhs);

        /* Behavioral */
        glm::vec4 normalize (void) const;

    private:
        unsigned char r_;
        unsigned char g_;
        unsigned char b_;
        unsigned char a_;

        bool isWithinBounds (int value) const;
};

#endif