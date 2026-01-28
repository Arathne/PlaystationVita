#ifndef TEST_COLOR_H
#define TEST_COLOR_H

#include <rendering/Color.h>
#include <tests/Test.h>
#include <glm/glm.hpp>

class TestColor : public Test 
{
    public:
        std::string getName (void) const;
        void run (Logger & log);

    private:
        void constructor_empty (Logger & log);
        void constructor_argumentsRedGreenBlue (Logger & log);
        void constructor_argumentsRedGreenBlueAlpha (Logger & log);
        void constructor_copy (Logger & log);

        void setterAndGetter_red (Logger & log);
        void setterAndGetter_green (Logger & log);
        void setterAndGetter_blue (Logger & log);
        void setterAndGetter_alpha (Logger & log);

        void operatorAssign_copy (Logger & log);
        void operatorEquals_whenIdentical_returnsTrue (Logger & log);
        void operatorEquals_whenDifferent_returnsFalse (Logger & log);
        void operatorNotEquals_whenIdentical_returnsFalse (Logger & log);
        void operatorNotEquals_whenDifferent_returnsTrue (Logger & log);

        void attributes_whenParam255_allow (Logger & log);
        void attributes_whenParam256_disallow (Logger & log);
};

#endif