// Warning this example will crash!
// Defining a destructor
#include "Message.h"

void print(Message message)
{
    message.show();
}

int main()
{
    Message beware{"Careful"};
    print(beware);
    std::cout << "After print() call, output the beware directly:\n"
              << std::endl;
    beware.show();
}
