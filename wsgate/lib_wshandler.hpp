#ifndef LIBWSGATE_WSHANDLER_HPP
#define LIBWSGATE_WSHANDLER_HPP

extern "C" typedef void(*f_send_text)(const char* str);
extern "C" typedef void(*f_send_binary)(const unsigned char* data, size_t len);

namespace libwsgate {

class wshandler {
public:
    wshandler(f_send_text st, f_send_binary sb);
    void send_text(const char* str) const;
    void send_binary(const unsigned char* data, size_t len) const;
    template<typename T>
    void send_binary_t(const T& data) {
        send_binary(reinterpret_cast<const unsigned char*>(&data), sizeof(T));
    }
private:
    f_send_text m_st;
    f_send_binary m_sb;
};

} // namespace libwsgate 

#endif // LIBWSGATE_WSHANDLER_HPP
