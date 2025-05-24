import unittest
from unittest.mock import patch
import main_program

class TestMainFunction(unittest.TestCase):

    @patch('builtins.input', side_effect=['3', '85', '90', '95'])
    @patch('builtins.print')
    def test_main_valid_input(self, mock_print, mock_input):
        main_program.main()
        mock_print.assert_called_with('The class average is: 90.00')
        self.assertIn(
            unittest.mock.call('The class average is: 90.00'), 
            mock_print.mock_calls
        )

    @patch('builtins.input', side_effect=['0','3', '85', '90', '95'])
    @patch('builtins.print')
    def test_invalid_number_of_students(self, mock_print, mock_input):
        main_program.main()
        mock_print.assert_called_with('The class average is: 90.00')
        self.assertIn(
            unittest.mock.call('The class average is: 90.00'), 
            mock_print.mock_calls
        )

    @patch('builtins.input', side_effect=['3', '105', '85', '-5', '90', '95'])
    @patch('builtins.print')
    def test_invalid_grades(self, mock_print, mock_input):
        main_program.main()
        mock_print.assert_called_with('The class average is: 90.00')
        self.assertIn(
            unittest.mock.call('The class average is: 90.00'), 
            mock_print.mock_calls
        )

    @patch('builtins.input', side_effect=['Three','3', '69', '98', '75'])
    @patch('builtins.print')
    def test_nonNumeric_invalid_Student_input(self, mock_print, mock_input):
        main_program.main()
        mock_print.assert_called_with('The class average is: 80.67')
        self.assertIn(
            unittest.mock.call('The class average is: 80.67'), 
            mock_print.mock_calls
        )
    # In this test for non-numeric input for No.of Students, i have provided new input parameters 
    # for side_effect which is 'three' a non-numeric format and matched resultant average 
    # value for the mock/assert accordingly. It is first taking the input for no. of students 'three'
    # and rejecting it and asks for new input which i have set to '3'. The test performs correctly.


    @patch('builtins.input', side_effect=['4','Eighty','80','Sixty Nine','69','Ninety Eight','98','Seventy Five','75'])
    @patch('builtins.print')
    def test_nonNumeric_invalid_Grade_input(self, mock_print, mock_input):
        main_program.main()
        mock_print.assert_called_with('The class average is: 80.50')
        self.assertIn(
            unittest.mock.call('The class average is: 80.50'), 
            mock_print.mock_calls
        )
    # In this test for non-numeric input for each Grade, i have provided new input parameters 
    # for side_effect in non-numeric format which will be rejected, so added '80' to satisfy conditions
    # and matched resultant average value for the mock/assert accordingly.It is taking the input 
    # for each grade and encounters the first input to be 'Eighty' and rejecting it due to being a non-numeric format
    # and asks for new input which i have set to '80'. The test performs correctly.
    
    
    @patch('builtins.input', side_effect=['1','80'])
    @patch('builtins.print')
    def test_signle_Student_input(self, mock_print, mock_input):
        main_program.main()
        mock_print.assert_called_with('The class average is: 80.00')
        self.assertIn(
            unittest.mock.call('The class average is: 80.00'), 
            mock_print.mock_calls
        )
    #bIn this test for single input for No.of Students, i have provided new input parameters 
    # for side_effect which is '1' as no. of student and '80' for grade, and to match resultant average 
    # value for the mock/assert to have made value changes accordingly. It is using the 1st parameter to
    # input and set no. of students to be 1 and then taking the grade and calculating the grade 
    # average correctly.


if __name__ == "__main__":
    unittest.main()
