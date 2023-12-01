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