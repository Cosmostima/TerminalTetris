# TerminalTetris
C++ Command-line 20x10 Tetris game, Retro

A retro-style, Tetris-inspired terminal game written in pure C++ with no external libraries. Runs on macOS and Linux terminals, using plain text with `[]` blocks.

## Features
- Compatible with macOS and Linux. No external libraries required.
- Pure terminal-based interface with `[]` block graphics
- WASD controls: `W` for rotation, and `A`(move left) `D` (move right) `S` (move down)
- Manual control only: use `S` to move blocks down (no auto-fall for retro experience)
- Screen auto-centers based on terminal width, automatically adjusts layout when terminal is resized
- Scoring system and line-clearing mechanics
- Supports custom block shapes


## Build & Run

```bash
make TETRIS

./TETRIS
```
