#include <iostream>
#include <string>
#include "macros.h"

#include <windows.h>
#include <iostream>

// int main() {
//     while (true) {
//         if (GetAsyncKeyState(VK_NUMPAD0)) {
//             return 0;
//         }
//         if (GetAsyncKeyState(VK_NUMPAD1)) {
//             INPUT input = { 0 };
//             input.type = INPUT_KEYBOARD;
//             input.ki.wVk = VkKeyScan('w');
//             SendInput(1, &input, sizeof(input));
//         }
//         if (GetAsyncKeyState(VK_NUMPAD2)) {

//         }
//     }
// }
char CURR_KEY;
std::string look() {
  // input.type = INPUT_MOUSE;
  return "look";
}

std::string stop() {
  SHORT key;
  UINT mappedkey;
  INPUT input = { 0 };
  key = VkKeyScan(CURR_KEY);

  mappedkey = MapVirtualKey(LOBYTE(key), 0);
  input.type = INPUT_KEYBOARD;
  input.ki.wScan = mappedkey;
  input.ki.dwFlags = KEYEVENTF_KEYUP;
  SendInput(1, &input, sizeof(input));

  CURR_KEY = ' ';
  return "Stopped";
}

std::string jump() {

  //keydown then keyup
  return "Jump";
}

std::string go() {
  SHORT key;
  UINT mappedkey;
  INPUT input = { 0 };
  key = VkKeyScan('w');
  CURR_KEY = 'w'; 

  mappedkey = MapVirtualKey(LOBYTE(key), 0);
  input.type = INPUT_KEYBOARD;
  // input.ki.dwFlags = KEYEVENTF_SCANCODE;
  input.ki.wScan = mappedkey;
  SendInput(1, &input, sizeof(input));
  Sleep(10);
  // input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
  input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
  SendInput(1, &input, sizeof(input));

  return "go go go";
}
