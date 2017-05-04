package core.model;

/**
 * @author azozello
 */
public class Jedi extends Warrior {

    private int sword;

    public Jedi(float health, int sword) {
        super(health);
        this.sword = sword;
    }

    public int isSword() {
        return sword;
    }
}
