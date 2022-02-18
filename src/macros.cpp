#include <iostream>
#include <string>
#include "macros.h"

#include <windows.h>
#include <iostream>


char CURR_KEY;

std::string crouch() {
  // May implement later
  return "crouched";
}

std::string left() {
  SHORT key;
  UINT mappedkey;
  INPUT input = { 0 };
  key = VkKeyScan('9'); // bound to +left in game
  CURR_KEY = '9'; 

  mappedkey = MapVirtualKey(LOBYTE(key), 0);
  input.type = INPUT_KEYBOARD;

  input.ki.dwFlags = KEYEVENTF_SCANCODE;
  input.ki.wScan = mappedkey;
  SendInput(1, &input, sizeof(input));
  Sleep(100);

  input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
  SendInput(1, &input, sizeof(input));

  return "looked left";
}

std::string right() {
  SHORT key;
  UINT mappedkey;
  INPUT input = { 0 };
  key = VkKeyScan('8'); // bound +right in game
  CURR_KEY = '8'; 

  mappedkey = MapVirtualKey(LOBYTE(key), 0);
  input.type = INPUT_KEYBOARD;

  input.ki.dwFlags = KEYEVENTF_SCANCODE;
  input.ki.wScan = mappedkey;
  SendInput(1, &input, sizeof(input));
  Sleep(100);

  input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
  SendInput(1, &input, sizeof(input));

  return "looked right";
}

//Alternate shoot command for tapping
std::string shoot() {
  INPUT input = { 0 };
  input.type = INPUT_MOUSE;
  input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  SendInput(1, &input, sizeof(INPUT));

  Sleep(10);

  ZeroMemory(&input, sizeof(INPUT)); 
  input.type = INPUT_MOUSE; 
  input.mi.dwFlags = MOUSEEVENTF_LEFTUP; 
  SendInput(1, &input, sizeof(INPUT)); 

  return "shot"; 
}

std::string spray() {
  INPUT input = { 0 };

  input.type = INPUT_MOUSE;
  input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  SendInput(1, &input, sizeof(INPUT));

  Sleep(500); //Should determine how long spray lasts

  ZeroMemory(&input, sizeof(INPUT)); 

  input.type = INPUT_MOUSE; 
  input.mi.dwFlags = MOUSEEVENTF_LEFTUP; 
  SendInput(1, &input, sizeof(INPUT)); 

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

  // CURR_KEY = ' ';
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



//**Note
//Issue with starting movement persists in csgo -> look into this
//Change to void once testing is done
