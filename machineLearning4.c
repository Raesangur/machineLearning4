/*****************************************************************************/
/* File includes */
#include <stdio.h>
#include "globaldef.h"


#include "neuron.h"
#include "connection.h"
#include "neuralNetwork.h"


/*****************************************************************************/
/* Public functions definitions */
int main(void)
{
	neuron_t* input = neuronConstructor("Input", 0.0);
	neuron_t* output = neuronConstructor("Output", 1.0);

	connection_t* connect = connectionConstructor(input, output, 0.0);


	printf("%s\n", connect->inputNeuron->name->string);
	printf("%s\n", connect->outputNeuron->name->string);

	printf("%f\n", ((connection_t*)(*(connection_t**)getData(getFirstElement(input->inputConnections))))->outputNeuron->bias);


	neuralNetwork_t* neuralNet = neuralNetworkConstructor();

	neuralNetwork_AddNeuron(neuralNet, input, 1);
	neuralNetwork_AddNeuron(neuralNet, output, 2);



	int test;
	printf("Hello World!");
	scanf("%i", &test);					/* Wait for user input */



	neuralNetworkDestructor(&neuralNet);

	return 0;
}