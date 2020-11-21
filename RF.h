#ifdef RF

#ifndef RF_H

#define RF_H

#include "ELM.h"
#include <stdbool.h>


#include "PPParams.h"
#include "RF_params.h"


void randomForest_test_dataset();
float randomForest_regression(float []);
int randomForest_classification(float []);
#endif

#endif //RF

