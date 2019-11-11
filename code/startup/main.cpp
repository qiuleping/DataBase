

#include <iostream>
#include "../hiredis/hiredis.h"

int main(void){

    redisContext* c = redisConnect("127.0.0.1", 6379);
    if (c->err)
    {
        redisFree(c);
        printf("Connect to redisServer faile\n");
        return 0;
    }
    printf("Connect to redisServer Success\n");

    const char* cmd = "set name person";
    redisReply* r = (redisReply*)redisCommand(c, cmd);
    if(NULL != r){
           printf("failed");
    }
    freeReplyObject(r);
    printf("Success");

    return 0;
}
