
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

sf::Vector2f quadraticBezier(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, float t) {
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;

    sf::Vector2f p = uu * p0;          // (1-t)^2 * P0
    p += 2 * u * t * p1;               // 2*(1-t)*t * P1
    p += tt * p2;                      // t^2 * P2
    return p;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Quadratic Bezier Curve");

    // Control points
    sf::Vector2f p0(100, 500);
    sf::Vector2f p1(400, 100);
    sf::Vector2f p2(700, 500);

    // Curve points
    std::vector<sf::Vertex> curve;
    for (float t = 0; t <= 1; t += 0.01f) {
        sf::Vector2f point = quadraticBezier(p0, p1, p2, t);
        curve.push_back(sf::Vertex(point, sf::Color::Red));
    }

    // Control point markers
    sf::CircleShape c0(5), c1(5), c2(5);
    c0.setFillColor(sf::Color::Green); c0.setOrigin(5, 5); c0.setPosition(p0);
    c1.setFillColor(sf::Color::Blue);  c1.setOrigin(5, 5); c1.setPosition(p1);
    c2.setFillColor(sf::Color::Green); c2.setOrigin(5, 5); c2.setPosition(p2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // Draw curve
        window.draw(&curve[0], curve.size(), sf::LineStrip);

        // Draw control points
        window.draw(c0);
        window.draw(c1);
        window.draw(c2);

        window.display();
    }

    return 0;
}
