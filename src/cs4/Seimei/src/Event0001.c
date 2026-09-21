#include "Event0001.h"
#include "Camera.h"
#include "KuonMsg.h"
#include "Game.h"
#include "Script.h"

static void InitS0001Event000(EVENT* lpEvent);
static void PlayS0001Event000(EVENT* lpEvent);
static void ActiS0001Event000(EVENT* lpEvent, u_int Id);

void SetEventFuncS0001(void) {
    EventMngSt->InitFunc = InitS0001Event000;
    EventMngSt->PlayFunc = PlayS0001Event000;
    EventMngSt->ActiFunc = ActiS0001Event000;
}

static void InitS0001Event000(EVENT* lpEvent) {
    
    if (GameSt.PlayerId != 0 || CheckEventFlag(0x6D6)) {
    
        
        SetEventFlag(0x6D6);
        lpEvent->State[0] = 2;
    }
    else if (!CheckEventFlag(0x7A)) {
        
        lpEvent->State[0] = 2;
    } else {
        
        
        lpEvent->State[0] = 0;
    }
}

static void PlayS0001Event000(EVENT* lpEvent) {
    if (lpEvent->State[0] != 1) return;
    
    
    if (++lpEvent->State[1] < 0x3C) return;

    lpEvent->State[0] = 2;
    lpEvent->State[1] = 0;
    SetEventFlag(0x6D6);
    
    SetCamCtrlMode(0);
}

static void ActiS0001Event000(EVENT* lpEvent, u_int Id) {
    switch (Id) {     
        case 1:
            if (lpEvent->State[0] == 0) {
                
                EasyEneAppear(1);
                
                lpEvent->State[0] = 1;
                
                lpEvent->State[1] = 0;
                SetCamCtrlMode(1);                
                SetCameraPos((float[]){-11.7f, -2.8f, 9.6999998f, 1.0f});        
                SetCameraAng((float[]){-0.26174998f, -0.087249994f, 0.0f, 0.0f});
            }
            else {
                KnMsgMng_SendMsg(0x61ACD);
            }
    }    
}
