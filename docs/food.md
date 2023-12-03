# class `FoodItems`:
## Approach
There are going to be 4 types of these classes. 
Since these objects are `shape` based, we will use the builtin classes for their appearance such as:
```cpp
sf::RectangleShape rect(sf::Vector2f(width, height));
sf::CircleShape circ(radius);
sf::CircleShape tri(length, 3);
sf::CircleShape hex(length, 6);
```
> Note: the `sf::CircleShape` constructor has an overloaded variant which takes number of vertices (corners) as 2nd argument which lets us define polygons like `triangles`, `pentagones`, `hexagons`, `octagones` etc

these classes will be used in `composition` with the [arena](./arena.md) class since it is `arena` afterall which _contains_ the food. 