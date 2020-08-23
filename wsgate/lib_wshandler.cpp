#include <cstddef>

#include "lib_wshandler.hpp"

namespace libwsgate {

wshandler::wshandler(f_send_text st, f_send_binary sb) :
    m_st(st), m_sb(sb) {}

void wshandler::send_text(const char* str) const {
    if (m_st) m_st(str);
}

void wshandler::send_binary(const unsigned char* data, size_t len) const {
    if (m_sb) m_sb(data, len);
}

} // namespace libwsgate 