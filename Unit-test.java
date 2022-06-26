[Fact]
public void Sum_of_two_numbers(){

	//Arrange 
	double first= 0;
	double second= 0;
	var calculator = new Calculator();

	//Act
	double result = calculator.Sum(first, second);

	//Assert 
	Ausert.Equal(0, result);

}

[Fact]
public void Sum_of_two_postitive_Negative_numbers(){

	//Arrange 
	double first= -1000;
	double second= 1000;
	var calculator = new Calculator();

	//Act
	double result = calculator.Sum(first, second);

	//Assert 
	Ausert.Equal(0, result);

}
