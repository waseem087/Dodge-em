# Game Logic
## Objects
We can start off by creating our objects, which are:
- `sf::RenderWindow` gameWindow; The window object where everything will be drawn.
- `sf::Clock` ticks;
- `float` fps;
- `Player` player;
- `Opponent` oppo;
- `Arena` map;

## Game Loop
The loop looks like:
```cpp
while(gameWindow.isOpen()) {
    //game logic
}
```