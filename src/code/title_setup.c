#include "global.h"
#include "overlays/gamestates/ovl_title/z_title.h"

void TitleSetup_GameStateResetContext(void) {
    XREG(2) = 0;
    XREG(10) = 26;
    XREG(11) = 20;
    XREG(12) = 14;
    XREG(13) = 0;
    XREG(31) = 0;
    R_MAGIC_CONSUME_TIMER_GIANTS_MASK = 80;
    XREG(43) = 0xFC54;

    XREG(44) = 215;
    XREG(45) = 218;
    XREG(68) = 97;
    XREG(69) = 147;
    XREG(70) = 40;
    XREG(73) = 30;
    XREG(74) = 66;
    XREG(75) = 30;
    XREG(76) = 28;
    XREG(77) = 60;
    XREG(78) = 47;
    XREG(79) = 98;
    XREG(87) = 0;
    XREG(88) = 86;
    XREG(89) = 600;
    XREG(90) = 450;
    XREG(91) = 0;
    XREG(94) = 0;
    XREG(95) = 0;

    YREG(32) = 0x50;
    YREG(33) = 0x3C;
    YREG(34) = 0xDC;
    YREG(35) = 0x3C;
    YREG(36) = 0x50;
    YREG(37) = 0xA0;
    YREG(38) = 0xDC;
    YREG(39) = 0xA0;
    YREG(40) = 0x8E;
    YREG(41) = 0x6C;
    YREG(42) = 0xCC;
    YREG(43) = 0xB1;
}

void TitleSetup_InitImpl(GameState* gameState) {
    func_80185908();
    SaveContext_Init();
    TitleSetup_GameStateResetContext();

    gameState->running = 0;

setNextGamestate
    :; // This label is probably a leftover of a debug ifdef, it's essential to not have gameState->running reordered!
    SET_NEXT_GAMESTATE(gameState, Title_Init, TitleContext);
}

void TitleSetup_Destroy(GameState* gameState) {
    ;
}

void TitleSetup_Init(GameState* gameState) {
    gameState->destroy = TitleSetup_Destroy;
    TitleSetup_InitImpl(gameState);
}
