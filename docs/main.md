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

### Render:
For the `frame rate`, we can use something like:
```cpp
if (ticks.getElapsedTime().asMilliseconds() >= 1 / fps * 1000) {
    //render objects
    ticks.restart();    //restart the clock
}
```
For the rendering, we can use `render` functions for the objects:
```cpp
gameWindow.clear();     //to clear previous screen
map.render(gameWindow);
player.render(gameWindow);
oppo.render(gameWindow);
gameWindow.display();   //to display the rendered objects
```