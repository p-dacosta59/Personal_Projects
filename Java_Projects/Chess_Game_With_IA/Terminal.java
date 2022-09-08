import java.util.Scanner;
import java.util.ArrayList;
import java.util.Iterator;

public class Terminal {
    /*####****************** MEMBERS ******************####*/
    Chess mainChess;
    Scanner myObj;

    /*####****************** CONSTRUCTOR ******************####*/
    public Terminal() {
        this.mainChess = new Chess();
        myObj = new Scanner(System.in);
    }

    /*####****************** DESTRUCTOR ******************####*/
    public void finalize() {
        this.myObj.close();
    }

    /*####****************** DO ONE STEP ******************####*/
    public void doOneStep() {
        while(true){
            this.printTable();
            Position pieceToMoove = this.readMovements();
            ArrayList<Position> tabPosibility;
            tabPosibility = this.mainChess.getDeplacement(pieceToMoove);
            while(tabPosibility.size() == 0){
                System.out.println("Aucun déplacement disponible pour cette piece!");
                pieceToMoove = this.readMovements();
                tabPosibility = this.mainChess.getDeplacement(pieceToMoove);
            }
            Position newPosition = this.displayPossibility(tabPosibility, pieceToMoove);
            mainChess.searchAndEatPiece(newPosition.posX, newPosition.posY);
            mainChess.moovePiece(pieceToMoove, newPosition);
            System.out.print("\033[H\033[2J");  
            System.out.flush();
        }
    }

    /*####****************** PRINT TABLE IN TERMINAL ******************####*/
    private void printTable() {
        System.out.println("\n---------------------------------");
        for(int y = 8; y > 0; y--){
            System.out.print("| ");
            for(int x = 1; x < 9; x++){
                String piece = this.mainChess.searchInTableWhite(x, y);
                if(piece == "")
                    piece = this.mainChess.searchInTableBlack(x, y);
                if(piece == "")
                    piece = " ";
                System.out.print(piece + " | ");
            }
            System.out.println(String.valueOf(y) + "\n---------------------------------");
        }
        System.out.println("  A   B   C   D   E   F   G   H ");
    }

    /*####****************** READ USER PIECE TO MOVE ******************####*/
    private Position readMovements() {
        // Get input of user
        int posX = 0, posY = 0;
        while(posX == 0 || posY == 0){
            String moovements = "";
            System.out.print("Que shouaitez vous bouger?");
            moovements = this.myObj.next();
            if(moovements.length() == 2){
                // Convert positions in int
                char posXChar = moovements.charAt(0);
                char posYChar = moovements.charAt(1);        
                posX = posXChar - 96;
                posY = posYChar - 48;
                if(posX < 1 || posX > 8 || posY < 1 || posY > 8){
                    posX = 0;
                    posY = 0;
                // }else if(this.mainChess.searchInTableWhite(posX, posY) == ""){
                //     posX = 0;
                //     posY = 0;
                }
            }
        }
        return new Position(posX, posY);
    }

    /*####****************** READ USER PIECE TO MOVE ******************####*/
    private Position displayPossibility(ArrayList<Position> tabPosibility, Position pieceToMoove) {
        int posX = 0, posY = 0;
        while(posX == 0 || posY == 0){
            System.out.println("Vous pouvez choisir entre ces possibilités :");
            for (Position i : tabPosibility)
                System.out.print("[" + (char)(i.posX+64) + ":" + i.posY + "] ");

            // Get input of user
            String moovements = "";
            moovements = this.myObj.next();
            if(moovements.length() == 2){
                // Convert positions in int
                char posXChar = moovements.charAt(0);
                char posYChar = moovements.charAt(1);
                posX = posXChar - 96;
                posY = posYChar - 48;
                if(posX < 1 || posX > 8 || posY < 1 || posY > 8){
                    posX = 0;
                    posY = 0;
                }
                // Check if position was in table
                Iterator<Position> itPos = tabPosibility.iterator();
                while(itPos.hasNext()){
                    Position itPosition = itPos.next();
                    if(itPosition.posX == posX && itPosition.posY == posY)
                        return new Position(posX, posY);
                }
            }
            posX = 0;
            posY = 0;
        }
        return null;
    }
}