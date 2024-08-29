# Pong Game using `ncurses` Library

## Overview

This is an implementation of the classic Pong game using the `ncurses` library in C. The game simulates the traditional Pong gameplay, where two paddles move vertically to bounce a ball back and forth across the screen.

## Features

- **Duel-player mode:** Play against your friend on the same keyboard.
- **Smooth animation:** The game runs smoothly using the `ncurses` library for console-based graphics.
- **Controls:**
  - **Left Paddle:** Use `A` (Up) and `Z` (Down) keys.
  - **Right Paddle:** Use the `UP` and `DOWN` arrow keys.
  - **Quit:** Press `Q` or `ESC` to quit the game.

## Requirements

- **C Compiler:** You need a C compiler like `gcc`.
- **ncurses Library:** Ensure that the `ncurses` library is installed on your system. You can install it on Ubuntu-based systems using:
  ```bash
  sudo apt-get install libncurses5-dev libncursesw5-dev
  ```

## Compilation and Running

1. **Navigate to the Project Directory:**
   ```bash
   cd C-Language/project
   ```

2. **Compile the Code:**
   ```bash
   gcc -o pong pong.c -lncurses
   ```

3. **Run the Game:**
   ```bash
   ./pong
   ```

## Future Work

This is just the beginning! In the future, I plan to expand this project by adding more games implemented using the `ncurses` library. 
Stay tuned!
