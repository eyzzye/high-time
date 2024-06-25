#ifndef HT_STAGE3_TILES_H
#define HT_STAGE3_TILES_H

#define HERO_TILE1 (0x0059)
#define HERO_TILE2 (0x005A)
#define HERO_TILE3 (0x0062)
#define HERO_TILE4 (0x0063)
#define GOAL_TILE1 (0x0057)
#define GOAL_TILE2 (0x0058)
#define GOAL_TILE3 (0x0060)
#define GOAL_TILE4 (0x0061)
#define TELEPORT_TILE1 (0x0056)
#define TELEPORT_TILE2 (0x001F)
#define TELEPORT_TILE3 (0x005E)
#define TELEPORT_TILE4 (0x005F)
#define UP_STAIRS_TILE1 (0x0054)
#define UP_STAIRS_TILE2 (0x0055)
#define UP_STAIRS_TILE3 (0x005C)
#define UP_STAIRS_TILE4 (0x005D)
#define DOWN_STAIRS_TILE1 (0x0053)
#define DOWN_STAIRS_TILE2 (0x0453)
#define DOWN_STAIRS_TILE3 (0x005B)
#define DOWN_STAIRS_TILE4 (0x045B)
#define UP_GATE_CLOSE_TILE1 (0x004A)
#define UP_GATE_CLOSE_TILE2 (0x004B)
#define UP_GATE_CLOSE_TILE3 (0x044B)
#define UP_GATE_CLOSE_TILE4 (0x044A)
#define UP_GATE_CLOSE_TILE5 (0x084C)
#define UP_GATE_CLOSE_TILE6 (0x084D)
#define UP_GATE_CLOSE_TILE7 (0x0050)
#define UP_GATE_CLOSE_TILE8 (0x0C4C)
#define UP_GATE_OPEN_TILE1 (0x0051)
#define UP_GATE_OPEN_TILE2 (0x0000)
#define UP_GATE_OPEN_TILE3 (0x0000)
#define UP_GATE_OPEN_TILE4 (0x0451)
#define UP_GATE_OPEN_TILE5 (0x0852)
#define UP_GATE_OPEN_TILE6 (0x0000)
#define UP_GATE_OPEN_TILE7 (0x0000)
#define UP_GATE_OPEN_TILE8 (0x0C52)
#define DOWN_GATE_CLOSE_TILE1 (0x004C)
#define DOWN_GATE_CLOSE_TILE2 (0x004D)
#define DOWN_GATE_CLOSE_TILE3 (0x044D)
#define DOWN_GATE_CLOSE_TILE4 (0x044C)
#define DOWN_GATE_CLOSE_TILE5 (0x084A)
#define DOWN_GATE_CLOSE_TILE6 (0x084B)
#define DOWN_GATE_CLOSE_TILE7 (0x0C4B)
#define DOWN_GATE_CLOSE_TILE8 (0x0C4A)
#define DOWN_GATE_OPEN_TILE1 (0x0052)
#define DOWN_GATE_OPEN_TILE2 (0x0000)
#define DOWN_GATE_OPEN_TILE3 (0x0000)
#define DOWN_GATE_OPEN_TILE4 (0x0452)
#define DOWN_GATE_OPEN_TILE5 (0x0851)
#define DOWN_GATE_OPEN_TILE6 (0x0000)
#define DOWN_GATE_OPEN_TILE7 (0x0000)
#define DOWN_GATE_OPEN_TILE8 (0x0C51)
#define LEFT_GATE_CLOSE_TILE1 (0x0046)
#define LEFT_GATE_CLOSE_TILE2 (0x0047)
#define LEFT_GATE_CLOSE_TILE3 (0x004E)
#define LEFT_GATE_CLOSE_TILE4 (0x004F)
#define LEFT_GATE_CLOSE_TILE5 (0x084E)
#define LEFT_GATE_CLOSE_TILE6 (0x084F)
#define LEFT_GATE_CLOSE_TILE7 (0x0846)
#define LEFT_GATE_CLOSE_TILE8 (0x0847)
#define LEFT_GATE_OPEN_TILE1 (0x0048)
#define LEFT_GATE_OPEN_TILE2 (0x0049)
#define LEFT_GATE_OPEN_TILE3 (0x0000)
#define LEFT_GATE_OPEN_TILE4 (0x0000)
#define LEFT_GATE_OPEN_TILE5 (0x0000)
#define LEFT_GATE_OPEN_TILE6 (0x0000)
#define LEFT_GATE_OPEN_TILE7 (0x0848)
#define LEFT_GATE_OPEN_TILE8 (0x0849)
#define RIGHT_GATE_CLOSE_TILE1 (0x0447)
#define RIGHT_GATE_CLOSE_TILE2 (0x0446)
#define RIGHT_GATE_CLOSE_TILE3 (0x044F)
#define RIGHT_GATE_CLOSE_TILE4 (0x044E)
#define RIGHT_GATE_CLOSE_TILE5 (0x0C4F)
#define RIGHT_GATE_CLOSE_TILE6 (0x0C4E)
#define RIGHT_GATE_CLOSE_TILE7 (0x0C47)
#define RIGHT_GATE_CLOSE_TILE8 (0x0C46)
#define RIGHT_GATE_OPEN_TILE1 (0x0449)
#define RIGHT_GATE_OPEN_TILE2 (0x0448)
#define RIGHT_GATE_OPEN_TILE3 (0x0000)
#define RIGHT_GATE_OPEN_TILE4 (0x0000)
#define RIGHT_GATE_OPEN_TILE5 (0x0000)
#define RIGHT_GATE_OPEN_TILE6 (0x0000)
#define RIGHT_GATE_OPEN_TILE7 (0x0C49)
#define RIGHT_GATE_OPEN_TILE8 (0x0C48)

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

