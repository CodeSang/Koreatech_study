void _10162() {
	int i;
	int inputNum, temp;
	int divider[3] = { 300, 60, 10 };
	int result[3] = { 0 };

	scanf("%d", &inputNum);
	temp = inputNum;
	for (i = 0; i < 3; i++) {
		result[i] = temp / divider[i];
		temp = temp - result[i] * divider[i];
	}
	if (temp) {
		printf("-1");
	}
	else {
		for (i = 0; i < 3; i++) {
			printf("%d ", result[i]);
		}
	}
}