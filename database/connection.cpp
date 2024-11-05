#include "database/connection.h"

QX_REGISTER_CPP_AMS(Connection)

namespace qx {
    template <> void register_class(QxClass<Connection> & t)
    {
        t.setName("connection");
        // 注册 Connection::ID <=> 数据库中的主键
        t.id(&Connection::ID, "id");

        // 注册 Connection::e_ID 属性，使用的 key 是 name，version 是 1。
        t.data(&Connection::e_ID, "e_id", 1);

        // 注册 Connection::s_ID 属性，使用的 key 是 age。
        t.data(&Connection::s_ID, "s_id");

        t.data(&Connection::status, "status");
        t.data(&Connection::PS, "ps");
    }
}
