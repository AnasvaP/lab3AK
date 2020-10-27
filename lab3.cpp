#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    int result=0;
  map <string, bool> checked_keys;

  int opt_index = -1;
  const char* short_options = "hlvcTPfV::?";
  //h-help; v-version; l-list; c-computer, P-Post
  
  const struct option long_options[] = {
  
        {"help",0,NULL,'h'},
        {"version",0,NULL,'v'},
        {"list",0,NULL,'l'},
        {"computer", 0, NULL, 'c'},
        {"Telegram", 0, NULL, 'T'},
        {"Post", 0, NULL, 'P'},
        {"finder", 0, NULL, 'f'},
      {"value", 19, NULL, 'V'},
        
    };
 
  while ((result = getopt_long(argc,argv,short_options,long_options, &opt_index)) != -1){
    switch (result){
    case 'h': {
      if (checked_keys["h"] == false) {
        printf("Arg: Help me\n");
        checked_keys["h"] = true;
        break;
      }
      break;
    }
    case 'P': {
      if (checked_keys["P"] == false) {
        printf("Arg: Post for me \n");
        checked_keys["P"] = true;
        break;
      }
      break;
    }
    case 'l': {
      if (checked_keys["l"] == false) {
        printf("Arg: List of something\n");
        checked_keys["l"] = true;
        break;
      }
      break;
    }
    case 'v': {
      if (checked_keys["v"] == false) {
        printf("Arg: Version of my Mac\n");
        checked_keys["v"] = true;
        break;
      }
      break;
    }
    case 'T': {
      if (checked_keys["T"] == false) {
        printf("Arg: Telegram messenger\n");
        checked_keys["T"] = true;
        break;
      }
      break;
    }
    case 'c': {
      if (checked_keys["c"] == false) {
        printf("Arg: computer program\n");
        checked_keys["c"] = true;
        break;
      }
      break;
    }
    case 'f': {
      if (checked_keys["f"] == false) {
          printf("Arg: finder is the most important program \n");
          checked_keys["f"] = true;
          break;
      }
      break;
    }
    case 'V':{
        if (checked_keys["V"] == false){
            if(optarg == NULL){
                printf("Arg: value");
                checked_keys["V"] = true;
            }
            else{
                printf("Arg: value %s\n", optarg);
                checked_keys["V"] = true;
            }
            break;
        }
        break;
    }
    default: {
      printf("Option not found\n");
      break;
      }
        };
    opt_index = -1;
  };
};
