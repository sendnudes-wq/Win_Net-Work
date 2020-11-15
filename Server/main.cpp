#include <iostream>
#include "../include/SocketClient.h"
#include "../include/SocketServer.h"

using namespace std;

bool good=true;

void messageReceived(messageStruct *s)
{
    cout << "client: " << s->message << endl;
}

void errorOccurred(errorStruct *e)
{
    cout << e->code << " : " << e->message << endl;
    good=false;
}

int main()
{
    SocketServer server(55555);
    SocketClient client(server.accept());
    client.setErrorCallback(errorOccurred);
    client.setMessageCallback(messageReceived);

    while(good){};

    client.close();
    server.close();
}
