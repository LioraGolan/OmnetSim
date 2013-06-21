package project;

import ned.IdealChannel;
import project.Node;


simple Medium{
    parameters:

        @display("i=block/network2");
    gates:
        inout port[];
}

simple Node
{
    parameters:
        bool sendInitialMessage = default(false);
        int id = default(0);
    gates:
        inout port[];
        inout clock;        
}

//
// TODO auto-generated type
//
network Project
{
    @display("bgb=710,600;bgl=2");
    submodules:
        medium: Medium {
            @display("p=627,128");
        }
        node1: Node {
            @display("p=52,42");
        }
        node2: Node {
            @display("p=45,204");
        }
        node3: Node {
            @display("p=273,41");
        }
        node4: Node {
            @display("p=43,350");
        }
        node5: Node {
            @display("p=193,213");
        }
        node6: Node {
            @display("p=336,213");
        }
        node7: Node {
            @display("p=496,42");
        }
        node8: Node {
            @display("p=43,541");
        }
        node9: Node {
            @display("p=195,361");
        }
        node10: Node {
            @display("p=338,363");
        }
        node11: Node {
            @display("p=460,349");
        }
        node12: Node {
            @display("p=496,209");
        }
        node13: Node {
            @display("p=203,544");
        }
        node14: Node {
            @display("p=349,543");
        }
        node15: Node {

            @display("p=563,480");
        }
    connections:
        node1.port++ <--> {  delay = 100ms; } <--> node2.port++;
        node2.port++ <--> node4.port++;
        node1.port++ <--> node3.port++;
        node3.port++ <--> node7.port++;
        node7.port++ <--> node12.port++;
        node2.port++ <--> node5.port++;
        node5.port++ <--> node6.port++;
        node6.port++ <--> node12.port++;
        node3.port++ <--> node5.port++;
        node3.port++ <--> node6.port++;
        node5.port++ <--> node4.port++;
        node4.port++ <--> node9.port++;
        node5.port++ <--> node9.port++;
        node5.port++ <--> node10.port++;
        node9.port++ <--> node10.port++;
        node6.port++ <--> node10.port++;
        node10.port++ <--> node11.port++;
        node6.port++ <--> node11.port++;
        node12.port++ <--> node11.port++;
        node12.port++ <--> node15.port++;
        node15.port++ <--> node14.port++;
        node11.port++ <--> node15.port++;
        node10.port++ <--> node15.port++;
        node10.port++ <--> node14.port++;
        node10.port++ <--> node13.port++;
        node9.port++ <--> node13.port++;
        node9.port++ <--> node8.port++;
        node4.port++ <--> node8.port++;
        node13.port++ <--> node14.port++;

        medium.port++ <--> IdealChannel <--> node1.clock;
        medium.port++ <--> IdealChannel <--> node2.clock;
        medium.port++ <--> IdealChannel <--> node3.clock;
        medium.port++ <--> IdealChannel <--> node4.clock;
        medium.port++ <--> IdealChannel <--> node5.clock;
        medium.port++ <--> IdealChannel <--> node6.clock;
        medium.port++ <--> IdealChannel <--> node7.clock;
        medium.port++ <--> IdealChannel <--> node8.clock;
        medium.port++ <--> IdealChannel <--> node9.clock;
        medium.port++ <--> IdealChannel <--> node10.clock;
        medium.port++ <--> IdealChannel <--> node11.clock;
        medium.port++ <--> IdealChannel <--> node12.clock;
        medium.port++ <--> IdealChannel <--> node13.clock;
        medium.port++ <--> IdealChannel <--> node14.clock;
        medium.port++ <--> IdealChannel <--> node15.clock;
}
