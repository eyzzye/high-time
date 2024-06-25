import sys

tile_indexes = []

def read_tile_indexes(filename):
    found_rodata_cnt = 0
    total_index = 0
    with open(filename) as file:
        for line in file:
            #print(line.rstrip())
            if found_rodata_cnt < 2:
                if ".section .rodata" in line:
                    found_rodata_cnt += 1
            elif found_rodata_cnt == 2:
                if ".hword" in line:
                    line_no_newline = line.rstrip()
                    #print(line_no_newline[8:])
                    data_list = line_no_newline[8:].split(",")
                    for index in data_list:
                        tile_indexes.append(index)
                        total_index += 1
                elif ".section .rodata" in line:
                    break
                else:
                    #print("skip")
                    pass
    #print(total_index)
    #print(tile_indexes)

def get_hero_tile():
    print("#define HERO_TILE1 ({})".format(tile_indexes[1022-32]))
    print("#define HERO_TILE2 ({})".format(tile_indexes[1023-32]))
    print("#define HERO_TILE3 ({})".format(tile_indexes[1022]))
    print("#define HERO_TILE4 ({})".format(tile_indexes[1023]))

def get_goal_tile():
    print("#define GOAL_TILE1 ({})".format(tile_indexes[1020-32]))
    print("#define GOAL_TILE2 ({})".format(tile_indexes[1021-32]))
    print("#define GOAL_TILE3 ({})".format(tile_indexes[1020]))
    print("#define GOAL_TILE4 ({})".format(tile_indexes[1021]))

def get_teleport_tile():
    print("#define TELEPORT_TILE1 ({})".format(tile_indexes[1018-32]))
    print("#define TELEPORT_TILE2 ({})".format(tile_indexes[1019-32]))
    print("#define TELEPORT_TILE3 ({})".format(tile_indexes[1018]))
    print("#define TELEPORT_TILE4 ({})".format(tile_indexes[1019]))

def get_up_stairs_tile():
    print("#define UP_STAIRS_TILE1 ({})".format(tile_indexes[1016-32]))
    print("#define UP_STAIRS_TILE2 ({})".format(tile_indexes[1017-32]))
    print("#define UP_STAIRS_TILE3 ({})".format(tile_indexes[1016]))
    print("#define UP_STAIRS_TILE4 ({})".format(tile_indexes[1017]))

def get_down_stairs_tile():
    print("#define DOWN_STAIRS_TILE1 ({})".format(tile_indexes[1014-32]))
    print("#define DOWN_STAIRS_TILE2 ({})".format(tile_indexes[1015-32]))
    print("#define DOWN_STAIRS_TILE3 ({})".format(tile_indexes[1014]))
    print("#define DOWN_STAIRS_TILE4 ({})".format(tile_indexes[1015]))

def get_up_gate_tile():
    print("#define UP_GATE_CLOSE_TILE1 ({})".format(tile_indexes[1000-96]))
    print("#define UP_GATE_CLOSE_TILE2 ({})".format(tile_indexes[1001-96]))
    print("#define UP_GATE_CLOSE_TILE3 ({})".format(tile_indexes[1002-96]))
    print("#define UP_GATE_CLOSE_TILE4 ({})".format(tile_indexes[1003-96]))
    print("#define UP_GATE_CLOSE_TILE5 ({})".format(tile_indexes[1000-64]))
    print("#define UP_GATE_CLOSE_TILE6 ({})".format(tile_indexes[1001-64]))
    print("#define UP_GATE_CLOSE_TILE7 ({})".format(tile_indexes[1002-64]))
    print("#define UP_GATE_CLOSE_TILE8 ({})".format(tile_indexes[1003-64]))
    
    print("#define UP_GATE_OPEN_TILE1 ({})".format(tile_indexes[1000-32]))
    print("#define UP_GATE_OPEN_TILE2 ({})".format(tile_indexes[1001-32]))
    print("#define UP_GATE_OPEN_TILE3 ({})".format(tile_indexes[1002-32]))
    print("#define UP_GATE_OPEN_TILE4 ({})".format(tile_indexes[1003-32]))
    print("#define UP_GATE_OPEN_TILE5 ({})".format(tile_indexes[1000]))
    print("#define UP_GATE_OPEN_TILE6 ({})".format(tile_indexes[1001]))
    print("#define UP_GATE_OPEN_TILE7 ({})".format(tile_indexes[1002]))
    print("#define UP_GATE_OPEN_TILE8 ({})".format(tile_indexes[1003]))

