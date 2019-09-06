/*****************************************************************************/
/* File includes */
#include "neuralNetwork.h"
#include "connection.h"


/*****************************************************************************/
/* Public functions definitions */
neuralNetwork_t* neuralNetworkConstructor(void)
{
	neuralNetwork_t* nn = malloc(sizeof(neuralNetwork_t));
	if (nn == NULL)
	{
		return NULL;
	}


	nn->lines_in_layer = createLinkedList(sizeof(uint16_t));
	nn->layers = createLinkedList(sizeof(linkedList_t*));

	uint16_t initialLines = 0;
	createLink(nn->lines_in_layer, &initialLines);

	linkedList_t* firstLayer = createLinkedList(sizeof(neuron_t*));
	createLink(nn->layers, &firstLayer);

	nn->layersCount = 1;

	return nn;
}

void neuralNetworkDestructor(neuralNetwork_t** nn)
{
	link_t* currentLayer = getFirstElement((*nn)->layers);
	uint16_t i;
	uint16_t j;
	for (i = 1; i <= (*nn)->layersCount; i++)
	{
		uint16_t numElements = neuralNetwork_getElementCountInLayer(*nn, i);
		linkedList_t* currentLayerLL = *(linkedList_t**)getData(currentLayer);

		for (j = 0; j < numElements; j++)
		{
			neuron_t* currentNeuron = *(neuron_t**)getData(searchByNumber(currentLayerLL, j));

			neuronDestructor(&currentNeuron);
		}
		currentLayer = getNextElement(currentLayer);
	}

	deleteLinkedList((*nn)->lines_in_layer);
	deleteLinkedList((*nn)->layers);
}

void neuralNetwork_AddNeuron(neuralNetwork_t* nn, neuron_t* n, uint16_t layer)
{
	if (layer >= (nn->layersCount + 1))
	{
		return;
	}
	else if (layer == (nn->layersCount + 1))
	{
		linkedList_t* newLayer = createLinkedList(sizeof(neuron_t));
		createLink(nn->layers, &newLayer);

		nn->layersCount++;
	}
	/* No 'else' statement because the following is done by all code paths */

	linkedList_t* layerLL = *(linkedList_t**)(getData(searchByNumber(nn->layers, (layer - 1))));

	createLink(layerLL, &n);

	neuralNetwork_incrementElementCountInLayer(nn, layer);
}
