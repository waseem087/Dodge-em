# class `FoodItems`:
## Approach
There are going to be 4 types of these classes. 
```cpp
class Rect {};
class Cric {};
class Tri {};
class Hex {};
```

### Appearance
Since these objects are `shape` based, we will use the builtin classes for their appearance such as:
```cpp
sf::RectangleShape rect(sf::Vector2f(width, height));
sf::CircleShape circ(radius);
sf::CircleShape hex(length, 6);
sf::CircleShape tri(length, 3);
```
> Note: the `sf::CircleShape` constructor has an overloaded variant which takes number of vertices (corners) as 2nd argument which lets us define polygons like `triangles`, `pentagones`, `hexagons`, `octagones` etc

We will also use `setFillColor()` for `shapes` to define their colors.

### Collision Detection
When the food item is collided, it disappears and provides certain perks to `player`.
```cpp
bool Rect::collides(Player& target) {
    if(this->appearance.intersects(target.appearance))
        //reward 10 scores
}

bool Circ::collides(Player& target) {
    if(this->appearance.intersects(target.appearance)){
        //rewards extra life
        //rewards 20 points
    }
}

bool Hex::collides(Player& target) {
    if(this->appearance.intersects(target.appearance)){
        //speed boost by 1.5x for 10 seconds
        //rewards 10 points
    }
}

bool Tri::collides(Player& target) {
    if(this->appearance.intersects(target.appearance))
        //opponents disappear
}
```

### Usage
These classes will be used in `composition` with the [arena](./arena.md) class since it is `arena` afterall which _contains_ the food. 