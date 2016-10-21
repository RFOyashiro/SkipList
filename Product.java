package strategy;


public class Product implements Operator{

	public String symbol()
	{
		return "*";
	}
	
	public double initialValue()
	{
		return 1;
	}
	
	public double cumulativeValue(double accumulator, double value)
	{
		return accumulator * value;
	}
}
