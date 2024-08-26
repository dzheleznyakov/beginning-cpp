// Defining a destructor and the copy constructor
#include "Message.h"

void print(Message message)
{
    message.show();
}

int main()
{
    Message beware{"Careful"};
    Message warning;

    warning = beware;
    std::cout << "After assignment beware is:\n";
    beware.show();
    std::cout << "After assignment warning is:\n";
    warning.show();
}
