#include <SFML/Graphics.hpp>

class Particle :sf::CircleShape
{
public:
	double xVelocity;
	double yVelocity;
	sf::Vector2f particlePosition;
	sf::CircleShape particle;
	
	Particle(sf::RenderWindow* window, const float& radius)
	{
		
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> xx(20, 600.f);
			std::uniform_int_distribution<> yy(20, 600.f);

			particlePosition.x = xx(gen);
			particlePosition.y = yy(gen);

			particle.setPosition(particlePosition);



			std::uniform_int_distribution<> xvel(1, 3);
			std::uniform_int_distribution<> yvel(1, 3);
			xVelocity = xvel(gen);
			yVelocity = yvel(gen);
			particle.setRadius(radius);


			window->draw(particle);
			window->display();

	}
	Particle(sf::RenderWindow& window, const float& radius, const sf::Vector2f& position)
	{
		std::random_device rd;
		std::mt19937 gen(rd());

		particlePosition.x = position.x;
		particlePosition.y = position.y;

		particle.setPosition(particlePosition);

		std::uniform_int_distribution<> xvel(5, 10);
		std::uniform_int_distribution<> yvel(5, 10);
		xVelocity = xvel(gen);
		yVelocity = yvel(gen);
		particle.setRadius(radius);

		window.draw(particle);
		window.display();
	}
	sf::Vector2f getSpeed()
	{
		sf::Vector2f output;
		output.x = xVelocity;
		output.y = yVelocity;
		return output;
	}
	void setSpeed(const double& xVel, const double& yVel)
	{
		xVelocity = xVel;
		yVelocity = yVel;
	}
};