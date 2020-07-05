# Personal Budget System
 Project for the Introduction to Algorithms and Data Structures course

The purpose of a budget is to control how the money we have at our disposal is used.
This system supports this purpose. In this case it is related to a person or a small household, as opposed to a company that may have a much more complicated budget.

# Input data

The program reads the input data from the standard input. Each line corresponds to a command, the type of which is identified by the letter placed at the beginning of the line. Command arguments are given on the same line and appear separated by a blank space. The specification of the commands is as follows:

1. The command to insert a movement, or a set of movements, has the following format:
- the letter 'i';
- the value (amount) of the movement;
- a number with the date of the first movement;
- a number with the periodicity between movements; if this value is 0, the movement is unique (not periodic);
- the character 'r' if the movement is a recipe, or the character 'd' if it is an expense;
- a sequence of a maximum of 60 characters, not white, with the description of the movement.

2. The command to show all movements that occurred on a given date has the following format:
- the letter 'l';
- a number with the date for which you want to view the movements.

3. The command to remove a given movement has the following format:
- the letter 'r';
- the date on which the movement occurred;
- the movement index, given by the previous command.

4. The command to calculate the balance sheet on a given date, including all movements that occurred on that date, has the following format:
- the letter 'b';
- the date for which the balance sheet is to be obtained.

5. The command to change the minimum balance sheet value that does not invalidate a budget, whose default value is 0, has the following format:
- the letter 'm';
- the new minimum value.

6. The command to check the validity of the budget has the following format:
- the letter ’v’.

7. The command to determine the first date on which a given expense becomes affordable, without invalidating the budget, has the following format:
- the letter 'w';
- the first date to consider;
- the amount of the expenditure.

Restrictions:
- all dates are integers between 0 and 999, the last date being budget 999.
- on each date there can be a maximum of 100 movements;
- a transaction description does not contain more than 60 characters.

# Output Data

After processing each of the commands indicated in the input data, the program should write the respective result in the standard output, if any. The only commands that produce results are: 'l', 'b', 'v' and 'w'. The rest of the commands are silent.

1. The command 'l', for each movement occurring on the indicated date, presents the following fields in a line separated by a space:
- an integer, indicating the relative position of the movement (index), whose value starts at 0 and is increased by 1 for each movement;
- the amount associated with the movement in question;
- the character 'r' or 'd', depending on the type of movement being a revenue or an expense, respectively;
- the description of the movement in question.

2. Command ’b’ displays a line containing only the balance sheet value at the given date.

3. The ’v’ command displays a line containing the message Valid or Invalid message, depending on whether the budget is valid or invalid, ie whether or not the defined minimum balance limit is met.

4. The ’w’ command displays a line containing only the first date (from the date indicated) on which the indicated expense can be borne, without making the budget invalid.
