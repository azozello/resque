package core.model;

/**
 * @author azozello
 */
public abstract class Warrior {

    private float health;

    Warrior(float health) {
        this.health = health;
    }

    public float getHealth() {
        return health;
    }
}
