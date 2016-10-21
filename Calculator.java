package formula;

import java.util.ArrayList;
import java.util.Stack;

public class Calculator {
	
	private AbstractFormulaFactory factory;
	
	public Calculator(AbstractFormulaFactory factory) {
		this.setFactory(factory);
	}
	
	public Formula analyze(String tokens[]) {
		Stack<Formula> stack = new Stack<Formula>();
		for (int i = 0; i < tokens.length; i++) {
			analyzeToken(tokens[i], stack);
		}
		return stack.elementAt(0);
	}
	
	private void analyzeToken(String token, Stack<Formula> stack) {
		if (token == "*") {
			analyzeProduct(stack);
		}
		else if (token == "+") {
			analyzeSum(stack);
		}
		else
			analyzeConstant(token, stack);
	}
	
	private void analyzeSum(Stack<Formula> stack) {
		ArrayList<Formula> formulas = new ArrayList<Formula>();
		formulas.add(stack.pop());
		formulas.add(stack.pop());
		stack.push(factory.createSum(formulas));
	}
	
	private void analyzeProduct(Stack<Formula> stack) {
		ArrayList<Formula> formulas = new ArrayList<Formula>();
		formulas.add(stack.pop());
		formulas.add(stack.pop());
		stack.push(factory.createProduct(formulas));
	}
	
	private void analyzeConstant(String token, Stack<Formula> stack) {
		stack.add(new Constant(Double.parseDouble(token)));
	}

	public AbstractFormulaFactory getFactory() {
		return factory;
	}

	public void setFactory(AbstractFormulaFactory factory) {
		this.factory = factory;
	}
}
