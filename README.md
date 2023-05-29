# MobiCash - Mobile Banking System

MobiCash is a mobile banking system that provides various banking operations such as cash in, cash out, mobile recharge, send money, check balance, and transaction details. It allows users to perform banking transactions conveniently from their mobile devices.

## Features

- User Registration: Users can register their mobile numbers and create an account.
- User Login: Registered users can log in to their accounts using their mobile numbers and passwords.
- Forgot Password: Users can recover their passwords if forgotten by providing their mobile number.
- Cash In: Users can deposit money into their accounts through authorized agents.
- Cash Out: Users can withdraw money from their accounts through authorized agents.
- Send Money: Users can send money to other mobile numbers.
- Mobile Recharge: Users can recharge mobile numbers with desired amounts.
- Check Balance: Users can check their account balances.
- Transaction Details: Users can view transaction details, including cash in, cash out, and mobile recharge transactions.
- Administrator: The system includes an admin interface to manage users and agents.

## How to Use

1. Registration:
   - Run the program and select the "Register User" or "Register Agent" option.
   - Provide the required information, such as mobile number, username, and password.
   - Upon successful registration, a new account will be created.

2. Login:
   - Select the "Login" option and enter your mobile number and password.
   - If the credentials are correct, you will be logged in to your account.

3. Perform Transactions:
   - After logging in, choose from various transaction options, such as send money, cash in, cash out, mobile recharge, check balance, or transaction details.
   - Follow the prompts and provide the necessary information to complete the transaction.

4. Administrator Access:
   - Select the "Admin of MobiCash" option to access the admin interface.
   - From there, you can view and manage registered users and agents.

## File Structure

- `main.cpp`: The main source code file containing the implementation of the mobile banking system.
- `README.md`: This file, providing an overview of the project and usage instructions.
- `User.txt`: Text file storing the list of registered users.
- `UserMobile.txt`: Text file storing the mapping of user mobile numbers to usernames.
- `Agent.txt`: Text file storing the list of registered agents.
- `data<user_mobile_number>.txt`: Text files storing user-specific data such as username and password.
- `Balance<user_mobile_number>.txt`: Text files storing the account balances of users.
- `Tran<user_mobile_number>.txt`: Text files storing transaction details for each user.

## Dependencies

The project does not have any external dependencies. It is implemented using C++ and standard library functions.

## Contributors

This project was developed by Tirtho Mondal as part of their coursework at CSE, KUET.

