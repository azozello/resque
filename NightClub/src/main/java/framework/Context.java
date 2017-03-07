package framework;

import framework.factory.Ann;
import framework.factory.BeanFactory;

import java.lang.reflect.Field;
import java.util.*;

public class Context {

    private static final String CONST = "framework.interfaces.Constant";

    private static final String DYN = "framework.interfaces.Dynamic";

    private static Set<Class<?>> BUILDINGS;
    private static Set<Class<?>> CUSTOMERS;
    private static Set<Class<?>> EMPLOYEES;

    private Context context;
    private Context(){
        context = new Context();
    }

    public static void start(){
        CUSTOMERS = BeanFactory.getAllBeans(Ann.CUSTOMER);
        BUILDINGS = BeanFactory.getAllBeans(Ann.BUILDING);
        EMPLOYEES = BeanFactory.getAllBeans(Ann.EMPLOYEE);
        for (Class c: BUILDINGS){
            try {
                Object obj = c.newInstance();
                String name = c.getSimpleName();
                Field[] fields = c.getDeclaredFields();
                for (Field f: fields){
                    if (f.getName().equalsIgnoreCase("name")){
                        name = (String) f.get(obj);
                    }
                }
                printBuilding(name);
                System.out.println();
            } catch (Exception e){
                e.printStackTrace();
            }
        }
        System.out.println("EMPLOYEES: ");
        for (Class c: EMPLOYEES){
            try {
                Object obj = c.newInstance();
                String name = c.getSimpleName();
                Field[] fields = c.getDeclaredFields();
                for (Field f: fields){
                    if (f.getName().equalsIgnoreCase("name")){
                        name = (String) f.get(obj);
                    }
                }
                printPerson(name);
                System.out.println();
            } catch (Exception e){
                e.printStackTrace();
            }
        }
        System.out.println("CUSTOMERS: ");
        for (Class c: CUSTOMERS){
            try {
                String name = c.getSimpleName();
                Field[] fields = c.getDeclaredFields();
                for (Field f: fields){
                    if (f.getName().equalsIgnoreCase("name")){
                        Object obj = c.newInstance();
                        name = (String) f.get(obj);
                    }
                }
                printPerson(name);
                System.out.println();
            } catch (Exception e){
                e.printStackTrace();
            }
        }
        System.out.println();
    }

    public static void stop(){

    }

    private static void printBuilding(String name){
        char[] allLetters = name.toUpperCase().toCharArray();
        for (int i=0;i<3;i++){
            if (i == 1) {
                System.out.print("#");
                System.out.print("#");
                for (char c: allLetters){
                    System.out.print(c);
                }
                System.out.print("#");
                System.out.print("#");
            } else {
                for (int j = 0; j < allLetters.length + 4; j++) {
                    System.out.print("#");
                }
            }
            System.out.println();
        }
    }

    private static void printPerson(String name){
        if (name.length()<5){
            System.out.println(" ( ) ");
            System.out.println(" /|\\ ");
            System.out.println(" / \\ ");
            System.out.println(" "+name);
        } else if (name.length()>7){
            System.out.println("  ( ) ");
            System.out.println("  /|\\ ");
            System.out.println("  / \\ ");
            System.out.println(name);
        } else if (name.length()>5){
            System.out.println(" ( ) ");
            System.out.println(" /|\\ ");
            System.out.println(" / \\ ");
            System.out.println(name);
        }
    }

    public Context getContext() {
        if (context!=null) return context;
        else return new Context();
    }
}
