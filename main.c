#include <stdio.h>

#include "ELM.h"


int main() {

#ifdef DS_TEST
	//run the appropriate test using the configuration from elm.h
	RunTest();
	return 0;
#endif

#ifdef SVM

#ifdef REGRESSION
	float X[] = { -0.8322759271291997, 0.3636749003861144, -0.17494119397906097, 0.07352810470119044, 0.1553397535369414, -0.06761655411472672, 0.0855392275355406, 0.04066219161654173, 0.11185559235083005, -0.08477616078227904, -0.15167252286243968, 0.07126487390801126, -0.03208499724042752, -0.02247560477462619, 0.03957488251247664, -0.002522386112650082, -0.014566087847607604, -0.04683558153996702, 0.04913937521052978, 0.029633163164301403, -0.017169611237453017, -0.041526437737699026, 0.00774344884336123, 0.0014122109847697463, 0.007470577064585154 };
	float* X_t = preprocess(X);
	svm_regression(X_t);
#else
	//float X[] = { 1, 2, 3, 4, 5, 6 };
	//float Y[] = { -0.20647835151039698, -0.4513772469140586, -0.22887836700722633, -0.10757521477907099 };
	float* X_t = preprocess(X);
	svm_classification(X_t);
#endif
#endif


#ifdef DT

#ifdef REGRESSION
	float X[] = { -0.8322759271291997, 0.3636749003861144, -0.17494119397906097, 0.07352810470119044, 0.1553397535369414, -0.06761655411472672, 0.0855392275355406, 0.04066219161654173, 0.11185559235083005, -0.08477616078227904, -0.15167252286243968, 0.07126487390801126, -0.03208499724042752, -0.02247560477462619, 0.03957488251247664, -0.002522386112650082, -0.014566087847607604, -0.04683558153996702, 0.04913937521052978, 0.029633163164301403, -0.017169611237453017, -0.041526437737699026, 0.00774344884336123, 0.0014122109847697463, 0.007470577064585154 };
	float* X_t = preprocess(X);
	decisionTree_regression(X_t);
#else
	//float X[] = { 41,0,1,130,204,0,0,172,0,1.4,2,0,2 };
	float X[] = { 56,1,1,120,236,0,1,178,0,0.8,2,0,2 };
	//float X[] = { 57,0,1,130,236,0,0,174,0,0,1,1,2 };

	float* X_t = preprocess(X);
	int out = decisionTree_classification(X_t);
	printf("%d", out);

#endif
#endif


#ifdef KNN

#ifdef REGRESSION
	float X[] = { -0.8322759271291997, 0.3636749003861144, -0.17494119397906097, 0.07352810470119044, 0.1553397535369414, -0.06761655411472672, 0.0855392275355406, 0.04066219161654173, 0.11185559235083005, -0.08477616078227904, -0.15167252286243968, 0.07126487390801126, -0.03208499724042752, -0.02247560477462619, 0.03957488251247664, -0.002522386112650082, -0.014566087847607604, -0.04683558153996702, 0.04913937521052978, 0.029633163164301403, -0.017169611237453017, -0.041526437737699026, 0.00774344884336123, 0.0014122109847697463, 0.007470577064585154 };
	float* X_t = preprocess(X);
	knn_regression(X_t);
#else
	float X[] = { -0.01419929665534347, 0.7123654720811174, 0.24148214073025193, 1.0513512053890597, 0.7123654720811174, 0.24148214073025193, 1.0513512053890597, 0.7123654720811174, 0.24148214073025193, 1.0513512053890597 };
	float Y[] = { -0.20647835151039698, -0.4513772469140586, -0.22887836700722633, -0.10757521477907099 };
	float* X_t = preprocess(X);
	knn_classification(X_t);
#endif
#endif


#ifdef TripleES
#include "TripleES_params.h"
	//Holt-Winters model coefficients

	int n_preds = 24; //predictions horizon

	int arrayD[] = { 80115, 79885, 89325, 101930, 121630, 116475, 106495, 102795, 108055, 116125, 131030, 149020, 157590, 150715, 149295, 150100, 144780, 150690, 163840, 166235, 139520, 105895, 96780, 82520, 80125, 75335, 85105, 102080, 125135, 118030, 109225, 102475, 102240, 115840, 130540, 144325, 148970, 149150, 148040, 148810, 149830, 150570, 149440, 150520, 129130, 103815, 92175, 82765, 76315, 75130, 82640, 88795, 118430, 115190, 110940, 98860, 104185, 108665, 126640, 140435, 152470, 146275, 148020, 147735, 145750, 149285, 159725, 161085, 135520, 112945, 100200, 87615, 87835, 88845, 92350, 104465, 115940, 128950, 141385, 144440, 143250, 133190, 131240, 142480, 157375, 152500, 153735, 151195, 150645, 147435, 152525, 146875, 125245, 117925, 96700, 93610, 89060, 89345, 90575, 98290, 112570, 129470, 141405, 152560, 152580, 141170, 147550, 161110, 166335, 166780, 163140, 157305, 159055, 160020, 168345, 169900, 142710, 112955, 97345, 81675, 79510, 78350, 88045, 99790, 123780, 111325, 99440, 97655, 97655, 102565, 119930, 135755, 140120, 141730, 142220, 145360, 145335, 150410, 161520, 153415, 134720, 107065, 95045, 79515, 78335, 74670, 81990, 97950, 119345, 113115, 98880, 94000, 93660, 104185, 119750, 135990, 146455, 139165, 147225, 144935, 151370, 156080, 161385, 165010, 134090, 105585, 92855, 79270, 79980, 78110, 85785, 100010, 123880, 116335, 104290, 101440, 97635, 108265, 121250, 140850, 138555, 140990, 141525, 141590, 140610, 139515, 146215, 142425, 123945, 101360, 88170, 76050, 70335, 72150, 80195, 94945, 121910, 113950, 106495, 97290, 98860, 105635, 114380, 132335, 146630, 141995, 142815, 146020, 152120, 151790, 155665, 155890, 123395, 103080, 95155, 80285 };

	int vlen = sizeof(arrayD) / sizeof(int);

	int* finalRes = HW_TripleExpoSmoothing(arrayD, vlen, ALPHA, BETA, GAMMA, SEASON_LENGTH, n_preds, SCALING_FACTOR);

	for (int i = 0; i < n_preds; i++)
	{
		printf("Triple Exponential Smoothing for season length=%d and n_preds=%d, prediction nr. %d has value: %d\n", SEASON_LENGTH, n_preds, i + 1, finalRes[i]);
	}

	free(finalRes);

#endif


#ifdef RF

	
#endif 

}
