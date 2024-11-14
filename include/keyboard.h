/**
 * keyboard.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
 */

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <termios.h>
#include <unistd.h>
#include <ctype.h>

void keyboardInit();

void keyboardDestroy();

int keyhit();

int readch();

#endif /* __KEYBOARD_H__ */
