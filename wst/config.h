#ifndef _CONFIG_H_
#define _CONFIG_H_

// linux include files
#include <dirent.h>
#include <unistd.h>

// c include files
#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <string.h>

// c++ include files
#include <sstream>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <mutex>

// libevent include files
#include <event.h>
#include <evhttp.h>

#if LOGER
#include "logger.h"
#endif // LOGER
using namespace std;

#define LLMBS_VERSION "v1.0.0"

enum errcode 
{
    ERROR = -1,
    SUCCESS = 0,
    TOKENERROR = 100,
    USERPWDERROR = 101,
    AUTHFAIL = 102,
    NOTDEST = 103,
    NOTCOMMAND = 104,
    HTTPTIMEOUT = 105,
    ADDUSERERROR = 106,
    DELETEUSERERROR = 107,
    CHANGEUSERERROR = 108,
    QUERYUSERERROR = 109,

    PARAMERROR = 300,
    CHANNELSTARTED = 301,
    CHANNELNOTFOUND = 302,
    CREATECHANNELFAILED = 303,
    FREECHANNELFAILED = 304,
    MIXPARAM2 = 305,
    FILENOTFOUND = 306,
    DISKFULL = 307,
    RECORDCHANNELFULL = 308,
    PLAYCHANNELFULL = 309,
    AUTHORIZATIONDATEEXPIRED = 310,
    
    AGORAFAILED=311,
    AGORAINVAILDAGUMENT=312,
    AGORAINTERNALFAILED=313
};

typedef struct _file_info
{
    string name;        // file name
    string meta;        // metadata file name
    string pic;         // picture file
    string type;        // file type
    string path;        // file path
    string channel;
} FileInfo;

typedef struct _dev_info
{
    string      devnum;
    string      devname;
    uint32_t    devtime;
    uint32_t    devstate;
    string      devtype;
    string      devdescription;
} DevInfo;

#define HTTP_CONTENT_TYPE_URL_ENCODED   "application/json"
#define HTTP_CONTENT_TYPE_FORM_DATA     "multipart/form-data"
#define HTTP_CONTENT_TYPE_TEXT_PLAIN    "text/plain"

#define REQUEST_POST_FLAG               2
#define REQUEST_GET_FLAG                3

struct http_request_get 
{
    struct evhttp_uri *uri;
    struct event_base *base;
    struct evhttp_connection *cn;
    struct evhttp_request *req;
    void * param;
};

struct http_request_post
{
    struct evhttp_uri *uri;
    struct event_base *base;
    struct evhttp_connection *cn;
    struct evhttp_request *req;
    char *content_type;
    char *post_data;
    void * param;
};


#endif // _CONFIG_H_