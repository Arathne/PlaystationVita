#include <rendering/Color.h>


Color::Color (void):
    r_(0),
    g_(0),
    b_(0),
    a_(255)
{}

Color::Color (int r, int g, int b):
    r_(0),
    g_(0),
    b_(0),
    a_(255)
{
    Color::setRed(r);
    Color::setGreen(g);
    Color::setBlue(b);
}

Color::Color (int r, int g, int b, int a):
    r_(0),
    g_(0),
    b_(0),
    a_(255)
{
    Color::setRed(r);
    Color::setGreen(g);
    Color::setBlue(b);
    Color::setAlpha(a);
}

Color::Color (const Color & rhs):
    r_(rhs.r_),
    g_(rhs.g_),
    b_(rhs.b_),
    a_(rhs.a_)
{}

void Color::setRed (int r)
{
    if (isWithinBounds(r))
        r_ = r;
}

void Color::setGreen (int g)
{
    if (isWithinBounds(g))
        g_ = g;
}

void Color::setBlue (int b)
{
    if (isWithinBounds(b))
        b_ = b;
}

void Color::setAlpha (int a)
{
    if (isWithinBounds(a))
        a_ = a;
}

int Color::getRed (void) const
{
    return r_;
}

int Color::getGreen (void) const
{
    return g_;
}

int Color::getBlue (void) const
{
    return b_;
}

int Color::getAlpha (void) const
{
    return a_;
}

const Color & Color::operator = (const Color & rhs)
{
    if (&rhs != &(*this))
    {
        r_ = rhs.r_;
        g_ = rhs.g_;
        b_ = rhs.b_;
        a_ = rhs.a_;
    }

    return *this;
}

bool Color::operator == (const Color & rhs)
{
    if (r_ == rhs.r_ && g_ == rhs.g_ && b_ == rhs.b_ && a_ == rhs.a_)
        return true;

    return false;
}

bool Color::operator != (const Color & rhs)
{
    return !(*this == rhs);
}

glm::vec4 Color::normalize (void) const
{
    return glm::vec4(r_/255.0f, g_/255.0f, b_/255.0f, a_/255.0f);
}

bool Color::isWithinBounds (int value) const
{
    return (value >= 0 && value < 256) ? true : false;
}