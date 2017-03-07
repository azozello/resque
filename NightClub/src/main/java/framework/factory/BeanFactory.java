package framework.factory;

import framework.annotations.Building;
import framework.annotations.Customer;
import framework.annotations.Employee;
import org.reflections.Reflections;

import java.util.Set;

public abstract class BeanFactory {

    public static Object createBeanForName(String name){
        Object o = null;
        try {
            Class c = Class.forName(name);
            o = c.newInstance();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return o;
    }

    public static Set<Class<?>> getAllBeans(Ann ann){
        Reflections allReflections = new Reflections("custom");
        Set<Class<?>> allClasses = null;

        switch (ann){
            case BUILDING:
                allClasses = allReflections.getTypesAnnotatedWith(Building.class);
                return allClasses;
            case CUSTOMER:
                allClasses = allReflections.getTypesAnnotatedWith(Customer.class);
                return allClasses;
            case EMPLOYEE:
                allClasses = allReflections.getTypesAnnotatedWith(Employee.class);
                return allClasses;
        }
        return null;
    }

    public static Set<Class<?>> getAllBeans(){
        Reflections allReflections = new Reflections("custom");
        Set<Class<?>> allClasses = allReflections.getTypesAnnotatedWith(Building.class);
        for (Class c: allReflections.getTypesAnnotatedWith(Customer.class)){
            allClasses.add(c);
        }
        for (Class c: allReflections.getTypesAnnotatedWith(Employee.class)){
            allClasses.add(c);
        }
        return allClasses;
    }
}
