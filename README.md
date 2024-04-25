# so_long

<img width="1368" alt="Screen Shot 2024-04-25 at 6 06 22 PM" src="https://github.com/Monsieur-Verdoux/so_long/assets/140087779/a1f0c3ed-7891-4dd6-a6b6-a0f015b85718">

This simple game is my first graphics project at Hive Helsinki, utilizing the MLX42 library - https://github.com/codam-coding-college/MLX42
The goal of the game is to pick up every collectible on the map in the fewest number of moves before exiting. 

The project's two main parts were:
- learning how to properly parse the map file given, rejecting all maps that break the stated rules
- learning to use the MLX42 functions to manipulate images to then create the visual representation of the map and allow player movement and collectible pick-up

## map rules

- The map has to be constructed with 3 components: walls, collectibles, and free space
- The map can be composed of only these 5 characters:
    - 0 for an empty space
    - 1 for a wall
    - C for a collectible
    - E for a map exit
    - P for the player’s starting position
- The map must contain 1 exit, at least 1 collectible, and 1 starting position
- The map must be rectangular
- The map must be closed/surrounded by walls
- There has to be a valid path in the map

An example of a valid map:

```1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
