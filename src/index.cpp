#include <napi.h>
#include <string>
#include "macros.h"

// --- //
Napi::String lookUp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = up();

    return Napi::String::New(env, result);
}

Napi::String lookDown(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = down();

    return Napi::String::New(env, result);
}

Napi::String lookLeft(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = left();

    return Napi::String::New(env, result);
}

Napi::String lookRight(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = right();

    return Napi::String::New(env, result);
}

Napi::String shootAt(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = shoot();

    return Napi::String::New(env, result);
}

Napi::String sprayDown(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = spray();

    return Napi::String::New(env, result);
}

Napi::String stopMovement(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = stop();

    return Napi::String::New(env, result);
}

Napi::String jumpUp(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = jump();

    return Napi::String::New(env, result);
}

Napi::String goForward(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string result = go();

    return Napi::String::New(env, result);
}
// --- //

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(
        Napi::String::New(env, "lookUp"), 
        Napi::Function::New(env, lookUp)   
    );

    exports.Set(
        Napi::String::New(env, "lookDown"), 
        Napi::Function::New(env, lookDown)   
    );

    exports.Set(
        Napi::String::New(env, "lookLeft"), 
        Napi::Function::New(env, lookLeft)   
    );

    exports.Set(
        Napi::String::New(env, "lookRight"), 
        Napi::Function::New(env, lookRight)   
    );

    exports.Set(
        Napi::String::New(env, "shootAt"), 
        Napi::Function::New(env, shootAt)   
    );

    exports.Set(
        Napi::String::New(env, "sprayDown"), 
        Napi::Function::New(env, sprayDown)   
    );
    
    exports.Set(
        Napi::String::New(env, "stopMovement"), 
        Napi::Function::New(env, stopMovement)   
    );

    exports.Set(
        Napi::String::New(env, "jumpUp"), 
        Napi::Function::New(env, jumpUp)   
    );

    exports.Set(
        Napi::String::New(env, "goForward"), 
        Napi::Function::New(env, goForward)   
    );

    return exports;
}

NODE_API_MODULE(macro, Init)