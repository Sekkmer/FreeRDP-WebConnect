

#include "libwsgate.hpp"
#include "lib_wshandler.hpp"

#include "rdpcommon.hpp"
#include "RDP.hpp"

using namespace wsgate;
using libwsgate::wshandler;

extern "C" {

void* wsgate_ws_create(f_send_text st, f_send_binary sb) {
    return reinterpret_cast<void*>(new wshandler(st, sb));
}

void wsgate_ws_free(void* ws) {
    delete reinterpret_cast<wshandler*>(ws);
}

void* wsgate_create(void* ws) {
    return reinterpret_cast<void*>(new RDP(reinterpret_cast<wshandler*>(ws)));
}

void wsgate_free(void* handler) {
    delete reinterpret_cast<RDP*>(handler);
}

bool wsgate_connect(void* handler, const char* host, const char* pcb, const char* user, const char* domain, const char* pass, const void* params) {
    return reinterpret_cast<RDP*>(handler)->Connect(host, pcb, user, domain, pass, *reinterpret_cast<const WsRdpParams*>(params));
} 

bool wsgate_disconnect(void* handler) {
    return reinterpret_cast<RDP*>(handler)->Disconnect();
} 

void wsgate_ws_message(void* handler, const char* data, size_t length) {
    return reinterpret_cast<RDP*>(handler)->OnWsMessage(data, length);
} 

} // extern "C"