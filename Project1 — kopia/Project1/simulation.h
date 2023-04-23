#include <SFML/Graphics.hpp>
#include <vector>
#include "PhysicsHandler.h"

class Simulation
{
public:
	std::vector<Particle> particles;
	sf::RenderWindow* windows;
	PhysicsHandler physics;
	Simulation(const int& n, const float& radius)
	{
		windows = new sf::RenderWindow(sf::VideoMode(600.f, 600.f), "Particles");

		windows->setFramerateLimit(90);
		for (int i = 0; i < n; ++i)
		{
			particles.push_back(Particle(windows, radius));
		}
		
	}

	void run()
	{
		
		while (windows->isOpen())
		{
			sf::Event event;
			while (windows->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) windows->close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) windows->close();
			}
			for (int i = 0; i < particles.size(); ++i)
			{
				particles[i].particlePosition.x += particles[i].xVelocity;
				particles[i].particlePosition.y += particles[i].yVelocity;
				particles[i].particle.setPosition(particles[i].particlePosition);
			}

			for (int i = 0; i < particles.size(); ++i)
			{
				physics.handleWindowBoundsCollision(particles[i]);
				for (int j = 0; j < particles.size(); ++j)
				{
					physics.handleCollision(particles[i], particles[j]);
				}				
			}
			
			windows->clear();
			for (auto& p : particles)
			{
				windows->draw(p.particle);
			}
			windows->display();

		}
	}
};
