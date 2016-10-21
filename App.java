package fr.licinfo.factory;

import formula.Calculator;
import formula.ExtensionFormulaFactory;
import formula.Formula;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        Calculator c = new Calculator(new ExtensionFormulaFactory());
        Formula f = c.analyze(new String[] {"2", "5", "*", "3", "4", "7", "+", "*", "+"});
        System.out.println(f.asString());
        System.out.println(f.asValue());
    }
}
