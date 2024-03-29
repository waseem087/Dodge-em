# Objectives
## Gameplay
- `Player` moves clockwise.
- `Opponent` moves counter clockwise.
- Avoid head on collision.
- `Player` has 3 lives.
- Rectangle shaped gift box are placed at equal distances in `arena`.
- Gifts reward player with 10 points.
- Collision makes player lose 1 life and refills the whole `arena` with gifts again.
- `Score` and `lives` left are visible at top of screen.

## Rules
- `Roadways` has 4 turns.
- There are 4 `Roadways` (like a ringed structure).
- `Player` starts at middle of top most roadway.
- `Opponent` starts at any turn of same roadway.
- Arrow keys to turn.
- Opponent can turn if it brings itself closer to player and may not otherwise.

## Level Design
- Next level when all gifts are picked up.
- Going to next level resets positions and rewards 100 points.

### Level 1:
- `Opponent` cannot take top and bottom turns. 
### Level 2:
- `Opponent` can take any turn now.
### Level 3:
- `opponent` speed is increased.
### Level 4:
- `Opponents` don't get reset.
- Speed is reduced to normal.
- There are 2 `opponents`.
- Display "You Won!" message after clearing the levels.

## Food types:
- `Red Rectangle` rewards 10 points.
- `Green Circle` rewards extra `life` and 20 points.
- `Orange hexagon` increases speed by 1.5x for 10 seconds and gives 10 points.
- `White triangle` will make `opponents` disappear for 10 seconds.

## File processing:
- `Highscores` are read from a `.txt` file and are stored in an array of size 5.
- If `highscore` is broken, array is updated and the `highscore` is replaced in the `.txt` file.

## Menu:
1. Start a new game
2. See high-scores
3. Help
4. Exit

- Triggered by pressing corresponding `numeric key`.
## Pause:
- You can press `P` key to pause the game, which shows same options with 1 additional one, `5. Continue`.