#ifndef EVENT_H
#define EVENT_H

#include "typedefs.h"

#include "Model.h"

// total size: 0x60
typedef struct _EVENT {
    // Members
    void (* InitFunc)(); // offset 0x0, size 0x4
    void (* PlayFunc)(); // offset 0x4, size 0x4
    void (* ActiFunc)(); // offset 0x8, size 0x4
    int State[10] __attribute__ ((aligned(16))); // offset 0xC, size 0x28
    MDLMNG* lpMdl[10]; // offset 0x34, size 0x28
} EVENT;

void SetEventModelDrawAndHit(MDLMNG* lpMdl, u_char OnOff);
void EventEneHitCheck(MDLMNG* lpEne);
void EasyEneAppearEx(int CtrlId, u_short AnimId, u_char bLogicFree);
void EasyEneAppear(int CtrlId);
int CheckSquareRange(float* Pos, float* Range);
void ActiEventFunc(u_int EventNo, u_int Id);
void PlayEventFunc(void);
void InitEventFunc(void);
void SetEventFunc(void);

extern EVENT EventMngSt[50]; // size: 0x12C0, address: 0xA58E50

#endif // EVENT_H
