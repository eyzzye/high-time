#ifndef HT_STAGE1_TILES_H
#define HT_STAGE1_TILES_H

#define HERO_TILE1 (0x0072)
#define HERO_TILE2 (0x0073)
#define HERO_TILE3 (0x007B)
#define HERO_TILE4 (0x007C)
#define GOAL_TILE1 (0x0070)
#define GOAL_TILE2 (0x0071)
#define GOAL_TILE3 (0x0079)
#define GOAL_TILE4 (0x007A)
#define TELEPORT_TILE1 (0x006F)
#define TELEPORT_TILE2 (0x0037)
#define TELEPORT_TILE3 (0x0077)
#define TELEPORT_TILE4 (0x0078)
#define UP_STAIRS_TILE1 (0x006D)
#define UP_STAIRS_TILE2 (0x006E)
#define UP_STAIRS_TILE3 (0x0075)
#define UP_STAIRS_TILE4 (0x0076)
#define DOWN_STAIRS_TILE1 (0x006C)
#define DOWN_STAIRS_TILE2 (0x046C)
#define DOWN_STAIRS_TILE3 (0x0074)
#define DOWN_STAIRS_TILE4 (0x0474)
#define UP_GATE_CLOSE_TILE1 (0x0063)
#define UP_GATE_CLOSE_TILE2 (0x0064)
#define UP_GATE_CLOSE_TILE3 (0x0464)
#define UP_GATE_CLOSE_TILE4 (0x0463)
#define UP_GATE_CLOSE_TILE5 (0x0865)
#define UP_GATE_CLOSE_TILE6 (0x0866)
#define UP_GATE_CLOSE_TILE7 (0x0069)
#define UP_GATE_CLOSE_TILE8 (0x0C65)
#define UP_GATE_OPEN_TILE1 (0x006A)
#define UP_GATE_OPEN_TILE2 (0x0000)
#define UP_GATE_OPEN_TILE3 (0x0000)
#define UP_GATE_OPEN_TILE4 (0x046A)
#define UP_GATE_OPEN_TILE5 (0x086B)
#define UP_GATE_OPEN_TILE6 (0x0000)
#define UP_GATE_OPEN_TILE7 (0x0000)
#define UP_GATE_OPEN_TILE8 (0x0C6B)
#define DOWN_GATE_CLOSE_TILE1 (0x0065)
#define DOWN_GATE_CLOSE_TILE2 (0x0066)
#define DOWN_GATE_CLOSE_TILE3 (0x0466)
#define DOWN_GATE_CLOSE_TILE4 (0x0465)
#define DOWN_GATE_CLOSE_TILE5 (0x0863)
#define DOWN_GATE_CLOSE_TILE6 (0x0864)
#define DOWN_GATE_CLOSE_TILE7 (0x0C64)
#define DOWN_GATE_CLOSE_TILE8 (0x0C63)
#define DOWN_GATE_OPEN_TILE1 (0x006B)
#define DOWN_GATE_OPEN_TILE2 (0x0000)
#define DOWN_GATE_OPEN_TILE3 (0x0000)
#define DOWN_GATE_OPEN_TILE4 (0x046B)
#define DOWN_GATE_OPEN_TILE5 (0x086A)
#define DOWN_GATE_OPEN_TILE6 (0x0000)
#define DOWN_GATE_OPEN_TILE7 (0x0000)
#define DOWN_GATE_OPEN_TILE8 (0x0C6A)
#define LEFT_GATE_CLOSE_TILE1 (0x005F)
#define LEFT_GATE_CLOSE_TILE2 (0x0060)
#define LEFT_GATE_CLOSE_TILE3 (0x0067)
#define LEFT_GATE_CLOSE_TILE4 (0x0068)
#define LEFT_GATE_CLOSE_TILE5 (0x0867)
#define LEFT_GATE_CLOSE_TILE6 (0x0868)
#define LEFT_GATE_CLOSE_TILE7 (0x085F)
#define LEFT_GATE_CLOSE_TILE8 (0x0860)
#define LEFT_GATE_OPEN_TILE1 (0x0061)
#define LEFT_GATE_OPEN_TILE2 (0x0062)
#define LEFT_GATE_OPEN_TILE3 (0x0000)
#define LEFT_GATE_OPEN_TILE4 (0x0000)
#define LEFT_GATE_OPEN_TILE5 (0x0000)
#define LEFT_GATE_OPEN_TILE6 (0x0000)
#define LEFT_GATE_OPEN_TILE7 (0x0861)
#define LEFT_GATE_OPEN_TILE8 (0x0862)
#define RIGHT_GATE_CLOSE_TILE1 (0x0460)
#define RIGHT_GATE_CLOSE_TILE2 (0x045F)
#define RIGHT_GATE_CLOSE_TILE3 (0x0468)
#define RIGHT_GATE_CLOSE_TILE4 (0x0467)
#define RIGHT_GATE_CLOSE_TILE5 (0x0C68)
#define RIGHT_GATE_CLOSE_TILE6 (0x0C67)
#define RIGHT_GATE_CLOSE_TILE7 (0x0C60)
#define RIGHT_GATE_CLOSE_TILE8 (0x0C5F)
#define RIGHT_GATE_OPEN_TILE1 (0x0462)
#define RIGHT_GATE_OPEN_TILE2 (0x0461)
#define RIGHT_GATE_OPEN_TILE3 (0x0000)
#define RIGHT_GATE_OPEN_TILE4 (0x0000)
#define RIGHT_GATE_OPEN_TILE5 (0x0000)
#define RIGHT_GATE_OPEN_TILE6 (0x0000)
#define RIGHT_GATE_OPEN_TILE7 (0x0C62)
#define RIGHT_GATE_OPEN_TILE8 (0x0C61)

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

