import unittest
from main import Connect4

class Connect4CheckWinTestCase(unittest.TestCase):
    def setUp(self):
        self.game = Connect4()

    def test_check_win_horizontal(self):
        # Test winning horizontally
        drop_sequence = [4, 4, 3, 3, 2, 2, 5]

        for column in drop_sequence:
            self.game.drop_chip(column)
            self.game.switch_player()

        self.assertFalse(self.game.check_win('O'))
        self.assertTrue(self.game.check_win('X'))

    def test_check_win_vertical(self):
        # Test winning vertically
        drop_sequence = [1, 4, 3, 4, 2, 4, 1, 4]

        for column in drop_sequence:
            self.game.drop_chip(column)
            self.game.switch_player()

        self.assertFalse(self.game.check_win('X'))
        self.assertTrue(self.game.check_win('O'))

    def test_check_win_diagonal(self):
        # Test winning diagonally
        drop_sequence = [1, 2, 2, 3, 3, 4, 3, 4, 4, 3, 4]

        for column in drop_sequence:
            self.game.drop_chip(column)
            self.game.switch_player()

        self.assertFalse(self.game.check_win('O'))
        self.assertTrue(self.game.check_win('X'))

    def test_check_win_no_win(self):
        # Test no win
        drop_sequence = [1, 2, 3, 4, 5, 6, 7, 1, 2, 3]

        for column in drop_sequence:
            self.game.drop_chip(column)
            self.game.switch_player()

        result = self.game.check_win('O')
        self.assertFalse(result)

if __name__ == '__main__':
    unittest.main()