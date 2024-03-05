#include "core.h"

using namespace sf;
using namespace std;

void core::update( uint64_t elapsed_us )
{
    auto t = float(elapsed_us) / 1'000'000.0f;

    auto p = _v * t + _a * t * t / 2.0f;

    _v = _a * t + _v;

    _position += p;

    if( _position.x < thickness )
    {
        _position.x = thickness;
        _v.x = -k * _v.x;
        _a.x = -_a.x;
    }

    if( _position.x > area_size.x - 2 * radius - thickness )
    {
        _position.x = area_size.x - 2 * radius - thickness;
        _v.x = -k * _v.x;
        _a.x = -_a.x;
    }

    if( _position.y < thickness )
    {
        _position.y = thickness;
        _v.y = -k * _v.y;
        _a.x = -_a.x;
    }

    if( _position.y > area_size.y - 2 * radius - thickness )
    {
        _position.y = area_size.y - 2 * radius - thickness;
        _v.y = -k * _v.y;
    }

    if( _v.x > 0 )
        _a.x = -a;

    if( _v.x < 0 )
        _a.x = a;
}

void core::touch_left()
{
    _v.x -= 50.0f;
}

void core::touch_right()
{
    _v.x += 50.0f;
}

void core::touch_up()
{
    _v.y -= 50.0f;
}

void core::touch_down()
{
    _v.y += 50.0f;
}

void core::draw( RenderTarget& target, RenderStates states) const
{
    states.transform *= getTransform();

    RectangleShape area( area_size );
    area.setFillColor( Color::White );
    target.draw( area, states );

    CircleShape circle( radius );
    circle.setFillColor( Color::Transparent );
    circle.setOutlineColor( Color::Red );
    circle.setOutlineThickness( thickness );
    circle.setPosition( _position );
    target.draw( circle, states );
}
