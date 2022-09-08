/*
  main.cpp
 
  Created by Pierre Da Costa on 2021/01/09.
  Copyright © 2020 Pierre Da Costa. All rights reserved.
*/
import java.util.ArrayList;
import java.util.Iterator;

public class Chess {
    /*####****************** MEMBERS ******************####*/
    private ArrayList<Piece> whitePlayerPiece = new ArrayList<Piece>();
    private ArrayList<Piece> blackPlayerPiece = new ArrayList<Piece>();
    
    /*####****************** CONSTRUCTOR ******************####*/
    public Chess() {
        // Initialize White Player
        this.initializeWhitePlayer();
        this.initializeBlackPlayer();
    }
    
    /*####****************** CHECK IF CHECKMATE ******************####*/
    public boolean checkIfMate() {
        return true;
    }

    /*####****************** GET DEPLACEMENTS OF PIECE ******************####*/
    public ArrayList<Position> getDeplacement(Position pieceToMoove){
        Deplacements nextMoove = new Deplacements(pieceToMoove);
        ArrayList<ArrayList<String>> tabMap = new ArrayList<ArrayList<String>>();

        for(int y = 1; y < 9; y++){
            ArrayList<String> listToAdd = new ArrayList<String>();
            for(int x = 1; x < 9; x++){
                String piece = this.searchInTableWhite(x, y);
                if(piece != "")
                    listToAdd.add("W" + piece);
                else{
                        piece = this.searchInTableBlack(x, y);
                    if(piece != "")
                        listToAdd.add("B" + piece);
                    else 
                        listToAdd.add("");
                }
            }
            tabMap.add(listToAdd);
        }
        return nextMoove.getDeplacements(tabMap);
    }  

    /*####****************** MOOVE PIECE IN NEW POSITIONS ******************####*/
    public void moovePiece(Position actual, Position newPosition){
        Iterator<Piece> itBlack = this.blackPlayerPiece.iterator();
        while(itBlack.hasNext()){
            Piece iteraBlack = itBlack.next();
            if(iteraBlack.getPositionX() == actual.posX && iteraBlack.getPositionY() == actual.posY){
                iteraBlack.changePosition(newPosition.posX, newPosition.posY);
                return;
            }
        }
        Iterator<Piece> itWhite = this.whitePlayerPiece.iterator();
        while(itWhite.hasNext()){
            Piece iteraWhite = itWhite.next();
            if(iteraWhite.getPositionX() == actual.posX && iteraWhite.getPositionY() == actual.posY){
                iteraWhite.changePosition(newPosition.posX, newPosition.posY);
                return;
            }
        }
    }

    /*####****************** IA MOOVE A PIECE ******************####*/
    public void iaMoovePiece(){
        Position actual = new Position(0, 0), newPosition = new Position(0, 0);
        
        ComputPlayer iaMoove = new ComputPlayer(actual, newPosition);
         
        this.moovePiece(actual, newPosition);
    }

    /*####****************** SEARCH AND EAT PIECE ******************####*/
    public void searchAndEatPiece(int posX, int posY){
        Iterator<Piece> itBlack = this.blackPlayerPiece.iterator();
        while(itBlack.hasNext()){
            Piece iteraBlack = itBlack.next();
            if(iteraBlack.getPositionX() == posX && iteraBlack.getPositionY() == posY){
                itBlack.remove();
                return;
            }
        }

        Iterator<Piece> itWhite = this.whitePlayerPiece.iterator();
        while(itWhite.hasNext()){
            Piece iteraWhite = itWhite.next();
            if(iteraWhite.getPositionX() == posX && iteraWhite.getPositionY() == posY){
                itWhite.remove();
                return;
            }
        }
    }
  
    /*####****************** SEARCH PIECE BLACK IN POSITIONS ******************####*/
    public String searchInTableBlack(int posX, int posY){
        Iterator<Piece> itBlack = this.blackPlayerPiece.iterator();
        while(itBlack.hasNext()){
            Piece iteraBlack = itBlack.next();
            if(iteraBlack.getPositionX() == posX && iteraBlack.getPositionY() == posY)
                return iteraBlack.getType();
        }
        return "";
    }   

    /*####****************** SEARCH PIECE WHITE IN POSITIONS ******************####*/
    public String searchInTableWhite(int posX, int posY){
        Iterator<Piece> itWhite = this.whitePlayerPiece.iterator();
        while(itWhite.hasNext()){
            Piece iteraWhite = itWhite.next();
            if(iteraWhite.getPositionX() == posX && iteraWhite.getPositionY() == posY)
                return iteraWhite.getType();
        }
        return "";
    } 

    /*####****************** INITIALIZE PIECE OF WHITE PLAYER ******************####*/
    private void initializeWhitePlayer() {
        // Create White Piece
        this.whitePlayerPiece.add(new Rook());
        this.whitePlayerPiece.add(new Knight());
        this.whitePlayerPiece.add(new Bishop());
        this.whitePlayerPiece.add(new King());
        this.whitePlayerPiece.add(new Queen());
        this.whitePlayerPiece.add(new Bishop());
        this.whitePlayerPiece.add(new Knight());
        this.whitePlayerPiece.add(new Rook());
        for(int i=0; i<8; i++)
            this.whitePlayerPiece.add(new Pawn());
        
        // Set positions of pieces
        Iterator<Piece> it = this.whitePlayerPiece.iterator();
        int x = 1, y = 1;
        while(it.hasNext()) {
            if(x > 8){
                x = 1;
                y++;
            }    
            it.next().changePosition(x, y);
            x++;
        }
    }

    /*####****************** INITIALIZE PIECE OF BLACK PLAYER ******************####*/
    private void initializeBlackPlayer() {
        // Create Black Piece
        this.blackPlayerPiece.add(new Rook());
        this.blackPlayerPiece.add(new Knight());
        this.blackPlayerPiece.add(new Bishop());
        this.blackPlayerPiece.add(new Queen());
        this.blackPlayerPiece.add(new King());
        this.blackPlayerPiece.add(new Bishop());
        this.blackPlayerPiece.add(new Knight());
        this.blackPlayerPiece.add(new Rook());
        for(int i=0; i<8; i++)
            this.blackPlayerPiece.add(new Pawn());
        
        // Set positions of pieces
        Iterator<Piece> it = this.blackPlayerPiece.iterator();
        int x = 8, y = 8;
        while(it.hasNext()) {
            if(x < 1){
                x = 8;
                y--;
            }    
            it.next().changePosition(x, y);
            x--;
        }
    }
}