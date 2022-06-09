#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "Cross.h"
#include "Octagon.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <vector>
#include <iostream>

using namespace std;

sf::Font font;
sf::Text text;
Cross cross;
Cross cross1;
Cross cross2;
Cross cross3;
Cross cross4;
Cross cross5;

bool checkDistance(sf::CircleShape shape1, sf::CircleShape shape2)
{
    float p1 = shape1.getPointCount();
    float ratio = (p1 - 1) / p1;
    float x2 = shape2.getPosition().x + shape2.getRadius();
    float y2 = shape2.getPosition().y + shape2.getRadius();

    for (int i = 0; i < p1; i++)
    {
        float x = shape1.getTransform().transformPoint(shape1.getPoint(i)).x;
        float y = shape1.getTransform().transformPoint(shape1.getPoint(i)).y;
        float distance = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
        if (distance <= shape2.getRadius() * ratio) {
            return true;
        }
    }


    return false;
}

int getP(sf::CircleShape shape1, sf::CircleShape shape2)
{
    float p1 = shape1.getPointCount();
    float ratio = (p1 - 1) / p1;
    float x2 = shape2.getPosition().x + shape2.getRadius();
    float y2 = shape2.getPosition().y + shape2.getRadius();
    for (int i = 0; i < p1; i++)
    {
        float x = shape1.getTransform().transformPoint(shape1.getPoint(i)).x;
        float y = shape1.getTransform().transformPoint(shape1.getPoint(i)).y;
        float distance = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
        if (distance <= shape2.getRadius() * ratio) {
            return i;
        }
    }
    return -1;
}

float setXr(sf::CircleShape shape1, sf::CircleShape shape2)
{
    int p = getP(shape1, shape2);
    float x1 = shape1.getPosition().x + shape1.getRadius();
    float x = shape1.getTransform().transformPoint(shape1.getPoint(p)).x;
    if (x >= x1) {
        return x - 15;
    }
    return x + 15;

}

float setYr(sf::CircleShape shape1, sf::CircleShape shape2)
{
    int p = getP(shape1, shape2);
    float y1 = shape1.getPosition().y + shape1.getRadius();
    float y = shape1.getTransform().transformPoint(shape1.getPoint(p)).y;
    if (y >= y1) {
        return y - 15;
    }
    return y + 15;

}

void check(sf::CircleShape shape1, sf::CircleShape shape2) {
    
    if (shape1.getGlobalBounds().intersects(shape2.getGlobalBounds()))
    {
        if (checkDistance(shape1, shape2))
        {
            cross.setRect(setXr(shape1, shape2), setYr(shape1, shape2));
            text.setString("Collision");
        }
        else if (checkDistance(shape2, shape1))
        {
            cross.setRect(setXr(shape2, shape1), setYr(shape2, shape1));
            text.setString("Collision");
        }
        else
        {
            cross.setRect(-10, -10);
            text.setString("No Collision");
        }
    }
    else
    {
        cross.setRect(-10, -10);
        text.setString("No Collision");
    }
}


