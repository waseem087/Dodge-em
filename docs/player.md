# class `Player`:
## Approach
The `Player` class inherits from `Car` class.
```cpp
class Player : public Car {}; 
```
This gives the `player` class:
- `sf::Sprite` appearance
- `float` speed
- `bool` isDead
- `Direction` current_dir
- `move()`
> checkout [car.md](./car.md) for more detail about these inherited methods and attributes.

Additional, the `class` will also contain:
```cpp
int lives = 3;
```