package strategy;


public class Sum implements Operator {
	

	public String symbol()
	{
		return "+";
	}

	public double cumulativeValue(double acc, double value)
	{
		return acc + value;
	}

	public double initialValue() {
		return 0;
	}
}
