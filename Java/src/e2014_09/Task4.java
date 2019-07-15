package e2014_09;

import java.util.ArrayList;
import java.util.List;

class Globals {
    public static final int N = 5;
}

class Point {
	int x;
	int y;
	char value;
	
	Point() {}
	
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	Point(int x, int y, char value) {
		this.x = x;
		this.y = y;
		this.value = value;
	}
	
	Point(Point point) {
		this.x = point.x;
		this.y = point.y;
		this.value = point.value;
	}
	
	void printPoint() {
		System.out.print(this.value + "(" + this.x + "," + this.y + ")");
	}
}

interface GamePlayer {
	public static final Point position = null;
	
	
	public Point getPosition();
	public List<Point> allowedMoves(Point board[][]);
	public boolean isNextToPlayer(Point board[][]);
	public Point[][] moveTo(Point point, Point board[][]);
}

class Knight implements GamePlayer {
	private Point position;
	
	Knight(int x, int y) {
		this.position = new Point(x, y, 'K');
	}
	
	Knight(Knight knight) {
		this.position = new Point(knight.position);
	}
	
	public Point getPosition() {
		return this.position;
	}
	
	public List<Point> allowedMoves(Point board[][]) {
		List<Point> moves = new ArrayList<Point>();
		
		int x = position.x;
		int y = position.y;

		for (int i=y-1; i<=x+1; i++) {
			for (int j=x-1; j<=y+1; j++) {
				if (i == x && j == y) {
					continue;
				}
				
				if (checkBounds(i, j) && checkPosition(board, i, j)) {
					moves.add(new Point(i, j, 'K'));
				}
			}
		}
		
		return moves;
	}
	
	/**
	 * Check weather the bounds are correct
	 * @param x
	 * @param y
	 * @return
	 */
	boolean checkBounds(int x, int y) {
		if (x < 0 || x >= Globals.N || y < 0 || y >= Globals.N) {
			return false;
		}
		return true;
	}
	
	/**
	 * Validate the land on the specific position
	 * @return
	 */
	boolean validatePosition(Point board[][], int x, int y) {
		if (board[y][x].value == '1' || board[y][x].value == '2') {
			return false;
		}
		
		return true;
	}
	
	/**
	 * Check a speciffic position and validate its neighbourds
	 * @param board
	 * @param x
	 * @param y
	 * @return
	 */
	boolean checkPosition(Point board[][], int x, int y) {
		if (board[y][x].value == '1' || board[y][x].value == '2') {
			return false;
		}
		
		for (int i=x-1; i<=x+1; i++) {
			for (int j=y-1; j<=y+1; j++) {
				if (i == x && j == y) {
					continue;
				}
				
				if (i == position.x && j == position.y) {
					continue;
				}
				
				if (checkBounds(i, j) == false) {
					continue;
				}
				
				if (validatePosition(board, i, j) == false) {
					return false;
				}
			}
		}
		
		return true;
	}
	
	public boolean isNextToPlayer(Point board[][]) {
		for (int i=position.x-1; i<=position.x+1; i++) {
			for (int j=position.y-1; j<=position.y+1; j++) {
				if (i == position.x && j == position.y) {
					continue;
				}
				
				if (checkBounds(i, j) == false) {
					continue;
				}
				
				if (board[i][j].value == 'K') {
					return true;
				}
			}
		}
		
		return false;
	}
	
	public Point[][] moveTo(Point newPosition, Point board[][]) {
		Point[][] newBoard = new Point[Globals.N][Globals.N];
		
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				if (i == position.y && j == position.x) {
					newBoard[i][j] = new Point(j, i, '0');
				}
				else if (i == newPosition.x && j == newPosition.y) {
					newBoard[i][j] = new Point(j, i, 'K');
				}
				else {
					newBoard[i][j] = board[i][j];
				}
			}
		}
		
		return newBoard;
	}
	
}

public class Task4 {
	
	/**
	 * Utils
	 */
	
	
	public static Point[][] initBoard(char board[][]) {
		Point[][] gameBoard = new Point[Globals.N][Globals.N];
		
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				gameBoard[i][j] = new Point(i, j, board[i][j]);
			}
		}
		
		return gameBoard;
	}
	
	public static void printBoard(Point board[][]) {
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				System.out.print(board[i][j].value + " ");
			}
			System.out.println("");
		}
	}
	
	public static void printMoves(GamePlayer player, List<Point> moves) {
		for (Point position: moves) {
		    player.getPosition().printPoint();
		    System.out.print(" -> ");
		    position.printPoint();
		    System.out.println("");
		}
	}
	
	public static boolean isWar(Point board[][]) {
		List<GamePlayer> players = new ArrayList<GamePlayer>();
		
		for (int i=0; i < board.length; i++) {
			for (int j=0; j < board[i].length; j++) {
				if (board[j][i].value == 'K') {
					players.add(new Knight(j, i));
				}
			}
		}
		
		for (GamePlayer player: players) {
			if (player.isNextToPlayer(board)) {
				return true;
			}
			
		}
		
		return false;
	}
	
	public static void allMoves(Point board[][]) {
		List<GamePlayer> players = new ArrayList<GamePlayer>();
		
		for (int i=0; i < board.length; i++) {
			for (int j=0; j < board[i].length; j++) {
				if (board[j][i].value == 'K') {
					players.add(new Knight(i, j));
				}
			}
		}
		
		// Loop through all players and their moves
		for (GamePlayer player: players) {
			List<Point> moves = player.allowedMoves(board);
//			printMoves(player, moves);

			for (Point move: moves) {
				Point[][] tempBoard = player.moveTo(move, board);
				if (isWar(tempBoard)) {
					player.getPosition().printPoint();
					System.out.print(" -> ");
					move.printPoint();
					System.out.println();
					printBoard(tempBoard);
				}
			}			
		}
	}
	
	public static void main(String[] args) {
		
		char board[][] = {
			{ '1', '1' , '0', '2', 'K' },
			{ '0', '1' , '1', '0', '1' },
			{ '2', 'S' , '2', '2', '0' },
			{ '1', '1' , '0', '0', 'K' },
			{ '2', '2' , '0', 'K', '0' }
		};
		
		Point gameBoard[][] = initBoard(board);
		
		printBoard(gameBoard);
		
//		Knight knight = new Knight(4, 3);
//		List<Point> knightMoves = knight.allowedMoves(gameBoard);
//		printMoves(knight, knightMoves);
		
		System.out.println("Is War: " + isWar(gameBoard));
		
		allMoves(gameBoard);
		
	}

}
