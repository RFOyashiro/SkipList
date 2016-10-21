package formula;

import java.util.ArrayList;

public class ExtensionFormulaFactory implements AbstractFormulaFactory{

	public Formula createConstant(double value) {
		return new Constant(value);
	}

	public Formula createProduct(ArrayList<Formula> formulas) {
		return new extension.Product(formulas);
	}

	public Formula createSum(ArrayList<Formula> formulas) {
		return new extension.Sum(formulas);
	}

}
