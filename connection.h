/*****************************************************************************/
/* File : connection.h														 */
/* Author : Raesangur														 */
/*          https://www.github.com/Raesangur/								 */
/*****************************************************************************/
#ifndef CONNECTION_H
#define CONNECTION_H
/*****************************************************************************/
/* File includes */
#include "globaldef.h"
#include "neuron.h"


/*****************************************************************************/
/* Typedefs */
typedef struct
{
	neuron_t* inputNeuron;
	neuron_t* outputNeuron;

	double weight;
}connection_t;


/*****************************************************************************/
/* Public functions declarations */
connection_t* connectionConstructor(neuron_t* input, neuron_t* output, double weight);
void connectionDestructor(connection_t** c);



#endif	/* CONNECTION_H */à
/* End of file */