// Copyright (c) 2022 Evgeny Vovk All rights reserved.
//
// Created by: Evgeny Vovk
// Created on: December 2022
// This program is the Space Aliens for the GameBoy

#include <gb/gb.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "GBDK_Constants.h"
#include "MetaSprites.c"
#include "SpaceAliens.c"
#include "Background.c"

void main () {
    uint8_t joypadData;

    bool aButtonJustPressed = false;
    bool aButtonStillPressed = false;

    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;

    const int FIXED_Y_POSITION_OF_SHIP = 144;
    int shipXPosition = 76;
    int shipYPosition = FIXED_Y_POSITION_OF_SHIP;

    set_sprite_data(0, 16, SpaceAliens);
    set_meta_sprite_tile(0, 1, 2, 3, 4);
    move_meta_sprite(0, shipXPosition, shipYPosition);

    set_bkg_data(0, 16, SpaceAliens);
    set_bkg_tiles(0, 0, 20, 36, Background);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    // game loop
    while (1) {
        joypadData = joypad();

        if (joypadData & J_LEFT) {
            scroll_meta_sprite(0, -1, 0);
            shipXPosition -= 1;
            if (shipXPosition < 8) {
                shipXPosition = 8;
                move_meta_sprite(0, 8, FIXED_Y_POSITION_OF_SHIP);
            }
        }
        if (joypadData & J_RIGHT) {
            scroll_meta_sprite(0, 1, 0);
            shipXPosition += 1;
            if (shipXPosition > SCREEN_WIDTH - 8) {
                shipXPosition = SCREEN_WIDTH - 8;
                move_meta_sprite(0, (uint8_t)(SCREEN_WIDTH - 8), FIXED_Y_POSITION_OF_SHIP);
            }
        }

        if (joypadData & J_A) {
            if (aButtonJustPressed == true) {
                aButtonStillPressed = true;
            }
            else {
                aButtonJustPressed = true;
                //play sound
                NR10_REG = 0x16;
                NR11_REG = 0x82;
                NR12_REG = 0x69;
                NR13_REG = 0x59;
                NR14_REG = 0xC6;
            }
        }
        else {
            aButtonJustPressed = false;
            aButtonStillPressed = false;
        }
        scroll_bkg(0, -1);

        wait_vbl_done();
    }
}

