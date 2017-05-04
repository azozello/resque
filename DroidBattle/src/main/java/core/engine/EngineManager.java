package core.engine;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author azozello
 * NOT TO RUN TOGETHER "Main" class
 */
public class EngineManager {
    public static void main(String[] args){
        JediBrain jediBrain = new JediBrain();
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            int flag;
            System.out.println("1 - test");
            System.out.println("2 - train");
            System.out.println("0 - exit");
            flag = Integer.parseInt(br.readLine());
            switch (flag){
                case 0: return;
                case 1:
                    jediBrain.test();
                    break;
                case 2:
                    jediBrain.train();
                    break;
            }
        }catch (IOException ioe){
            ioe.printStackTrace();
        }
    }
}
