package formula;

import java.util.ArrayList;

public class StrategyFormulaFactory implements AbstractFormulaFactory{

	public Formula createConstant(double value) {
		return new Constant(value);
	}

	public Formula createProduct(ArrayList<Formula> formulas) {
		return new strategy.VariadicOperator(new strategy.Product(), formulas);
	}

	public Formula createSum(ArrayList<Formula> formulas) {
		return new strategy.VariadicOperator(new strategy.Sum(), formulas);
	}

}
