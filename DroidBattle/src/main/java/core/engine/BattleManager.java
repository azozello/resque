package core.engine;

import core.model.Droid;
import core.model.Jedi;

import java.util.List;

/**
 * @author azozello
 */
public class BattleManager {

    private static BattleManager instance;
    private JediBrain jediBrain;

    public static synchronized BattleManager getInstance() {
        if (instance == null) {
            instance = new BattleManager();
        }
        return instance;
    }

    private BattleManager(){
        this.jediBrain = new JediBrain();
    }

    public void battle(List<Droid> droids, Jedi jedi){

        float[] in = {jedi.getHealth(), jedi.isSword(), droids.size()};
        int decision = jediBrain.getDecision(in);

        switch (decision){
            case 0:
                float result = fight(droids,jedi);
                if (result>0) System.out.println("Jedi loses");
                else if (result==0) System.out.println("Holly Cow!");
                else System.out.println("Jedi wins");
                break;
            case 1:
                System.out.println("Jedi hides");
                if (droids.size()>1) {
                    droids.remove(0);
                    System.out.println("One Droid went away");
                    battle(droids,jedi);
                }
                break;
            case 2:
                System.out.println("Jedi runs");
                break;
            case 3:
                System.out.println("Jedi smokes");
                break;
        }
    }

    private float fight(List<Droid> droids, Jedi jedi){
        float droidsHealth = getDroidsHealth(droids);
        float jediDamage = getJediDamage(jedi);
        System.out.println("#######FIGHT#######");
        System.out.println("droidsHealth:  "+droidsHealth);
        System.out.println("jediDamage:    "+jediDamage);
        System.out.println();
        return droidsHealth-jediDamage;
    }

    private float getJediDamage(Jedi jedi){
        switch (jedi.isSword()){
            case 0:
                return jedi.getHealth()*10;
            case 1:
                return jedi.getHealth()*30;
            default:
                return 0;
        }
    }

    private float getDroidsHealth(List<Droid> droids){
        float activeHealth = 0.0f;
        for (Droid d : droids){
            if (d.getHealth()!=0.0f){
                activeHealth += (d.getHealth()*d.getArmor());
            }
        }
        return activeHealth;
    }
}
