#ifndef __UI_H__
#define __UI_H__

typedef enum {
	resultSelectedFile,
	resultClose,
	resultUnpause,
	resultExit,
	resultNone,
	resultLoadState,
	resultSaveState,
	resultSettingsChanged,
	resultShowCredits
} UIResult;

typedef enum { stateRunning, stateFileselect, statePaused, stateSettings, stateRemapButtons } UIState;

#define PATH_LENGTH 512

void uiInit();
void uiDeinit();

void uiGetSelectedFile(char* out, int outLength);

UIResult uiLoop(u32 keysDown);
void uiPushState(UIState state);
void uiPopState();
UIState uiGetState();

void uiAddSetting(const char* name, u32* valueIdx, u32 valuesCount, const char* strValues[], bool meta = false);
void uiFinaliseAndLoadSettings();
void uiSaveSettings();

void uiStatusMsg(const char* fmt, ...);

#endif