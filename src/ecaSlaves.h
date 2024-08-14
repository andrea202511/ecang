#ifndef ECASLAVES_H
#define ECASLAVES_H


class ecaSlaves
{
    public:
        ecaSlaves() {}
        wxString Slave_name;
        int16_t Slave_addr;
        bool enabled;
    protected:

    private:
};

WX_DECLARE_OBJARRAY(ecaSlaves,SLVArray);

#endif // ECASLAVES_H
