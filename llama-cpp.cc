#include <clasp/clasp.h> 

void llamaCpp() {
    printf("Hello Llama.cpp\n");
}

PACKAGE_USE("COMMON-LISP")
PACKAGE_NICKNAME("LLAMACPP")
NAMESPACE_PACKAGE_ASSOCIATION(llamacpp,LLAMACPPPkg,"LLAMA-CPP");

namespace llamacpp {
    CL_EXPOSE
    void llama_cpp_startup() {
        printf("------ llama_cpp_start()");
        using namespace clbind;
        package_ sc(LLAMACPPPkg);
        sc.def("llama-cpp", &llamaCpp, "entry point to llama.cpp"_docstring);
    }
}
