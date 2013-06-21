#include "Node.h"

Define_Module(Node);

void Node::initialize() {
    if (par("sendInitialMessage").boolValue()) {
        cMessage *msg = new cMessage("ass");
        send(msg, "port$o", 1);
    }
}

int i=0;

void Node::handleMessage(cMessage *msg) {
     // just send back the message we received
    bool flag = false;
    while (!flag) {
        if (gate("port$o", i)->isConnected()){
            flag = true;
        } else {
            i += 4;
            i = i % 15;
        }
    }
    send(msg, "port$o", i);

    //if we got approval from the medium we send the message to the next node
    if (msg=="You can send Message")
    {
    	EV << "Time to Send message!\n";

    }
}
