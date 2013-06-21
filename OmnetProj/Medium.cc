#include "Medium.h"

Define_Module(Medium);

void Medium::initialize() {
    srand(time(NULL));
    buildAdjacency();		// build the adjacency matrix A(i,j)
    buildFlow();			// build flow matrix vector X(f,i,j)
    buildWeightVector();    // calculate W(i)
    FFVSA();
    ctr = NUMOFFLOWS;		//**** have to check it ****
}

void Medium::buildAdjacency() {
    int i, j;
    for (i = 0; i < NETSIZE; i++) {
        for (j = 0; j < NETSIZE; j++) {
            AdjacencyMatrix[i][j] = 0;
        }
    }
    AdjacencyMatrix[0][1] = 1;
    AdjacencyMatrix[0][2] = 1;
    AdjacencyMatrix[1][0] = 1;
    AdjacencyMatrix[1][3] = 1;
    AdjacencyMatrix[1][4] = 1;
    AdjacencyMatrix[2][0] = 1;
    AdjacencyMatrix[2][4] = 1;
    AdjacencyMatrix[2][5] = 1;
    AdjacencyMatrix[2][6] = 1;
    AdjacencyMatrix[3][1] = 1;
    AdjacencyMatrix[3][4] = 1;
    AdjacencyMatrix[3][7] = 1;
    AdjacencyMatrix[3][8] = 1;
    AdjacencyMatrix[4][1] = 1;
    AdjacencyMatrix[4][2] = 1;
    AdjacencyMatrix[4][3] = 1;
    AdjacencyMatrix[4][5] = 1;
    AdjacencyMatrix[4][8] = 1;
    AdjacencyMatrix[4][9] = 1;
    AdjacencyMatrix[5][2] = 1;
    AdjacencyMatrix[5][4] = 1;
    AdjacencyMatrix[5][9] = 1;
    AdjacencyMatrix[5][10] = 1;
    AdjacencyMatrix[5][11] = 1;
    AdjacencyMatrix[6][2] = 1;
    AdjacencyMatrix[6][11] = 1;
    AdjacencyMatrix[7][3] = 1;
    AdjacencyMatrix[7][8] = 1;
    AdjacencyMatrix[8][3] = 1;
    AdjacencyMatrix[8][4] = 1;
    AdjacencyMatrix[8][7] = 1;
    AdjacencyMatrix[8][9] = 1;
    AdjacencyMatrix[8][12] = 1;
    AdjacencyMatrix[9][4] = 1;
    AdjacencyMatrix[9][5] = 1;
    AdjacencyMatrix[9][8] = 1;
    AdjacencyMatrix[9][10] = 1;
    AdjacencyMatrix[9][12] = 1;
    AdjacencyMatrix[9][13] = 1;
    AdjacencyMatrix[9][14] = 1;
    AdjacencyMatrix[10][5] = 1;
    AdjacencyMatrix[10][9] = 1;
    AdjacencyMatrix[10][11] = 1;
    AdjacencyMatrix[10][14] = 1;
    AdjacencyMatrix[11][5] = 1;
    AdjacencyMatrix[11][6] = 1;
    AdjacencyMatrix[11][10] = 1;
    AdjacencyMatrix[11][14] = 1;
    AdjacencyMatrix[12][8] = 1;
    AdjacencyMatrix[12][9] = 1;
    AdjacencyMatrix[12][13] = 1;
    AdjacencyMatrix[13][9] = 1;
    AdjacencyMatrix[13][12] = 1;
    AdjacencyMatrix[13][14] = 1;
    AdjacencyMatrix[14][9] = 1;
    AdjacencyMatrix[14][10] = 1;
    AdjacencyMatrix[14][11] = 1;
    AdjacencyMatrix[14][13] = 1;
}

void Medium::buildFlow() {
    int i, j, k;
    for (i = 0; i < NUMOFFLOWS; i++) {
        for (j = 0; j < NETSIZE; j++) {
            for (k = 0; k < NETSIZE; k++) {
                FlowTable[i][j][k] = 0;
            }
        }
    }
    buildRandomPaths();
}

