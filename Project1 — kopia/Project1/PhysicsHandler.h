#include <SFML/Graphics.hpp>

class PhysicsHandler
{
public:

    void moving(Particle p)
    {
        p.particlePosition.x += p.xVelocity;
        p.particlePosition.y += p.yVelocity;
        p.particle.setPosition(p.particlePosition);
    }
    void handleCollision(Particle& p1, Particle& p2)
    {
        sf::Vector2f delta = p2.particle.getPosition() - p1.particle.getPosition();
        double distance = std::sqrt(std::pow(delta.x, 2) + std::pow(delta.y, 2));

        if (distance <= p1.particle.getRadius() + p2.particle.getRadius())
        {
            double p1x = p1.xVelocity;
            double p1y = p1.yVelocity;
            double p2x = p2.xVelocity;
            double p2y = p2.yVelocity;
            
            p1.setSpeed(p2x, p2y);
            p2.setSpeed(p1x, p1y);
        }
    }

    void handleWindowBoundsCollision(Particle& p)
    {
        if (p.particlePosition.x < 0 || p.particlePosition.x > 600 - (p.particle.getRadius() * 2)) p.xVelocity *= -1;
        if (p.particlePosition.y < 0 || p.particlePosition.y > 600 - (p.particle.getRadius() * 2)) p.yVelocity *= -1;
        p.particlePosition.x += p.xVelocity;
        p.particlePosition.y += p.yVelocity;
        p.particle.setPosition(p.particlePosition);
    }
};
