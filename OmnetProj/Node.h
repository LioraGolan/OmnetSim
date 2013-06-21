
#include <omnetpp.h>
#include <cgate.h>


/**
 * Implements the Txc simple module. See the NED file for more information.
 */
class Node : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};
