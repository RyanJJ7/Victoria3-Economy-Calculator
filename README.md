# Victoria3-Economy-Calculator

This program calculates market changes in the smash hit video game Victoria 3 by Paradox Interactive. The user can input current market data and in-game construction plans. The calculator will estimate sell and buy order changes based off of the estimated building construction. This program also includes an infamy calculator for diplomatic plays.

Big Note: This program will create new directories using the create_directory() and create_directories() functions found in the filesystem library. Before running this program, all instances of these functions, as well as open() and remove_all(), should have the file paths edited for personal use... I should probably use a database to store data instead.

Small Note: This program includes an option to estimate pop consumption changes within a market based on user inputed pop consumption. This estimation does not account of Standard of Living changes. Often times, the construction of new buildings that employ people will raise SoL, which can raise or lower pop consumption. Pop consumption changes caused by this mechanic are not included in this calculator.
