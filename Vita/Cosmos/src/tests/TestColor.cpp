#include <tests/TestColor.h>

std::string TestColor::getName (void) const
{
    return "TestColor";
}

void TestColor::run (Logger & log)
{
    constructor_empty(log);
    constructor_argumentsRedGreenBlue(log);
    constructor_argumentsRedGreenBlueAlpha(log);
    constructor_copy(log);
    setterAndGetter_red(log);
    setterAndGetter_green(log);
    setterAndGetter_blue(log);
    setterAndGetter_alpha(log);
    operatorAssign_copy(log);
    operatorEquals_whenIdentical_returnsTrue(log);
    operatorEquals_whenDifferent_returnsFalse(log);
    operatorNotEquals_whenIdentical_returnsFalse(log);
    operatorNotEquals_whenDifferent_returnsTrue(log);
    attributes_whenParam255_allow (log);
    attributes_whenParam256_disallow (log);
}

void TestColor::constructor_empty (Logger & log)
{
    Color color;

    glm::vec4 expectedColor = glm::vec4(0, 0, 0, 255);
    glm::vec4 actualColor = glm::vec4(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

    bool result = (expectedColor == actualColor);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::constructor_argumentsRedGreenBlue (Logger & log)
{
    Color color(10,20,30);

    glm::vec4 expectedColor = glm::vec4(10, 20, 30, 255);
    glm::vec4 actualColor = glm::vec4(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

    bool result = (expectedColor == actualColor);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::constructor_argumentsRedGreenBlueAlpha (Logger & log)
{
    Color color(10,20,30,40);

    glm::vec4 expectedColor = glm::vec4(10, 20, 30, 40);
    glm::vec4 actualColor = glm::vec4(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

    bool result = (expectedColor == actualColor);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::constructor_copy (Logger & log)
{
    Color* color1 = new Color(1,2,3,4);
    Color color2(*color1);
    delete color1;

    glm::vec4 expectedColor = glm::vec4(1, 2, 3, 4);
    glm::vec4 actualColor = glm::vec4(color2.getRed(), color2.getGreen(), color2.getBlue(), color2.getAlpha());

    bool result = (expectedColor == actualColor);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::setterAndGetter_red (Logger & log)
{
    Color color;
    color.setRed(1);

    int expected = 1;
    int actual = color.getRed();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::setterAndGetter_green (Logger & log)
{
    Color color;
    color.setGreen(1);

    int expected = 1;
    int actual = color.getGreen();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::setterAndGetter_blue (Logger & log)
{
    Color color;
    color.setBlue(1);

    int expected = 1;
    int actual = color.getBlue();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::setterAndGetter_alpha (Logger & log)
{
    Color color;
    color.setAlpha(1);

    int expected = 1;
    int actual = color.getAlpha();

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::operatorAssign_copy (Logger & log)
{
    Color color1(1,2,3,4);
    Color color2 = color1;

    glm::vec4 expected = glm::vec4(1,2,3,4);
    glm::vec4 actual = glm::vec4(color2.getRed(), color2.getGreen(), color2.getBlue(), color2.getAlpha());

    bool result = (expected == actual);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::operatorEquals_whenIdentical_returnsTrue (Logger & log)
{
    Color color1;
    Color color2;

    bool expected = true;
    bool actual = (color1 == color2);

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestColor::operatorEquals_whenDifferent_returnsFalse (Logger & log)
{
    Color color1(1,1,1);
    Color color2;

    bool expected = false;
    bool actual = (color1 == color2);

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestColor::operatorNotEquals_whenIdentical_returnsFalse (Logger & log)
{
    Color color1;
    Color color2;

    bool expected = false;
    bool actual = (color1 != color2);

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestColor::operatorNotEquals_whenDifferent_returnsTrue (Logger & log)
{
    Color color1(1,1,1);
    Color color2;

    bool expected = true;
    bool actual = (color1 != color2);

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestColor::attributes_whenParam255_allow (Logger & log)
{
    Color color(255,255,255,255);
    
    int expected = 255;
    int actual = color.getRed();

    bool result = (actual == expected);
    UnitTest::equals(true, result, __FUNCTION__, log);
}

void TestColor::attributes_whenParam256_disallow (Logger & log)
{
    Color color(256,256,256,256);
    
    int expected = 256;
    int actual = color.getRed();

    bool result = (actual == expected);
    UnitTest::equals(false, result, __FUNCTION__, log);
}