# Victoria3-Economy-Calculator

This program calculates market changes in the smash hit video game Victoria 3 by Paradox Interactive. The user can input current market data and in-game construction plans. The calculator will estimate sell and buy order changes based off of the estimated building construction. This program also includes an infamy calculator for diplomatic plays.

Big Note: This program will create new directories using the create_directory() and create_directories() functions found in the filesystem library. Before running this program, all instances of these functions, as well as open() and remove_all(), should have the file paths edited for personal use... I should probably use a database to store data instead.

Small Note: This program includes an option to estimate pop consumption changes within a market based on user inputted pop consumption. This estimation does not account for Standard of Living changes. Often times, the construction of new buildings that employ people will raise SoL, which can raise or lower pop consumption. This calculator will function as if SoL is always static, even when it is not. This calculator will also fail when the user inputted pop consumption is zero (when a consumption good is being introduced to the market through building construction). When this occurs, pop consumption calculations default to zero.
