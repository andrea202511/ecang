#ifndef ECAPDO_H
#define ECAPDO_H

#include <stdint.h>


class ecaPDO
{
    public:
        ecaPDO() {}
        wxString PDO_name;
        int16_t PDO_offset;
        int16_t PDO_bytes;
        bool out;
        bool enabled;

    protected:

    private:
};

WX_DECLARE_OBJARRAY(ecaPDO,PDOArray);

#endif // ECAPDO_H
