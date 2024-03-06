#include "game.h"

using namespace std;
using namespace sf;

game::game()
    : _state( state::idle )
    , _walk_time_us( 0 )
{
    auto state = _texture.loadFromFile( "character_femaleAdventurer_sheetHD.png" );
    if( !state )
        throw runtime_error( "texture loading error" );

    _sprite.setTexture( _texture );
    set_texture( _sprite, _state, _walk_time_us );
}

void game::update( uint64_t elapsed_us )
{
    if( _state == state::walk_left || _state == state::walk_right )
    {
        _walk_time_us += elapsed_us;
        if( _walk_time_us > walk_period_us )
        {
            _state = state::idle;
            _walk_time_us = 0;
        }

        auto shaft = float(elapsed_us / 5000);
        if( _state == state::walk_left )
            shaft = -shaft;

        _sprite.move( { shaft, 0 } );
    }

    set_texture( _sprite, _state, _walk_time_us );
}

void game::left()
{
    if( _state != state::walk_left )
    {
        _state = state::walk_left;
        _walk_time_us = 0;
    }
}

void game::right()
{
    if( _state != state::walk_right )
    {
        _state = state::walk_right;
        _walk_time_us = 0;
    }
}

void game::draw( RenderTarget& target, RenderStates states ) const
{
    target.draw( _sprite, states );
}

void game::set_texture( Sprite& sprite, state state, uint64_t walk_time_us )
{
    auto id = get_texture_id( state, walk_time_us );
    auto rect = Rect{ id.x * sprite_width, id.y * sprite_height, sprite_width, sprite_height };

    if( state == state::walk_left )
    {
        rect.left += rect.width;
        rect.width = -rect.width;
    }

    sprite.setTextureRect( rect );
}

Vector2i game::get_texture_id( state state, uint64_t walk_time_us )
{
    if( state == state::idle )
        return { 0, 0 };

    if( state == state::walk_left || state == state::walk_right )
    {
        auto i = ( walk_time_us % walk_period_us ) / ( walk_period_us / walk_steps );

        return { int(i), 4 };
    }
            
    throw runtime_error( "invalid state" );
}
