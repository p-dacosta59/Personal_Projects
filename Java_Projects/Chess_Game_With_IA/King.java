public class King extends Piece {
    /*####****************** MEMBERS ******************####*/
    private boolean checkMate;
    
    /*####****************** CONSTRUCTOR ******************####*/
    public King() {
        this.checkMate = false;
        this.posX = 0;
        this.posY = 0;
        this.value = 100;
        this.type = "K";
    }

    /*####****************** GET CHECKMATE ******************####*/
    public boolean getCheckMate() {
        return this.checkMate;
    }

    /*####****************** CHANGE CHECKMATE ******************####*/
    public void changeCheckMate(boolean mate) {
        this.checkMate = mate;
    }
}