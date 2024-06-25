#ifndef HT_STAGE2_TILES_H
#define HT_STAGE2_TILES_H

#define HERO_TILE1 (0x0062)
#define HERO_TILE2 (0x0063)
#define HERO_TILE3 (0x006B)
#define HERO_TILE4 (0x006C)
#define GOAL_TILE1 (0x0060)
#define GOAL_TILE2 (0x0061)
#define GOAL_TILE3 (0x0069)
#define GOAL_TILE4 (0x006A)
#define TELEPORT_TILE1 (0x005F)
#define TELEPORT_TILE2 (0x0029)
#define TELEPORT_TILE3 (0x0067)
#define TELEPORT_TILE4 (0x0068)
#define UP_STAIRS_TILE1 (0x005D)
#define UP_STAIRS_TILE2 (0x005E)
#define UP_STAIRS_TILE3 (0x0065)
#define UP_STAIRS_TILE4 (0x0066)
#define DOWN_STAIRS_TILE1 (0x005C)
#define DOWN_STAIRS_TILE2 (0x045C)
#define DOWN_STAIRS_TILE3 (0x0064)
#define DOWN_STAIRS_TILE4 (0x0464)
#define UP_GATE_CLOSE_TILE1 (0x0053)
#define UP_GATE_CLOSE_TILE2 (0x0054)
#define UP_GATE_CLOSE_TILE3 (0x0454)
#define UP_GATE_CLOSE_TILE4 (0x0453)
#define UP_GATE_CLOSE_TILE5 (0x0855)
#define UP_GATE_CLOSE_TILE6 (0x0856)
#define UP_GATE_CLOSE_TILE7 (0x0059)
#define UP_GATE_CLOSE_TILE8 (0x0C55)
#define UP_GATE_OPEN_TILE1 (0x005A)
#define UP_GATE_OPEN_TILE2 (0x0000)
#define UP_GATE_OPEN_TILE3 (0x0000)
#define UP_GATE_OPEN_TILE4 (0x045A)
#define UP_GATE_OPEN_TILE5 (0x085B)
#define UP_GATE_OPEN_TILE6 (0x0000)
#define UP_GATE_OPEN_TILE7 (0x0000)
#define UP_GATE_OPEN_TILE8 (0x0C5B)
#define DOWN_GATE_CLOSE_TILE1 (0x0055)
#define DOWN_GATE_CLOSE_TILE2 (0x0056)
#define DOWN_GATE_CLOSE_TILE3 (0x0456)
#define DOWN_GATE_CLOSE_TILE4 (0x0455)
#define DOWN_GATE_CLOSE_TILE5 (0x0853)
#define DOWN_GATE_CLOSE_TILE6 (0x0854)
#define DOWN_GATE_CLOSE_TILE7 (0x0C54)
#define DOWN_GATE_CLOSE_TILE8 (0x0C53)
#define DOWN_GATE_OPEN_TILE1 (0x005B)
#define DOWN_GATE_OPEN_TILE2 (0x0000)
#define DOWN_GATE_OPEN_TILE3 (0x0000)
#define DOWN_GATE_OPEN_TILE4 (0x045B)
#define DOWN_GATE_OPEN_TILE5 (0x085A)
#define DOWN_GATE_OPEN_TILE6 (0x0000)
#define DOWN_GATE_OPEN_TILE7 (0x0000)
#define DOWN_GATE_OPEN_TILE8 (0x0C5A)
#define LEFT_GATE_CLOSE_TILE1 (0x004F)
#define LEFT_GATE_CLOSE_TILE2 (0x0050)
#define LEFT_GATE_CLOSE_TILE3 (0x0057)
#define LEFT_GATE_CLOSE_TILE4 (0x0058)
#define LEFT_GATE_CLOSE_TILE5 (0x0857)
#define LEFT_GATE_CLOSE_TILE6 (0x0858)
#define LEFT_GATE_CLOSE_TILE7 (0x084F)
#define LEFT_GATE_CLOSE_TILE8 (0x0850)
#define LEFT_GATE_OPEN_TILE1 (0x0051)
#define LEFT_GATE_OPEN_TILE2 (0x0052)
#define LEFT_GATE_OPEN_TILE3 (0x0000)
#define LEFT_GATE_OPEN_TILE4 (0x0000)
#define LEFT_GATE_OPEN_TILE5 (0x0000)
#define LEFT_GATE_OPEN_TILE6 (0x0000)
#define LEFT_GATE_OPEN_TILE7 (0x0851)
#define LEFT_GATE_OPEN_TILE8 (0x0852)
#define RIGHT_GATE_CLOSE_TILE1 (0x0450)
#define RIGHT_GATE_CLOSE_TILE2 (0x044F)
#define RIGHT_GATE_CLOSE_TILE3 (0x0458)
#define RIGHT_GATE_CLOSE_TILE4 (0x0457)
#define RIGHT_GATE_CLOSE_TILE5 (0x0C58)
#define RIGHT_GATE_CLOSE_TILE6 (0x0C57)
#define RIGHT_GATE_CLOSE_TILE7 (0x0C50)
#define RIGHT_GATE_CLOSE_TILE8 (0x0C4F)
#define RIGHT_GATE_OPEN_TILE1 (0x0452)
#define RIGHT_GATE_OPEN_TILE2 (0x0451)
#define RIGHT_GATE_OPEN_TILE3 (0x0000)
#define RIGHT_GATE_OPEN_TILE4 (0x0000)
#define RIGHT_GATE_OPEN_TILE5 (0x0000)
#define RIGHT_GATE_OPEN_TILE6 (0x0000)
#define RIGHT_GATE_OPEN_TILE7 (0x0C52)
#define RIGHT_GATE_OPEN_TILE8 (0x0C51)

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
