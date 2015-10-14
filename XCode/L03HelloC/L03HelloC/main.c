//
//  main.c
//  L03HelloC
//
//  Created by 杨辉 on 10/14/15.
//  Copyright © 2015 杨辉. All rights reserved.
//

#include <stdio.h>

int max(int a, int b) {
    if (a>b) {
        return a;
    }else{
        return b;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n",max(10, 12));
    return 0;
}
