import java.util.ArrayList;

public class Deplacements {
    /*####****************** MEMBERS ******************####*/
    Position piece;
    String colorPiece;

    /*####****************** CONSTRUCTOR ******************####*/
    public Deplacements(Position piece) { 
        this.piece = piece;
    }

    /*####****************** GET DEPLACEMENTS ******************####*/
    public ArrayList<Position> getDeplacements(ArrayList<ArrayList<String>> tabMap){
        ArrayList<Position> tabToReturn = new ArrayList<Position>();

        if(tabMap.get(this.piece.posY-1).get(this.piece.posX-1).length() != 2)
            return tabToReturn;

        String typeOfPiece = tabMap.get(this.piece.posY-1).get(this.piece.posX-1).substring(1);
        this.colorPiece = this.getColorPiece(tabMap.get(this.piece.posY-1).get(this.piece.posX-1));
         
        if(typeOfPiece.equals("B")){
            this.getDiagonalDeplacements(tabToReturn, tabMap, this.piece.posX, this.piece.posY);
            return tabToReturn;
        }else if(typeOfPiece.equals("R")){
            this.getStraightDeplacements(tabToReturn, tabMap, this.piece.posX, this.piece.posY);
            return tabToReturn;
        }else if(typeOfPiece.equals("Q")){
            this.getDiagonalDeplacements(tabToReturn, tabMap, this.piece.posX, this.piece.posY);
            this.getStraightDeplacements(tabToReturn, tabMap, this.piece.posX, this.piece.posY);
            return tabToReturn;
        }else if(typeOfPiece.equals("C")){
            this.getKnightDeplacements(tabToReturn, tabMap, this.piece.posX, this.piece.posY);
            return tabToReturn;
        }else if(typeOfPiece.equals("K")){
            this.getKingDeplacements(tabToReturn, tabMap, this.piece.posX, this.piece.posY);
            return tabToReturn;
        }else if(typeOfPiece.equals("P")){
            this.getPawnDeplacements(tabToReturn, tabMap, this.piece.posX, this.piece.posY);
            return tabToReturn;
        }
        return tabToReturn;
    }

    /*####****************** GET KING DEPLACEMENTS ******************####*/
    private void getKingDeplacements(ArrayList<Position> tabToReturn, ArrayList<ArrayList<String>> tabMap, int posX, int posY){
        int y = posY, x = posX;
        y--;
        x = posX;
        if(x >= 0 && x < 8){
            String piece = tabMap.get(y).get(x);
            if(this.checkIfEmpty(piece))
                tabToReturn.add(new Position(x+1, y+1));
        }           
        x = posX - 2;
        if(x >= 0 && x < 8){
            String piece = tabMap.get(y).get(x);
            if(this.checkIfEmpty(piece))
                tabToReturn.add(new Position(x+1, y+1));
        }        
        x = posX - 1;
        y = posY;
        if(y >= 0 && y < 8){
            String piece = tabMap.get(y).get(x);
            if(this.checkIfEmpty(piece))
                tabToReturn.add(new Position(x+1, y+1));
        }           
        y = posY - 2;
        if(y >= 0 && y < 8){
            String piece = tabMap.get(y).get(x);
            if(this.checkIfEmpty(piece))
                tabToReturn.add(new Position(x+1, y+1));
        }        
        
        x = posX - 2;
        y = posY - 2;
        if(y >= 0 && y < 8 && x >= 0 && x < 8){
            String piece = tabMap.get(y).get(x);
            if(this.checkIfEmpty(piece))
                tabToReturn.add(new Position(x+1, y+1));
        }
        x = posX;
        y = posY - 2;
        if(y >= 0 && y < 8 && x >= 0 && x < 8){
            String piece = tabMap.get(y).get(x);
            if(this.checkIfEmpty(piece))
                tabToReturn.add(new Position(x+1, y+1));
        }
        x = posX - 2;
        y = posY;
        if(y >= 0 && y < 8 && x >= 0 && x < 8){
            String piece = tabMap.get(y).get(x);
            if(this.checkIfEmpty(piece))
                tabToReturn.add(new Position(x+1, y+1));
        }
        x = posX;
        y = posY;
        if(y >= 0 && y < 8 && x >= 0 && x < 8){
            String piece = tabMap.get(y).get(x);
            if(this.checkIfEmpty(piece))
                tabToReturn.add(new Position(x+1, y+1));
        }           
    }

    /*####****************** GET DIAGONAL DEPLACEMENTS ******************####*/
    private void getDiagonalDeplacements(ArrayList<Position> tabToReturn, ArrayList<ArrayList<String>> tabMap, int posX, int posY){
        int x = posX, y = posY;
        while(y < 8 && x < 8){
            String piece = tabMap.get(y).get(x);
            if(piece != ""){
                if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                    tabToReturn.add(new Position(x+1, y+1));
                break;
            }
            tabToReturn.add(new Position(x+1, y+1));
            y++;
            x++;
        }

        x = posX;
        y = posY - 2;
        while(y >= 0 && x < 8){
            String piece = tabMap.get(y).get(x);
            if(piece != ""){
                if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                    tabToReturn.add(new Position(x+1, y+1));
                break;
            }
            tabToReturn.add(new Position(x+1, y+1));
            y--;
            x++;
        }

        x = posX - 2;
        y = posY;
        while(y < 8 && x >= 0){
            String piece = tabMap.get(y).get(x);
            if(piece != ""){
                if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                    tabToReturn.add(new Position(x+1, y+1));
                break;
            }
            tabToReturn.add(new Position(x+1, y+1));
            y++;
            x--;
        }   

        x = posX - 2;
        y = posY - 2;
        while(y >= 0 && x >= 0){
            String piece = tabMap.get(y).get(x);
            if(piece != ""){
                if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                    tabToReturn.add(new Position(x+1, y+1));
                break;
            }
            tabToReturn.add(new Position(x+1, y+1));
            y--;
            x--;
        }
    }    
    
