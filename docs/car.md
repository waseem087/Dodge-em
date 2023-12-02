# class `Car`:
## Approach
This `class` is supposed to act as a generic base class for `player` and `opponent`. 
Since both of them have alot of similarities, we can use `inheritance`. 
This `class` will might contain things like:
- `sf::Sprite` for its appearance.
- `float speed` which is affected by `food` items.
- `bool isDead` to check if the target is dead or alive.
- A `Direction enum` such as:
```cpp
enum Direction {
    Up = 1,
    Down,
    Left,
    Right
};
```
- A `move` function. 
Since both cars will moving over time so we have to just call the function in a time based loop. 
The formula for moving the sprite might look something like:
```cpp
this->speed * sf::Vector2i(a, b);
```
> Note: `a` and `b` can either be `1` or `-1`, set using a `switch` onto the `direction`.