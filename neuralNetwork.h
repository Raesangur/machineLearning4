/*****************************************************************************/
/* File : connection.h														 */
/* Author : Raesangur														 */
/*          https://www.github.com/Raesangur/								 */
/*****************************************************************************/
#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
/*****************************************************************************/
/* File includes */
#include "globaldef.h"
#include "neuron.h"


/*****************************************************************************/
/* Typedefs */
typedef struct
{
	linkedList_t* layers;
	linkedList_t* lines_in_layer;
	uint16_t layersCount;
}neuralNetwork_t;


/*****************************************************************************/
/* Public functions declarations */
neuralNetwork_t* neuralNetworkConstructor(void);
void neuralNetworkDestructor(neuralNetwork_t** nn);


void neuralNetwork_AddNeuron(neuralNetwork_t* nn, neuron_t* n, uint16_t layer);


/*****************************************************************************/
/* Inline functions definitions */
static inline uint16_t neuralNetwork_getElementCountInLayer(neuralNetwork_t* nn, uint16_t layer)
{
	return (uint16_t)getData(searchByNumber(nn->lines_in_layer, (layer - 1)));
}

static inline uint16_t neuralNetwork_incrementElementCountInLayer(neuralNetwork_t* nn, uint16_t layer)
{
	uint16_t temp = neuralNetwork_getElementCountInLayer(nn, layer);

	temp++;

	changeData(nn->lines_in_layer, searchByNumber(nn->lines_in_layer, (layer - 1)), &temp);

	return temp;
}




#endif	/* NEURALNETWORK_H */
/* End of file */