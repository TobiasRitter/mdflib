#include "ImportMdf4.h"
#include <emscripten/emscripten.h>

EMSCRIPTEN_KEEPALIVE
int get_measurefile_basicinfo(char* file_path, int* versionId, int* cgCount){
    int ret = 0;
    CMdf4FileImport *pImport = new CMdf4FileImport;
    ret = pImport->ImportFile(file_path, versionId, cgCount);
    pImport->ReleaseFile();
    delete pImport;
    return ret;
}

EMSCRIPTEN_KEEPALIVE
int get_measurefile_cginfo(char* file_path, int cgIndex, int* chCount, int *recCount){
    int ret = 0,vId = 0;
    CMdf4FileImport *pImport = new CMdf4FileImport;
    pImport->ImportFile(file_path, &vId, &count);
    ret = pImport->GetMetaInfo(cgIndex,chCount,recCount);
    pImport->ReleaseFile();
    delete pImport;
    return ret;
}