int main()
{
    if (!font.loadFromFile("ARCADE_I.TTF"))
    {
        return EXIT_FAILURE;
    }
    int cube_1, cube_2;

    text.setFont(font);
    text.setPosition(0, 0);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(25);
    cross.setEdge(5);

    cout << "\t\t\t\t USER MANUAL " << endl;
    cout << endl;
    cout << "\t== User can press the arrow keys to move either shape" << endl;
    cout << endl;
    cout << "\t== Key + , -, to zoom in or out of either picture" << endl;
    cout << endl;
    cout << "\t== Press 1 to move the first shape, press 2 to move the second shape." << endl;
    cout << endl;
    cout << "\t== 'Graphic Shape' screen appears 'No collision' when both images have not collided," << endl;
    cout << "\t    please move shapes to see the collision" <<endl;
    cout << endl;
    cout << "\t== Please choose 2 of 4 shapes:" << endl;
    cout << "\t \t1.Circle" << endl;
    cout << "\t \t2.Rectangle" << endl;
    cout << "\t \t3.Octagon" << endl;
    cout << "\t \t4.Triangle" << endl << endl;
    cout << "\t* Enter the First shape : ";
    cin >> cube_1;
    cout << endl;
    cout << "\t* Enter the Second shape : ";
    cin >> cube_2;
    cout << endl;

    int controlShape = 1;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 800), "Graphic Shapes", sf::Style::Default, settings);

    Circle cir1;
    Circle cir2;

    Triangle tri1;
    Triangle tri2;

    Rectangle rec1;
    Rectangle rec2;

    Octagon oct1;
    Octagon oct2;

    cross.setEdge(10);
    cross1.setEdge(10);
    cross2.setEdge(10);
    cross3.setEdge(10);
    cross4.setEdge(10);
    cross5.setEdge(10);

    if (cube_1 == 1) {
        cir1.setRadi(80);
        cir1.setRect(300, 300);
    }

    if (cube_2 == 1) {
        cir2.setRadi(80);
        cir2.setRect(500, 500);
    }

    if (cube_1 == 2) {
        rec1.setEdge(80);
        rec1.setRect(300, 300);
    }

    if (cube_2 == 2) {
        rec2.setEdge(80);
        rec2.setRect(500, 500);
    }

    if (cube_1 == 3) {
        oct1.setEdge(80);
        oct1.setRect(300, 300);
    }

    if (cube_2 == 3) {
        oct2.setEdge(80);
        oct2.setRect(500, 500);
    }

    if (cube_1 == 4) {
        tri1.setEdge(80);
        tri1.setRect(300, 300);
    }

    if (cube_2 == 4) {
        tri2.setEdge(80);
        tri2.setRect(500, 500);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                controlShape = 1;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                controlShape = 2;
            }

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (controlShape == 1) {
                if (cube_1 == 1) {
                    cir1.KeyPr();
                }

                if (cube_1 == 2) {
                    rec1.KeyPr();
                }

                if (cube_1 == 3) {
                    oct1.KeyPr();
                }


                if (cube_1 == 4) {
                    tri1.KeyPr();
                }
            }

            if (controlShape == 2) {
                if (cube_2 == 1) {
                    cir2.KeyPr();
                }

                if (cube_2 == 2) {
                    rec2.KeyPr();
                }

                if (cube_2 == 3) {
                    oct2.KeyPr();
                }


                if (cube_2 == 4) {
                    tri2.KeyPr();
                }
            }

        }
        window.clear(sf::Color(255, 255, 255, 255));



        if (cube_1 == 1 && cube_2 == 1) {
            check(cir1.getshape(), cir2.getshape());
            window.draw(cir1.getshape());
            window.draw(cir2.getshape());
        }

        if (cube_1 == 1 && cube_2 == 2) {
            check(cir1.getshape(), rec2.getshape());
            window.draw(cir1.getshape());
            window.draw(rec2.getshape());
        }

        if (cube_1 == 1 && cube_2 == 3) {
            check(cir1.getshape(), oct2.getshape());
            window.draw(cir1.getshape());
            window.draw(oct2.getshape());
        }

        if (cube_1 == 1 && cube_2 == 4) {
            check(cir1.getshape(), tri2.getshape());
            window.draw(cir1.getshape());
            window.draw(tri2.getshape());
        }

        if (cube_1 == 2 && cube_2 == 1) {
            check(rec1.getshape(), cir2.getshape());
            window.draw(rec1.getshape());
            window.draw(cir2.getshape());
        }

        if (cube_1 == 2 && cube_2 == 2) {
            check(rec1.getshape(), rec2.getshape());
            window.draw(rec1.getshape());
            window.draw(rec2.getshape());
        }

        if (cube_1 == 2 && cube_2 == 3) {
            check(rec1.getshape(), oct2.getshape());
            window.draw(rec1.getshape());
            window.draw(oct2.getshape());
        }

        if (cube_1 == 2 && cube_2 == 4) {
            check(rec1.getshape(), tri2.getshape());
            window.draw(rec1.getshape());
            window.draw(tri2.getshape());
        }

        if (cube_1 == 3 && cube_2 == 1) {
            check(oct1.getshape(), cir2.getshape());
            window.draw(oct1.getshape());
            window.draw(cir2.getshape());
        }

        if (cube_1 == 3 && cube_2 == 2) {
            check(oct1.getshape(), rec2.getshape());
            window.draw(oct1.getshape());
            window.draw(rec2.getshape());
        }

        if (cube_1 == 3 && cube_2 == 3) {
            check(oct1.getshape(), oct2.getshape());
            window.draw(oct1.getshape());
            window.draw(oct2.getshape());
        }

        if (cube_1 == 3 && cube_2 == 4) {
            check(oct1.getshape(), tri2.getshape());
            window.draw(oct1.getshape());
            window.draw(tri2.getshape());
        }

        if (cube_1 == 4 && cube_2 == 1) {
            check(tri1.getshape(), cir2.getshape());
            window.draw(tri1.getshape());
            window.draw(cir2.getshape());
        }

        if (cube_1 == 4 && cube_2 == 2) {
            check(tri1.getshape(), rec2.getshape());
            window.draw(tri1.getshape());
            window.draw(rec2.getshape());
        }

        if (cube_1 == 4 && cube_2 == 3) {
            check(tri1.getshape(), oct2.getshape());
            window.draw(tri1.getshape());
            window.draw(oct2.getshape());
        }

        if (cube_1 == 4 && cube_2 == 4) {
            check(tri1.getshape(), tri2.getshape());
            window.draw(tri1.getshape());
            window.draw(tri2.getshape());
        }
        window.draw(cross.getshape());
        window.draw(cross1.getshape());
        window.draw(cross2.getshape());
        window.draw(cross5.getshape());
        window.draw(cross4.getshape());
        window.draw(cross3.getshape());
        window.draw(text);
        window.display();
    }

    return 0;
}