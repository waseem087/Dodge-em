# class `Arena`:
<figure id="fig_1.1">
    <img src="./img/Arena.png" alt="Screenshot of Arena">
    <figcaption>Fig 1.1 - A screen shot of the game</figcaption>
</figure>

## Approach 
<figure id="fig_2.1"s>
    <img src="./img/Arena_corner.png" alt="Screenshot of Arena">
    <figcaption>Fig 2.1 - Top Left corner of Arena</figcaption>
</figure>

There are 4 of such sections. 
The `player` cannot take turns while on these sections. 
Therefore, we can represent <a href="#fig_2.1">Fig 2.1</a> as `sf::Sprite`, a sprite class from [SFML](https://www.sfml-dev.org/) which will have the pink walls but transparent background.

<figure id="fig_2.2"s>
    <img src="./img/Arena_corner2.png" alt="Screenshot of Arena">
    <figcaption>Fig 2.2 - Arena corner being represented as a sprite</figcaption>
</figure>
<figure id="fig_2.3">
    <img src="./img/Arena_corner3.png" alt="Screenshot of Arena">
    <figcaption>Fig 2.3 - Arena corner being opaque</figcaption>
</figure>

Then we can display 4 of them, each one multiplied by `1` or `-1` with their `x` or `y` components to flip them.

<figure id="fig_2.4">
    <img src="./img/Arena_corners.png" alt="Screenshot of Arena">
    <figcaption>Fig 2.4 - Arena corners</figcaption>
</figure>

The `player` can only take turns outside these sprites. 
We can use `intersects()` function from `sf::Sprite` class to check if player is inside these blocks or not. 
If not, then we allow `player` to take turns. 
Otherwise inputs will be ignored. 

<figure id="fig_2.5">
    <img src="./img/tracks.png" alt="Screenshot of Arena">
    <figcaption>Fig 2.5 - Tracks</figcaption>
</figure>

`Player` can move onto these 4 `tracks`. 
Each one will have 4 ordered pairs (coordinates for each corner). 
Structure might look something like:
```cpp
struct track {
    sf::Vector2i corners[4];
};
```
They will be set by `Arena constructor` based on the dimensions of it. 

### Food
The `Arena` will also contain [food](./food.md) items. 
They are tracked by a 2-dimensional array called `foodMap`.  
If we look at <a href="#fig_1.1">Fig 1.1</a>, we can think of the `tracks` as `rings` where `ring 0` represents the inner most `track`. 
Let `ring number` be represented by `r` then for each `ring`, number of `food` items is: 
$$\left( 4 + 8r \right)$$

The total amount of food on the map is represented by equation:
$$\sum_{r = 0}^3 \left(4 + 8r\right)$$