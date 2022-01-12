#include <napi.h>
#include <string>
#include "macros.h"

// --- //
Napi::String goForward(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = go();

    return Napi::String::New(env, result);
}

Napi::String jumpUp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = jump();

    return Napi::String::New(env, result);
}

Napi::String stopMovement(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = stop();

    return Napi::String::New(env, result);
}
// --- //

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(
        Napi::String::New(env, "goForward"), 
        Napi::Function::New(env, goForward)   
    );

    exports.Set(
        Napi::String::New(env, "jumpUp"), 
        Napi::Function::New(env, jumpUp)   
    );

    exports.Set(
        Napi::String::New(env, "stopMovement"), 
        Napi::Function::New(env, stopMovement)   
    );

    return exports;
}

NODE_API_MODULE(macro, Init)