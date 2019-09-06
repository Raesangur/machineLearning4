/*****************************************************************************/
/* File includes */
#include <math.h>
#include "neuron.h"
#include "connection.h"


/*****************************************************************************/
/* Private functions declarations */
static double activationFunction(double x);


/*****************************************************************************/
/* Public functions definitions */
neuron_t* neuronConstructor(const char* name, double bias)
{
	neuron_t* n = malloc(sizeof(neuron_t));
	if (n == NULL)
	{
		return NULL;
	}

	n->name = stringConstructor(name);
	n->bias = bias;

	n->inputConnections = createLinkedList(sizeof(connection_t*));
	n->outputConnections = createLinkedList(sizeof(connection_t*));

	return n;
}
void neuronDestructor(neuron_t** n)
{
	if (*n == NULL)
	{
		return;							/* Neuron was already destroyed! */
	}

	stringDestructor(&(*n)->name);

	link_t* currentConnection = getFirstElement((*n)->inputConnections);
	while (currentConnection != NULL)
	{
		connection_t* currentConn = (connection_t*)getData(currentConnection);
		if (currentConn->inputNeuron == NULL)
		{
			connectionDestructor(&currentConn);
		}
		else
		{
			currentConn->outputNeuron = NULL;
		}

		currentConnection = getNextElement(currentConnection);
	}
	currentConnection = getFirstElement((*n)->outputConnections);
	while (currentConnection != NULL)
	{
		connection_t* currentConn = (connection_t*)getData(currentConnection);
		if (currentConn->outputNeuron == NULL)
		{
			connectionDestructor(&currentConn);
		}
		else
		{
			currentConn->inputNeuron = NULL;
		}

		currentConnection = getNextElement(currentConnection);
	}

	deleteLinkedList((*n)->inputConnections);
	deleteLinkedList((*n)->outputConnections);

	free(*n);
	*n = NULL;
}


double neuron_calculateOutput(neuron_t* n)
{
	if (getFirstElement(n->inputConnections) != NULL)
	{
		connection_t* conn;
		link_t* currentConnection = getFirstElement(n->inputConnections);
		while (currentConnection != NULL)
		{
			conn = ((connection_t*)getData(currentConnection));
			n->input += conn->inputNeuron->output * conn->weight;
			currentConnection = getNextElement(currentConnection);
		}
		n->output = activationFunction(n->input) + n->bias;
		return n->output;
	}
	else
	{
		return n->input + n->bias;
	}
}


/*****************************************************************************/
/* Private functions definitions */
static double activationFunction(double x)
{
	/* Sigmoid function: */
	/* _____1_____       */
	/*   1 + e^x	     */
	x = exp(x);							/* value = e^x */

	x = 1 / 1 + x;

	return x;
}