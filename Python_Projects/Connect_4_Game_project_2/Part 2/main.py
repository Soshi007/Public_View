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
    if column < 1 or column > 7:
        return False

    column -= 1
    row = 5
    while row >= 0: 
        if self.board[row][column] == ' ':
            self.board[row][column] = self.current_player
            return True
        row -= 1
    return False


  def check_win(self, player):
    for row in range(6):
      for col in range(4):
        if all(self.board[row][col + x] == player for x in range(4)):
            return True

    
    for col in range(7):
      for row in range(3):  
        if all(self.board[row + x][col] == player for x in range(4)):
            return True

    
    for row in range(3):
      for col in range(4):
        if all(self.board[row + x][col + x] == player for x in range(4)):
            return True

    
    for row in range(3, 6): 
      for col in range(4):
        if all(self.board[row - x][col + x] == player for x in range(4)):
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

      if self.check_win(self.current_player):
        self.print_board()
        print(f"Player {self.current_player} wins!")
        game_over = True

      self.switch_player()

if __name__ == "__main__":
  game = Connect4()
  game.play_game()
