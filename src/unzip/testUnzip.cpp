#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>

#include <string>

#include "ioapi.h"
#include "unzip.h"

int makedir(const char* newdir) {
    char* buffer;
    char* p;
    int len = (int)strlen(newdir);

    if (len <= 0) return 0;

    buffer = (char*)malloc(len + 1);
    if (buffer == NULL) {
        printf("内存申请失败\n");
        return UNZ_INTERNALERROR;
    }
    strcpy(buffer, newdir);

    if (buffer[len - 1] == '/') {
        buffer[len - 1] = '\0';
    }
    if (mkdir(buffer, 0775) == 0) {
        free(buffer);
        return 1;
    }

    p = buffer + 1;
    while (1) {
        char hold;

        while (*p && *p != '\\' && *p != '/') p++;
        hold = *p;
        *p = 0;
        if ((mkdir(buffer, 0775) == -1) && (errno == ENOENT)) {
            printf("couldn't create directory %s\n", buffer);
            free(buffer);
            return 0;
        }
        if (hold == 0) break;
        *p++ = hold;
    }
    free(buffer);
    return 1;
}

int getUnzipFile(unzFile uf, const char *unZipDir) {
    const char* password = NULL;
    char filename_inzip[256];
    char filename_temp[256];
    char* filename_withoutpath;
    char* p;
    int err = UNZ_OK;
    FILE* fout = NULL;
    void* buf;
    uInt size_buf;

    unz_file_info64 file_info;
    uLong ratio = 0;
    err = unzGetCurrentFileInfo64(uf, &file_info, filename_temp,
                                  sizeof(filename_temp), NULL, 0, NULL, 0);

    sprintf(filename_inzip, "%s/%s", unZipDir, filename_temp);
    printf("filename_inzip is %s\n", filename_inzip);
    if (err != UNZ_OK) {
        printf("error %d with zipfile in unzGetCurrentFileInfo\n", err);
        return err;
    }

    size_buf = 8196;
    buf = (void*)malloc(size_buf);
    if (buf == NULL) {
        printf("Error allocating memory\n");
        return UNZ_INTERNALERROR;
    }

    p = filename_withoutpath = filename_inzip;
    while ((*p) != '\0') {
        if (((*p) == '/') || ((*p) == '\\')) 
            filename_withoutpath = p + 1;
        p++;
    }

    if ((*filename_withoutpath) == '\0') {
        printf("创建文件夹: %s\n", filename_inzip);
        mkdir(filename_inzip, 0775);
    } else {
        const char* write_filename;

        write_filename = filename_inzip;

        err = unzOpenCurrentFilePassword(uf, password);
        if (err != UNZ_OK) {
            printf("error %d with zipfile in unzOpenCurrentFilePassword\n",
                   err);
        }

        if (err == UNZ_OK) {
            fout = fopen64(write_filename, "wb");
            if ((fout == NULL) && (filename_withoutpath != (char*)filename_inzip)) {
                char c = *(filename_withoutpath - 1);
                *(filename_withoutpath - 1) = '\0';
                makedir(write_filename);
                *(filename_withoutpath - 1) = c;
                fout = fopen64(write_filename, "wb");
            }

            if (fout == NULL) {
                printf("打开文件%s失败\n", write_filename);
            }
        }

        if (fout != NULL) {
            // printf(" extracting: %s\n", write_filename);

            do {
                err = unzReadCurrentFile(uf, buf, size_buf);
                if (err < 0) {
                    printf("error %d with zipfile in unzReadCurrentFile\n",
                           err);
                    break;
                }
                if (err > 0)
                    if (fwrite(buf, err, 1, fout) != 1) {
                        printf("error in writing extracted file\n");
                        err = UNZ_ERRNO;
                        break;
                    }
            } while (err > 0);
            if (fout) fclose(fout);
        }

        if (err == UNZ_OK) {
            err = unzCloseCurrentFile(uf);
            if (err != UNZ_OK) {
                printf("error %d with zipfile in unzCloseCurrentFile\n", err);
            }
        } else
            unzCloseCurrentFile(uf); /* don't lose the error */
    }

    free(buf);
    return err;
}

int MiniUnZip(const char *zipDir, const char *unZipDir) {
    int ret = UNZ_OK;
    unz_global_info64 global_info;
    // 1.打开压缩包
    unzFile uf = unzOpen64(zipDir);
    uLong i;
    // 2.获取压缩包全局信息
    ret = unzGetGlobalInfo64(uf, &global_info);
    if (ret != UNZ_OK) {
        printf("压缩包打开失败\n");
        return ret;
    }
    printf("正在打开压缩包%s\n", zipDir);
     mkdir(unZipDir, 0775);
    for (i = 0; i < global_info.number_entry; ++i) {
        printf("%ld ", i);
        ret = getUnzipFile(uf, unZipDir);
        if (ret != UNZ_OK) break;

        if ((i + 1) < global_info.number_entry) {
            ret = unzGoToNextFile(uf);
            if (ret != UNZ_OK) {
                printf("unzGoToNextFile出错\n");
                break;
            }
        }
    }
}

int main() {
    const char* zipDir = "/data/压缩包/60.zip";
    const char* unZipDir = "/data/60";
    printf("%s\n", unZipDir);
    MiniUnZip(zipDir, unZipDir);
}