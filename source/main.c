#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>
int main(int argc, char **argv) {
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);
        SwkbdState swkbd;
	printf("Press A to start the keyboard.\n");
        printf("Press B to send a notification to the home menu.");
        printf("Press START to go back to the loader.\n");
        newsInit();
        char woah[30];
        swkbdInit(&swkbd, SWKBD_TYPE_QWERTY,3,30);
	// Main loop
	while (aptMainLoop()) {

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
                }/* else if (kDown & KEY_B){
                    char title[10] = "Shana3DS"; 
                    char message[255] = "Hello there. I'm Omochao and I'll be your guide."; 
                 dead for now
                    NEWS_AddNotification((u16) atoi(title),(u32) sizeof(title),(u16) atoi(message),
                            (u32) sizeof(message), MagickImage, sizeof(MagickImage),false);*/
                }

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}
	gfxExit();
	return 0;
}
