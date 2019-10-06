#include "../rc-switch/RCSwitch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void Sleep(float s);

void sendArray(int arr[]);

int main(int argc, char *argv[]) {

   int a_off[4] = {13323424,12897568,13074704,13183632};
   int a_on[4] = {13298480,13112896,13546672,12673904};
   int b_off[4] = {13074708,12897572,13323428,13183636};
   int b_on[4] = {13298484,13546676,12673908,13112900};
   int c_off[4] = {12897580,13323436,13183644,13074716};
   int c_on[4] = {13546684,12673916,13112908,13298492};

   std::string arg1 = argv[1];
   std::string arg2 = argv[2];

   int protocol = 3;
   int PIN = 0;
   int pulselength = 0;

   if (wiringPiSetup () == -1) return 1;
   RCSwitch mySwitch = RCSwitch();
   mySwitch.setProtocol(protocol);
   mySwitch.enableTransmit(PIN);

   if (arg1 == "a" && arg2=="on") {
      sendArray(a_on);
   }
   else if (arg1 == "a" && arg2=="off") {
      sendArray(b_off);
   }
   else if (arg1 == "b" && arg2=="on") {
      sendArray(b_on);
   }
   else if (arg1 == "b" && arg2=="off") {
      sendArray(b_off);
   }
   else if (arg1 == "c" && arg2=="on") {
      sendArray(c_off);
   }
   else if (arg1 == "c" && arg2=="off") {
      sendArray(c_off);
   }else{
   printf("No input");
   }

   return 0;

}

void sendArray(int arr[]){
   int protocol = 3;
   int PIN = 0;
   int pulselength = 0;

   RCSwitch mySwitch = RCSwitch();
   mySwitch.setProtocol(protocol);
   mySwitch.enableTransmit(PIN);

   for (int i = 0; i < 4; ++i) {
      mySwitch.send(arr[i], 24);
      }
}

void Sleep(float s)
{
    int sec = int(s*1000000);
    usleep(sec);
}

