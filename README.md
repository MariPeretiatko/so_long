# So_long

So_long is a simple 2D game project developed as part of the 42 school curriculum. The objective of the game is to navigate through a map, collect items, and avoid obstacles.

![small_map](https://github.com/MariPeretiatko/so_long/assets/83024504/dc0f422c-9ee3-442d-8733-ff749220bb22)

## Table of Contents
- [Introduction](#introduction)
- [Functionality](#functionality)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction
So_long is a project aimed at reinforcing fundamental programming concepts, including input/output, memory management, and basic game logic. The game is written in C and uses the MinilibX library for graphics rendering.

## Functionality
- Display a window with a map where the player character can move.
- Collect items placed on the map while avoiding obstacles and walls.
- Keep track of the player's score and the number of collected items.
- Implement basic collision detection to handle interactions between the player character, items, and obstacles.

## Project Structure
- `so_long.c`: Main file containing the game's entry point and logic.
- `map_parser.c`: Responsible for parsing the map from a file and initializing the game environment.
- `game_utils.c`: Utility functions for game logic, such as handling player movement and collision detection.
- `render.c`: Functions for rendering the game graphics and updating the display.
- `libft/`: The libft library containing standard functions for string and memory manipulation.

## Usage
1. Compile the source files along with any necessary libraries.
2. Run the executable to start the game.
3. Use keyboard inputs to control the player character and navigate through the map.
4. Collect items and avoid obstacles to increase your score.

## Contributing
Contributions are welcome! Feel free to submit bug reports, feature requests, or pull requests.

## License
This project is licensed under the [MIT License](LICENSE).

![big_map](https://github.com/MariPeretiatko/so_long/assets/83024504/a2746c89-f784-4759-b5c4-e224a1902f7d)