void Medium::buildRandomPaths() {
    int flowNum;
    for (flowNum = 0; flowNum < NUMOFFLOWS; flowNum++) { // for every flow
        int nodeIndex, src, dst, tmp, pathIndex = 0;
        int usedNode[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        src = rand() % NETSIZE;   // generate random source
        do {
            dst = rand() % NETSIZE; // generate random destination that is different than the source
        } while (src == dst);
        usedNode[src] = 1;
        usedNode[dst] = 1;
        PathVectors[flowNum][pathIndex] = src;
        tmp = src;
        while (tmp != dst) { // while the destination hasn't been reached
            pathIndex++;
            if (AdjacencyMatrix[tmp][dst] == 1) { // if source and destination are neighbors
                FlowTable[flowNum][tmp][dst] = 1;
                PathVectors[flowNum][pathIndex] = dst;
                if (pathIndex < 14) {
                    PathVectors[flowNum][pathIndex + 1] = -1;
                }
                tmp = dst;
            } else { // if source and destination aren't neighbors
                do {
                    nodeIndex = (nodeIndex + 1) % NETSIZE; // we tried using the rand() function in this line, but the simulation tends to get stuck.
                } while ((usedNode[nodeIndex] == 1) || (nodeIndex == tmp)
                        || (AdjacencyMatrix[tmp][nodeIndex] == 0)); // continue till a valid next hop is found
                usedNode[nodeIndex] = 1;
                FlowTable[flowNum][tmp][nodeIndex] = 1;
                PathVectors[flowNum][pathIndex] = nodeIndex;
                tmp = nodeIndex;
            }
        }
    }
}

void Medium::buildWeightVector() {
    for (int i = 0; i < NETSIZE; i++) {
        WeightVector[i] = 0;
    }

    for (int i = 0; i < NETSIZE; i++) //running over every node in the whole flow
            {
        for (int f = 0; f < NUMOFFLOWS; f++) //every flow
                {
            for (int j = 0; j < NETSIZE; j++) {
                WeightVector[i] += FlowTable[f][i][j]; //sum up the weights
            }
        }
    }
}

void Medium::sortNodesByWeight() {
    int tempWeight[NETSIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int i, j, maxWeight = -1, maxIndex = -1;
    for (i = 0; i < NETSIZE; i++) {
        tempWeight[i] = WeightVector[i];
    }
    for (i = 0; i < NETSIZE; i++) {
        for (j = 0; j < NETSIZE; j++) {
            if (tempWeight[j] > maxWeight) {
                maxIndex = j;
                maxWeight = tempWeight[j];
            }
            SortedNodes[i] = maxIndex;
            tempWeight[maxIndex] = -1;
            maxWeight = -1;
        }
    }
}

int Medium::multiplyVectors(int a[], int b[]) {
    int i, sum = 0;
    for (i = 0; i < NETSIZE; i++) {
        sum += (a[i] * b[i]);
    }
    return sum;
}

void Medium::Dijkstra() {

}

void Medium::FFVSA() {
    int i, slot = 0;
    do {
        int S[NETSIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // initialize new slot
        sortNodesByWeight();    // sort the nodes by descending weight
        for (i = 0; i < NETSIZE; i++) {  // initialize collision vector
            CollisionVector[i] = 0;
        }
        for (i = 0; i < NETSIZE; i++) {  // start filing up the slot
            if (multiplyVectors(AdjacencyMatrix[i], CollisionVector) == 0) { // if the current node doesn't collide with its neighbors
                S[i] = 1;   // update the slot
                for (int j=0; j<NETSIZE; j++){
                    CollisionVector[j] += AdjacencyMatrix[i][j];    // update collision vector
                }
                WeightVector[i]--;  // update weights
            }
        }
        slot++;
    } while (WeightVector[SortedNodes[0]] > 0); // while there's at least one node with a weight larger than zero
}

void Medium::handleMessage(cMessage *msg)
{
	ctr--;
	if (ctr!=0)
	{
		EV << "Sending initial message\n";
		cMessage *msg = new cMessage("You can send Message");

	}
	else
	{
		EV << "There are no flows to send\n";
	}

}


MsgToSend *Medium::generateMessage(int Source,int Dest)
{
	// Produce source and destination addresses.

	char msgname[20];

	// Create message object and set source and destination field.
	MsgToSend *msg = new MsgToSend(msgname);

	return msg;
}
