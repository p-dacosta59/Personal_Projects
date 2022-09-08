abstract class Piece {
    /*####****************** MEMBERS ******************####*/
    protected String type;
    protected int posX, posY;
    protected int value;

    /*####****************** MOOVE ******************####*/
    public void changePosition(int posX, int posY) {
        this.posX = posX;
        this.posY = posY;
    }

    /*####****************** GET POSITIONS X ******************####*/
    public int getPositionX() {
        return this.posX;
    }

    /*####****************** GET POSITIONS Y ******************####*/
    public int getPositionY() {
        return this.posY;
    }

    /*####****************** GET VALUE ******************####*/
    public int getValue() {
        return this.value;
    }

    /*####****************** GET TYPE ******************####*/
    public String getType() {
        return this.type;
    }
}
