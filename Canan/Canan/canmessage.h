#ifndef CANMESSAGE_H
#define CANMESSAGE_H

#include <QMainWindow>

class CanMessage
{
public:
    CanMessage();

private:
    uint8_t DLC;
    uint8_t ID[4];
    uint8_t Data[8];
};

#endif // CANMESSAGE_H
