/*****************************************************************************/
/* File : neuron.h															 */
/* Author : Raesangur														 */
/*          https://www.github.com/Raesangur/								 */
/*****************************************************************************/
#ifndef NEURON_H
#define NEURON_H
/*****************************************************************************/
/* File includes */
#include "globaldef.h"


/*****************************************************************************/
/* Typedefs */
typedef struct
{
	string_t* name;

	double bias;
	double input;
	double output;

	linkedList_t* inputConnections;
	linkedList_t* outputConnections;
}neuron_t;


/*****************************************************************************/
/* Public functions declarations */
neuron_t* neuronConstructor(const char* name, double bias);
void neuronDestructor(neuron_t** n);

double neuron_calculateOutput(neuron_t* n);


/*****************************************************************************/
/* Inline functions definitions */
static inline void neuron_setInput(neuron_t* n, double input)
{
	n->input = input;
}



#endif	/* NEURON_H*/
/* End of file */