def get_down_gate_tile():
    print("#define DOWN_GATE_CLOSE_TILE1 ({})".format(tile_indexes[1004-96]))
    print("#define DOWN_GATE_CLOSE_TILE2 ({})".format(tile_indexes[1005-96]))
    print("#define DOWN_GATE_CLOSE_TILE3 ({})".format(tile_indexes[1006-96]))
    print("#define DOWN_GATE_CLOSE_TILE4 ({})".format(tile_indexes[1007-96]))
    print("#define DOWN_GATE_CLOSE_TILE5 ({})".format(tile_indexes[1004-64]))
    print("#define DOWN_GATE_CLOSE_TILE6 ({})".format(tile_indexes[1005-64]))
    print("#define DOWN_GATE_CLOSE_TILE7 ({})".format(tile_indexes[1006-64]))
    print("#define DOWN_GATE_CLOSE_TILE8 ({})".format(tile_indexes[1007-64]))
    
    print("#define DOWN_GATE_OPEN_TILE1 ({})".format(tile_indexes[1004-32]))
    print("#define DOWN_GATE_OPEN_TILE2 ({})".format(tile_indexes[1005-32]))
    print("#define DOWN_GATE_OPEN_TILE3 ({})".format(tile_indexes[1006-32]))
    print("#define DOWN_GATE_OPEN_TILE4 ({})".format(tile_indexes[1007-32]))
    print("#define DOWN_GATE_OPEN_TILE5 ({})".format(tile_indexes[1004]))
    print("#define DOWN_GATE_OPEN_TILE6 ({})".format(tile_indexes[1005]))
    print("#define DOWN_GATE_OPEN_TILE7 ({})".format(tile_indexes[1006]))
    print("#define DOWN_GATE_OPEN_TILE8 ({})".format(tile_indexes[1007]))

def get_left_gate_tile():
    print("#define LEFT_GATE_CLOSE_TILE1 ({})".format(tile_indexes[992-96]))
    print("#define LEFT_GATE_CLOSE_TILE2 ({})".format(tile_indexes[993-96]))
    print("#define LEFT_GATE_CLOSE_TILE3 ({})".format(tile_indexes[992-64]))
    print("#define LEFT_GATE_CLOSE_TILE4 ({})".format(tile_indexes[993-64]))
    print("#define LEFT_GATE_CLOSE_TILE5 ({})".format(tile_indexes[992-32]))
    print("#define LEFT_GATE_CLOSE_TILE6 ({})".format(tile_indexes[993-32]))
    print("#define LEFT_GATE_CLOSE_TILE7 ({})".format(tile_indexes[992]))
    print("#define LEFT_GATE_CLOSE_TILE8 ({})".format(tile_indexes[993]))
    
    print("#define LEFT_GATE_OPEN_TILE1 ({})".format(tile_indexes[994-96]))
    print("#define LEFT_GATE_OPEN_TILE2 ({})".format(tile_indexes[995-96]))
    print("#define LEFT_GATE_OPEN_TILE3 ({})".format(tile_indexes[994-64]))
    print("#define LEFT_GATE_OPEN_TILE4 ({})".format(tile_indexes[995-64]))
    print("#define LEFT_GATE_OPEN_TILE5 ({})".format(tile_indexes[994-32]))
    print("#define LEFT_GATE_OPEN_TILE6 ({})".format(tile_indexes[995-32]))
    print("#define LEFT_GATE_OPEN_TILE7 ({})".format(tile_indexes[994]))
    print("#define LEFT_GATE_OPEN_TILE8 ({})".format(tile_indexes[995]))

def get_right_gate_tile():
    print("#define RIGHT_GATE_CLOSE_TILE1 ({})".format(tile_indexes[996-96]))
    print("#define RIGHT_GATE_CLOSE_TILE2 ({})".format(tile_indexes[997-96]))
    print("#define RIGHT_GATE_CLOSE_TILE3 ({})".format(tile_indexes[996-64]))
    print("#define RIGHT_GATE_CLOSE_TILE4 ({})".format(tile_indexes[997-64]))
    print("#define RIGHT_GATE_CLOSE_TILE5 ({})".format(tile_indexes[996-32]))
    print("#define RIGHT_GATE_CLOSE_TILE6 ({})".format(tile_indexes[997-32]))
    print("#define RIGHT_GATE_CLOSE_TILE7 ({})".format(tile_indexes[996]))
    print("#define RIGHT_GATE_CLOSE_TILE8 ({})".format(tile_indexes[997]))
    
    print("#define RIGHT_GATE_OPEN_TILE1 ({})".format(tile_indexes[998-96]))
    print("#define RIGHT_GATE_OPEN_TILE2 ({})".format(tile_indexes[999-96]))
    print("#define RIGHT_GATE_OPEN_TILE3 ({})".format(tile_indexes[998-64]))
    print("#define RIGHT_GATE_OPEN_TILE4 ({})".format(tile_indexes[999-64]))
    print("#define RIGHT_GATE_OPEN_TILE5 ({})".format(tile_indexes[998-32]))
    print("#define RIGHT_GATE_OPEN_TILE6 ({})".format(tile_indexes[999-32]))
    print("#define RIGHT_GATE_OPEN_TILE7 ({})".format(tile_indexes[998]))
    print("#define RIGHT_GATE_OPEN_TILE8 ({})".format(tile_indexes[999]))

def get_item_key_tile():
    print("#define ITEM_KEY_TILE1 ({})".format(tile_indexes[704]))
    print("#define ITEM_KEY_TILE2 ({})".format(tile_indexes[705]))
    print("#define ITEM_KEY_TILE3 ({})".format(tile_indexes[704+32]))
    print("#define ITEM_KEY_TILE4 ({})".format(tile_indexes[705+32]))

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("USAGE: python tile_index_from_s_file.py S_FILENAME")
    else:
        #print(sys.argv[1])
        read_tile_indexes(sys.argv[1])
        get_hero_tile()
        get_goal_tile()
        get_teleport_tile()
        get_up_stairs_tile()
        get_down_stairs_tile()
        get_up_gate_tile()
        get_down_gate_tile()
        get_left_gate_tile()
        get_right_gate_tile()
        #get_item_key_tile()

