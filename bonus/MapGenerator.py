#!/usr/bin/env python3
from os import path
import pygame

BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
GREY = (220, 220, 220)

BRICK = 3
BLOCK = 2
BORDER = 1
PATH = 0

BLOCK_MAP_CLOR = {
    BRICK: RED,
    BLOCK: BLUE,
    BORDER: GREY,
    PATH: GREEN
}



def getHboreder(size):
    line = [BORDER for x in range(size + 2)]
    return line

def create_base_map(size):
    map = []
    map.append(getHboreder(size))
    for y in range(1, size + 1):
        buf_line = []
        for x in range(size + 2):
            if x == 0:
                buf_line.append(BORDER)
                continue
            elif x== (size + 1):
                buf_line.append(BORDER)
                continue
            if y % 2 == 1:
                buf_line.append(BLOCK)
            else:
                if x % 2 == 1:
                    buf_line.append(BLOCK)
                else:
                    buf_line.append(BRICK)
        map.append(buf_line)
    map.append(getHboreder(size))
    return map

def SaveMap(filename, universe, size, map):
    file = open(filename + ".save", "w")
    file.write(universe + "\n")
    file.write(str(size) + "\n")
    for y in map:
        for x in y:
            file.write(str(x)+ "|")
        file.write("\n")
    file.close()

#########################################

#pygame

screen = pygame.display.set_mode((600, 600))

PADDING = 40
CELL_SIZE = 30

def draw_cell(x, y, value):
    color = BLOCK_MAP_CLOR[value]

    pygame.draw.rect(screen, BLACK, ((CELL_SIZE * x) + PADDING, (CELL_SIZE * y) + PADDING, CELL_SIZE, CELL_SIZE))
    pygame.draw.rect(screen, color, ((CELL_SIZE * x) + 1 + PADDING, (CELL_SIZE * y) + 1 + PADDING, CELL_SIZE, CELL_SIZE))

def draw_map(map):
    for y in range(len(map)):
        for x in range(len(map)):
            draw_cell(x, y, map[y][x])

def handle_click(map, x, y):
    x_map = int((x - PADDING) / CELL_SIZE)
    y_map = int((y - PADDING) / CELL_SIZE)
    if (x_map < 0) or y_map < 0:
        return map
    if y_map >=len(map) or x_map >= len(map):
        return map
    x = x_map
    y = y_map
    if map[y][x] == PATH:
        map[y][x] = BLOCK
    elif map[y][x] == BLOCK:
        map[y][x] = PATH
    return map

import time

def pygameLoop(map):
    running = True
    while running:
        draw_map(map)
        if pygame.mouse.get_pressed()[0]:
            (x_mouse, y_mouse) = pygame.mouse.get_pos()
            map = handle_click(map, x_mouse, y_mouse)
            time.sleep(0.2)

        if pygame.key.get_pressed()[pygame.K_SPACE] == True:
            running = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        pygame.display.update()
    pygame.quit()
    return map

def main(saveFileName):
    size = 15
    map = create_base_map(size)
    for line in map:
        print(line)
    print(len(map))
    print(len(map[0]))
    map = pygameLoop(map)
    SaveMap(saveFileName, "Pirates", size, map)

import sys

if __name__ == '__main__':
    if len(sys.argv) != 1:
        main(sys.argv[1])
    else:
        main("MapSave")
