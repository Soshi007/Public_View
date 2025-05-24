# Connect 4 Game

class Connect4:
  def __init__(self):
    self.board = [[' ' for _ in range(7)] for _ in range(6)]
    self.current_player = 'X'

  def switch_player(self):
    self.current_player = 'O' if self.current_player == 'X' else 'X'

  def print_board(self):
    for row in self.board:
      print('|', end='')
      for cell in row:
        print(cell, end='|')
      print()
    print('---------------')
    print(' 1 2 3 4 5 6 7')

  def drop_chip(self, column):
      if column<1 or column>7:
          print("Invalid column, Please choose column between 1 and 7.")
          return False
      column -= 1
        
      if self.board[0][column]!=' ':
          print(f"Column {column + 1} is full, please choose another column.")
          return False
        
      for row in range(5, -1, -1):
          if self.board[row][column]== ' ':
              self.board[row][column] = self.current_player
              return True
      return False

         

  def check_win(self):
     ways=[(-1, 0), (0, 1), (-1, -1), (-1, 1)] 
     for row in range(6):
         for col in range(7):
            if self.board[row][col] == self.current_player:
                for wr, wc in ways:
                    count = 1
                    for jump in range(1, 4):
                        r,c= row+wr*jump,col+wc*jump
                        if 0 <= r < 6 and 0 <= c < 7 and self.board[r][c] == self.current_player:
                            count += 1
                        else:
                            break 
                    if count == 4:
                        return True
     return False

  def play_game(self):
    game_over = False
    while not game_over:
      self.print_board()
      print(f"Player {self.current_player}'s turn.")

      try:
        column = int(input("Enter the column number (1-7): "))
      except ValueError:
        print("Invalid input. Please enter a valid column number.")
        continue

      if not self.drop_chip(column):
        print("Column is full or out of range. Try again.")
        continue
      
      self.switch_player()

if __name__ == "__main__":
  game = Connect4()
  game.play_game()
