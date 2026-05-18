#include <SFML/Graphics.hpp>

bool playerMoving = false;

// Creating Window and Properties
sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "SFML works!", sf::Style::Default);

// Declaring Texture and Sprite globally
sf::Texture skyTexture;
sf::Sprite skySprite;

sf::Texture bgTexture;
sf::Sprite bgSprite;

sf::Texture heroTexture;
sf::Sprite heroSprite;

// Declaring function init() for loading Assets
void init()
{
    skyTexture.loadFromFile("Assets/graphics/sky.png");
    skySprite.setTexture(skyTexture);

    bgTexture.loadFromFile("Assets/graphics/bg.png");
    bgSprite.setTexture(bgTexture);

    heroTexture.loadFromFile("Assets/graphics/hero.png");
    heroSprite.setTexture(heroTexture);
    // Setting position
    heroSprite.setPosition(sf::Vector2f(viewSize.x / 2, viewSize.y / 2));
    heroSprite.setOrigin(heroTexture.getSize().x / 2, heroTexture.getSize().y / 2);
}

// Drawing our assets on Window
void draw()
{
    window.draw(skySprite);
    window.draw(bgSprite);
    window.draw(heroSprite);
}

// Managind the window events like press keys from keyboard
void updateInput()
{
    sf::Event event;
        while (window.pollEvent(event))
        {   // Handing Player Input
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    playerMoving = true;
                }
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    playerMoving = false;
                }
            }

            if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
            window.close();
        }
}

// DeltaTime to have same speed
void update(float dt)
{
    if (playerMoving)
    {
        heroSprite.move(150.0f * dt, 0);
    }
}
  


// Main Function
int main()
{
    // Getting System Clock
    sf::Clock clock;

    // Callint function loading sprites
    init();  

    while (window.isOpen())
    {
            updateInput(); // Update Input
            sf::Time dt = clock.restart(); // Update the Game
            update(dt.asSeconds());

            window.clear();
            draw(); // Calling function to draw the sprites
            window.display();
    }
           
            
    return 0;
}

   