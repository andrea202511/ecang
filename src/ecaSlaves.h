#ifndef ECASLAVES_H
#define ECASLAVES_H


class ecaSlaves
{
    public:
        ecaSlaves() {}
        wxString Slave_name;
        int16_t Slave_addr;
        int Slave_incr;
        bool Reg_enable;
        bool Sdo_enable;
        int16_t Regcol;  //registro, valore
        int16_t Sdocol;  //indirizzo.sub, valore
    protected:

    private:
};

WX_DECLARE_OBJARRAY(ecaSlaves,SLVArray);

#endif // ECASLAVES_H
