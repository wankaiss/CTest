//
//  main.c
//  L01HelloC
//
//  Created by 杨辉 on 10/13/15.
//  Copyright © 2015 杨辉. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
    for (int i = 0; i <argc; i++) {
        printf("%s\n",argv[0]);
    }
}
