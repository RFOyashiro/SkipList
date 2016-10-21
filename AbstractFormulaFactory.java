package formula;

import java.util.ArrayList;

public abstract interface AbstractFormulaFactory {
	public Formula createConstant(double value);
	public Formula createProduct(ArrayList<Formula> formulas);
	public Formula createSum(ArrayList<Formula> formulas);
}