    /*####****************** GET STRAIGHT DEPLACEMENTS ******************####*/
    private void getStraightDeplacements(ArrayList<Position> tabToReturn, ArrayList<ArrayList<String>> tabMap, int posX, int posY){
        int y = posY - 1, x = posX;
        while(x < 8){
            String piece = tabMap.get(y).get(x);
            if(piece != ""){
                if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                    tabToReturn.add(new Position(x+1, y+1));
                break;
            }
            tabToReturn.add(new Position(x+1, y+1));
            x++;
        }

        x = posX - 2;
        while(x >= 0){
            String piece = tabMap.get(y).get(x);
            if(piece != ""){
                if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                    tabToReturn.add(new Position(x+1, y+1));
                break;
            }
            tabToReturn.add(new Position(x+1, y+1));
            x--;
        }

        x = posX - 1;
        y = posY;
        while(y < 8){
            String piece = tabMap.get(y).get(x);
            if(piece != ""){
                if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                    tabToReturn.add(new Position(x+1, y+1));
                break;
            }
            tabToReturn.add(new Position(x+1, y+1));
            y++;
        }        
        
        y = posY - 2;
        while(y >= 0){
            String piece = tabMap.get(y).get(x);
            if(piece != ""){
               if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                    tabToReturn.add(new Position(x+1, y+1));
                break; 
            }
            tabToReturn.add(new Position(x+1, y+1));
            y--;
        }
    }

    /*####****************** GET KNIGHT DEPLACEMENTS ******************####*/
    private void getKnightDeplacements(ArrayList<Position> tabToReturn, ArrayList<ArrayList<String>> tabMap, int posX, int posY){
        int y = posY, x = posX;

        if(y >= 0 && y < 8){
            x++;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(this.checkIfEmpty(piece))
                    tabToReturn.add(new Position(x+1, y+1));
            }
            x = posX - 3;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(this.checkIfEmpty(piece))
                    tabToReturn.add(new Position(x+1, y+1));
            }
        }

        y -= 2;
        if(y >= 0 && y < 8){
            x = posX + 1;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(this.checkIfEmpty(piece))
                    tabToReturn.add(new Position(x+1, y+1));
            }
            x = posX - 3;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(this.checkIfEmpty(piece))
                    tabToReturn.add(new Position(x+1, y+1));
            }
        }

        y = posY + 1;
        if(y >= 0 && y < 8){
            x = posX;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(this.checkIfEmpty(piece))
                    tabToReturn.add(new Position(x+1, y+1));
            }
            x = posX - 2;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(this.checkIfEmpty(piece))
                    tabToReturn.add(new Position(x+1, y+1));
            }
        }

        y = posY - 3;
        if(y >= 0 && y < 8){
            x = posX;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(this.checkIfEmpty(piece))
                    tabToReturn.add(new Position(x+1, y+1));
            }
            x = posX - 2;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(this.checkIfEmpty(piece))
                    tabToReturn.add(new Position(x+1, y+1));
            }
        }
    }

    /*####****************** GET PAWN DEPLACEMENTS ******************####*/
    private void getPawnDeplacements(ArrayList<Position> tabToReturn, ArrayList<ArrayList<String>> tabMap, int posX, int posY){
        int y = posY, x = posX;
        x--;
        y--;
        if(this.colorPiece.equals("W")){
            if(y == 1){
                y += 2;
                String piece = tabMap.get(y).get(x);
                if(piece == "")
                    tabToReturn.add(new Position(x+1, y+1));
            }
            y = posY;
            if(y >= 0 && y < 8){
                String piece = tabMap.get(y).get(x);
                if(piece == "")
                    tabToReturn.add(new Position(x+1, y+1));
            }

            x = posX - 2;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(piece != "")
                    if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                        tabToReturn.add(new Position(x+1, y+1));
            }            
            x = posX;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(piece != "")
                    if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                        tabToReturn.add(new Position(x+1, y+1));
            }

        }else if(this.colorPiece.equals("B")){
            if(y == 6){
                y -= 2;
                String piece = tabMap.get(y).get(x);
                if(piece == "")
                    tabToReturn.add(new Position(x+1, y+1));
            }
            y = posY - 2;
            if(y >= 0 && y < 8){
                String piece = tabMap.get(y).get(x);
                if(piece == "")
                    tabToReturn.add(new Position(x+1, y+1));
            }

            x = posX - 2;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(piece != "")
                    if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                        tabToReturn.add(new Position(x+1, y+1));
            }            
            x = posX;
            if(x >= 0 && x < 8){
                String piece = tabMap.get(y).get(x);
                if(piece != "")
                    if(!(this.getColorPiece(piece).equals(this.colorPiece)))
                        tabToReturn.add(new Position(x+1, y+1));
            }
        }
    }

    /*####****************** GET COLOR OF A PIECE ******************####*/
    private String getColorPiece(String piece){
        return piece.substring(0,1);
    }    
    
    /*####****************** CHECK IF EMPTY ******************####*/
    private boolean checkIfEmpty(String piece){
        return (piece == "" || !(this.getColorPiece(piece).equals(this.colorPiece)));
    }
}