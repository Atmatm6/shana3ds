#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>

void wose(){
    
}

int main(int argc, char **argv) {
	gfxInitDefault();
        PrintConsole topScreen, bottomScreen;
	consoleInit(GFX_TOP, &topScreen);
        consoleInit(GFX_BOTTOM, &bottomScreen);
        SwkbdState swkbd;
        int prevShell = PTMU_GetShellState();
	printf("Press A to start the keyboard.\n");
        printf("Press START to go back to the loader.\n");
        newsInit();
        char woah[30];
        swkbdInit(&swkbd, SWKBD_TYPE_QWERTY,3,30);
        bool closed = false;
	// Main loop
	while (aptMainLoop()) {
                if (prevShell != PTMU_GetShellState() & !closed){
                    
                }
                gspWaitForVBlank();
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
                else if (kDown & KEY_A){
                    SwkbdButton sb = swkbdInputText(&swkbd,&woah,sizeof(woah));
                    if (sb == SWKBD_BUTTON_CONFIRM) printf(woah, '\n');
                    else if(sb == SWKBD_BUTTON_LEFT) printf("Canceled\n");
                    else printf("I'm not sure what happened.\n");
                } else if (kDown & KEY_B){
                    
                }

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}
	gfxExit();
	return 0;
}
