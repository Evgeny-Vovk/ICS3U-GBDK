// Copyright (c) 2022 Evgeny Vovk All rights reserved.
//
// Created by: Evgeny Vovk
// Created on: December 2022
// This program is the Space Aliens for the GameBoy

#include <gb/gb.h>
#include <stdio.h>

#include "MetaSprites.c"
#include "SpaceAliens.c"

void main () {
    set_sprite_data(0, 16, SpaceAliens);
    set_meta_sprite_tile(0, 1, 2, 3, 4);
    move_meta_sprite(0, 76, 120);

    SHOW_SPRITES;
    DISPLAY_ON;
}

