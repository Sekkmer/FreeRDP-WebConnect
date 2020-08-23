#ifndef LIBWSGATE_HPP
#define LIBWSGATE_HPP

#include <cstddef>
#include "lib_wshandler.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void* wsgate_ws_create(f_send_text st, f_send_binary sb);
void wsgate_ws_free(void* ws);

void* wsgate_create(void* ws);
void wsgate_free(void* handler);

bool wsgate_connect(void* handler, const char* host, const char* pcb, const char* user, const char* domain, const char* pass, const void* params);
bool wsgate_disconnect(void* handler);
void wsgate_ws_message(void* handler, const char* data, size_t length);

#ifdef __cplusplus
}
#endif

#endif // LIBWSGATE_HPP