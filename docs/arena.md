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