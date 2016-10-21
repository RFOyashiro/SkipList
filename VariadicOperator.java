package strategy;

import java.util.ArrayList;

import formula.Formula;

public class VariadicOperator implements Formula {

	private ArrayList<Formula> formulas;
	private Operator operator;
	
	public VariadicOperator(Operator op, ArrayList<Formula> formulas) {
		this.operator = op;
		this.setFormulas(formulas);
	}
	
	public VariadicOperator(Operator op, Formula f1, Formula f2) {
		this.operator = op;
		formulas = new ArrayList<Formula>();
		formulas.add(f1);
		formulas.add(f2);
	}
	
	public String asString() {
		String finalString = "(";
		for (int i = 0; i < formulas.size(); i++) {
			finalString += formulas.get(i).asString();
			if (i < formulas.size() - 1) finalString += operator.symbol();
		}
		return finalString + ")";
	}

	public double asValue() {
		double result = operator.initialValue();
		for (Formula f : formulas) {
			result = operator.cumulativeValue(result, f.asValue());
		}
		return result;
	}

	public ArrayList<Formula> getFormulas() {
		return formulas;
	}

	public void setFormulas(ArrayList<Formula> formulas) {
		this.formulas = formulas;
	}
}
