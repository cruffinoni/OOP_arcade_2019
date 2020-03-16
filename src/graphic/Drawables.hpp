/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Drawables
*/

#ifndef DRAWABLES_HPP_
#define DRAWABLES_HPP_

#include <string>

struct Vector2f {
    float x;
    float y;

    Vector2f(float pX, float pY);
};

struct Color {
    static Color Red();
    static Color Blue();
    static Color Green();
    static Color Black();
    static Color White();
    static Color Transparent();

    unsigned char red;
    unsigned char blue;
    unsigned char green;
    unsigned char alpha;

    Color(unsigned char colorRed, unsigned char blue, unsigned char green,
          unsigned char alpha);
};

class APosition {
    public:
        APosition(const Vector2f &pos);
        ~APosition() = default;

        void setPosition(const Vector2f pos);
        void setPositionX(float posX);
        void setPositionY(float posY);
        void move(const Vector2f pos);
        void moveX(float movx);
        void moveY(float movy);
        Vector2f getPosition(void) const;
        float getPositionX(void) const;
        float getPositionY(void) const;

    private:
        Vector2f _pos;
};

class ASize {
    public:
        ASize(const Vector2f &size);
        ~ASize() = default;

        void setSize(const Vector2f &size);
        void setSizeX(float sizeX);
        void setSizeY(float sizeY);
        Vector2f getSize(void) const;
        float getSizeX(void) const;
        float getSizeY(void) const;

    private:
        Vector2f _size;
};

class AColor {
    public:
        AColor(const Color &color);
        ~AColor() = default;

        void setColor(const Color &color);
        void setColorRed(unsigned char red);
        void setColorGreen(unsigned char green);
        void setColorBlue(unsigned char blue);
        void setColorAlpha(unsigned char alpha);
        Color getColor(void) const;
        unsigned char getColorRed(void) const;
        unsigned char getColorGreen(void) const;
        unsigned char getColorBlue(void) const;
        unsigned char getColorAlpha(void) const;

    private:
        Color _color;
};

class Rect : public APosition, public ASize, public AColor {
    public:
    Rect(Vector2f pos = Vector2f(0, 0), Vector2f size = Vector2f(0, 0),
         Color color = Color(0, 0, 0, 0));

    ~Rect() = default;
};

class Circle : public APosition, public ASize, public AColor {
    public:
    Circle(Vector2f pos = Vector2f(0, 0), Vector2f size = Vector2f(0, 0),
           Color color = Color(0, 0, 0, 0));

    ~Circle() = default;
};

class Text : public APosition, public ASize, public AColor {
    public:
    Text(const std::string &text, Vector2f pos = Vector2f(0, 0),
         Vector2f size = Vector2f(0, 0), Color color = Color(0, 0, 0, 0));

    ~Text() = default;

    const std::string &getText(void) const;

    void setText(const std::string &newText);

    private:
    std::string _text;
};

class Sprite : public APosition, public ASize {
    public:
    Sprite(const std::string &name, Vector2f pos = Vector2f(0, 0),
           Vector2f size = Vector2f(0, 0));
    ~Sprite() = default;

    const std::string &getTextureName(void) const;

    private:
        std::string _textureName;
};

#endif /* !DRAWABLES_HPP_ */
