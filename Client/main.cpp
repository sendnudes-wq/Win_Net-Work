#include <iostream>
#include <fstream>
#include "../include/SocketClient.h"

using namespace std;

void onError(errorStruct *e)
{
    cout << e->message << endl;
}

bool keep(string input)
{
    if (input.compare(0,4,"exit"))
        return true;
    else
        return false;
}

int main()
{
    bool keepalive = true;
    SocketClient client("127.0.0.1",55555); /* Build connection */
    client.setErrorCallback(onError);        /* Define behavior in case of error */
    client.connect();

    string str;
    while(keepalive)
    {
        cout << ">";
        getline(cin, str);
        client.send(str);
        keepalive = keep(str);
    }
    client.close();
}
