# class `Opponent`:
## Approach
The `Opponent` class inherits from `Car` class.
```cpp
class Opponent : public Car {}; 
```
This gives the `opponent` class:
- `sf::Sprite` appearance
- `float` speed
- `bool` isDead
- `Direction` current_dir
- `move()`
> checkout [car.md](./car.md) for more detail about these inherited methods and attributes.

Additional, the `class` will also contain:
```cpp
void kill(Player target);
```
This is because any of the `opponents` can check if it is touching the player. 
If it is, then it `kills` the player and itself by setting `isDead` to `true`.