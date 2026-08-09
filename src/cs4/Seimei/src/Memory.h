#ifndef MEMORY_H
#define MEMORY_H
void MemInit();


void * MemAllocAlignReal(unsigned int size /* r11 */, unsigned int align /* r2 */, char * lpFuncName /* r2 */, char * lpUseName /* r2 */);
#endif
