#pragma once

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define SUCCESS 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);
int main(int argc, char* argv[]);
void sendPrintScreen();