#ifndef HT_STAGE4_TILES_H
#define HT_STAGE4_TILES_H

#define HERO_TILE1 (0x00CD)
#define HERO_TILE2 (0x00CE)
#define HERO_TILE3 (0x00D6)
#define HERO_TILE4 (0x00D7)
#define GOAL_TILE1 (0x00CB)
#define GOAL_TILE2 (0x00CC)
#define GOAL_TILE3 (0x00D4)
#define GOAL_TILE4 (0x00D5)
#define TELEPORT_TILE1 (0x00CA)
#define TELEPORT_TILE2 (0x0094)
#define TELEPORT_TILE3 (0x00D2)
#define TELEPORT_TILE4 (0x00D3)
#define UP_STAIRS_TILE1 (0x00C8)
#define UP_STAIRS_TILE2 (0x00C9)
#define UP_STAIRS_TILE3 (0x00D0)
#define UP_STAIRS_TILE4 (0x00D1)
#define DOWN_STAIRS_TILE1 (0x00C7)
#define DOWN_STAIRS_TILE2 (0x04C7)
#define DOWN_STAIRS_TILE3 (0x00CF)
#define DOWN_STAIRS_TILE4 (0x04CF)
#define UP_GATE_CLOSE_TILE1 (0x00BE)
#define UP_GATE_CLOSE_TILE2 (0x00BF)
#define UP_GATE_CLOSE_TILE3 (0x04BF)
#define UP_GATE_CLOSE_TILE4 (0x04BE)
#define UP_GATE_CLOSE_TILE5 (0x08C0)
#define UP_GATE_CLOSE_TILE6 (0x08C1)
#define UP_GATE_CLOSE_TILE7 (0x00C4)
#define UP_GATE_CLOSE_TILE8 (0x0CC0)
#define UP_GATE_OPEN_TILE1 (0x00C5)
#define UP_GATE_OPEN_TILE2 (0x0000)
#define UP_GATE_OPEN_TILE3 (0x0000)
#define UP_GATE_OPEN_TILE4 (0x04C5)
#define UP_GATE_OPEN_TILE5 (0x08C6)
#define UP_GATE_OPEN_TILE6 (0x0000)
#define UP_GATE_OPEN_TILE7 (0x0000)
#define UP_GATE_OPEN_TILE8 (0x0CC6)
#define DOWN_GATE_CLOSE_TILE1 (0x00C0)
#define DOWN_GATE_CLOSE_TILE2 (0x00C1)
#define DOWN_GATE_CLOSE_TILE3 (0x04C1)
#define DOWN_GATE_CLOSE_TILE4 (0x04C0)
#define DOWN_GATE_CLOSE_TILE5 (0x08BE)
#define DOWN_GATE_CLOSE_TILE6 (0x08BF)
#define DOWN_GATE_CLOSE_TILE7 (0x0CBF)
#define DOWN_GATE_CLOSE_TILE8 (0x0CBE)
#define DOWN_GATE_OPEN_TILE1 (0x00C6)
#define DOWN_GATE_OPEN_TILE2 (0x0000)
#define DOWN_GATE_OPEN_TILE3 (0x0000)
#define DOWN_GATE_OPEN_TILE4 (0x04C6)
#define DOWN_GATE_OPEN_TILE5 (0x08C5)
#define DOWN_GATE_OPEN_TILE6 (0x0000)
#define DOWN_GATE_OPEN_TILE7 (0x0000)
#define DOWN_GATE_OPEN_TILE8 (0x0CC5)
#define LEFT_GATE_CLOSE_TILE1 (0x00BA)
#define LEFT_GATE_CLOSE_TILE2 (0x00BB)
#define LEFT_GATE_CLOSE_TILE3 (0x00C2)
#define LEFT_GATE_CLOSE_TILE4 (0x00C3)
#define LEFT_GATE_CLOSE_TILE5 (0x08C2)
#define LEFT_GATE_CLOSE_TILE6 (0x08C3)
#define LEFT_GATE_CLOSE_TILE7 (0x08BA)
#define LEFT_GATE_CLOSE_TILE8 (0x08BB)
#define LEFT_GATE_OPEN_TILE1 (0x00BC)
#define LEFT_GATE_OPEN_TILE2 (0x00BD)
#define LEFT_GATE_OPEN_TILE3 (0x0000)
#define LEFT_GATE_OPEN_TILE4 (0x0000)
#define LEFT_GATE_OPEN_TILE5 (0x0000)
#define LEFT_GATE_OPEN_TILE6 (0x0000)
#define LEFT_GATE_OPEN_TILE7 (0x08BC)
#define LEFT_GATE_OPEN_TILE8 (0x08BD)
#define RIGHT_GATE_CLOSE_TILE1 (0x04BB)
#define RIGHT_GATE_CLOSE_TILE2 (0x04BA)
#define RIGHT_GATE_CLOSE_TILE3 (0x04C3)
#define RIGHT_GATE_CLOSE_TILE4 (0x04C2)
#define RIGHT_GATE_CLOSE_TILE5 (0x0CC3)
#define RIGHT_GATE_CLOSE_TILE6 (0x0CC2)
#define RIGHT_GATE_CLOSE_TILE7 (0x0CBB)
#define RIGHT_GATE_CLOSE_TILE8 (0x0CBA)
#define RIGHT_GATE_OPEN_TILE1 (0x04BD)
#define RIGHT_GATE_OPEN_TILE2 (0x04BC)
#define RIGHT_GATE_OPEN_TILE3 (0x0000)
#define RIGHT_GATE_OPEN_TILE4 (0x0000)
#define RIGHT_GATE_OPEN_TILE5 (0x0000)
#define RIGHT_GATE_OPEN_TILE6 (0x0000)
#define RIGHT_GATE_OPEN_TILE7 (0x0CBD)
#define RIGHT_GATE_OPEN_TILE8 (0x0CBC)

