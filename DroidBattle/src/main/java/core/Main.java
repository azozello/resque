package core;

import core.engine.BattleManager;
import core.model.Droid;
import core.model.Jedi;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author azozello
 * NOT TO RUN TOGETHER WITH "EngineManager" class
 */
public class Main {

    public static void main(String[] args){
       try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            while (true){
                String action;
                System.out.println();
                System.out.println("Type 'play' for Battle");
                System.out.println("Type 'quit' for Exit");
                action = br.readLine();
                if (action.equalsIgnoreCase("play")) printFight(br);
                else if (action.equalsIgnoreCase("quit")) return;
                else System.out.println("Unknown command");
            }
        } catch (IOException ioe){
            ioe.printStackTrace();
        } catch (NullPointerException npe){
            System.out.println("Something wrong with you");
        }
    }

    private static void printFight(BufferedReader br) throws IOException{
        BattleManager bm = BattleManager.getInstance();

        int droidArmor;
        int jediSword;
        int droidsAmount;

        System.out.println("Enter Droid`s armor: ");
        droidArmor = Integer.parseInt(br.readLine());

        System.out.println("Enter Jedi Sword (1 for yes, 0 for no): ");
        jediSword = Integer.parseInt(br.readLine());

        System.out.println("Enter droid amount: ");
        droidsAmount = Integer.parseInt(br.readLine());

        Jedi jedi = new Jedi(1.0f,jediSword);
        Droid droid = new Droid(1.0f,droidArmor);

        List<Droid> droids = new ArrayList<>();
        for(int i=0;i<droidsAmount;i++){
            droids.add(droid);
        }

        bm.battle(droids,jedi);
    }
}
