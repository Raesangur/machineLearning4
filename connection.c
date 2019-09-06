/*****************************************************************************/
/* File includes */
#include "connection.h"


/*****************************************************************************/
/* Public functions definitions */
connection_t* connectionConstructor(neuron_t* input, neuron_t* output, double weight)
{
	connection_t* c = malloc(sizeof(connection_t));

	c->inputNeuron = input;
	c->outputNeuron = output;
	c->weight = weight;


	createLink(c->inputNeuron->inputConnections, &c);
	createLink(c->outputNeuron->outputConnections, &c);


	return c;
}
void connectionDestructor(connection_t** c)
{
	deleteLink((*c)->inputNeuron->inputConnections, searchByData((*c)->inputNeuron->inputConnections, (*c)));
	deleteLink((*c)->outputNeuron->outputConnections, searchByData((*c)->outputNeuron->outputConnections, (*c)));

	free(*c);
	*c = NULL;
}