static int _get_gate_tile_index(int direction, int open_close, int index) {
    if (direction == 0) { // down
        if (open_close == 1) { // open
            if (index == 0) return DOWN_GATE_OPEN_TILE1;
            if (index == 1) return DOWN_GATE_OPEN_TILE2;
            if (index == 2) return DOWN_GATE_OPEN_TILE3;
            if (index == 3) return DOWN_GATE_OPEN_TILE4;
            if (index == 4) return DOWN_GATE_OPEN_TILE5;
            if (index == 5) return DOWN_GATE_OPEN_TILE6;
            if (index == 6) return DOWN_GATE_OPEN_TILE7;
            if (index == 7) return DOWN_GATE_OPEN_TILE8;
        }
        else {
            if (index == 0) return DOWN_GATE_CLOSE_TILE1;
            if (index == 1) return DOWN_GATE_CLOSE_TILE2;
            if (index == 2) return DOWN_GATE_CLOSE_TILE3;
            if (index == 3) return DOWN_GATE_CLOSE_TILE4;
            if (index == 4) return DOWN_GATE_CLOSE_TILE5;
            if (index == 5) return DOWN_GATE_CLOSE_TILE6;
            if (index == 6) return DOWN_GATE_CLOSE_TILE7;
            if (index == 7) return DOWN_GATE_CLOSE_TILE8;
        }
    }
    else if (direction == 1) { // up
        if (open_close == 1) { // open
            if (index == 0) return UP_GATE_OPEN_TILE1;
            if (index == 1) return UP_GATE_OPEN_TILE2;
            if (index == 2) return UP_GATE_OPEN_TILE3;
            if (index == 3) return UP_GATE_OPEN_TILE4;
            if (index == 4) return UP_GATE_OPEN_TILE5;
            if (index == 5) return UP_GATE_OPEN_TILE6;
            if (index == 6) return UP_GATE_OPEN_TILE7;
            if (index == 7) return UP_GATE_OPEN_TILE8;
        }
        else {
            if (index == 0) return UP_GATE_CLOSE_TILE1;
            if (index == 1) return UP_GATE_CLOSE_TILE2;
            if (index == 2) return UP_GATE_CLOSE_TILE3;
            if (index == 3) return UP_GATE_CLOSE_TILE4;
            if (index == 4) return UP_GATE_CLOSE_TILE5;
            if (index == 5) return UP_GATE_CLOSE_TILE6;
            if (index == 6) return UP_GATE_CLOSE_TILE7;
            if (index == 7) return UP_GATE_CLOSE_TILE8;
        }
    }
    else if (direction == 2) { // right
        if (open_close == 1) { // open
            if (index == 0) return RIGHT_GATE_OPEN_TILE1;
            if (index == 1) return RIGHT_GATE_OPEN_TILE2;
            if (index == 2) return RIGHT_GATE_OPEN_TILE3;
            if (index == 3) return RIGHT_GATE_OPEN_TILE4;
            if (index == 4) return RIGHT_GATE_OPEN_TILE5;
            if (index == 5) return RIGHT_GATE_OPEN_TILE6;
            if (index == 6) return RIGHT_GATE_OPEN_TILE7;
            if (index == 7) return RIGHT_GATE_OPEN_TILE8;
        }
        else {
            if (index == 0) return RIGHT_GATE_CLOSE_TILE1;
            if (index == 1) return RIGHT_GATE_CLOSE_TILE2;
            if (index == 2) return RIGHT_GATE_CLOSE_TILE3;
            if (index == 3) return RIGHT_GATE_CLOSE_TILE4;
            if (index == 4) return RIGHT_GATE_CLOSE_TILE5;
            if (index == 5) return RIGHT_GATE_CLOSE_TILE6;
            if (index == 6) return RIGHT_GATE_CLOSE_TILE7;
            if (index == 7) return RIGHT_GATE_CLOSE_TILE8;
        }
    }
    else if (direction == 3) { // left
        if (open_close == 1) { // open
            if (index == 0) return LEFT_GATE_OPEN_TILE1;
            if (index == 1) return LEFT_GATE_OPEN_TILE2;
            if (index == 2) return LEFT_GATE_OPEN_TILE3;
            if (index == 3) return LEFT_GATE_OPEN_TILE4;
            if (index == 4) return LEFT_GATE_OPEN_TILE5;
            if (index == 5) return LEFT_GATE_OPEN_TILE6;
            if (index == 6) return LEFT_GATE_OPEN_TILE7;
            if (index == 7) return LEFT_GATE_OPEN_TILE8;
        }
        else {
            if (index == 0) return LEFT_GATE_CLOSE_TILE1;
            if (index == 1) return LEFT_GATE_CLOSE_TILE2;
            if (index == 2) return LEFT_GATE_CLOSE_TILE3;
            if (index == 3) return LEFT_GATE_CLOSE_TILE4;
            if (index == 4) return LEFT_GATE_CLOSE_TILE5;
            if (index == 5) return LEFT_GATE_CLOSE_TILE6;
            if (index == 6) return LEFT_GATE_CLOSE_TILE7;
            if (index == 7) return LEFT_GATE_CLOSE_TILE8;
        }
    }
    return 0;
}

#endif

