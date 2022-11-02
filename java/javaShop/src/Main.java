import java.util.Scanner;
import java.util.*;


public class Main {
    public static void main(String[] args) {
        double orderTotal = 0;
        Vector<String> physicalOrders = new Vector<String>();
        double array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        outputMenuGreeting(array);

        orderTotal = getOrderTotal(array);
        outputOrder( orderTotal );
        orderTotal = studentDiscount( orderTotal );
        paymentScreen();
    }

    public static void outputMenuGreeting(double array[]) {
        System.out.println("Hello! Thank you for coming to Gabrielle's, the coffee of the future.");
        System.out.println("We are currently having a special on our black coffee, because man that stuff is terrible.");
        System.out.println("Would you like to place an order?");

        Scanner sc = new Scanner(System.in);
        String response = sc.next();
        System.out.println("Sweet! I really don't care what your answer was. Let's order!");
        outputMenu(array);
    }

    public static void outputMenu(double array[]) {
        double priceIncrease;
        System.out.println("");
        System.out.println("Our glorious menu consists of:");
        System.out.println("1:    Bagels              2.39");
        System.out.println("2:    Vanilla Coffee      1.99");
        System.out.println("3:    Chocolate Coffee    7.89");
        System.out.println("4:    Concrete            4.66");
        System.out.println("5:    Violence            FREE (today only)");
        System.out.println("Please enter the number you would like to order:");
        Scanner sc = new Scanner(System.in);
        int chosenValue = sc.nextInt();
        while( chosenValue > 5 || chosenValue < 1)
        {
            System.out.println("That isn't on the menu. Pick again.");
            chosenValue = sc.nextInt();
        }

        if(chosenValue == 1)
            priceIncrease = 2.39;
        else if(chosenValue == 2)
            priceIncrease = 1.99;
        else if(chosenValue == 3)
            priceIncrease = 7.89;
        else if(chosenValue == 4)
            priceIncrease = 4.66;
        else
            priceIncrease = 0.00;

        addValueToOrder(array, priceIncrease);
    }

    public static void addValueToOrder(double array[], double chosenValue){
        int i = 0;
        while(array[i] != 0) {
            i++;
        }
        if(i < 10)
        {
            array[i] = chosenValue;
        }
    }

    public static double studentDiscount(double orderTotal)
    {
        System.out.println("Are you by chance a student? We offer a discount.(yes/no)");
        Scanner sc = new Scanner(System.in);
        String response = sc.next();
        orderTotal = orderTotal * 1.3;
        System.out.println("Your new total is $" + orderTotal);

        return orderTotal;
    }

    public static void outputOrder( double orderTotal ) {
        System.out.println("Your total is: $" + orderTotal);
    }

    public static double getOrderTotal(double array[]) {
        int i;
        double total = 0;
        for (i = 0; i < 10; i++)
        {
            total = total + array[i];
        }
        return total;
    }
    public static void paymentScreen()
    {
        System.out.println("Are you ready to pay?[y/n]");
        Scanner sc = new Scanner(System.in);
        String response = sc.next();

        System.out.println("Thank you for your business :)");
    }
}