// Copyright (c) 2022 Evgeny Vovk All rights reserved.
//
// Created by: Evgeny Vovk
// Created on: December 2022
// This program is the Space Aliens for the GameBoy

#include <gb/gb.h>
#include <stdio.h>

#include "SpaceAliens.c"

void main () {
    set_sprite_data(0, 16, SpaceAliens);
    set_sprite_tile(0, 15);
    move_sprite(0, 88, 78);

    set_sprite_tile(1, 5);
    set_sprite_tile(2, 10);

    move_sprite(1, 8, 144);
    move_sprite(2, 64, 64);

    SHOW_SPRITES;
}

