#pragma once

#include <SFML/Graphics.hpp>

class core : public sf::Drawable, public sf::Transformable
{
public:
    void update( uint64_t elapsed_us );
    
    void touch_left();
    void touch_right();
    void touch_up();
    void touch_down();

    void draw( sf::RenderTarget&, sf::RenderStates ) const override;

private:
    static constexpr float radius = 20;
    static constexpr float thickness = 4;

    static constexpr float k = 0.75;
    static constexpr float a = 50 * 9.81;

    const sf::Vector2f area_size = { 800, 800 };

    sf::Vector2f _position = { area_size.x / 2, thickness };

    sf::Vector2f _v = { 0, 0 };
    sf::Vector2f _a = { 0, a };
};

