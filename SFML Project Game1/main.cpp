#include <SFML/Graphics.hpp>

// Creating the viewsize window and window-mode as well
sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);

// Creating the default style for the window
sf::RenderWindow window(vm, "Hello SFML Game", sf::Style::Default);

int main()
{
	// Setting the size of Circle (Drawing Shapes)
	sf::CircleShape circle(100);

	circle.setFillColor(sf::Color::Green);
	circle.setPosition(viewSize.x / 2, viewSize.y / 2);
	circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius()));

	// Setting the size of Triangle (Drawing Shapes)
	sf::ConvexShape triangle;

	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(-100, 0));
	triangle.setPoint(1, sf::Vector2f(0, -100));
	triangle.setPoint(2, sf::Vector2f(100, 0));

	triangle.setFillColor(sf::Color(128, 0, 128, 255));
	triangle.setPosition(viewSize.x / 2, viewSize.y / 2);

	// Setting the size of Rectangle (Drawing Shapes)
	sf::RectangleShape rect(sf::Vector2f(500.0f, 300.0f));

	rect.setFillColor(sf::Color::Yellow);
	rect.setPosition(viewSize.x / 2, viewSize.y / 2);
	rect.setOrigin(sf::Vector2f(
		rect.getSize().x / 2,
		rect.getSize().y / 2
	));

	// Creating Game Loop (Game Objects)
	while (window.isOpen())
	{
		// Handle Keyboard Events
		// Update Game Objects in the Game
		window.clear(sf::Color::Red);

		// Render Game Objects
		window.draw(rect);
		window.draw(circle);
		window.draw(triangle);
		window.display();
	}
	return 0;
}