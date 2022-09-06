#include "Observation.h"
#include "Facts.h"

int main(int argc, char **argv)
{
    //Create a SordWorld object
    SordWorld* world = sord_world_new();

    //Create a SordModel object
    SordModel* kb = sord_new(world, SORD_SPO, true);

    //Create the filepath to read the differents stream of observations
    //char filepathRead[] = "data/observations.txt";
    
    // Storage of all observations in a LinkedList
    LinkedList* l = readFromFile(argv[1]);

    //Printing of all observations
    //printObs(l);

    //Add many quads (facts) to a model from a LinkedList of observation.
    AddFactsFromLinkedList(l,kb);

    //print the facts
    //printFact(kb);

    //Create the filepath to write the differents facts extracts from a model (sordModel)
    //char filepathWrite[] = "data/facts.ttl";

    //write the facts to a file
    makeFileFacts(argv[2], kb);

    //reads and counts the number of facts contained in a file
    //char factFilePath[20] = "data/facts.ttl";
    readFileOfFacts(argv[2]);

    //Free the LinkedList
    freeLinkedList(l);

    //Free the model
    sord_free(kb);

    //Free the world
    sord_world_free(world);

    return 0;
}