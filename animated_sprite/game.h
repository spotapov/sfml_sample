#pragma once

#include <SFML/Graphics.hpp>

class game : public sf::Drawable, public sf::Transformable
{
private:
    enum class state
    {
        idle,
        walk_left,
        walk_right,
    };

public:
    game();

    void update( uint64_t elapsed_us );

    void left();
    void right();

    void draw( sf::RenderTarget&, sf::RenderStates ) const override;

private:
    static void set_texture( sf::Sprite&, state, uint64_t walk_time_us );
    static sf::Vector2i get_texture_id( state, uint64_t walk_time_us );

private:
    static constexpr int sprite_width = 192;
    static constexpr int sprite_height = 256;

    static constexpr int walk_period_us = 1'000'000;
    static constexpr int walk_steps = 8;

    state _state;
    uint64_t _walk_time_us;

    sf::Texture _texture;
    sf::Sprite _sprite;
};

