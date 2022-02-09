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

// -- MOUSE -- //
std::string up() {
  //Snaps to position instead of gradually moving up
  POINT currPos;
  GetCursorPos(&currPos);
  SetCursorPos(currPos.x, currPos.y - 75);
  return "looked up";
}

std::string down() {
  // input.type = INPUT_MOUSE;
  return "looked down";
}

std::string left() {
  // input.type = INPUT_MOUSE;
  return "looked left";
}

std::string right() {
  // input.type = INPUT_MOUSE;
  return "looked right";
}

//Haven't decided if it will tap or spray, (could do both with a toggle)
std::string shoot() {
  INPUT input = { 0 };
  input.type = INPUT_MOUSE;
  input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  SendInput(1, &input, sizeof(INPUT));

  Sleep(10);

  ZeroMemory(&input,sizeof(INPUT)); 
  input.type = INPUT_MOUSE; 
  input.mi.dwFlags = MOUSEEVENTF_LEFTUP; 
  SendInput(1,&input,sizeof(INPUT)); 

  return "shot"; 
}

std::string spray() {
  INPUT input = { 0 };

  input.type = INPUT_MOUSE;
  input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  SendInput(1, &input, sizeof(INPUT));

  Sleep(1000); //determines how long spray lasts

  ZeroMemory(&input,sizeof(INPUT)); 
  input.type = INPUT_MOUSE; 
  input.mi.dwFlags = MOUSEEVENTF_LEFTUP; 
  SendInput(1,&input,sizeof(INPUT)); 

  return "sprayed";
}


// -- KEYBOARD -- ??
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
  UINT mappedkey;
  INPUT input = {0};

  mappedkey = MapVirtualKey(VK_SPACE, 0);
  input.type = INPUT_KEYBOARD;

  input.ki.dwFlags = KEYEVENTF_SCANCODE;
  input.ki.wScan = mappedkey;
  SendInput(1, &input, sizeof(input));
  Sleep(10);

  input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
  SendInput(1, &input, sizeof(input));

  return "Jumped";
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

//Add crouch


//**Note
//Issue with starting movement persists in csgo -> look into this
//Change to void once testing is done
