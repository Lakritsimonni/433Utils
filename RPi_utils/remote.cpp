#include "../rc-switch/RCSwitch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void Sleep(float s) 
{ 
    int sec = int(s*1000000); 
    usleep(sec); 
} 


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
      for (int i = 0; i < 4; ++i) {
      mySwitch.send(a_on[i], 24);
      Sleep(0.1);
      printf("%d \n", a_on[i]);
      }
   }

   else if (arg1 == "a" && arg2=="off") {
      
      for (int i = 0; i < 4; ++i) {
      mySwitch.send(a_off[i], 24);
      printf("%d \n", a_off[i]);
      }
   }
   else if (arg1 == "b" && arg2=="on") {
      for (int i = 0; i < 4; ++i) {
      mySwitch.send(b_on[i], 24);
      printf("%d \n", b_on[i]);
      }
   }
   else if (arg1 == "b" && arg2=="off") {
      for (int i = 0; i < 4; ++i) {
      mySwitch.send(b_off[i], 24);
      printf("%d \n", b_off[i]);
      }
   }
   else if (arg1 == "c" && arg2=="on") {
      for (int i = 0; i < 4; ++i) {
      mySwitch.send(c_on[i], 24);
      printf("%d \n", c_on[i]);
      }
   }
   else if (arg1 == "c" && arg2=="off") {
      for (int i = 0; i < 4; ++i) {
      mySwitch.send(c_off[i], 24);
      printf("%d \n", c_off[i]);
      }



   }else{
   printf("Nothing");
   }
   printf("%s \n",argv[1]);
   printf("%s \n", argv[2]);
   return 0;

}


