# cub3D
### Wolfenstein3D reimagination except 30 years later it's way less impressive.
 
Description

Cub3D is a 42 School project that focuses on raycasting, a technique used in computer graphics for rendering 3D scenes. This project is inspired by the classic game Wolfenstein 3D.
Features

    Raycasting Engine: Utilizes the raycasting technique to render a 3D environment.
    Map Parsing: Reads a simple map from a provided file to generate the game world.
    Textured Walls: Renders textured walls to enhance the visual experience.
    Player Movement: Allows the player to move within the 3D space and rotate the view.

Usage

    Clone the repository and compile it with 'make'

Run the game with a provided map:

    ./cub3D map/subjectmap.cub
    (other mapfiles available in map-directory)

Controls

    W/A/S/D: Move forward/left/backward/right.
    Arrow keys: Rotate the view.
    ESC: Exit the game.

Dependencies

    MinilibX: A simple X Window System graphics library.
        Note: Ensure that the MinilibX library is installed on your system.
