#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>

class Message
{
private:
    std::string *ptext;

public:
    void show() const
    {
        std::cout << "Message is: " << *ptext << std::endl;
    }

    Message(const char *text = "No message")
    {
        ptext = new std::string{text};
    }

    ~Message()
    {
        delete ptext;
    }
};

#endif
