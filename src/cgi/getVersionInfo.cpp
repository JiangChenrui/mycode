#include "cgic.h"
#include "cJSON.h"
#include <string.h>
#include <string>

extern char *cgiQueryString;

extern cgiUnescapeResultType cgiUnescapeChars(char **sp, char *cp, int len);

int responseStrDataJsonTest(int code, char *msg, char *data) {
    char *out = NULL;
    cJSON *root = NULL;
    root = cJSON_CreateObject();
    cJSON_AddNumberToObject(root, "code", code);
    if (msg == NULL) {
        cJSON_AddStringToObject(root, "msg", "未设置错误信息");
    } else {
        cJSON_AddStringToObject(root, "msg", msg);
    }
    if (data != NULL) {
        cJSON_AddStringToObject(root, "data", data);
    }
    out = cJSON_Print(root);
    fprintf(cgiOut, out);
    cJSON_Delete(root);
    if (out != NULL)
        free(out);
    return 0;
}

int cgiMain() {
    int ret = 0;
    char errMsg[128] = {0};
    char token[128] = {0};

    //1.输出响应头
    // responseHeader();
    cgiHeaderStatus(200, (char*)"OK");
    cgiHeaderAccessControlAllowOrigin((char*)"*");
    cgiHeaderContentType((char*)"application/json;charset=utf-8");

    //2.接受token
    cgiFormResultType resultType;
    resultType = cgiFormString("token", token, 128);
    //3.判断token
    if (resultType != cgiFormSuccess) {
        return responseStrDataJsonTest(503, "用户未登录", NULL);
    }
    //4.判断token是否存在或过时
    // ret = checkUserToken(token, errMsg);
    if (ret != 0) {
        return responseStrDataJsonTest(503, errMsg, NULL);
    }
    
    //5.访问服务程序并发送请求配置信息
    // std::string request;
    // std::string response;

    // ret = packGetVersionInfo(request);
    // if (ret != 0) {
    //     return responseStrDataJson(503, PACK_CMD_FAILED, NULL);
    // }
    // IPCClient client(uv_default_loop(), false);
    // ret = client.sendCmd(request, response);
    // if (ret != 0) {
    //     return responseStrDataJson(503, MAIN_SERVER_CONNECT_FAILED, NULL);
    // }

    //6.直接输出服务端返回信息
    // fprintf(cgiOut, response.c_str());
    
    // return 0;
    return responseStrDataJsonTest(200, "getVersionInfo", NULL);
}