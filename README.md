# Cub3D

# so_long

Small 3D game using raycasting with basic gameplay.

## How it works

1. The player move with WASD and close the game by pressing ESC.

2. Components of map:
   - Player and its direction - 'N' / 'S' / 'E' / 'W'
   - Wall - '1'
   - Free space - '0'

3. Some map examples are stored in `/maps` folder. Feel free to change them (`.cub` format is required)!

## How to launch the game

1. To compile the program :

   ```sh
   $ make
   ```

   With bonus :

   ```sh
   $ make bonus
   ```
   
2. To start the game :

   ```sh
   $ ./cub3D [path_to_valid_map]
   ```
3. Remove all :

	```sh
	$ make fclean
	```
